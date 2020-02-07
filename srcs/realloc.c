/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 11:49:28 by gmachena          #+#    #+#             */
/*   Updated: 2019/11/20 12:07:57 by acoudray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

t_block	*ft_search_addr(void *ptr)
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
    t_block *tmp;

    if (ptr == NULL)
        return (ft_malloc(size));
    if (size == 0)
	{
        ft_free(ptr);
		return (NULL);
	}
    if ((tmp = ft_search_addr(ptr)) == NULL)
    	return ((void*)tmp);
    return (NULL);
}