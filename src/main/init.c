/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 19:32:20 by bharrold          #+#    #+#             */
/*   Updated: 2020/10/25 20:08:40 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "md5.h"
#include "sha2.h"

static void	init_funcs(t_ssl *ssl) {
	ssl->funcs_cnt = 2;
	ssl->funcs = (t_hfunc*)malloc(ssl->funcs_cnt * sizeof(t_hfunc));
	ssl->funcs[0] = (t_hfunc){.name="md5", .func=md5_string};
	ssl->funcs[1] = (t_hfunc){.name="sha256", .func=sha256_string};
}

void		init(t_ssl *ssl) {
	bzero(ssl, sizeof(t_ssl));
	init_funcs(ssl);
}