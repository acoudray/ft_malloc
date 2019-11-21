/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 11:18:37 by gmachena          #+#    #+#             */
/*   Updated: 2019/11/20 15:52:44 by acoudray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

// void    ft_set_free(t_block *ptr)
// {
	
// }

static void		merge(void)
{
	t_block *prev;
	t_block *current;

	current = glob_m;
	while (current)
	{
		if (prev->a < 'a' && current->next == NULL)
			munmap(&current, current->size);
		else if (current->free && current->next && current->next->free)
		{
			if (current->a < 'a' && current->next->a > 'a')
				current->size += current->next->size + sizeof(t_block);
		}
		prev = current;
		current = current->next;
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
}