#ifndef LZSA_ENUM_H
#define LZSA_ENUM_H

/** High level status for compression and decompression */
typedef enum _lzsa_status_t {
   LZSA_OK = 0,                           /**< Success */
   LZSA_ERROR_SRC,                        /**< Error reading input */
   LZSA_ERROR_DST,                        /**< Error reading output */
   LZSA_ERROR_DICTIONARY,                 /**< Error reading dictionary */
   LZSA_ERROR_MEMORY,                     /**< Out of memory */

   /* Compression-specific status codes */
   LZSA_ERROR_COMPRESSION,                /**< Internal compression error */
   LZSA_ERROR_RAW_TOOLARGE,               /**< Input is too large to be compressed to a raw block */
   LZSA_ERROR_RAW_UNCOMPRESSED,           /**< Input is incompressible and raw blocks don't support uncompressed data */

   /* Decompression-specific status codes */
   LZSA_ERROR_FORMAT,                     /**< Invalid input format or magic number when decompressing */
   LZSA_ERROR_DECOMPRESSION               /**< Internal decompression error */
} lzsa_status_t;

#endif
