/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512_private.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 14:16:37 by bharrold          #+#    #+#             */
/*   Updated: 2020/09/02 17:29:35 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sha2_private.h"
#include "ft_ssl_utils.h"

static const uint64_t g_k[80] = {
	0x428a2f98d728ae22, 0x7137449123ef65cd,
	0xb5c0fbcfec4d3b2f, 0xe9b5dba58189dbbc,
	0x3956c25bf348b538, 0x59f111f1b605d019,
	0x923f82a4af194f9b, 0xab1c5ed5da6d8118,
	0xd807aa98a3030242, 0x12835b0145706fbe,
	0x243185be4ee4b28c, 0x550c7dc3d5ffb4e2,
	0x72be5d74f27b896f, 0x80deb1fe3b1696b1,
	0x9bdc06a725c71235, 0xc19bf174cf692694,
	0xe49b69c19ef14ad2, 0xefbe4786384f25e3,
	0x0fc19dc68b8cd5b5, 0x240ca1cc77ac9c65,
	0x2de92c6f592b0275, 0x4a7484aa6ea6e483,
	0x5cb0a9dcbd41fbd4, 0x76f988da831153b5,
	0x983e5152ee66dfab, 0xa831c66d2db43210,
	0xb00327c898fb213f, 0xbf597fc7beef0ee4,
	0xc6e00bf33da88fc2, 0xd5a79147930aa725,
	0x06ca6351e003826f, 0x142929670a0e6e70,
	0x27b70a8546d22ffc, 0x2e1b21385c26c926,
	0x4d2c6dfc5ac42aed, 0x53380d139d95b3df,
	0x650a73548baf63de, 0x766a0abb3c77b2a8,
	0x81c2c92e47edaee6, 0x92722c851482353b,
	0xa2bfe8a14cf10364, 0xa81a664bbc423001,
	0xc24b8b70d0f89791, 0xc76c51a30654be30,
	0xd192e819d6ef5218, 0xd69906245565a910,
	0xf40e35855771202a, 0x106aa07032bbd1b8,
	0x19a4c116b8d2d0c8, 0x1e376c085141ab53,
	0x2748774cdf8eeb99, 0x34b0bcb5e19b48a8,
	0x391c0cb3c5c95a63, 0x4ed8aa4ae3418acb,
	0x5b9cca4f7763e373, 0x682e6ff3d6b2b8a3,
	0x748f82ee5defb2fc, 0x78a5636f43172f60,
	0x84c87814a1f0ab72, 0x8cc702081a6439ec,
	0x90befffa23631e28, 0xa4506cebde82bde9,
	0xbef9a3f7b2c67915, 0xc67178f2e372532b,
	0xca273eceea26619c, 0xd186b8c721c0c207,
	0xeada7dd6cde0eb1e, 0xf57d4f7fee6ed178,
	0x06f067aa72176fba, 0x0a637dc5a2c898a6,
	0x113f9804bef90dae, 0x1b710b35131c471b,
	0x28db77f523047d84, 0x32caab7b40c72493,
	0x3c9ebe0a15c9bebc, 0x431d67c49c100d4c,
	0x4cc5d4becb3e42b6, 0x597f299cfc657e2a,
	0x5fcb6fab3ad6faec, 0x6c44198c4a475817
};

void	sha512_init(t_sha512_ctx *ctx)
{
	ctx->h[0] = 0x6a09e667f3bcc908;
	ctx->h[1] = 0xbb67ae8584caa73b;
	ctx->h[2] = 0x3c6ef372fe94f82b;
	ctx->h[3] = 0xa54ff53a5f1d36f1;
	ctx->h[4] = 0x510e527fade682d1;
	ctx->h[5] = 0x9b05688c2b3e6c1f;
	ctx->h[6] = 0x1f83d9abfb41bd6b;
	ctx->h[7] = 0x5be0cd19137e2179;
	ctx->t1 = 0;
	ctx->t2 = 0;
	memset(ctx->w, 0, sizeof(ctx->w));
}

static void	sha512_loop_step(t_sha512_ctx *ctx, size_t t)
{
	ctx->t1 = ctx->v[7] + EP1_512(ctx->v[4]) +
		CH(ctx->v[4], ctx->v[5], ctx->v[6]) + g_k[t] + ctx->w[t];
	ctx->t2 = EP0_512(ctx->v[0]) + MAJ(ctx->v[0], ctx->v[1], ctx->v[2]);
	ctx->v[7] = ctx->v[6];
	ctx->v[6] = ctx->v[5];
	ctx->v[5] = ctx->v[4];
	ctx->v[4] = ctx->v[3] + ctx->t1;
	ctx->v[3] = ctx->v[2];
	ctx->v[2] = ctx->v[1];
	ctx->v[1] = ctx->v[0];
	ctx->v[0] = ctx->t1 + ctx->t2;
}


static void	sha512_loop(t_sha512_ctx *ctx)
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
		while (++i < 80)
			ctx->w[i] = SIG1_512(ctx->w[i - 2]) + ctx->w[i - 16]
				+ SIG0_512(ctx->w[i - 15]) + ctx->w[i - 7];
		i = -1;
		while (++i < 8)
			ctx->v[i] = ctx->h[i];
		s = -1;
		while (++s < 80)
			sha512_loop_step(ctx, s);
		i = -1;
		while (++i < 8)
			ctx->h[i] += ctx->v[i];
	}
}

void	sha512_update(t_sha512_ctx *ctx, unsigned char *data, size_t len)
{
	size_t		i;

	ctx->len = len;
	ctx->bitlen = ctx->len * sizeof(unsigned char) * 8;
	if ((ctx->k = (448 - ctx->bitlen - 1) % 1024) < 0)
		ctx->k += 1024;
	ctx->msg_size = ctx->bitlen + 1 + ctx->k + 64;
	ctx->msg = (unsigned char*)malloc((ctx->msg_size / 16)
		* sizeof(unsigned char));
	memset(ctx->msg, 0, (ctx->msg_size / 16) * sizeof(unsigned char));
	memcpy(ctx->msg, data, ctx->len);
	ctx->msg[ctx->len] = 0b10000000;
	ctx->bitlen = bswap_uint64(ctx->bitlen);
	memcpy(ctx->msg + (ctx->msg_size / 16) - 16, &ctx->bitlen, 16);
	ctx->n = ctx->msg_size / 512;
	ctx->m = (uint64_t*)ctx->msg;
	i = -1;
	while (++i < ctx->n * 16)
		ctx->m[i] = bswap_uint64(ctx->m[i]);
	sha512_loop(ctx);
}


void	sha512_final(t_sha512_ctx *ctx)
{
	int	i;

	i = -1;
	free(ctx->msg);
	while (++i < 8)
		ctx->h[i] = bswap_uint64(ctx->h[i]);
}
