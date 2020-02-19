/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachena <gmachena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 11:49:28 by gmachena          #+#    #+#             */
/*   Updated: 2020/02/19 13:41:03 by gmachena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "ft_malloc.h"

void	*ft_resize_block(void *addr, size_t size)
{
	t_block *tmp;

	tmp = addr - sizeof(t_block);
	tmp->free = 1;
	if ((int)size < ((int)tmp->size - (int)sizeof(t_block)))
		ft_block_split(tmp, size);
	else
	{
		if ((tmp->next == NULL) || (tmp->next->a < 'a'))
			return (NULL);
		if (tmp->next->free == 1 &&
		((tmp->next->size + tmp->size + sizeof(t_block)) >= size))
		{
			tmp->size = (tmp->next->size + tmp->size + sizeof(t_block));
			tmp->next = tmp->next->next;
			ft_block_split(tmp, size);
		}
		else
			return (NULL);
	}
	return (addr);
}

void	*ft_search_addr(void *ptr)
{
	t_block *tmp;

	tmp = glob_m;
	while (tmp)
	{
		if (ptr == (void*)tmp + sizeof(t_block))
			return (ptr);
		tmp = tmp->next;
	}
	return (NULL);
}

void	*realloc(void *ptr, size_t size)
{
	void *addr;

	if (ptr == NULL)
		return (ft_malloc(size));
	if (size == 0)
	{
		ft_free(ptr);
		return (NULL);
	}
	if ((addr = ft_search_addr(ptr)) == NULL)
		return (addr);
	if (ft_resize_block(addr, size) == NULL)
	{
		if ((addr = ft_search_block(size)) == NULL)
			if ((addr = ft_new_block(size)) == MAP_FAILED)
				return (NULL);
		ft_memcpy(addr + sizeof(t_block), ptr, size);
		ft_block_split(addr, size);
	}
	return ((void*)addr + sizeof(t_block));
}
