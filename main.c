/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 11:48:25 by gmachena          #+#    #+#             */
/*   Updated: 2020/02/20 14:08:55 by acoudray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./includes/ft_malloc.h"
# include <pthread.h>

void *task1(void *test)
{
    test = malloc(sizeof(char) * 20);
    test = realloc(test, sizeof(char) * 10);
    test = "task1";
    ft_printf("%s\n", test);
    // free(test);
    return test;
}

void *task2(void *test)
{
    test = malloc(sizeof(char) * 20);
    test = realloc(test, sizeof(char) * 30);
    test = "task2";
    ft_printf("%s\n", test);
    // free(test);
    return test;
}

int main(void)
{
    // char *t;
    // char *c;
    // char *i;
    char *test1 = 0;
    char *test2 = 0;
    pthread_t thread1;
    pthread_t thread2;

    // t = (char*)malloc(sizeof(char) * 1073741824);
    // c = (char*)malloc(sizeof(char) * 5);
    // i = (char*)malloc(sizeof(char) * 499);
    //printf("\n\n sizeof %lu \n\n", 100 - sizeof(t_block) - 5);
    //ft_debug();
    //free(t);
    //free(c);
    //ft_debug();
    if(pthread_create(&thread1, NULL, task1, test1) == -1) {
	    return 1;
    }
    if(pthread_create(&thread2, NULL, task2, test2) == -1) {
	    return 1;
    }
    if (pthread_join(thread1, NULL)) {
	    return 1;
    }
    if (pthread_join(thread2, NULL)) {
	    return 1;
    }
    show_alloc_mem();
    return (0);
}