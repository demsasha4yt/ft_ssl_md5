/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 19:35:05 by bharrold          #+#    #+#             */
/*   Updated: 2020/09/02 16:44:32 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "sha2_private.h"

char	*sha512_string(char *string)
{
	t_sha512_ctx	ctx;
	char			prebuf[64];
	char			*buf;
	int				i;

	buf = malloc(128 + 1);
	memset(buf, 0, 128);
	sha512_init(&ctx);
	sha512_update(&ctx, (uint8_t*)string, strlen(string));
	sha512_final(&ctx);
	i = -1;
	while (++i < 8)
	{
		uint64_to_bchar(ctx.h[i], (prebuf + 8 * i));
		snprintf(buf, 129, "%s%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x", buf,
		prebuf[i * 4 + 0] & 0xff,
		prebuf[i * 4 + 1] & 0xff,
		prebuf[i * 4 + 2] & 0xff,
		prebuf[i * 4 + 3] & 0xff,
		prebuf[i * 4 + 4] & 0xff,
		prebuf[i * 4 + 5] & 0xff,
		prebuf[i * 4 + 6] & 0xff,
		prebuf[i * 4 + 7] & 0xff);
	}
	return (buf);
}
