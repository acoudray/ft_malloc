/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachena <gmachena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 10:32:41 by gmachena          #+#    #+#             */
/*   Updated: 2019/11/20 10:57:43 by gmachena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void    ft_print_size(t_block *tmp)
{
    if (tmp->a == 'T')
        printf("TINY : ");
    else if (tmp->a == 'S')
        printf("SMALL : ");
    else if (tmp->a == 'L')
        printf("LARGE : ");
    printf("%p\n", (void*)tmp);
}

int     ft_print_block(t_block *tmp)
{
    int size;
    void *mem;

    size = 0;
    mem = (void*)tmp + sizeof(t_block);
    size = tmp->size;
    printf("%p - %p : %d octets\n", mem, mem + size, size);
    return (size);
}

void    show_alloc_mem()
{
    t_block *tmp;
    int     i;

    i = 0;
    tmp = glob_m;
    while (tmp)
    {
        if (tmp->a < 97)
            ft_print_size(tmp);
        if (tmp->free == 0)
            i += ft_print_block(tmp);
        tmp = tmp->next;
    }
    printf("Total : %d octets\n", i);
}