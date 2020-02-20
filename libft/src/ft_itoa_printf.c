/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 16:27:19 by gmachena          #+#    #+#             */
/*   Updated: 2019/11/11 15:19:50 by acoudray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_itoa_base_printf(uintmax_t nbr, t_fid fid, int base)
{
	static char		res[21];
	int				i;
	uintmax_t		temp;
	char			alpha;

	ft_bzero(res, 21);
	if (fid.max_width == 0 && nbr == 0)
		res[0] = '\0';
	else
	{
		alpha = (ft_isupper(fid.f_id)) ? 'A' : 'a';
		i = 0;
		temp = nbr;
		i = i + 2;
		while (temp /= base)
			i++;
		res[--i] = '\0';
		(nbr == 0 ? res[--i] = '0' : 0);
		while (i-- && nbr != 0)
		{
			res[i] = nbr % base + ((nbr % base > 9) ? alpha - 10 : '0');
			nbr = nbr / base;
		}
	}
	return (res);
}

void	ty_norme(int *i, intmax_t *temp, intmax_t *nbr)
{
	*i = *i + 2;
	*temp = *nbr;
}

char	*ft_itoa_printf(intmax_t nbr, t_fid fid)
{
	static char		res[21];
	int				i;
	intmax_t		temp;

	i = 0;
	ft_bzero(res, 21);
	(nbr < 0) ? res[i++] = '-' : 0;
	(nbr >= 0 && fid.flags.plus == 1) ? res[i++] = '+' : 0;
	(fid.flags.blank == 1 && i == 0) ? res[i++] = ' ' : 0;
	if (fid.max_width == 0 && nbr == 0)
		return (res);
	if (nbr < -9223372036854775807)
		return ("-9223372036854775808");
	(nbr < 0) ? nbr = -nbr : 0;
	ty_norme(&i, &temp, &nbr);
	while (temp /= 10)
		i++;
	res[--i] = '\0';
	(nbr == 0) ? res[--i] = '0' : 0;
	while (i-- && nbr != 0)
	{
		res[i] = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	return (res);
}
