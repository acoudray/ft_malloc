/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachena <gmachena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 11:18:37 by gmachena          #+#    #+#             */
/*   Updated: 2019/11/13 11:37:08 by gmachena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <sys/time.h>
# include <sys/resource.h>
#include "../includes/ft_malloc.h"

void    free(void *ptr)
{
    //if (!(ft_get_block()))
    //	return;
	ft_malloc(1);
    //munmap(0, 0);
    (void)ptr;
}