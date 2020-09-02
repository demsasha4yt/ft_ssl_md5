/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uints.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 16:12:33 by bharrold          #+#    #+#             */
/*   Updated: 2020/09/02 16:18:56 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_utils.h"

void		uint32_to_bytes(uint32_t val, uint8_t *bytes)
{
	bytes[0] = (uint8_t)val;
	bytes[1] = (uint8_t)(val >> 8);
	bytes[2] = (uint8_t)(val >> 16);
	bytes[3] = (uint8_t)(val >> 24);
}

void		uint32_to_bchar(uint32_t val, char *bytes)
{
	bytes[0] = val;
	bytes[1] = (val >> 8);
	bytes[2] = (val >> 16);
	bytes[3] = (val >> 24);
}

uint32_t	bytes_to_uint32(const uint8_t *bytes)
{
	return ((uint32_t)bytes[0] | ((uint32_t)bytes[1] << 8)
	| ((uint32_t)bytes[2] << 16) | ((uint32_t)bytes[3] << 24));
}

void		uint64_to_bchar(uint64_t val, char *bytes)
{
	bytes[0] = val;
	bytes[1] = (val >> 8);
	bytes[2] = (val >> 16);
	bytes[3] = (val >> 24);
	bytes[4] = (val >> 32);
	bytes[5] = (val >> 40);
	bytes[6] = (val >> 48);
	bytes[7] = (val >> 56);
}

uint64_t	bytes_to_uint64(const uint8_t *bytes)
{
	return ((uint64_t)bytes[0] | ((uint64_t)bytes[1] << 8)
	| ((uint64_t)bytes[2] << 16) | ((uint64_t)bytes[3] << 24)
	| ((uint64_t)bytes[4] << 32) | ((uint64_t)bytes[5] << 40)
	| ((uint64_t)bytes[6] << 48) | ((uint64_t)bytes[7] << 56));
}
