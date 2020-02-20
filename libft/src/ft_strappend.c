/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:23:28 by gmachena          #+#    #+#             */
/*   Updated: 2019/10/23 15:05:36 by acoudray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strappend(char **dest, char const *src)
{
	char	*tmp;

	tmp = ft_strjoin(*dest, src);
	ft_strdel(dest);
	*dest = tmp;
	return (*dest);
}
