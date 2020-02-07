/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachena <gmachena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 11:48:25 by gmachena          #+#    #+#             */
/*   Updated: 2020/02/07 15:24:38 by gmachena         ###   ########.fr       */
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
    char *t;
    char *c;
    char *i;

    t = (char*)ft_malloc(sizeof(char) * 200);
    c = (char*)ft_malloc(sizeof(char) * 127001);
    i = (char*)ft_malloc(sizeof(char) * 5);
    printf("\n\n sizeof %lu \n\n", 100 - sizeof(t_block) - 5);
    realloc(t, 100 - sizeof(t_block) - 5);
    realloc(t, 105);
    ft_debug();
    show_alloc_mem();
    return (0);
}