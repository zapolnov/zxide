#ifndef SDCC_BRIDGE_H
#define SDCC_BRIDGE_H

#include <stddef.h>
#include <stdarg.h>

#ifdef __cplusplus
extern "C" {
#endif

int sdcpp_main(int argc, const char** argv);
int sdcc_main(int argc, char** argv, char** envp);

extern void (*sdcc_abort)(void);
extern void (*sdcc_fatal_exit)(void);

extern void* (*sdcc_in_open)(const char* filename);
extern void (*sdcc_in_close)(void* file);
extern int  (*sdcc_in_read)(void* file, void* buffer, size_t size);
extern int  (*sdcc_in_getc)(void* file);
extern long (*sdcc_in_getfilesize)(void* file);
extern void (*sdcc_in_rewind)(void* file);
extern int  (*sdcc_in_eof)(void* file);
extern char* (*sdcc_in_fgets)(char* buf, size_t max, void* file);

extern int (*sdcc_yyin_getc)(void);

extern void (*sdcc_out_putc)(char ch);
extern void (*sdcc_out_puts)(const char* str);
extern void (*sdcc_out_printf)(const char* fmt, ...);
extern void (*sdcc_out_write)(const void* data, size_t size);

extern void (*sdcc_msg_setlocation)(const char* file, int line);
extern void (*sdcc_msg_putc)(char ch);
extern void (*sdcc_msg_puts)(const char* str);
extern void (*sdcc_msg_printf)(const char* fmt, ...);
extern void (*sdcc_msg_vprintf)(const char* fmt, va_list args);

extern void (*sdcc_print_include)(const char* file);

void sdcc_cleanupAsm(void);
void sdcc_cleanupLex(void);
void sdcc_cleanupY(void);
void sdcc_cleanupHTab(void);
void sdcc_cleanupAst(void);
void sdcc_cleanupLabel(void);
void sdcc_cleanupGen(void);
void sdcc_cleanupRAlloc(void);
void sdcc_cleanupPeeph(void);
void sdcc_cleanupLRange(void);
void sdcc_cleanupOpt(void);
void sdcc_cleanupZ80Gen(void);
void sdcc_cleanupGlue(void);
void sdcc_collectGarbage(void);
void sdcc_closeInputFile(void);

#ifdef __cplusplus
}
#endif

#endif
