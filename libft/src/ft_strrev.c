/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 00:13:05 by acoudray          #+#    #+#             */
/*   Updated: 2020/02/20 13:23:12 by acoudray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>

char	*ft_strrev(char *str)
{
	char	*rev;
	int		length;
	int		i;

	length = ft_strlen(str);
	if (!(rev = (char *)malloc(sizeof(char) * (length) + 1)))
		return (0);
	i = 0;
	while (length > 0)
	{
		rev[i] = str[length - 1];
		i++;
		length--;
	}
	rev[i] = '\0';
	return (rev);
}
