/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcdel_right.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachena <gmachena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 11:29:54 by gmachena          #+#    #+#             */
/*   Updated: 2019/10/21 22:04:43 by gmachena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_strcdel_right(char **str, char c)
{
    int i;


    if (!(*str) || !(str))
        return ;
    i = ft_strlen(*str) - 1;
    while ((*str)[i] == c)
    {
        (*str)[i] = '\0';
        --i;
    }
}
