/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resultwriter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 20:09:54 by bharrold          #+#    #+#             */
/*   Updated: 2020/10/25 20:14:41 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void		write_result(t_ssl *ssl) {
	printf("Result = %s\n", ssl->resulthash);
}