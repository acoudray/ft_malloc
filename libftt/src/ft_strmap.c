/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 02:28:44 by gmachena          #+#    #+#             */
/*   Updated: 2020/02/07 16:50:05 by acoudray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*str;

	i = -1;
	if (s == 0)
		return (0);
	if (!(str = (char*)ft_malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (0);
	while (s[++i])
		str[i] = f((char)s[i]);
	str[i] = '\0';
	return (str);
}
