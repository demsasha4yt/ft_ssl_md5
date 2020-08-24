/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 16:24:41 by bharrold          #+#    #+#             */
/*   Updated: 2020/08/24 21:32:15 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "md5.h"
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
	(void)ssl;
	md5_string("Hello world");
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

#else

static const t_tc g_tcs[] = {
	{
		.name = "MD5",
		.string = "Hello",
		.func = &md5_string,
		.valid = "5d41402abc4b2a76b9719d911017c592",
	},
	{
		.name = "STOP",
		.string = "\0",
		.func = NULL,
		.valid = "\0",
	}
};

int			main(void)
{
	t_tc	*tc;
	char	*result;

	tc = (t_tc*)g_tcs;
	while (tc && tc->func != NULL)
	{
		printf("[TEST]: Start %s: value=\"%s\", expected=\"%s\"\n",
			tc->name, tc->string, tc->valid);
		result = tc->func(tc->string);
		assert(result != NULL);
		assert(!strcmp(result, tc->valid));
		tc++;
	}
	return (0);
}

#endif

/*
** TEST
*/
