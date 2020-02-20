/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachena <gmachena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 16:12:10 by gmachena          #+#    #+#             */
/*   Updated: 2019/11/11 10:10:21 by gmachena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_check_fid(char *str, int i)
{
	i++;
	return (str);
}

int		ft_size_fid(char *str, int i)
{
	int j;

	j = 1;
	j += is_flag(str, i + j);
	j += is_width(str, i + j);
	j += sz_preci(str, i + j);
	j += sz_length(str, i + j);
	if (is_type(str, i + j) == 0)
		return (0);
	return (j);
}

int		ft_count_fid(char *str)
{
	int x;
	int count;

	x = 0;
	count = 0;
	if (str == 0)
		return (-1);
	while (str[x])
	{
		if (str[x] == '%')
		{
			if ((x += ft_size_fid(str, x)) != 0)
				count++;
		}
		x++;
	}
	return (count);
}
