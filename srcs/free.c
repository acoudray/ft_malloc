/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 11:18:37 by gmachena          #+#    #+#             */
/*   Updated: 2019/11/21 16:54:59 by acoudray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

// void    ft_set_free(t_block *ptr)
// {
	
// }

static void		remove_empty_blocks()
{
	t_block *curr;

	curr = glob_m;
	while (curr)
	{
		if (curr->a < 'a' && curr->free)
		{
			if (curr == glob_m && glob_m->next)
			{
				glob_m = glob_m->next;
				glob_m->a -= 32;
			}
			munmap(curr + sizeof(t_block), curr->size);
		}
		curr = curr->next;
	}
}

static void		merge(void)
{
	t_block *curr;

	curr = glob_m;
	while (curr)
	{
		if (curr->free && curr->next && curr->next->free)
			curr->size += curr->next->size + sizeof(t_block);
		curr = curr->next;
	}
}

void			ft_free(void *ptr)
{
	t_block		*metadata;
	t_block		*start;
	t_block		*ptrblock;

	if ((ptrblock = ft_search_addr(ptr)) == NULL)
		return ;
	start = glob_m;
	metadata = ptr - sizeof(t_block);
	if (metadata == NULL || metadata->free == 1)
		return ;
	metadata->free = 1;
	merge();
	remove_empty_blocks();
}