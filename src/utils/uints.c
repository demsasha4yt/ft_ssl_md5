/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uints.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 16:12:33 by bharrold          #+#    #+#             */
/*   Updated: 2020/09/01 19:15:13 by bharrold         ###   ########.fr       */
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
