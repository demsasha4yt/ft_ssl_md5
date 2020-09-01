/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_private.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 16:04:22 by bharrold          #+#    #+#             */
/*   Updated: 2020/09/01 19:39:19 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_utils.h"
#include "sha2_private.h"

static const uint32_t g_k[64] = {
	0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1,
	0x923f82a4, 0xab1c5ed5, 0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
	0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174, 0xe49b69c1, 0xefbe4786,
	0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
	0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147,
	0x06ca6351, 0x14292967, 0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
	0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85, 0xa2bfe8a1, 0xa81a664b,
	0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
	0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a,
	0x5b9cca4f, 0x682e6ff3, 0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
	0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

void		sha256_init(t_sha256_ctx *ctx)
{
	ctx->len = 0;
	ctx->bitlen = 0;
	ctx->h[0] = 0x6a09e667;
	ctx->h[1] = 0xbb67ae85;
	ctx->h[2] = 0x3c6ef372;
	ctx->h[3] = 0xa54ff53a;
	ctx->h[4] = 0x510e527f;
	ctx->h[5] = 0x9b05688c;
	ctx->h[6] = 0x1f83d9ab;
	ctx->h[7] = 0x5be0cd19;
	ctx->t1 = 0;
	ctx->t2 = 0;
	memset(ctx->w, 0, sizeof(ctx->w));
}

static void	sha256_loop_step(t_sha256_ctx *ctx, size_t t)
{
	ctx->t1 = ctx->v[7] + EP1(ctx->v[4]) +
		CH(ctx->v[4], ctx->v[5], ctx->v[6]) + g_k[t] + ctx->w[t];
	ctx->t2 = EP0(ctx->v[0]) + MAJ(ctx->v[0], ctx->v[1], ctx->v[2]);
	ctx->v[7] = ctx->v[6];
	ctx->v[6] = ctx->v[5];
	ctx->v[5] = ctx->v[4];
	ctx->v[4] = ctx->v[3] + ctx->t1;
	ctx->v[3] = ctx->v[2];
	ctx->v[2] = ctx->v[1];
	ctx->v[1] = ctx->v[0];
	ctx->v[0] = ctx->t1 + ctx->t2;
}

static void	sha256_loop(t_sha256_ctx *ctx)
{
	int		i;
	size_t	t;
	size_t	s;

	t = -1;
	while (++t < ctx->n)
	{
		i = -1;
		while (++i < 16)
			ctx->w[i] = ctx->m[t * 16 + i];
		i = 15;
		while (++i < 64)
			ctx->w[i] = SIG1(ctx->w[i - 2]) + ctx->w[i - 16]
				+ SIG0(ctx->w[i - 15]) + ctx->w[i - 7];
		i = -1;
		while (++i < 8)
			ctx->v[i] = ctx->h[i];
		s = -1;
		while (++s < 64)
			sha256_loop_step(ctx, s);
		i = -1;
		while (++i < 8)
			ctx->h[i] += ctx->v[i];
	}
}

void		sha256_update(t_sha256_ctx *ctx, unsigned char *data, size_t len)
{
	size_t		i;

	ctx->len = len;
	ctx->bitlen = ctx->len * sizeof(unsigned char) * 8;
	if ((ctx->k = (448 - ctx->bitlen - 1) % 512) < 0)
		ctx->k += 512;
	ctx->msg_size = ctx->bitlen + 1 + ctx->k + 64;
	ctx->msg = (unsigned char*)malloc((ctx->msg_size / 8)
		* sizeof(unsigned char));
	memset(ctx->msg, 0, (ctx->msg_size / 8) * sizeof(unsigned char));
	memcpy(ctx->msg, data, ctx->len);
	ctx->msg[ctx->len] = 0b10000000;
	ctx->bitlen = bswap_uint64(ctx->bitlen);
	memcpy(ctx->msg + (ctx->msg_size / 8) - 8, &ctx->bitlen, 8);
	ctx->n = ctx->msg_size / 512;
	ctx->m = (uint32_t*)ctx->msg;
	i = -1;
	while (++i < ctx->n * 16)
		ctx->m[i] = bswap_uint32(ctx->m[i]);
	sha256_loop(ctx);
}

void		sha256_final(t_sha256_ctx *ctx)
{
	int	i;

	i = -1;
	free(ctx->msg);
	while (++i < 8)
		ctx->h[i] = bswap_uint32(ctx->h[i]);
}
