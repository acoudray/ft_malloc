/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dispatchf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachena <gmachena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 11:12:27 by gmachena          #+#    #+#             */
/*   Updated: 2020/02/21 16:38:30 by gmachena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_round_decimal(char **str, int len, int preci)
{
	int		i;
	int		r;

	r = 0;
	i = (len + preci > (int)ft_strlen((*str))) ?
		ft_strlen((*str)) : len + preci;
	if ((*str)[i--] >= '5')
		r = 1;
	while (r == 1)
	{
		if (i >= 0 && ft_isdigit((*str)[i]))
		{
			(*str)[i]++;
			if ((*str)[i] > 57 && (r = 1))
				(*str)[i] -= 10;
			else
				r = 0;
		}
		else if (i < 0)
			ft_strcadd_left(str, '1', r--);
		i--;
	}
	return (r);
}

char	*ft_roundf(char **str, int preci, t_fid fid)
{
	int		len;
	int		r;
	int		i;

	r = 0;
	len = ft_strclen((*str), '.') + 1;
	i = (len + preci > (int)ft_strlen((*str))) ?
		ft_strlen((*str)) : len + preci;
	r = ft_round_decimal(&(*str), len, preci);
	(*str)[i] = '\0';
	if (preci != 0)
		ft_strcadd_right(str, '0', len + preci - ft_strlen((*str)));
	else if (fid.flags.diese != 1)
		ft_strcdel_right(str, '.');
	return (*str);
}

int		ft_dispatchf(t_fid fid, va_list va)
{
	int				x;
	char			*a;

	x = 0;
	if (fid.size == L)
	{
		if (!(a = ft_lftoa(va_arg(va, long double))))
			return (0);
	}
	else
		a = ft_ftoa(va_arg(va, double));
	if (!(ft_strcmp(a, "-inf")) || !(ft_strcmp(a, "inf")) ||
		!(ft_strcmp(a, "nan")) || !(ft_strcmp(a, "-nan")))
	{
		ft_putstr(a);
		return (ft_strlen(a));
	}
	if (!((ft_roundf(&a, fid.max_width, fid))))
		return (-1);
	x += ft_print_flags_f(fid, &a);
	return (x);
}
