/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachena <gmachena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 11:48:25 by gmachena          #+#    #+#             */
/*   Updated: 2020/02/20 17:05:00 by gmachena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./includes/ft_malloc.h"
# include <pthread.h>

void    ft_debug(void)
{
    t_block *tmp;
    int i;

    i = 1;
    tmp = g_glob;
    while (tmp)
    {
        printf("-------- BLOC N°%d --------\n\n", i);
        printf(" -TYPE = %c\n -TAILLE = %d\n -LIBRE = %d\n\n\n", tmp->a, (int)tmp->size, tmp->free);
        i++;
        tmp = tmp->next;
    }
}

void *task1(void *test)
{
    test = (char*)malloc(sizeof(char) * 20);
    test = realloc(test, sizeof(char) * 10);
    free(test);
    return test;
}

void *task2(void *test)
{
    test = malloc(sizeof(char) * 20);
    test = realloc(test, sizeof(char) * 30);
    free(test);
    return test;
}

void ft_debug_pthread()
{
    char *test1 = 0;
    char *test2 = 0;
    pthread_t thread1;
    pthread_t thread2;

    if(pthread_create(&thread1, NULL, task1, test1) == -1) {
	    return ;
    }
    if(pthread_create(&thread2, NULL, task2, test2) == -1) {
	    return ;
    }
    if (pthread_join(thread1, NULL)) {
	    return ;
    }
    if (pthread_join(thread2, NULL)) {
	    return ;
    }
}

void ft_debug_rea1()
{
    char *t;

    t = (char*)malloc(sizeof(char) * 1);
    //show_alloc_mem();
    t = (char*)realloc(t, sizeof(char) * 127001);
    ft_debug();
	ft_printf("t = 0x%X\n", (void*)t);
    free(t);
}

void ft_debug_rea2()
{
    char *t;

    t = (char*)malloc(sizeof(char) * 1);
    t = (char*)realloc(t, sizeof(char) * 1073741824);
    free(t);
}

void ft_debug_man()
{
    char *t;
    char *c;
    char *i;


     t = (char*)malloc(sizeof(char) * 1073741824);
     c = (char*)malloc(sizeof(char) * 5);
     i = (char*)malloc(sizeof(char) * 499);
    //ft_debug();
    free(t);
    free(c);
    //ft_debug();
}

int main(void)
{
    //ft_debug_rea1();
    ft_debug_rea2();
    //ft_debug_man();
    //ft_debug_pthread();
    ft_debug();
    //show_alloc_mem();
    return (0);
}