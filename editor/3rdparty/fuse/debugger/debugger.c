/* debugger.c: Fuse's monitor/debugger
   Copyright (c) 2002-2016 Philip Kendall

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License along
   with this program; if not, write to the Free Software Foundation, Inc.,
   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

   Author contact information:

   E-mail: philip-fuse@shadowmagic.org.uk

*/

#include <config.h>

#include "debugger.h"
#include "debugger_internals.h"
#include "event.h"
#include "fuse.h"
#include "infrastructure/startup_manager.h"
#include "memory_pages.h"
#include "mempool.h"
#include "periph.h"
#include "ui/ui.h"
#include "z80/z80.h"
#include "z80/z80_macros.h"

/* The current activity state of the debugger */
enum debugger_mode_t debugger_mode;

/* Which base should we display things in */
int debugger_output_base;

/* Memory pool used by the lexer and parser */
int debugger_memory_pool;

/* The event type used for time breakpoints */
int debugger_breakpoint_event;

extern unsigned debugger_stepover_addr;
extern unsigned debugger_runto_addr;

/* Fuse's exit code */
static int exit_code = 0;

static int
debugger_init( void *context )
{
  debugger_breakpoints = NULL;
  debugger_output_base = 16;

  debugger_memory_pool = mempool_register_pool();

  debugger_breakpoint_event = event_register( debugger_breakpoint_time_fn, "Breakpoint" );

  debugger_event_init();
  debugger_system_variable_init();
  debugger_variable_init();
  debugger_reset();

  return 0;
}

void ui_runto_address_reached(void);

void
debugger_reset( void )
{
  debugger_breakpoint_remove_all();
  if (debugger_mode == DEBUGGER_MODE_RUN_TO_ADDRESS)
    ui_runto_address_reached();
  debugger_mode = DEBUGGER_MODE_INACTIVE;
}

static void
debugger_end( void )
{
  debugger_breakpoint_remove_all();
  debugger_variable_end();
  debugger_system_variable_end();
  debugger_event_end();
}

void
debugger_register_startup( void )
{
  startup_manager_module dependencies[] = {
    STARTUP_MANAGER_MODULE_EVENT,
    STARTUP_MANAGER_MODULE_MEMPOOL,
    STARTUP_MANAGER_MODULE_SETUID,
  };
  startup_manager_register( STARTUP_MANAGER_MODULE_DEBUGGER, dependencies,
                            ARRAY_SIZE( dependencies ), debugger_init, NULL,
                            debugger_end );
}

/* Activate the debugger */
int
debugger_trap( void )
{
  return ui_debugger_activate();
}

/* Step one instruction */
int
debugger_step( void )
{
  if (debugger_mode == DEBUGGER_MODE_RUN_TO_ADDRESS)
    ui_runto_address_reached();
  debugger_mode = DEBUGGER_MODE_HALTED;
  ui_debugger_deactivate( 0 );
  return 0;
}

/* Step to the next instruction, ignoring CALLs etc */
int
debugger_next( void )
{
  size_t length;

  libspectrum_byte opcode = readbyte_internal( PC );
  if (opcode != 0xC4 // call nz
    && opcode != 0xCC // call z
    && opcode != 0xCD // call
    && opcode != 0xD4 // call nc
    && opcode != 0xDC // call c
    && opcode != 0xE4 // call po
    && opcode != 0xEC // call pe
    && opcode != 0xF4 // call p
    && opcode != 0xFC // call m
    && opcode != 0xC7 // rst 0
    && opcode != 0xCF // rst 8
    && opcode != 0xD7 // rst 10
    && opcode != 0xDF // rst 18
    && opcode != 0xE7 // rst 20
    && opcode != 0xEF // rst 28
    && opcode != 0xF7 // rst 30
    && opcode != 0xFF // rst 38
    )
  {
    debugger_step();
    return 0;
  }

  /* Find out how long the current instruction is */
  debugger_disassemble( NULL, 0, &length, PC );

  if (debugger_mode == DEBUGGER_MODE_RUN_TO_ADDRESS)
    ui_runto_address_reached();
  debugger_mode = DEBUGGER_MODE_STEP_OVER;
  debugger_stepover_addr = (PC + length) & 0xffff;
  ui_debugger_deactivate( 0 );

  return 0;
}

/* Set debugger_mode so that emulation will occur */
int
debugger_run( void )
{
  if (debugger_mode == DEBUGGER_MODE_RUN_TO_ADDRESS)
    ui_runto_address_reached();
  debugger_mode = debugger_breakpoints ?
                  DEBUGGER_MODE_ACTIVE :
                  DEBUGGER_MODE_INACTIVE;
  ui_debugger_deactivate( 1 );
  return 0;
}

/* Exit from the last CALL etc by setting a oneshot breakpoint at
   (SP) and then starting emulation */
int
debugger_breakpoint_exit( void )
{
  if (debugger_mode == DEBUGGER_MODE_RUN_TO_ADDRESS)
    ui_runto_address_reached();
  debugger_mode = DEBUGGER_MODE_STEP_OUT;
  ui_debugger_deactivate( 0 );

  return 0;
}

void ui_runto_address_activated(unsigned addr);

int
debugger_run_to_address( unsigned addr )
{
  debugger_mode = DEBUGGER_MODE_RUN_TO_ADDRESS;
  debugger_runto_addr = addr;
  ui_debugger_deactivate( 0 );
  ui_runto_address_activated(addr);

  return 0;
}

/* Poke a value into RAM */
int
debugger_poke( libspectrum_word address, libspectrum_byte value )
{
  writebyte_internal( address, value );
  return 0;
}

/* Write a value to a port */
int
debugger_port_write( libspectrum_word port, libspectrum_byte value )
{
  writeport_internal( port, value );
  return 0;
}

/* Exit the emulator */
void
debugger_exit_emulator( debugger_expression *exit_code_expression )
{
  fuse_exiting = 1;

  exit_code = exit_code_expression ?
    debugger_expression_evaluate( exit_code_expression ) : 0;

  /* Ensure we break out of the main Z80 loop immediately */
  event_add( 0, event_type_null );

  debugger_run();
}

int
debugger_get_exit_code( void )
{
  return exit_code;
}
