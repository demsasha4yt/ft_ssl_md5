/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 16:47:05 by bharrold          #+#    #+#             */
/*   Updated: 2020/08/27 16:41:18 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "ft_ssl_utils.h"
#include "md5_private.h"
#include "md5.h"

void			md5_init(t_md5_ctx *ctx)
{
	ctx->hash[0] = 0x67452301;
	ctx->hash[1] = 0xefcdab89;
	ctx->hash[2] = 0x98badcfe;
	ctx->hash[3] = 0x10325476;
}

void			md5_final(t_md5_ctx *ctx)
{
	free(ctx->msg);
	uint32_to_bytes(ctx->hash[0], ctx->digest);
	uint32_to_bytes(ctx->hash[1], ctx->digest + 4);
	uint32_to_bytes(ctx->hash[2], ctx->digest + 8);
	uint32_to_bytes(ctx->hash[3], ctx->digest + 12);
}

char			*md5_string(char *string)
{
	t_md5_ctx		md_ctx;
	unsigned int	len;
	char			*result;
	int				i;

	if ((result = malloc(33)) == NULL)
		return (NULL);
	result[0] = 0;
	result[32] = 0;
	len = strlen(string);
	md5_init(&md_ctx);
	md5_update(&md_ctx, (unsigned char*)string, len);
	md5_final(&md_ctx);
	i = -1;
	while (++i < 16)
		snprintf(result, 33, "%s%2.2x", result, md_ctx.digest[i]);
	return (result);
}
