/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 11:49:28 by gmachena          #+#    #+#             */
/*   Updated: 2020/02/21 14:09:52 by acoudray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "ft_malloc.h"

int ft_same_sz(int size, t_block *t)
{
	if (t->a == 'T' || t->a == 't')
	{
		if (size > TINY_PC)
			return (0);
	}
	else if(t->a == 'S' || t->a == 's')
	{
		if (size > SMALL_PC)
			return (0);
	}
	return (1);
}

void	*ft_resize_block(void *addr, size_t size)
{
	t_block *tmp;

	tmp = addr - sizeof(t_block);
	tmp->free = 1;
	if (ft_same_sz(size, tmp) == 0)
		return (0);
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

	tmp = g_glob;
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
	void	*addr;
	t_block	*tmp;

	if (ptr == NULL)
		return (malloc(size));
	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}
	tmp = ptr - sizeof(t_block);
	pthread_mutex_lock(&g_mut);
	if ((addr = ft_search_addr(ptr)) == NULL)
		return (return_and_unlockmutex(addr));
	if (ft_resize_block(addr, size) == NULL)
	{
		if ((addr = ft_search_block(size)) == NULL)
			if ((addr = ft_new_block(size)) == MAP_FAILED)
				return (return_and_unlockmutex(NULL));
		addr += sizeof(t_block);
		ft_memcpy(addr, ptr, tmp->size);
		ft_block_split(addr - sizeof(t_block), size);
	}
	pthread_mutex_unlock(&g_mut);
	return ((void*)addr);
}
