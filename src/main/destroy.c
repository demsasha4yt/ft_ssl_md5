/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 19:41:00 by bharrold          #+#    #+#             */
/*   Updated: 2020/10/25 19:56:18 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void destroy(t_ssl *ssl) {
	ssl->funcs_cnt = 0;
	free(ssl->funcs);
	free(ssl->srcstr);
	free(ssl->func);
	free(ssl->resulthash);
}