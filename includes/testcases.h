/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testcases.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 21:02:21 by bharrold          #+#    #+#             */
/*   Updated: 2020/08/24 21:29:45 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTCASES_H
# define TESTCASES_H

# define TEST 1

# ifdef TEST
#  include <assert.h>

typedef char* (testfunc)(char *);

typedef struct	s_tc
{
	char		*name;
	char		*string;
	char		*valid;
	testfunc	*func;
}				t_tc;

# endif
#endif
