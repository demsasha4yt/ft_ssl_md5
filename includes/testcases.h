/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testcases.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 21:02:21 by bharrold          #+#    #+#             */
/*   Updated: 2020/09/01 19:47:54 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTCASES_H
# define TESTCASES_H

# define TEST 1

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
