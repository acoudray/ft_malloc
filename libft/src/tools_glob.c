/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_glob.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 17:16:12 by gmachena          #+#    #+#             */
/*   Updated: 2020/02/21 15:16:48 by acoudray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

t_block *g_glob = NULL;
pthread_mutex_t g_mut = PTHREAD_MUTEX_INITIALIZER;

void	*ft_search_block(size_t size)
{
	t_block	*ptr;
	char	sz;

	if (size > SMALL_PC)
		return (NULL);
	sz = (size <= TINY_PC) ? 't' : 's';
	ptr = g_glob;
	while (ptr)
	{
		if ((sz == ptr->a || sz == ptr->a + 32) && ptr->free == 1)
			if ((size + sizeof(t_block)) <= ptr->size)
				return (ptr);
		ptr = ptr->next;
	}
	return (NULL);
}

void	*ft_mem_initialize(t_block **block, size_t size, char sz)
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
	size_t	maptype;
	t_block	*new;
	size_t	largesize;

	largesize = (size + sizeof(t_block)) % 4096;
	if (size <= TINY_PC)
		sz = 'T';
	else
		sz = ((size > SMALL_PC) ? 'L' : 'S');
	if (sz == 'T')
		maptype = TINY_SZ;
	else
		maptype = ((sz == 'S') ? SMALL_SZ : size + sizeof(t_block) + largesize);
	if (((*block) = mmap(NULL, maptype, PROT_READ | PROT_WRITE,
		MAP_PRIVATE | MAP_ANONYMOUS, -1, 0)) == MAP_FAILED)
		return (MAP_FAILED);
	new = ft_mem_initialize(block, maptype - sizeof(t_block), sz);
	return (new);
}

void	*ft_new_block(size_t size)
{
	t_block *new;
	t_block *tmp;

	tmp = g_glob;
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
		tmp = ptr + size + sizeof(t_block);
		new = tmp;
		ft_mem_initialize(&new, block->size - (size + sizeof(t_block)),
		(block->a < 'a') ? block->a + 32 : block->a);
		new->next = block->next;
		block->size = size;
		block->next = new;
	}
}
