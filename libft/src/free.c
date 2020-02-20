/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 11:18:37 by gmachena          #+#    #+#             */
/*   Updated: 2020/02/07 16:13:53 by acoudray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

static void		merge(void)
{
	t_block *curr;

	curr = glob_m;
	while (curr)
	{
		if (curr->free && curr->next && curr->next->free && curr->next->a > 'a')
		{
			curr->size += curr->next->size + sizeof(t_block);
			curr->next = curr->next->next;
		}
		else
			curr = curr->next;
	}
}

static void		remove_empty_blocks()
{
	t_block *curr;
	t_block *prev;

	curr = glob_m;
	prev = NULL;
	while (curr)
	{
		if (curr->free == 1 && curr->a < 'a' && (curr->size + sizeof(t_block) == TINY_SZ
			|| curr->size + sizeof(t_block) >= SMALL_SZ))
		{
			if (prev != NULL)
				prev->next = curr->next;
			else
			{
				prev = curr->next;
				glob_m = prev;
			}
			munmap(curr, curr->size + sizeof(t_block));
			curr = prev;
		}
		else
		{
			prev = curr;
			curr = curr->next;
		}
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
	metadata->free = 1;
	merge();
	remove_empty_blocks();
}