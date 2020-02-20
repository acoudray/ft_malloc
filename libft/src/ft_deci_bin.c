/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deci_bin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachena <gmachena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 17:22:48 by gmachena          #+#    #+#             */
/*   Updated: 2019/11/11 10:31:33 by gmachena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_add_deci_str(char **dest, char *add)
{
	int r;
	int res;
	int i;
	int j;

	j = 0;
	r = 0;
	i = 0;
	res = 0;
	while (add[i] != '\0' || r == 1)
	{
		if ((res = (*dest)[j] + ((add[i] == 0) ? 0 : add[i] - 48) + r) > 57)
		{
			(*dest)[j] = res - 10;
			r = 1;
		}
		else if ((r = 0) == 0)
			(*dest)[j] = res;
		i += (add[i] == '\0') ? 0 : 1;
		j++;
	}
}

char	*ft_deci_bin(char *bin)
{
	int		i;
	char	*deci;
	char	*pow_two;
	char	*tmp;

	i = 0;
	if (!(deci = ft_strnew(ft_strlen(bin))) ||
		!(pow_two = ft_strnew(ft_strlen(bin))))
		return (0);
	ft_szero(&deci, ft_strlen(bin));
	ft_szero(&pow_two, ft_strlen(bin));
	pow_two[0] = '1';
	tmp = ft_strrev(bin);
	while (tmp[i] != '\0')
	{
		(tmp[i] == '1') ? ft_add_deci_str(&deci, pow_two) : 0;
		ft_str_mul_two(&pow_two, 1 + i++);
	}
	ft_strdel(&tmp);
	tmp = ft_strrev(deci);
	ft_strcdel_left(&tmp, '0');
	(ft_strlen(tmp) == 0) ? ft_strcadd_left(&tmp, '0', 1) : 0;
	ft_strdel(&deci);
	ft_strdel(&pow_two);
	return (tmp);
}
