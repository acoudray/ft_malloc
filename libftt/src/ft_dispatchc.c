/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dispatchc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 10:19:35 by gmachena          #+#    #+#             */
/*   Updated: 2019/11/11 14:35:36 by acoudray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_option_s(t_fid fid, va_list va)
{
	const char	*s;
	static char	tmp[7] = "(null)";
	int			size;
	int			x;

	x = 0;
	s = (const char *)va_arg(va, const char *);
	if (s == NULL)
		s = tmp;
	size = ft_strlen(s);
	if (fid.max_width != -1)
		(fid.max_width > size) ? 0 : (size = fid.max_width);
	if (fid.flags.minus == 1)
	{
		x += ft_putnstr(s, size, 0);
		x += ft_print_space(fid.min_width - size);
	}
	else
	{
		x += ft_print_space(fid.min_width - size);
		x += ft_putnstr(s, size, 0);
	}
	return (x);
}

int		ft_option_c(t_fid fid, va_list va)
{
	unsigned char	c;
	int				x;

	x = 0;
	c = (unsigned char)va_arg(va, int);
	if (fid.flags.minus == 1)
	{
		x++;
		ft_putchar(c);
		x += ft_print_space(fid.min_width - 1);
	}
	else
	{
		x++;
		x += ft_print_space(fid.min_width - 1);
		ft_putchar(c);
	}
	return (x);
}

int		ft_option_percent(t_fid fid)
{
	int x;

	x = 0;
	if (fid.flags.minus == 1)
	{
		ft_putchar('%');
		x++;
		x += ft_print_space(fid.min_width - 1);
	}
	else
	{
		x++;
		x += ft_print_space(fid.min_width - 1);
		ft_putchar('%');
	}
	return (x);
}

int		ft_dispatchc(t_fid fid, va_list va)
{
	int		x;

	x = 0;
	if (fid.f_id == 'c')
		x = ft_option_c(fid, va);
	else if (fid.f_id == 's')
	{
		if ((x = ft_option_s(fid, va)) == -1)
			x = ft_putnstr("(null)", 6, 0);
	}
	else if (fid.f_id == '%')
		x = ft_option_percent(fid);
	return (x);
}
