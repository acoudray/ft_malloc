/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcadd_left.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 11:31:47 by gmachena          #+#    #+#             */
/*   Updated: 2019/10/23 15:02:41 by acoudray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_stradd_l_t(char *s, char c, unsigned int x)
{
	unsigned int	i;
	unsigned int	len;
	char			*res;

	i = 0;
	if (!(s))
		return (0);
	len = ft_strlen(s) + x;
	if (!(res = ft_strnew(len)))
		return (0);
	while (i < x)
		res[i++] = c;
	ft_strlcpy(res + i, s, ft_strlen(s) + 1);
	return (res);
}

void	ft_strcadd_left(char **res, char c, unsigned int len)
{
	char	*tmp;

	if (len == 0)
		return ;
	tmp = ft_stradd_l_t(*res, c, len);
	ft_strdel(res);
	*res = tmp;
}
