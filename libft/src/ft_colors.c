/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachena <gmachena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 12:40:10 by gmachena          #+#    #+#             */
/*   Updated: 2020/02/21 16:38:30 by gmachena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_colors_1(char *format)
{
	if (ft_strnstr(format, "{red}", 5))
	{
		ft_putstr("\033[0;31m");
		return (5);
	}
	else if (ft_strnstr(format, "{green}", 7))
	{
		ft_putstr("\033[0;32m");
		return (7);
	}
	else if (ft_strnstr(format, "{yellow}", 8))
	{
		ft_putstr("\033[0;33m");
		return (8);
	}
	else if (ft_strnstr(format, "{blue}", 6))
	{
		ft_putstr("\033[0;34m");
		return (6);
	}
	return (0);
}

int		ft_colors_2(char *format)
{
	if (ft_strnstr(format, "{magenta}", 9))
	{
		ft_putstr("\033[0;35m");
		return (9);
	}
	else if (ft_strnstr(format, "{cyan}", 6))
	{
		ft_putstr("\033[0;36m");
		return (6);
	}
	else if (ft_strnstr(format, "{res}", 5))
	{
		ft_putstr("\033[0m");
		return (5);
	}
	return (0);
}
