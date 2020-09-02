/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 16:36:23 by bharrold          #+#    #+#             */
/*   Updated: 2020/09/02 16:14:59 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_UTILS_H
# define FT_SSL_UTILS_H

# include <stdlib.h>

# define ROTLEFT(a,b) (((a) << (b)) | ((a) >> (32-(b))))
# define ROTRIGHT(a,b) (((a) >> (b)) | ((a) << (32-(b))))
# define ROTLEFT64(a,b) (((a) << (b)) | ((a) >> (64-(b))))
# define ROTRIGHT64(a,b) (((a) >> (b)) | ((a) << (64-(b))))


void				uint32_to_bytes(uint32_t val, uint8_t *bytes);
void				uint32_to_bchar(uint32_t val, char *bytes);
uint32_t			bytes_to_uint32(const uint8_t *bytes);
uint32_t			bswap_uint32(uint32_t x);
uint64_t			bswap_uint64(uint64_t x);
void				uint64_to_bchar(uint64_t val, char *bytes);
uint64_t			bytes_to_uint64(const uint8_t *bytes);
#endif
