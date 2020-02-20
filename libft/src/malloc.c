/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 11:15:28 by acoudray          #+#    #+#             */
/*   Updated: 2020/02/20 13:12:37 by acoudray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	*malloc(size_t size)
{
	void *addr;

	addr = NULL;
	if (size == 0)
		return (NULL);
	else if	(!(glob_m))
	{
		if ((addr = ft_create_block(size, &glob_m)) == MAP_FAILED)
			return (NULL);
	}
	else if ((addr = ft_search_block(size)) == NULL)
		if ((addr = ft_new_block(size)) == MAP_FAILED)
			return (NULL);
	ft_block_split(addr, size);
	return(addr + sizeof(t_block));
}
