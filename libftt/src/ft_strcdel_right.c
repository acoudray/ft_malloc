/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcdel_right.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachena <gmachena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 11:29:54 by gmachena          #+#    #+#             */
/*   Updated: 2019/11/01 13:43:26 by gmachena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strcdel_right(char **str, char c)
{
	int		i;

	if (!(*str) || !str)
		return ;
	i = ft_strlen(*str) - 1;
	while (i >= 0 && (*str)[i] == c)
	{
		(*str)[i] = '\0';
		--i;
	}
}
