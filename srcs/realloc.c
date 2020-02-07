/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 11:49:28 by gmachena          #+#    #+#             */
/*   Updated: 2020/02/07 11:12:40 by gmachena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <string.h>
#include "ft_malloc.h"

void	*ft_resize_block(void *addr, size_t size)
{
	t_block *tmp;

	tmp  = addr - sizeof(t_block);
	tmp->free = 1;
    printf("size of: size = %lu\na = %lu\nfree = %lu\n struct %lu\n", sizeof(tmp->size), sizeof(tmp->a), sizeof(tmp->free), sizeof(t_block));
	if ((int)size < ((int)tmp->size - (int)sizeof(t_block)))
	{
		tmp->size = size;
		ft_block_split(tmp, size);
	}
	else
	{
		if ((tmp->next == NULL) || (tmp->next->a < 'a'))
		{
			tmp->free = 1;
			return (NULL);
		}
		if (tmp->next->free == 1 &&
		((tmp->next->size + tmp->size + sizeof(t_block)) >= size))
			ft_block_split(addr, size);
		else
		{
			tmp->free = 1;
			return (NULL);
		}
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
		memcpy(addr + sizeof(t_block), ptr, size);		//attention fonction interdite
		ft_block_split(addr, size);
	}
    return ((void*)addr + sizeof(t_block));
}