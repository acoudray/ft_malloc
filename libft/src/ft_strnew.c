/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 06:21:42 by gmachena          #+#    #+#             */
/*   Updated: 2020/02/20 13:12:54 by acoudray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*tab;
	size_t	i;

	i = -1;
	if (!(tab = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (++i <= size)
		tab[i] = '\0';
	return (tab);
}
