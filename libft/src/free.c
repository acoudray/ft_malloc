/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 11:18:37 by gmachena          #+#    #+#             */
/*   Updated: 2020/02/20 14:56:08 by acoudray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

static void		merge(void)
{
	t_block *curr;

	curr = g_glob;
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

static void		remove_empty_blocks(void)
{
	t_block *b[2];

	b[0] = g_glob;
	b[1] = NULL;
	while (b[0])
	{
		if (b[0]->free == 1 && b[0]->a < 'a' && (b[0]->size + sizeof(t_block)
			== TINY_SZ || b[0]->size + sizeof(t_block) >= SMALL_SZ))
		{
			if (b[1] != NULL)
				b[1]->next = b[0]->next;
			else
			{
				b[1] = b[0]->next;
				g_glob = b[1];
			}
			munmap(b[0], b[0]->size + sizeof(t_block));
			b[0] = b[1];
		}
		else
		{
			b[1] = b[0];
			b[0] = b[0]->next;
		}
	}
}

void			free(void *ptr)
{
	t_block		*metadata;
	t_block		*start;
	t_block		*ptrblock;

	pthread_mutex_lock(&g_mut);
	if ((ptrblock = ft_search_addr(ptr)) == NULL)
	{
		ft_printf("ptrblock = NULL\n");
		pthread_mutex_unlock(&g_mut);
		return ;
	}
	start = g_glob;
	metadata = ptr - sizeof(t_block);
	metadata->free = 1;
	merge();
	remove_empty_blocks();
	pthread_mutex_unlock(&g_mut);
}
