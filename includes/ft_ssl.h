/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 16:25:34 by bharrold          #+#    #+#             */
/*   Updated: 2020/08/24 21:12:32 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>

# define MD5 0
# define SHA256 2
# define SHA512 4

typedef struct	s_ssl
{
	int			argc;
	char		**argv;
	int			func;
}				t_ssl;

#endif
