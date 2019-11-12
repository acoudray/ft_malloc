/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcdel_left.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachena <gmachena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 11:30:29 by gmachena          #+#    #+#             */
/*   Updated: 2019/10/09 14:44:27 by gmachena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void       ft_strcdel_left(char **str, char c)
{
    int     i;
    char    *tmp;

    if ((!(*str) || !(str)) && ((*str)[0] != c))
        return ;
    i = 0;
    while ((*str)[i] == c)
        ++i;
    tmp = ((*str)[i] != '\0') ? ft_strdup((*str) + i) : ft_strnew(0);
    ft_strdel(str);
    *str = tmp;
}