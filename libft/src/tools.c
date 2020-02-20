/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachena <gmachena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 13:36:11 by gmachena          #+#    #+#             */
/*   Updated: 2019/11/11 10:12:33 by gmachena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		exit_error(char *str)
{
	ft_putstr(str);
	exit(EXIT_FAILURE);
}

int		ft_get_d_size(char *i, t_fid fid, int size)
{
	int incre;
	int zero;

	zero = 0;
	incre = 0;
	if (i[0] == ' ' || i[0] == '+' || i[0] == '-')
		incre++;
	zero = (fid.flags.zero == 1 && fid.flags.minus == 0 && fid.is_prec != 1)
		? fid.min_width - size : fid.max_width - size + incre;
	if (zero < 0)
		zero = 0;
	return (zero);
}

int		ft_putnstr(const char *str, int n, int start)
{
	int		i;
	char	buff[n - start + 1];

	i = -1;
	while (++i < (n - start))
		buff[i] = str[i + start];
	if (n > 0)
		write(1, buff, i);
	return (i);
}

int		ft_print_zero(int n)
{
	int		i;
	char	buff[n + 1];

	i = -1;
	while (++i < n)
		buff[i] = '0';
	if (n > 0)
		write(1, buff, i);
	return (i);
}

int		ft_print_space(int n)
{
	int		i;
	char	buff[n + 1];

	i = -1;
	while (++i < n)
		buff[i] = ' ';
	if (n > 0)
		write(1, buff, i);
	return (i);
}
