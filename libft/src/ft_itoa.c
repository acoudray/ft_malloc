/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachena <gmachena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:45:03 by phamelin          #+#    #+#             */
/*   Updated: 2020/02/21 16:38:30 by gmachena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(unsigned int n)
{
	int		temp;
	int		l;
	char	*res;

	temp = n;
	l = 2;
	while (temp /= 10)
		l++;
	if ((res = (char *)malloc(sizeof(char) * l)) == NULL)
		return (NULL);
	res[--l] = '\0';
	while (l--)
	{
		res[l] = n % 10 + '0';
		n = n / 10;
	}
	return (res);
}
