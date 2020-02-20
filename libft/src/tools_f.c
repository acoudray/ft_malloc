/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 10:17:45 by gmachena          #+#    #+#             */
/*   Updated: 2020/02/11 12:02:08 by acoudray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_flagsf_after(t_fid fid, char *str)
{
	int		i;
	int		len;

	i = 0;
	if (fid.min_width < fid.max_width)
		return (0);
	len = ft_strlen(str);
	if ((fid.flags.plus == 1 || fid.flags.blank == 1) && str[0] != '-')
		len++;
	while (i < fid.min_width - len)
	{
		if (fid.flags.minus)
		{
			write(1, " ", 1);
			i++;
		}
		else
			break ;
	}
	return (i);
}

int		ft_flagsf_before(t_fid fid, char *str)
{
	int		i;
	int		len;

	i = -1;
	if (fid.min_width < fid.max_width)
		i = -1;
	len = ft_strlen(str);
	if ((fid.flags.plus == 1 || fid.flags.blank == 1) && str[0] != '-')
		len++;
	while (++i <= fid.min_width - len - 1)
	{
		if (!fid.flags.zero && !fid.flags.minus)
			write(1, " ", 1);
		else if (fid.flags.zero)
			write(1, "0", 1);
	}
	if (fid.flags.plus == 1 && str[0] != '-' && i++)
		write(1, "+", 1);
	else if (fid.flags.blank == 1 && str[0] != '-')
	{
		write(1, " ", 1);
		i++;
	}
	return (i < 0 ? 0 : i);
}

int		ft_print_flags_f(t_fid fid, char **str)
{
	int	x;

	x = 0;
	x += ft_flagsf_before(fid, (*str));
	ft_putstr((*str));
	x += ft_strlen((*str));
	x += ft_flagsf_after(fid, (*str));
	ft_free((*str));
	return (x);
}
