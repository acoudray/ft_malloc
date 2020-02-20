/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 22:14:48 by gmachena          #+#    #+#             */
/*   Updated: 2020/02/07 16:49:33 by acoudray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list *newlink;

	if (!(newlink = (t_list*)ft_malloc(sizeof(t_list))))
		return (0);
	if (content == 0)
	{
		newlink->content = 0;
		newlink->content_size = 0;
	}
	else
	{
		if (!(newlink->content = (void*)ft_malloc(sizeof(content) *
			content_size)))
			return (0);
		ft_memcpy((newlink->content), content, content_size);
		newlink->content_size = content_size;
	}
	newlink->next = 0;
	return (newlink);
}
