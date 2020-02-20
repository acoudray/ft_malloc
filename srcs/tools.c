/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 16:13:31 by acoudray          #+#    #+#             */
/*   Updated: 2020/02/20 16:19:21 by acoudray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

void	*return_and_unlockmutex(void *ret)
{
	pthread_mutex_unlock(&g_mut);
	return (ret);
}