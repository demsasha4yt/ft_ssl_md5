/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_private.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 16:04:22 by bharrold          #+#    #+#             */
/*   Updated: 2020/08/27 19:28:19 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_utils.h"
#include "sha2_private.h"

static const uint32_t g_k[64] = {
	0x428a2f98,0x71374491,0xb5c0fbcf,0xe9b5dba5,0x3956c25b,0x59f111f1,0x923f82a4,0xab1c5ed5,
	0xd807aa98,0x12835b01,0x243185be,0x550c7dc3,0x72be5d74,0x80deb1fe,0x9bdc06a7,0xc19bf174,
	0xe49b69c1,0xefbe4786,0x0fc19dc6,0x240ca1cc,0x2de92c6f,0x4a7484aa,0x5cb0a9dc,0x76f988da,
	0x983e5152,0xa831c66d,0xb00327c8,0xbf597fc7,0xc6e00bf3,0xd5a79147,0x06ca6351,0x14292967,
	0x27b70a85,0x2e1b2138,0x4d2c6dfc,0x53380d13,0x650a7354,0x766a0abb,0x81c2c92e,0x92722c85,
	0xa2bfe8a1,0xa81a664b,0xc24b8b70,0xc76c51a3,0xd192e819,0xd6990624,0xf40e3585,0x106aa070,
	0x19a4c116,0x1e376c08,0x2748774c,0x34b0bcb5,0x391c0cb3,0x4ed8aa4a,0x5b9cca4f,0x682e6ff3,
	0x748f82ee,0x78a5636f,0x84c87814,0x8cc70208,0x90befffa,0xa4506ceb,0xbef9a3f7,0xc67178f2
};

static void	sha256_loop(t_sha256_ctx *ctx)
{
	while (++ctx->t[8] < 64)
	{
		ctx->t[10] = ctx->t[7] + EP1(ctx->t[4]) +
			CH(ctx->t[4], ctx->t[5], ctx->t[6]) +
				g_k[ctx->t[8]] + ctx->m[ctx->t[8]];
		ctx->t[11] = EP0(ctx->t[0]) + MAJ(ctx->t[0], ctx->t[1], ctx->t[2]);
		ctx->t[7] = ctx->t[6];
		ctx->t[6] = ctx->t[5];
		ctx->t[5] = ctx->t[4];
		ctx->t[4] = ctx->t[3] + ctx->t[10];
		ctx->t[3] = ctx->t[2];
		ctx->t[2] = ctx->t[1];
		ctx->t[1] = ctx->t[0];
		ctx->t[0] = ctx->t[10] + ctx->t[11];
	}
	ctx->state[0] += ctx->t[0];
	ctx->state[1] += ctx->t[1];
	ctx->state[2] += ctx->t[2];
	ctx->state[3] += ctx->t[3];
	ctx->state[4] += ctx->t[4];
	ctx->state[5] += ctx->t[5];
	ctx->state[6] += ctx->t[6];
	ctx->state[7] += ctx->t[7];
}

static void	sha256_transform(t_sha256_ctx *ctx, uint8_t *data)
{
	ctx->t[8] = 0;
	ctx->t[9] = 0;
	while (ctx->t[8] < 16 && ctx->t[9]>= 0)
	{
		ctx->m[ctx->t[9]] = bytes_to_uint32(&data[ctx->t[9]]);
		ctx->t[8]++;
		ctx->t[9]++;
	}

	while (++ctx->t[8] < 64)
			ctx->m[ctx->t[8]] = SIG1(ctx->m[ctx->t[8] - 2]) +
				ctx->m[ctx->t[8] - 7] + SIG0(ctx->m[ctx->t[8] - 15])
					+ ctx->m[ctx->t[8] - 16];
	ctx->t[0] = ctx->state[0];
	ctx->t[1] = ctx->state[1];
	ctx->t[2] = ctx->state[2];
	ctx->t[3] = ctx->state[3];
	ctx->t[4] = ctx->state[4];
	ctx->t[5] = ctx->state[5];
	ctx->t[6] = ctx->state[6];
	ctx->t[7] = ctx->state[7];
	ctx->t[8] = -1;
	sha256_loop(ctx);
}

void		sha256_init(t_sha256_ctx *ctx)
{
	ctx->datalen = 0;
	ctx->bitlen = 0;
	ctx->state[0] = H256_0;
	ctx->state[1] = H256_1;
	ctx->state[2] = H256_2;
	ctx->state[3] = H256_3;
	ctx->state[4] = H256_4;
	ctx->state[5] = H256_5;
	ctx->state[6] = H256_6;
	ctx->state[7] = H256_0;
	memset(ctx->t, 0, sizeof(ctx->t));
	memset(ctx->m, 0, sizeof(ctx->m));
}

void		sha256_update(t_sha256_ctx *ctx, const uint8_t *data, size_t len)
{
	uint32_t i;

	for (i = 0; i < len; ++i) {
		ctx->data[ctx->datalen] = data[i];
		ctx->datalen++;
		if (ctx->datalen == 64) {
			sha256_transform(ctx, ctx->data);
			ctx->bitlen += 512;
			ctx->datalen = 0;
		}
	}
}

void		sha256_final(t_sha256_ctx *ctx)
{
	ctx->t[10] = ctx->datalen;
	if (ctx->datalen < 56)
	{
		ctx->data[ctx->t[10]++] = 0x80;
		while (ctx->t[10] < 56)
			ctx->data[ctx->t[10]++] = 0x0;
		sha256_transform(ctx, ctx->data);
		// memset(ctx->data, 0, 56);
	}
	ctx->bitlen += ctx->datalen * 8;
	ctx->data[63] = ctx->bitlen;
	ctx->data[62] = ctx->bitlen >> 8;
	ctx->data[61] = ctx->bitlen >> 16;
	ctx->data[60] = ctx->bitlen >> 24;
	ctx->data[59] = ctx->bitlen >> 32;
	ctx->data[58] = ctx->bitlen >> 40;
	ctx->data[57] = ctx->bitlen >> 48;
	ctx->data[56] = ctx->bitlen >> 56;
	sha256_transform(ctx, ctx->data);
}
