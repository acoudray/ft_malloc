/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strprepend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:32:44 by gmachena          #+#    #+#             */
/*   Updated: 2019/10/23 14:58:09 by acoudray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strprepend(char const *src, char **dest)
{
	char	*tmp;

	tmp = ft_strjoin(src, *dest);
	ft_strdel(dest);
	*dest = tmp;
	return (*dest);
}
