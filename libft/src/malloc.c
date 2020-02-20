/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 11:15:28 by acoudray          #+#    #+#             */
/*   Updated: 2020/02/20 14:57:26 by acoudray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	*malloc(size_t size)
{
	void *addr;

	pthread_mutex_lock(&g_mut);
	addr = NULL;
	if (size == 0)
		return (NULL);
	else if (!(g_glob))
	{
		if ((addr = ft_create_block(size, &g_glob)) == MAP_FAILED)
			return (NULL);
	}
	else if ((addr = ft_search_block(size)) == NULL)
		if ((addr = ft_new_block(size)) == MAP_FAILED)
			return (NULL);
	ft_block_split(addr, size);
	pthread_mutex_unlock(&g_mut);
	return (addr + sizeof(t_block));
}
