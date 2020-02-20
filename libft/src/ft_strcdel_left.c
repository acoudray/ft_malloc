/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcdel_left.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 11:30:29 by gmachena          #+#    #+#             */
/*   Updated: 2019/10/23 15:00:33 by acoudray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strcdel_left(char **str, char c)
{
	int		i;
	char	*tmp;

	if ((!(*str) || !(str)) && ((*str)[0] != c))
		return ;
	i = 0;
	while ((*str)[i] == c)
		++i;
	tmp = ((*str)[i] != '\0') ? ft_strdup((*str) + i) : ft_strnew(0);
	ft_strdel(str);
	*str = tmp;
}
