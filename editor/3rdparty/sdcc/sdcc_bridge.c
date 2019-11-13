#include "sdcc_bridge.h"

void (*sdcc_abort)(void) = NULL;
void (*sdcc_fatal_exit)(void);

void* (*sdcc_in_open)(const char* filename);
void (*sdcc_in_close)(void* file);
int  (*sdcc_in_read)(void* file, void* buffer, size_t size);
int  (*sdcc_in_getc)(void* file);
long (*sdcc_in_getfilesize)(void* file);
void (*sdcc_in_rewind)(void* file);
int  (*sdcc_in_eof)(void* file);
char* (*sdcc_in_fgets)(char* buf, size_t max, void* file);

int (*sdcc_yyin_getc)(void);

void (*sdcc_out_putc)(char ch);
void (*sdcc_out_puts)(const char* str);
void (*sdcc_out_printf)(const char* fmt, ...);
void (*sdcc_out_write)(const void* data, size_t size);

void (*sdcc_msg_setlocation)(const char* file, int line);
void (*sdcc_msg_putc)(char ch);
void (*sdcc_msg_puts)(const char* str);
void (*sdcc_msg_printf)(const char* fmt, ...);
void (*sdcc_msg_vprintf)(const char* fmt, va_list args);

void (*sdcc_print_include)(const char* file);
