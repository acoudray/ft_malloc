/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcdel_left.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachena <gmachena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 11:30:29 by gmachena          #+#    #+#             */
/*   Updated: 2020/02/21 16:38:30 by gmachena         ###   ########.fr       */
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
