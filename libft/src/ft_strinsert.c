/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:18:47 by gmachena          #+#    #+#             */
/*   Updated: 2019/10/23 14:59:07 by acoudray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strinsert(char **dest, char *src, unsigned int i)
{
	char	*tmp;

	tmp = ft_strsub(*dest, 0, i);
	ft_strappend(&tmp, src);
	ft_strappend(&tmp, (*dest) + i);
	ft_strdel(dest);
	*dest = tmp;
	return (*dest);
}
