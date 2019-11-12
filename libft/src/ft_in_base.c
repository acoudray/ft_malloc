/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_in_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachena <gmachena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 10:42:16 by gmachena          #+#    #+#             */
/*   Updated: 2019/10/14 10:42:53 by gmachena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_in_base(char c, const char *base)
{
	int i;
	int index;

	index = -1;
	if (!base)
		return (index);
	i = -1;
	while (base[++i])
		if (base[i] == c)
			index = i;
	if (c == '\0')
		return (i);
	else
		return (index);
}