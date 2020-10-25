/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 16:25:34 by bharrold          #+#    #+#             */
/*   Updated: 2020/10/25 20:14:48 by bharrold         ###   ########.fr       */
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

# define FLAG_P_CHAR		'p'
# define FLAG_Q_CHAR		'q'
# define FLAG_R_CHAR		'r'
# define FLAG_S_CHAR		's'
# define FLAG_P			1 << 0
# define FLAG_Q			1 << 1
# define FLAG_R			1 << 2
# define FLAG_S			1 << 3

typedef char* (t_hashfunc)(char *);

typedef struct	s_hfunc {
	char		*name;
	t_hashfunc	*func;
}				t_hfunc;

typedef struct		s_ssl
{
	int				argc;
	char			**argv;
	uint32_t		flags;
	char			*func;
	char			*srcstr;
	char			*resulthash;
	uint32_t		funcs_cnt;
	t_hfunc			*funcs;
}					t_ssl;

void				init(t_ssl *ssl);
void				destroy(t_ssl *ssl);
int					parse_args(t_ssl *ssl);
t_hfunc				*find_hfunc(t_ssl *ssl);
int					fetch_data(t_ssl *ssl);
void				write_result(t_ssl *ssl);

#endif
