/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 11:48:25 by gmachena          #+#    #+#             */
/*   Updated: 2020/02/20 15:59:54 by acoudray         ###   ########.fr       */
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


void test1()
{
    ft_printf("test1\n");
    malloc(0);
}

void test2()
{
    ft_printf("test2\n");
    int* p = malloc(sizeof(int));
    *p = 5;
    ft_printf("address: %p, value: %d\n",p, *p);
    free(p);
}

void test3()
{
    ft_printf("test3\n");
    int i;
    for(i = 0; i < 5; i++){
        int* p = malloc(sizeof(int));
        *p = i;
        ft_printf("address: %p, value: %d\n",p, *p);
    }
}

void test4()
{
    ft_printf("test4\n");
    int i;
    int* p = malloc(5 * sizeof(int));
    for(i = 0; i < 5; i++){
        p[i] = i;
    }
    for(i = 0; i < 5; i++){
        ft_printf("address: %p, value: %d\n", p + i, p[i]);
     }
    free(p);
}

void test5()
{
    ft_printf("test5\n");
    free(NULL);
}

void test6()
{
    ft_printf("test6\n");
    int x;
    free(&x);
}

void test7()
{
    ft_printf("test7\n");
    void* p = malloc(1);
    free(p);
    ft_printf("p has been freed\n");
    free(p + 1);
}

void test8()
{
    ft_printf("test8\n");
    void* p = malloc(2);
    free(p);
    ft_printf("p has been freed\n");
    free(p + 1);
}

void test9()
{
    ft_printf("test9\n");
    void* p = malloc(1);
    free(p);
    free(p);
}

void test10()
{
    ft_printf("test10\n");
    void* p = malloc(sizeof(int));
    *((int*)p) = 5;
    ft_printf("integer: address: %p, value: %d\n", p, *((int*)p));
    free(p);
    char* c = "Hello World"; 
    p = malloc(sizeof(char) * (strlen(c) + 1));
    memcpy(p, c, strlen(c));
    ft_printf("String: address: %p, value: %s\n", p, (char*)p);
    free(p);
    p = malloc(sizeof(float));
    *((float*)p) = 1.2345;
    ft_printf("float: address: %p, value: %f\n", p, *((float*)p));
    free(p);
}

void test11()
{
    ft_printf("test11\n");
    void* p;
    int i;
    for(i = 1; (p = malloc(i)) != NULL; i++){
        ft_printf("%d bytes allocated\n", i);
        free(p);
    }
}

void test12()
{
    ft_printf("test12\n");
    void* p;
    int i;
    for(i = 1; (p = malloc(i)) != NULL; i++){
        ft_printf("%d bytes allocated\n", i);
    }
}

void test13()
{
    ft_printf("test13\n");
    void* p;
    int i;
    for(i = 1; (p = malloc(i % 2 == 0 ? 1 : 30)) != NULL; i++){
        ft_printf("%d items allocated\n", i);
    }
}

void test14()
{
    ft_printf("test14\n");
    void* p;
    int i;
    for(i = 1; (p = malloc(1)) != NULL; i++){
        ft_printf("%d items allocated\n", i);
    }
}

int main(void)
{
    // char *t;
    // char *c;
    // char *i;
    // char *test1 = 0;
    // char *test2 = 0;
    // pthread_t thread1;
    // pthread_t thread2;

    // t = (char*)malloc(sizeof(char) * 1073741824);
    // t = (char*)realloc(t, sizeof(char) * 1073741825);
    // free(t);
    // c = (char*)malloc(sizeof(char) * 5);
    // free(c);
    // i = (char*)malloc(sizeof(char) * 499);
    // free(i);
    // if(pthread_create(&thread1, NULL, task1, test1) == -1) {
	//     return 1;
    // }
    // if(pthread_create(&thread2, NULL, task2, test2) == -1) {
	//     return 1;
    // }
    // if (pthread_join(thread1, NULL)) {
	//     return 1;
    // }
    // if (pthread_join(thread2, NULL)) {
	//     return 1;
    // }
    show_alloc_mem();
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    test10();
    test11();
    test12();
    test13();
    test14();
    return (0);
}