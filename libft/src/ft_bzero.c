/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachena <gmachena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 00:12:26 by gmachena          #+#    #+#             */
/*   Updated: 2019/10/14 17:28:56 by gmachena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_szero(char **s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		(*s)[i] = '0';
		i++;
	}
	(*s)[i] = '\0';
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*tab;

	tab = s;
	i = 0;
	while (i < n)
	{
		tab[i] = 0;
		i++;
	}
}
