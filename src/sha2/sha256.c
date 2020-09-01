/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 19:15:00 by bharrold          #+#    #+#             */
/*   Updated: 2020/09/01 19:45:49 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "sha2_private.h"

char	*sha256_string(char *string)
{
	t_sha256_ctx	ctx;
	char			prebuf[32];
	char			*buf;
	int				i;

	buf = malloc(64 + 1);
	memset(buf, 0, 64);
	sha256_init(&ctx);
	sha256_update(&ctx, (uint8_t*)string, strlen(string));
	sha256_final(&ctx);
	i = -1;
	while (++i < 8)
	{
		uint32_to_bchar(ctx.h[i], (prebuf + 4 * i));
		snprintf(buf, 65, "%s%2.2x%2.2x%2.2x%2.2x", buf,
		prebuf[i * 4 + 0] & 0xff,
		prebuf[i * 4 + 1] & 0xff,
		prebuf[i * 4 + 2] & 0xff,
		prebuf[i * 4 + 3] & 0xff);
	}
	return (buf);
}
