/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 19:15:00 by bharrold          #+#    #+#             */
/*   Updated: 2020/08/27 19:03:13 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "sha2_private.h"

char	*sha256_string(char *string)
{
	t_sha256_ctx	ctx;
	char			*buf;

	buf = malloc(SHA256_BLOCK_SIZE + 1);
	buf[SHA256_BLOCK_SIZE] = 0;;
	printf("sha256\n");
	sha256_init(&ctx);
	printf("sha256\n");
	sha256_update(&ctx, (uint8_t*)string, strlen(string));
	printf("sha258\n");
	sha256_final(&ctx);
	ctx.t[10] = -1;
	while (++ctx.t[10] < 4)
	{
		buf[ctx.t[10]] = (ctx.state[0] >> (24 - ctx.t[10] * 8)) & 0x000000ff;
		buf[ctx.t[10] + 4] = (ctx.state[1] >> (24 - ctx.t[10] * 8)) & 0x000000ff;
		buf[ctx.t[10] + 8] = (ctx.state[2] >> (24 - ctx.t[10] * 8)) & 0x000000ff;
		buf[ctx.t[10] + 12] = (ctx.state[3] >> (24 - ctx.t[10] * 8)) & 0x000000ff;
		buf[ctx.t[10] + 16] = (ctx.state[4] >> (24 - ctx.t[10] * 8)) & 0x000000ff;
		buf[ctx.t[10] + 20] = (ctx.state[5] >> (24 - ctx.t[10] * 8)) & 0x000000ff;
		buf[ctx.t[10] + 24] = (ctx.state[6] >> (24 - ctx.t[10] * 8)) & 0x000000ff;
		buf[ctx.t[10] + 28] = (ctx.state[7] >> (24 - ctx.t[10] * 8)) & 0x000000ff;
	}
	printf("\n");
	return (buf);
}
