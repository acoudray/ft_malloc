/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachena <gmachena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:00:05 by gmachena          #+#    #+#             */
/*   Updated: 2020/02/21 16:38:30 by gmachena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_dispatcher(t_fid fid, va_list va)
{
	int		x;

	x = 0;
	if (fid.f_id == 'c' || fid.f_id == '%' || fid.f_id == 's')
		x = ft_dispatchc(fid, va);
	else if (fid.f_id == 'd' || fid.f_id == 'i' || fid.f_id == 'o'
		|| fid.f_id == 'x' || fid.f_id == 'X' || fid.f_id == 'u'
		|| fid.f_id == 'p')
		x = ft_dispatchd(fid, va);
	else if (fid.f_id == 'f')
		x = ft_dispatchf(fid, va);
	return (x);
}
