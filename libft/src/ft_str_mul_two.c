/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_mul_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachena <gmachena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 10:52:33 by gmachena          #+#    #+#             */
/*   Updated: 2020/02/21 16:38:30 by gmachena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_str_mul_two(char **str, unsigned int n)
{
	char			*ptr;
	unsigned int	i;
	int				mod;
	int				res;

	i = 0;
	mod = 0;
	res = 0;
	ptr = *str;
	while (i < n || mod == 1)
	{
		res = ((ptr[i] - '0') * 2 + (1 * mod)) + '0';
		if (res > 57)
		{
			ptr[i] = res - 10;
			mod = 1;
		}
		else
		{
			ptr[i] = res;
			mod = 0;
		}
		i++;
	}
}
