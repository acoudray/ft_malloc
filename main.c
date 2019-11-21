/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachena <gmachena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 11:48:25 by gmachena          #+#    #+#             */
/*   Updated: 2019/11/20 18:05:07 by gmachena         ###   ########.fr       */
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
    t = (char*)ft_malloc(sizeof(char) * 400);
    if (ft_search_addr(t) == NULL)
        printf("dw\n");
    printf("%p\n", t);
    t = "o9";
    printf("%p\n", t);
    if (ft_search_addr(t) == NULL)
        printf("dw\n");
    t = ft_malloc(5);
    //printf("%s\n", t);
    ft_malloc(50);
    ft_debug();
    show_alloc_mem();
    return (0);
}