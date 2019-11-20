/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 11:18:37 by gmachena          #+#    #+#             */
/*   Updated: 2019/11/20 11:51:34 by acoudray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

// void    ft_set_free(t_block *ptr)
// {
    
// }

void    ft_free(void *ptr)
{
    t_block *metadata;
    t_block *start;
    start = glob_m;
    metadata = ptr - sizeof(t_block);
    if (metadata->next != NULL)
    {
        while (start->next != metadata)
            start = start->next;
        start->next = metadata->next;
    }
    metadata->free = 1;
}