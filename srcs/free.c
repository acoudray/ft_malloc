/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachena <gmachena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 11:18:37 by gmachena          #+#    #+#             */
/*   Updated: 2019/11/13 16:42:09 by gmachena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void    ft_free(void *ptr)
{
    printf("bonjour\n");
    if (!(glob_m))
    	printf("bonjour\n");
	ft_malloc(1);
    //munmap(0, 0);
    (void)ptr;
}