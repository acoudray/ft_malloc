/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getpow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 15:09:40 by gmachena          #+#    #+#             */
/*   Updated: 2019/10/23 15:06:09 by acoudray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

uintmax_t	ft_getpow(int x, int pow)
{
	uintmax_t	res;

	res = 1;
	while (pow--)
	{
		res *= x;
	}
	return (res);
}
