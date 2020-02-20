/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_detector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 09:16:51 by gmachena          #+#    #+#             */
/*   Updated: 2019/11/11 17:11:38 by acoudray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_fill_type(char *format, t_fid *fid, int pos)
{
	char	c;

	c = format[pos + 1];
	if ((c == 'd') || (c == 'i') || (c == 'o') || (c == 'u') || (c == 'x') ||
		(c == 'X') || (c == 'f') || (c == 'c') || (c == 's') || (c == 'p') ||
		(c == '%'))
	{
		fid->len_fid++;
		fid->f_id = c;
		if (fid->f_id == 'f' && fid->max_width == -1)
			fid->max_width = 6;
		if ((fid->f_id != 's' && fid->f_id != 'c' && fid->f_id != 'p')
		&& fid->max_width == -1)
		{
			fid->max_width = 1;
		}
		else if (fid->f_id == 'p')
		{
			fid->flags.diese = 1;
			fid->size = L;
		}
		return (1);
	}
	else
		return (0);
}

int		is_type(char *str, int i)
{
	char	c;

	c = str[i];
	if ((c == 'd') || (c == 'i') || (c == 'o') || (c == 'u') || (c == 'x') ||
		(c == 'X') || (c == 'f') || (c == 'c') || (c == 's') || (c == 'p') ||
		(c == '%'))
		return (1);
	else
		exit_error("");
	return (0);
}
