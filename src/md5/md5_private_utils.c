/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_private_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 16:31:35 by bharrold          #+#    #+#             */
/*   Updated: 2020/08/25 19:04:22 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5.h"
#include "md5_private.h"

void		md5_to_bytes(uint32_t val, uint8_t *bytes)
{
	bytes[0] = (uint8_t)val;
	bytes[1] = (uint8_t)(val >> 8);
	bytes[2] = (uint8_t)(val >> 16);
	bytes[3] = (uint8_t)(val >> 24);
}

uint32_t	md5_to_int32(const uint8_t *bytes)
{
	return ((uint32_t)bytes[0] | ((uint32_t)bytes[1] << 8)
	| ((uint32_t)bytes[2] << 16) | ((uint32_t)bytes[3] << 24));
}
