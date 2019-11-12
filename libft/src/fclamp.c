/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fclamp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachena <gmachena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 14:14:11 by gmachena          #+#    #+#             */
/*   Updated: 2018/04/26 14:27:50 by adhanot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	fclamp(double d, double min, double max)
{
	if (d > max)
		d = max;
	if (d < min)
		d = min;
	return (d);
}
