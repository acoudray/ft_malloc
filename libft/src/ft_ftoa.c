/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachena <gmachena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 10:51:02 by gmachena          #+#    #+#             */
/*   Updated: 2019/10/28 17:10:59 by gmachena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void    ft_bin_str(int exp_2, unsigned long mantisse, char ***res, int size)
{
    char *str;

    str = ft_uitoa_base(mantisse, 2);
    ft_strcadd_left(&str, '0', size -ft_strlen(str));
    (size == 64) ? 0 : size--;
    if (exp_2 >= 0 && exp_2 < (size))
    {
        ft_strinsert(&str, ".", exp_2 + 1);
        ft_strcdel_right(&str, '0');
        if (str[ft_strlen(str) - 1] == '.')
            ft_strappend(&str, "0");
    }
    else if (exp_2 < 0)
    {
        ft_strcadd_left(&str, '0', -exp_2 - 1);
        ft_strcdel_right(&str, '0');
        ft_strprepend((ft_strequ(str, "")) ? "0.0" : "0.", &str);
    }
    else
    {
        ft_strcadd_right(&str, '0', exp_2 - (size));
        ft_strappend(&str, ".0");
    }
    *res = ft_strsplit(str, '.');
	ft_strdel(&str);
}


void    ft_add_num_str(char **dest, char *add, int i)
{
    int r;
    int res;

    r = 0;
    res = 0;
    while (i >= 0)
    {
        if ((res = (*dest)[i] + add[i] + r - 48) > 57)
        {
            (*dest)[i] = res - 10;
            r = 1;
        }
        else if ((r = 0) == 0)
            (*dest)[i] = res;
        i--;
    }
}

char   *ft_fract_bin(char *bin)
{
    int         i;
    char        *deci;
    char        *pow_two;

    i = 0;
    if (!(deci = ft_strnew(ft_strlen(bin))) ||
     !(pow_two = ft_strnew(ft_strlen(bin))))
        return (0);
    ft_szero(&deci, ft_strlen(bin));
    ft_szero(&pow_two, ft_strlen(bin));
    pow_two[0] = '5';
    while (bin[i] != '\0')
    {
        if (bin[i] == '1')
            ft_add_num_str(&deci, pow_two, i);
        ft_str_div_two(&pow_two, i+1);        
        i++;
    }
    deci[i] = '\0';
    ft_strdel(&pow_two);
    return (deci);
}

char    *ft_get_flstring(char **res)
{
    unsigned long   tmp;
    char            *str;
    char            *ret;
    char            *merged;

    tmp = ft_atoui_base(res[0], "01");
    str = ft_uitoa_base(tmp, 10);
    ft_strcadd_right(&str, '.', 1);
    merged = ft_fract_bin(res[1]);
    ret = ft_strjoin(str, merged);
    ft_strdel(&str);
    ft_strdel(&merged);
    return (ret);
}

char    *ft_ftoa(double nbr)
{
    char            **split;
    unsigned long   tmp;
    unsigned long   mantisse;
    char            *res;
    int             exp_2;

    res = 0;
    split = 0;
    tmp = *(unsigned long *)(&nbr);
    if (nbr != nbr)
        return ((tmp >> 63) ? ("-nan") : ("nan"));
    mantisse = ((tmp << 12) >> 12);
    if ((exp_2 = (((tmp << 1) >> 53) - 1023)) == 1024)
        return ((nbr < 0) ? ("-inf") : ("inf"));
    if (exp_2 != -1023)
        mantisse |= 0x10000000000000;
    else
        exp_2 = (nbr == 0.) ? 0 : exp_2 + 1;
    printf("\nexp = %d\n mantisse =%lu\n", exp_2, mantisse);
    ft_bin_str(exp_2, mantisse, &split, 53);
    printf("split 1 = %s \n split 2 = %s \n", split[0], split[1]);
    res = ft_get_flstring(split);
    if ((tmp >> 63) == 1)
        ft_strcadd_left(&res, '-', 1);
    return (res);
}