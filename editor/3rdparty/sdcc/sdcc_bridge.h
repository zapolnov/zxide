#ifndef SDCC_BRIDGE_H
#define SDCC_BRIDGE_H

#include <stddef.h>
#include <stdarg.h>

#ifdef __cplusplus
extern "C" {
#endif

int sdcpp_main(int argc, const char** argv);
int sdcc_main(int argc, const char** argv, char** envp);

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

#ifdef __cplusplus
}
#endif

#endif
