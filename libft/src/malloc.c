/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachena <gmachena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 11:15:28 by gmachena          #+#    #+#             */
/*   Updated: 2020/02/21 16:38:30 by gmachena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	*malloc(size_t size)
{
	void *addr;

	addr = NULL;
	if (size == 0)
		return (NULL);
	pthread_mutex_lock(&g_mut);
	if (!(g_glob))
	{
		if ((addr = ft_create_block(size, &g_glob)) == MAP_FAILED)
			return (return_and_unlockmutex(NULL));
	}
	else if ((addr = ft_search_block(size)) == NULL)
		if ((addr = ft_new_block(size)) == MAP_FAILED)
			return (return_and_unlockmutex(NULL));
	ft_block_split(addr, size);
	pthread_mutex_unlock(&g_mut);
	return (addr + sizeof(t_block));
}
