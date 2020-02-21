/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_par.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachena <gmachena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 16:29:49 by gmachena          #+#    #+#             */
/*   Updated: 2020/02/21 16:33:02 by gmachena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_gnl	*ft_list_par(t_gnl *ptr, int fd)
{
	while (ptr)
	{
		if ((ptr->fd) == fd)
			return (ptr);
		else
			ptr = ptr->next;
	}
	return (0);
}
