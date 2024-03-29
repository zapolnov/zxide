/*
 * (c) Copyright 2012 by Einar Saukas. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * The name of its author may not be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdio.h>
#include <stdlib.h>

#include "zx7.h"

typedef struct Ctx {
    unsigned char* output_data;
    size_t output_index;
    size_t bit_index;
    int bit_mask;
} Ctx;

static void write_byte(Ctx* ctx, int value) {
    ctx->output_data[ctx->output_index++] = value;
}

static void write_bit(Ctx* ctx, int value) {
    if (ctx->bit_mask == 0) {
        ctx->bit_mask = 128;
        ctx->bit_index = ctx->output_index;
        write_byte(ctx, 0);
    }
    if (value > 0) {
        ctx->output_data[ctx->bit_index] |= ctx->bit_mask;
    }
    ctx->bit_mask >>= 1;
}

static void write_elias_gamma(Ctx* ctx, int value) {
    int i;

    for (i = 2; i <= value; i <<= 1) {
        write_bit(ctx, 0);
    }
    while ((i >>= 1) > 0) {
        write_bit(ctx, value & i);
    }
}

unsigned char *zx7_compress(Optimal *optimal, unsigned char *input_data, size_t input_size, size_t *output_size) {
    size_t input_index;
    size_t input_prev;
    int offset1;
    int mask;
    int i;

    Ctx ctx;

    /* calculate and allocate output buffer */
    input_index = input_size-1;
    *output_size = (optimal[input_index].bits+18+7)/8;
    ctx.output_data = (unsigned char *)malloc(*output_size);
    if (!ctx.output_data) {
         /*fprintf(stderr, "Error: Insufficient memory\n");
         exit(1);*/
         return NULL;
    }

    /* un-reverse optimal sequence */
    optimal[input_index].bits = 0;
    while (input_index > 0) {
        input_prev = input_index - (optimal[input_index].len > 0 ? optimal[input_index].len : 1);
        optimal[input_prev].bits = input_index;
        input_index = input_prev;
    }

    ctx.output_index = 0;
    ctx.bit_index = 0;
    ctx.bit_mask = 0;

    /* first byte is always literal */
    write_byte(&ctx, input_data[0]);

    /* process remaining bytes */
    while ((input_index = optimal[input_index].bits) > 0) {
        if (optimal[input_index].len == 0) {

            /* literal indicator */
            write_bit(&ctx, 0);

            /* literal value */
            write_byte(&ctx, input_data[input_index]);

        } else {

            /* sequence indicator */
            write_bit(&ctx, 1);

            /* sequence length */
            write_elias_gamma(&ctx, optimal[input_index].len-1);

            /* sequence offset */
            offset1 = optimal[input_index].offset-1;
            if (offset1 < 128) {
                write_byte(&ctx, offset1);
            } else {
                offset1 -= 128;
                write_byte(&ctx, (offset1 & 127) | 128);
                for (mask = 1024; mask > 127; mask >>= 1) {
                    write_bit(&ctx, offset1 & mask);
                }
            }
        }
    }

    /* sequence indicator */
    write_bit(&ctx, 1);

    /* end marker > MAX_LEN */
    for (i = 0; i < 16; i++) {
        write_bit(&ctx, 0);
    }
    write_bit(&ctx, 1);

    return ctx.output_data;
}
