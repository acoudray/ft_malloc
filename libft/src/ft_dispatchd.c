/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dispatchd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 11:42:39 by gmachena          #+#    #+#             */
/*   Updated: 2019/11/11 15:48:13 by acoudray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_get_base(t_fid fid)
{
	int base;

	base = 0;
	if (fid.f_id == 'o')
		base = 8;
	if (fid.f_id == 'u')
		base = 10;
	if (fid.f_id == 'x' || fid.f_id == 'X' || fid.f_id == 'p')
		base = 16;
	return (base);
}

int		ft_optionbase(t_fid fid, va_list va)
{
	char	*i;
	int		x;
	int		base;

	i = 0;
	x = 0;
	base = ft_get_base(fid);
	if (fid.size == 0)
		i = ft_itoa_base_printf((uintmax_t)va_arg(va, unsigned int), fid, base);
	else if (fid.size == H)
		i = ft_itoa_base_printf((uintmax_t)(USHORT)va_arg(va, unsigned int),
			fid, base);
	else if (fid.size == HH)
		i = ft_itoa_base_printf((uintmax_t)(UCHAR)va_arg(va, unsigned int),
			fid, base);
	else if (fid.size == L)
		i = ft_itoa_base_printf((uintmax_t)(ULONG)va_arg(va, unsigned long int),
			fid, base);
	else if (fid.size == LL)
		i = ft_itoa_base_printf((uintmax_t)(LLONG)va_arg(va, ULL), fid, base);
	else if (fid.size == J)
		i = ft_itoa_base_printf((uintmax_t)va_arg(va, uintmax_t), fid, base);
	x = ft_fill_arg_d(i, ft_strlen(i), ft_get_d_size(i, fid, ft_strlen(i)),
		fid);
	return (x);
}

int		ft_optiondi(t_fid fid, va_list va)
{
	char		*i;
	int			x;

	x = 0;
	i = 0;
	if (fid.size == 0)
		i = ft_itoa_printf((intmax_t)va_arg(va, int), fid);
	else if (fid.size == H)
		i = ft_itoa_printf((intmax_t)(short)va_arg(va, int), fid);
	else if (fid.size == HH)
		i = ft_itoa_printf((intmax_t)(char)va_arg(va, int), fid);
	else if (fid.size == L)
		i = ft_itoa_printf((intmax_t)(long)va_arg(va, long int), fid);
	else if (fid.size == LL)
		i = ft_itoa_printf((intmax_t)(long long)va_arg(va, long long int), fid);
	else if (fid.size == J)
		i = ft_itoa_printf((intmax_t)va_arg(va, intmax_t), fid);
	x = ft_fill_arg_d(i, ft_strlen(i), ft_get_d_size(i, fid, ft_strlen(i)),
		fid);
	return (x);
}

int		ft_dispatchd(t_fid fid, va_list va)
{
	int x;

	x = 0;
	if (fid.f_id == 'd' || fid.f_id == 'i')
		x = ft_optiondi(fid, va);
	else if (fid.f_id == 'o' || fid.f_id == 'u' ||
		fid.f_id == 'x' || fid.f_id == 'X' || fid.f_id == 'p')
		x = ft_optionbase(fid, va);
	return (x);
}
