/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lftoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 12:14:36 by gmachena          #+#    #+#             */
/*   Updated: 2020/02/19 11:15:44 by acoudray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void		ft_nb(unsigned char tab, int len, unsigned char **res, int k)
{
	char	c;
	int		j;
	int		b;

	j = 0;
	b = (k + 1) * 8;
	while (j < len)
	{
		c = '0' + (tab % 2);
		(*res)[--b] = c;
		tab /= 2;
		j++;
	}
}

static void		print(unsigned char tab[], unsigned char **res)
{
	int		k;
	int		i;

	i = 0;
	k = 10;
	while (--k >= 0)
	{
		ft_nb(tab[k], 8, &(*res), i++);
	}
}

int				ft_get_iee(unsigned char **res, long double nbr)
{
	char				**split;
	int					exp_2;
	char				*exp;
	unsigned char		*tmp2;

	tmp2 = *res;
	tmp2 += 1;
	if (!(exp = ft_strnew(15)))
		return (0);
	exp = ft_strncpy(exp, (const char *)tmp2, 15);
	if ((exp_2 = (int)ft_atoui_base(exp, "01") - 16383) == 16384)
	{
		ft_strdel(&exp);
		return (-1);
	}
	if (exp_2 == -16382)
		exp_2 = (nbr == 0.) ? 0 : exp_2 + 1;
	ft_bin_str(exp_2, ft_atoui_base((const char *)(tmp2 + 15), "01"),
		&split, 64);
	ft_free((*res));
	*res = (unsigned char *)ft_get_flstring(&split);
	ft_strdel(&exp);
	return (1);
}

char			*ft_lftoa(long double nbr)
{
	unsigned char	*longdb_tab;
	unsigned char	*res;
	int				neg;

	if (nbr != nbr)
		return ((nbr < 0) ? ("-nan") : ("nan"));
	if (!(longdb_tab = (UC *)ft_malloc(sizeof(UC)* sizeof(LD) + 1)))
		return (0);
	if (!(res = (unsigned char *)ft_malloc(sizeof(unsigned char) * 128 + 1)))
		return (0);
	ft_memset(longdb_tab, '\0', sizeof(long double) + 1);
	ft_memset(res, '\0', sizeof(unsigned char) * 128 + 1);
	ft_memcpy(longdb_tab, &nbr, sizeof(long double));
	print(longdb_tab, &res);
	neg = (res[0] == '1') ? 1 : 0;
	if (ft_get_iee(&res, nbr) == -1)
	{
		ft_free(longdb_tab);
		ft_free(res);
		return ((neg == 1) ? ("-inf") : ("inf"));
	}
	if (neg == 1)
		ft_strcadd_left((char **)&res, '-', 1);
	ft_free(longdb_tab);
	return ((char*)res);
}
