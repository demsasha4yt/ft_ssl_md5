/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_private.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 16:14:52 by bharrold          #+#    #+#             */
/*   Updated: 2020/08/25 19:03:45 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5.h"
#include "md5_private.h"
#include <stdio.h>

const uint32_t g_r[] = {7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17,
	22, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 4, 11, 16,
	23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 6, 10, 15, 21, 6, 10, 15,
	21, 6, 10, 15, 21, 6, 10, 15, 21};

const uint32_t g_k[] = {
	0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
	0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
	0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
	0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
	0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
	0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
	0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
	0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
	0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
	0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
	0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
	0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
	0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
	0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
	0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
	0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391};

static void		md5_step_end(t_md5_ctx *ctx, int i)
{
	ctx->t[7] = ctx->t[3];
	ctx->t[3] = ctx->t[2];
	ctx->t[2] = ctx->t[1];
	ctx->t[1] = ctx->t[1]
			+ LEFTROTATE(ctx->t[0] + ctx->t[5] + g_k[i] + ctx->w[ctx->t[6]],
						g_r[i]);
	ctx->t[0] = ctx->t[7];
}

static void		md5_step(t_md5_ctx *ctx, int i)
{
	if (i < 16)
	{
		ctx->t[5] = F(ctx->t[1], ctx->t[2], ctx->t[3]);
		ctx->t[6] = i;
	}
	else if (i < 32)
	{
		ctx->t[5] = G(ctx->t[1], ctx->t[2], ctx->t[3]);
		ctx->t[6] = (5 * i + 1) % 16;
	}
	else if (i < 48)
	{
		ctx->t[5] = H(ctx->t[1], ctx->t[2], ctx->t[3]);
		ctx->t[6] = (3 * i + 5) % 16;
	}
	else
	{
		ctx->t[5] = I(ctx->t[1], ctx->t[2], ctx->t[3]);
		ctx->t[6] = (7 * i) % 16;
	}
	md5_step_end(ctx, i);
}

static void		md5_loop(t_md5_ctx *ctx)
{
	int		i;

	ctx->offset = 0;
	while (ctx->offset < ctx->new_len)
	{
		i = -1;
		while (++i < 16)
			ctx->w[i] = md5_to_int32(ctx->msg + ctx->offset + i * 4);
		ctx->t[0] = ctx->hash[0];
		ctx->t[1] = ctx->hash[1];
		ctx->t[2] = ctx->hash[2];
		ctx->t[3] = ctx->hash[3];
		i = -1;
		while (++i < 64)
			md5_step(ctx, i);
		ctx->hash[0] += ctx->t[0];
		ctx->hash[1] += ctx->t[1];
		ctx->hash[2] += ctx->t[2];
		ctx->hash[3] += ctx->t[3];
		ctx->offset += 512 / 8;
	}
}

void			md5_update(t_md5_ctx *ctx, unsigned char *inbuf, uint32_t len)
{
	ctx->new_len = len;
	while (++ctx->new_len % (512 / 8) != 448 / 8)
		;
	ctx->msg = malloc(ctx->new_len + 8);
	memcpy(ctx->msg, inbuf, len);
	ctx->msg[len] = 0x80;
	ctx->offset = len;
	while (++ctx->offset < ctx->new_len)
		ctx->msg[ctx->offset] = 0;
	md5_to_bytes(len * 8, ctx->msg + ctx->new_len);
	md5_to_bytes(len >> 29, ctx->msg + ctx->new_len + 4);
	md5_loop(ctx);
}
