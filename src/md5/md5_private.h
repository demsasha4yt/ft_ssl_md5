/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_private.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 18:10:26 by bharrold          #+#    #+#             */
/*   Updated: 2020/08/27 16:41:25 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MD5_PRIVATE_H
# define MD5_PRIVATE_H

# include <stdlib.h>
# include <string.h>

# define H0 = 0x67452301

# define F(b, c, d) (((b) & (c)) | ((~b) & (d)))
# define G(b, c, d) (((d) & (b)) | ((~d) & (c)))
# define H(b, c, d) ((b) ^ (c) ^ (d))
# define I(b, c, d) ((c) ^ ((b) | (~d)))

typedef unsigned long int	t_uint4;

typedef struct		s_md5_ctx
{
	uint32_t		hash[4];
	uint8_t			*msg;
	size_t			new_len;
	size_t			offset;
	uint32_t		w[16];
	uint32_t		t[8];
	uint8_t			digest[16];
}					t_md5_ctx;

void				md5_init(t_md5_ctx *ctx);
void				md5_update(t_md5_ctx *ctx, unsigned char *inbuf,
							uint32_t len);
void				md5_final(t_md5_ctx *ctx);
#endif

/*
** MD5_PRIVATE_H
*/
