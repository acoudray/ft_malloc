/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachena <gmachena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:25:59 by gmachena          #+#    #+#             */
/*   Updated: 2020/02/21 16:38:30 by gmachena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_isn_zero_printf(char *i, int size)
{
	if (size == 0)
		return (0);
	if (size == 1 && i[0] == '0')
		return (0);
	return (1);
}

int		ft_fill_arg_d(char *i, int size, int max, t_fid fid)
{
	char	buff[max + size + 2];
	int		x;
	int		j;

	x = 0;
	j = -1;
	if (fid.flags.diese == 1 &&
		(ft_isn_zero_printf(i, size) || fid.f_id == 'p' ||
		(fid.f_id == 'o' && fid.max_width == 0)))
	{
		buff[x++] = '0';
		if (fid.f_id == 'x' || fid.f_id == 'X' || fid.f_id == 'p')
			buff[x++] = (fid.f_id == 'p') ? 'x' : fid.f_id;
		max -= x;
	}
	if (i[0] == ' ' || i[0] == '-' || i[0] == '+')
		buff[x++] = i[++j];
	while (max-- > 0)
		buff[x++] = '0';
	while (i[++j] != '\0')
		buff[x++] = i[j];
	buff[x] = '\0';
	x = ft_printd(buff, fid);
	return (x);
}

int		ft_printd(char *buff, t_fid fid)
{
	int		min;
	int		size;
	int		x;

	x = 0;
	size = ft_strlen(buff);
	min = fid.min_width - size;
	if (fid.flags.minus == 1)
	{
		x += ft_putnstr(buff, size, 0);
		x += ft_print_space(min);
	}
	else
	{
		x += (fid.flags.zero == 1 && fid.is_prec == 0) ? 0 :
			ft_print_space(min);
		x += ft_putnstr(buff, size, 0);
	}
	return (x);
}

int		ft_apply_color(char *format)
{
	int		ret;

	ret = 0;
	if ((ret = ft_colors_1(format)) != 0)
		return (ret);
	else if ((ret = ft_colors_2(format)) != 0)
		return (ret);
	return (0);
}

int		ft_print(t_fid *fid, va_list va, char *format, int n)
{
	int		i;
	int		j;
	int		k;
	int		l;
	char	buff[ft_strlen(format) + 1];

	i = 0;
	j = 0;
	l = 0;
	while (format[i])
	{
		k = 0;
		while (format[i] && format[i] != '%' && format[i] != '{')
			buff[k++] = format[i++];
		if (k > 0)
			write(1, buff, k);
		if (j < n && format[i] != '{')
		{
			l += ft_dispatcher(fid[j], va);
			i += fid[j++].len_fid;
		}
		(format[i] == '{' ? i += ft_apply_color(format + i) : 0);
		l += k;
	}
	return (l);
}
