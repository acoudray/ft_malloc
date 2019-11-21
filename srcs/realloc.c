/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachena <gmachena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 11:49:28 by gmachena          #+#    #+#             */
/*   Updated: 2019/11/20 18:05:05 by gmachena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	*ft_resize_block(void *addr, size_t size)
{
	t_block *tmp;

	tmp  = addr;
	if (size < tmp->size - sizeof(t_block))
		ft_block_split(addr, size);
	else
	{
		if ((tmp->next == NULL) || (tmp->next->a < 'a'))
			return (NULL);
		if (tmp->next->free == 1 && 
		((tmp->next->size + tmp->size + sizeof(t_block)) >= size))
		{
			
		}
	}
	return (addr);
}

void	*ft_search_addr(void *ptr)
{
    t_block *tmp;
	void	*c;
	void	*d;

	tmp = glob_m;
	c = tmp + sizeof(t_block);
	printf("c = %p\n", c);
	printf("ptr = %p\n", ptr);
	d = tmp;
	while (tmp)
	{
		if (ptr >= c && ptr <= d)
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
		if ((addr = ft_search_block(size)) == NULL)
			if ((addr = ft_new_block(size)) == MAP_FAILED) // il faut copie la mem
				return (NULL);
	ft_block_split(addr, size);
    return ((void*)addr + sizeof(t_block));
}