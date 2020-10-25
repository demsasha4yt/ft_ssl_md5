/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findhfunc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 19:58:18 by bharrold          #+#    #+#             */
/*   Updated: 2020/10/25 20:03:54 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

t_hfunc *find_hfunc(t_ssl *ssl) {
	uint32_t	i;

	i = 0;
	while (i < ssl->funcs_cnt)
	{
		if(strcmp(ssl->funcs[i].name, ssl->func) == 0) 
		{
			return (&ssl->funcs[i]);
		}
		i++;
	}
	return (NULL);
}