/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_div_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 20:24:30 by gmachena          #+#    #+#             */
/*   Updated: 2019/11/01 15:58:33 by acoudray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_str_div_two(char **str, unsigned int n)
{
	char			*ptr;
	unsigned int	i;
	int				mod;
	int				res;
	unsigned int	j;

	i = 0;
	mod = 0;
	res = 0;
	ptr = *str;
	j = ft_strlen((*str));
	while (i < n || mod == 1)
	{
		res = ((ptr[i] - '0') / 2 + (5 * mod)) + '0';
		if (((ptr[i] - '0') % 2) && i < j)
			mod = 1;
		else
			mod = 0;
		ptr[i] = res;
		i++;
	}
}
