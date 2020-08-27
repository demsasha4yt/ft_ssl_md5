/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 16:36:23 by bharrold          #+#    #+#             */
/*   Updated: 2020/08/27 18:00:10 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>

# define ROTLEFT(a,b) (((a) << (b)) | ((a) >> (32-(b))))
# define ROTRIGHT(a,b) (((a) >> (b)) | ((a) << (32-(b))))

void				uint32_to_bytes(uint32_t val, uint8_t *bytes);
uint32_t			bytes_to_uint32(const uint8_t *bytes);
uint32_t			bswap_uint32(uint32_t x);
uint64_t			bswap_uint64(uint64_t x);
#endif
