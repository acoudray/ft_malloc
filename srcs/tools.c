/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachena <gmachena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 16:13:31 by acoudray          #+#    #+#             */
/*   Updated: 2020/02/20 17:29:34 by gmachena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

void    ft_debug(void)
{
    t_block *tmp;
    int i;

    i = 1;
    tmp = g_glob;
    while (tmp)
    {
        ft_printf("-------- BLOC N°%d --------\n\n", i);
        ft_printf(" -TYPE = %c\n -TAILLE = %d\n -LIBRE = %d\n\n\n", tmp->a,
		 (int)tmp->size, tmp->free);
        i++;
        tmp = tmp->next;
    }
}

void	*return_and_unlockmutex(void *ret)
{
	pthread_mutex_unlock(&g_mut);
	return (ret);
}