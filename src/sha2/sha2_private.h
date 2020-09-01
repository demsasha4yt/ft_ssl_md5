/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha2_private.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 15:40:48 by bharrold          #+#    #+#             */
/*   Updated: 2020/09/01 19:47:37 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHA2_PRIVATE_H
# define SHA2_PRIVATE_H

# include <stdlib.h>
# include <string.h>
# include "ft_ssl_utils.h"

# define SHA256_BLOCK_SIZE 32

# define H256_0 0x6A09E667
# define H256_1 0xBB67AE85
# define H256_2 0x3C6EF372
# define H256_3 0xA54FF53A
# define H256_4 0x510E527F
# define H256_5 0x9B05688C
# define H256_6 0x1F83D9AB
# define H256_7 0x5BE0CD19

# define H512_0 0x6a09e667f3bcc908
# define H512_1 0xbb67ae8584caa73b
# define H512_2 0x3c6ef372fe94f82b
# define H512_3 0xa54ff53a5f1d36f1
# define H512_4 0x510e527fade682d1
# define H512_5 0x9b05688c2b3e6c1f
# define H512_6 0x1f83d9abfb41bd6b
# define H512_7 0x5be0cd19137e2179

# define CH(x,y,z) (((x) & (y)) ^ (~(x) & (z)))
# define MAJ(x,y,z) (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))
# define EP0(x) (ROTRIGHT(x,2) ^ ROTRIGHT(x,13) ^ ROTRIGHT(x,22))
# define EP1(x) (ROTRIGHT(x,6) ^ ROTRIGHT(x,11) ^ ROTRIGHT(x,25))
# define SIG0(x) (ROTRIGHT(x,7) ^ ROTRIGHT(x,18) ^ ((x) >> 3))
# define SIG1(x) (ROTRIGHT(x,17) ^ ROTRIGHT(x,19) ^ ((x) >> 10))

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

#endif

/*
** SHA2_PRIVATE_H
*/
