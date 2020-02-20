/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 11:01:23 by gmachena          #+#    #+#             */
/*   Updated: 2019/10/23 14:57:48 by acoudray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <inttypes.h>

char	*ft_uitoa_base(uintmax_t nbr, int base)
{
	char			*res;
	int				i;
	uintmax_t		temp;

	i = 2;
	temp = nbr;
	while (temp /= base)
		i++;
	if (!(res = ft_strnew(i)))
		return (NULL);
	res[--i] = '\0';
	if (nbr == 0)
		res[--i] = '0';
	while (i-- && nbr != 0)
	{
		res[i] = nbr % base + ((nbr % base > 9) ? 'a' - 10 : '0');
		nbr = nbr / base;
	}
	return (res);
}
