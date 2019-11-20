/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_glob.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachena <gmachena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 17:16:12 by gmachena          #+#    #+#             */
/*   Updated: 2019/11/19 14:01:20 by gmachena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

t_block *glob_m = NULL;

void	*ft_search_block(size_t size)
{
	t_block	*ptr;
	char	sz;

	if (size > SMALL_PC)
		return (NULL);
	sz = (size <= TINY_PC) ? 't' : 's';
	ptr = glob_m;
	while (ptr)
	{
		if ((sz == ptr->a || sz == ptr->a + 32) && ptr->free == 1)
			if ((size + sizeof(t_block)) <= ptr->size)
				return (ptr);
		ptr = ptr->next;
	}
	return (NULL);
}

void	*ft_mem_initialize(t_block **block, int size, char sz)
{
    (*block)->a = sz;
    (*block)->size = size;
    (*block)->free = 1;
    (*block)->next = NULL;
	return ((*block));
}

void	*ft_create_block(size_t size, t_block **block)
{
	char	sz;
	int		maptype;
	t_block	*new;

	sz = (size <= TINY_PC) ? 'T' : ((size > SMALL_PC) ? 'L' : 'S');
	maptype = (sz == 'T') ? TINY_SZ : 
			((sz == 'S') ? SMALL_SZ : size + sizeof(t_block));
	if (((*block) = mmap(NULL, maptype, PROT_READ|PROT_WRITE,
     MAP_PRIVATE|MAP_ANONYMOUS, -1, 0)) == MAP_FAILED)
		return (MAP_FAILED);
	new = ft_mem_initialize(block, maptype - sizeof(t_block), sz);

	return (new);
}

void	*ft_new_block(size_t size)
{
	t_block *new;
	t_block *tmp;

	tmp = glob_m;
	if ((ft_create_block(size, &new)) == MAP_FAILED)
		return (MAP_FAILED);
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	return (new);
}

void	ft_block_split(void *ptr, size_t size)
{
	t_block *block;
	t_block *new;
	void	*tmp;

	block = ptr;
	tmp = 0;
	block->free = 0;
	if ((size + sizeof(t_block)) < block->size)
	{
		tmp = ptr + size;
		new = tmp;
		ft_mem_initialize(&new, block->size - (size + sizeof(t_block)), (block->a > 'z') ? block->a - 32: block->a);
		new->next = block->next;
		block->size = size;
		block->next = new;
	}
}