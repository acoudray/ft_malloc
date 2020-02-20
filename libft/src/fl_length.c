/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_length.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachena <gmachena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 18:19:14 by gmachena          #+#    #+#             */
/*   Updated: 2019/11/11 10:11:28 by gmachena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_fill_length_2(char *format, t_fid *fid, int pos)
{
	if (format[pos] == 'h')
	{
		if (format[pos + 1] == 'h')
		{
			fid->size = HH;
			fid->len_fid += 2;
			return (2);
		}
		fid->size = H;
		fid->len_fid += 1;
		return (1);
	}
	if (format[pos] == 'j')
	{
		fid->size = J;
		fid->len_fid += 1;
		return (1);
	}
	return (0);
}

int		ft_fill_length(char *format, t_fid *fid, int pos)
{
	int ret;

	ret = 0;
	pos++;
	if (format[pos] == 'l' || format[pos] == 'L')
	{
		if (format[pos + 1] == 'l' || format[pos + 1] == 'L')
		{
			fid->size = LL;
			fid->len_fid += 2;
			return (2);
		}
		fid->size = L;
		fid->len_fid += 1;
		return (1);
	}
	ret = ft_fill_length_2(format, fid, pos);
	return (ret);
}

char	*ft_size(char *str, int i)
{
	if (str[i] == 'h')
	{
		if (str[i + 1] == 'h')
			return ("hh");
		else
			return ("h");
	}
	if (str[i] == 'l')
	{
		if (str[i + 1] == 'l')
			return ("ll");
		else
			return ("l");
	}
	return (NULL);
}

int		sz_length(char *str, int i)
{
	if (str[i] == 'l' || str[i] == 'L')
	{
		if (str[i + 1] == 'l' || str[i + 1] == 'L')
			return (2);
		return (1);
	}
	if (str[i] == 'h')
	{
		if (str[i + 1] == 'h')
			return (2);
		return (1);
	}
	if (str[i] == 'j')
		return (1);
	return (0);
}
