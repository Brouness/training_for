/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybourajl <ybourajl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 11:14:35 by ybourajl          #+#    #+#             */
/*   Updated: 2026/02/13 13:24:45 by ybourajl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

t_list	*ft_lstnew(void	*content)
{
	t_list	*new;
	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}