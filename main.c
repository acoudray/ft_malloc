/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 11:48:25 by gmachena          #+#    #+#             */
/*   Updated: 2019/11/20 15:43:38 by acoudray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./includes/ft_malloc.h"

void    ft_debug(void)
{
    t_block *tmp;
    int i;

    i = 1;
    tmp = glob_m;
    while (tmp)
    {
        printf("-------- BLOC N°%d --------\n\n", i);
        printf(" -TYPE = %c\n -TAILLE = %d\n -LIBRE = %d\n\n\n", tmp->a, (int)tmp->size, tmp->free);
        i++;
        tmp = tmp->next;
    }
}

int main(void)
{
    char *p, *q, *r;

    p = ft_malloc(400);
    // printf("p = %p\n\n", &p);
    // p = "p";
    // printf("p = %p\n\n", &p);
    q = ft_malloc(5);
    // q = "q";
    r = ft_malloc(50);
    // r = "r";
    // ft_malloc(496);
    // ft_malloc(126000);
    // ft_malloc(128000);
    ft_free(p);
    ft_free(q);
    ft_free(r);    
    ft_debug();
    show_alloc_mem();
    return (0);
}