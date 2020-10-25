/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 16:24:41 by bharrold          #+#    #+#             */
/*   Updated: 2020/10/25 20:15:58 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "md5.h"
#include "sha2.h"
#include "testcases.h"

static const char	*g_print_usage = \
"usage: ft_ssl [command opts] [command args]\n\n\
Standart commands:\n\n\
Message diggest command:\n\n\
md5\n\
sha 256\n\n\
Cipher commands:\n";

int			select_mode(t_ssl *ssl)
{
	t_hfunc		*hfunc;

	init(ssl);
	if (parse_args(ssl))
		return (EXIT_FAILURE);
	hfunc = find_hfunc(ssl);
	if (hfunc == NULL)
		return (EXIT_FAILURE);
	if (fetch_data(ssl)) {
		return (EXIT_FAILURE);
	}
	ssl->resulthash = hfunc->func(ssl->srcstr);
	write_result(ssl);
	destroy(ssl);
	return (EXIT_SUCCESS);
}

int			print_usage(void)
{
	dprintf(2, "%s", g_print_usage);
	return (EXIT_FAILURE);
}

/*
** TEST
*/

#ifndef TEST

int			main(int argc, char **argv)
{
	t_ssl	ssl;

	ssl.argc = argc;
	ssl.argv = argv;
	if (argc < 2)
		return (print_usage());
	return (select_mode(&ssl));
}

#endif

/*
** TEST
*/
