/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha2_private.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 15:40:48 by bharrold          #+#    #+#             */
/*   Updated: 2020/09/02 16:47:54 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHA2_PRIVATE_H
# define SHA2_PRIVATE_H

# include <stdlib.h>
# include <string.h>
# include "ft_ssl_utils.h"

# define CH(x,y,z) (((x) & (y)) ^ (~(x) & (z)))
# define MAJ(x,y,z) (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))
# define EP0(x) (ROTRIGHT(x,2) ^ ROTRIGHT(x,13) ^ ROTRIGHT(x,22))
# define EP1(x) (ROTRIGHT(x,6) ^ ROTRIGHT(x,11) ^ ROTRIGHT(x,25))
# define SIG0(x) (ROTRIGHT(x,7) ^ ROTRIGHT(x,18) ^ ((x) >> 3))
# define SIG1(x) (ROTRIGHT(x,17) ^ ROTRIGHT(x,19) ^ ((x) >> 10))


# define EP0_512(x) (ROTRIGHT64(x,28) ^ ROTRIGHT64(x,34) ^ ROTRIGHT64(x,39))
# define EP1_512(x) (ROTRIGHT64(x,14) ^ ROTRIGHT64(x,18) ^ ROTRIGHT64(x,41))
# define SIG0_512(x) (ROTRIGHT64(x,1) ^ ROTRIGHT64(x,8) ^ ((x) >> 7))
# define SIG1_512(x) (ROTRIGHT64(x,19) ^ ROTRIGHT64(x,61) ^ ((x) >> 6))


typedef struct			s_sha256_ctx
{
	uint64_t			len;
	uint64_t			bitlen;
	size_t				k;
	size_t				msg_size;
	unsigned char		*msg;
	uint32_t			v[8];
	uint32_t			h[8];
	size_t				n;
	uint32_t			w[64];
	uint32_t			*m;
	uint32_t			t1;
	uint32_t			t2;
}						t_sha256_ctx;

void					sha256_init(t_sha256_ctx *ctx);
void					sha256_update(t_sha256_ctx *ctx,
						unsigned char *data, size_t len);
void					sha256_final(t_sha256_ctx *ctx);

typedef struct			s_sha512_ctx
{
	uint64_t			len;
	uint64_t			bitlen;
	size_t				k;
	size_t				msg_size;
	unsigned char		*msg;
	uint64_t			v[8];
	uint64_t			h[8];
	size_t				n;
	uint64_t			w[80];
	uint64_t			*m;
	uint64_t			t1;
	uint64_t			t2;
}						t_sha512_ctx;

void					sha512_init(t_sha512_ctx *ctx);
void					sha512_update(t_sha512_ctx *ctx,
						unsigned char *data, size_t len);
void					sha512_final(t_sha512_ctx *ctx);


#endif

/*
** SHA2_PRIVATE_H
*/
