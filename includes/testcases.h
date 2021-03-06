/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testcases.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 21:02:21 by bharrold          #+#    #+#             */
/*   Updated: 2020/10/25 19:11:29 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTCASES_H
# define TESTCASES_H

# define TEST_ 2

# ifdef TEST
#  include <assert.h>
#  include <stdlib.h>
#  include <string.h>

typedef char* (t_testfunc)(char *);

typedef struct	s_tc
{
	char		*name;
	char		*string;
	char		*valid;
	t_testfunc	*func;
}				t_tc;

# endif
#endif
