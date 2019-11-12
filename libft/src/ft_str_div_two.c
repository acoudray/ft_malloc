/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_div_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachena <gmachena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 20:24:30 by gmachena          #+#    #+#             */
/*   Updated: 2019/10/21 21:32:18 by gmachena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void ft_str_div_two(char **str, unsigned int n)
{
    char            *ptr;
    unsigned int     i;
    int             mod;
    int             res;

    i = 0;
    mod = 0;
    res = 0;
    ptr = *str;
    while (i < n || mod == 1)
    {
            res = ((ptr[i] - '0') / 2 + (5 * mod)) + '0';
            if (((ptr[i] - '0') % 2) && i < ft_strlen(ptr))
                mod = 1;
            else
                mod = 0;
            ptr[i] = res;
        i++;
    }
}