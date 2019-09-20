
#define PREFIX ""

#cmakedefine WORDS_BIGENDIAN 1

#define SIZEOF_INT @SIZEOF_INT@
#define SIZEOF_LONG @SIZEOF_LONG@

#cmakedefine HAVE_UNISTD_H 1
#cmakedefine HAVE_STRINGS_H 1
#cmakedefine HAVE_STDIO_EXT_H 1
#cmakedefine HAVE_MALLOC_H 1
#cmakedefine HAVE_FCNTL_H 1
#cmakedefine HAVE_SYS_PARAM_H 1
#cmakedefine HAVE_SYS_TYPES_H 1
#cmakedefine HAVE_SYS_STAT_H 1
#cmakedefine HAVE_SYS_TIME_H 1
#cmakedefine HAVE_SYS_FILE_H 1
#cmakedefine HAVE_SYS_WAIT_H 1
#cmakedefine HAVE_SYS_MMAN_H 1
#cmakedefine HAVE_SYS_RESOURCE_H 1
#cmakedefine HAVE_SYS_TIMES_H 1
#cmakedefine HAVE_IO_H 1
#cmakedefine HAVE_DIRECT_H 1

#cmakedefine HAVE_GETCWD 1
#cmakedefine HAVE_SBRK 1
#cmakedefine HAVE___FSETLOCKING 1
#cmakedefine HAVE_KILL 1
#cmakedefine HAVE_STRSIGNAL 1

#cmakedefine01 HAVE_DECL_BASENAME
#cmakedefine01 HAVE_DECL_STRNLEN
#cmakedefine01 HAVE_DECL_ASPRINTF
#cmakedefine01 HAVE_DECL_VASPRINTF
#cmakedefine01 HAVE_DECL_SBRK
#cmakedefine STRING_WITH_STRINGS
#cmakedefine TIME_WITH_SYS_TIME
#cmakedefine HAVE_LANGINFO_CODESET
#cmakedefine HAVE_SSIZE_T

/* No need to check for non-standard C, its 2019 today... */
#define STDC_HEADERS 1
#define HAVE_LONG_LONG 1
#define HAVE_DECL_SNPRINTF 1
#define HAVE_DECL_VSNPRINTF 1
#define HAVE_DECL_ERRNO 1
#define HAVE_DECL_MALLOC 1
#define HAVE_DECL_REALLOC 1
#define HAVE_DECL_CALLOC 1
#define HAVE_MEMCPY 1
#define HAVE_SETLOCALE 1
#define HAVE_INTTYPES_H 1
#define HAVE_LIMITS_H 1
#define HAVE_STDINT_H 1
#define HAVE_STDDEF_H 1
#define HAVE_STRING_H 1
#define HAVE_STDLIB_H 1
#define HAVE_LOCALE_H 1
#define HAVE_TIME_H 1

#ifndef HAVE_SSIZE_T
#define ssize_t ptrdiff_t
#endif
