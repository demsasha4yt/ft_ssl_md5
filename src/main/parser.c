/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 19:45:25 by bharrold          #+#    #+#             */
/*   Updated: 2020/10/25 20:04:13 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int		parse_args(t_ssl *ssl) {
	ssl->flags = 0;
	ssl->func = strdup("md5");
	ssl->srcstr = strdup("Hello world");
	return (0);
}