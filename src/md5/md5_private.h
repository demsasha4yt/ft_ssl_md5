/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_private.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 18:10:26 by bharrold          #+#    #+#             */
/*   Updated: 2020/08/24 21:10:48 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MD5_PRIVATE_H
# define MD5_PRIVATE_H

# include <stdlib.h>

# define ROTATE_LEFT(x, n) (((x) << (n)) | ((x) >> (32-(n))))
# define F(x, y, z) (((x) & (y)) | ((~x) & (z)))
# define G(x, y, z) (((x) & (z)) | ((y) & (~z)))
# define H(x, y, z) ((x) ^ (y) ^ (z))
# define I(x, y, z) ((y) ^ ((x) | (~z)))

typedef unsigned long int	t_uint4;

/*
** number of _bits_ handled mod 2^64
** stratch buffer
** input buffer
** actual diggest after MD5Final Call
*/

typedef struct		s_md5_ctx
{
	t_uint4			i[2];
	t_uint4			buf[64];
	unsigned char	in[64];
	unsigned char	digest[16];
}					t_md5_ctx;

void				md5_init(t_md5_ctx *ctx);
void				md5_update(t_md5_ctx *ctx, unsigned char *inbuf,
							uint32_t len);
void				md5_final(t_md5_ctx *ctx);

#endif

/*
** MD5_PRIVATE_H
*/
