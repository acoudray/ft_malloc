/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachena <gmachena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 15:26:33 by gmachena          #+#    #+#             */
/*   Updated: 2019/11/11 10:12:28 by gmachena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_fid	ft_init_fid(void)
{
	t_fid fid;

	fid.arg_count = 0;
	fid.f_id = 0;
	fid.len_fid = 1;
	fid.max_width = -1;
	fid.min_width = 0;
	fid.pos_fid = 0;
	fid.size = 0;
	fid.flags.blank = 0;
	fid.flags.diese = 0;
	fid.flags.minus = 0;
	fid.flags.plus = 0;
	fid.flags.zero = 0;
	fid.is_prec = 0;
	return (fid);
}

int		ft_count_format(char *format)
{
	int count;

	count = ft_count_fid(format);
	return (count);
}

int		ft_fill(t_fid *fid, char *format, int pos)
{
	int count;

	count = 0;
	fid->pos_fid = pos;
	count += ft_fill_flags(format, fid, pos + 1);
	count += ft_fill_width(format, fid, pos + count);
	count += ft_fill_precision(format, fid, pos + count);
	count += ft_fill_length(format, fid, pos + count);
	count += ft_fill_type(format, fid, pos + count);
	return (count);
}

int		ft_parse_format(char *format, int arg_count, va_list va)
{
	t_fid	fid[arg_count];
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (format[++i])
	{
		if (format[i] == '%')
		{
			fid[j] = ft_init_fid();
			i += ft_fill(&fid[j], format, i);
			j++;
		}
	}
	return (ft_print(fid, va, format, arg_count));
}

int		ft_printf(const char *format, ...)
{
	va_list		va;
	int			arg_count;
	int			ret;

	ret = 0;
	va_start(va, format);
	arg_count = ft_count_format((char *)format);
	ret = ft_parse_format((char *)format, arg_count, va);
	va_end(va);
	return (ret);
}
