/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcadd_right.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 11:31:13 by gmachena          #+#    #+#             */
/*   Updated: 2019/10/23 15:03:28 by acoudray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strcadd_r_t(char *str, char c, unsigned int x)
{
	unsigned int	i;
	unsigned int	len;
	char			*res;

	i = ft_strlen(str);
	if (!(str))
		return (0);
	len = i + x;
	if (!(res = ft_strnew(len)))
		return (0);
	ft_strlcpy(res, str, i + 1);
	while (i < len)
		res[i++] = c;
	return (res);
}

void	ft_strcadd_right(char **str, char c, unsigned int len)
{
	char	*tmp;

	if (len == 0)
		return ;
	tmp = ft_strcadd_r_t(*str, c, len);
	ft_strdel(str);
	*str = tmp;
}
