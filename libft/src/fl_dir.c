/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_dir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachena <gmachena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 14:49:06 by gmachena          #+#    #+#             */
/*   Updated: 2020/02/21 16:38:30 by gmachena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_flags(int *flags)
{
	flags[0] = 0;
	flags[1] = 0;
	flags[2] = 0;
	flags[3] = 0;
	flags[4] = 0;
}

int		ft_fill_flags(char *format, t_fid *fid, int pos)
{
	int	count;

	count = 0;
	while ((format[pos] == '#') || (format[pos] == '0') ||
		(format[pos] == '-') || (format[pos] == '+') || (format[pos] == ' '))
	{
		if (format[pos] == '#')
			fid->flags.diese = 1;
		else if (format[pos] == '0')
			fid->flags.zero = 1;
		else if (format[pos] == '-')
			fid->flags.minus = 1;
		else if (format[pos] == '+')
			fid->flags.plus = 1;
		else if (format[pos] == ' ')
			fid->flags.blank = 1;
		count++;
		fid->len_fid++;
		pos++;
	}
	return (count);
}

int		is_flag(char *str, int i)
{
	int		flags[5];
	int		count;

	count = 0;
	ft_init_flags(flags);
	while ((str[i] == '#') || (str[i] == '0') || (str[i] == '-') ||
		(str[i] == '+') || (str[i] == ' '))
	{
		if (str[i] == '#')
			flags[0] = 1;
		else if (str[i] == '0')
			flags[1] = 1;
		else if (str[i] == '-')
			flags[2] = 1;
		else if (str[i] == '+')
			flags[3] = 1;
		else if (str[i] == ' ')
			flags[4] = 1;
		i++;
		count++;
	}
	return (count);
}

int		is_width(char *str, int i)
{
	int		count;

	count = 0;
	while (ft_isdigit(str[i++]))
		count++;
	return (count);
}

int		ft_fill_width(char *format, t_fid *fid, int pos)
{
	int		count;

	count = 0;
	while (ft_isdigit(format[++pos]))
	{
		fid->min_width *= 10;
		fid->min_width += format[pos] - 48;
		fid->len_fid++;
		count++;
	}
	return (count);
}
