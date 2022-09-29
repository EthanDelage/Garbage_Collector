/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:16:37 by edelage           #+#    #+#             */
/*   Updated: 2022/09/29 12:47:48 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "ft_gc.h"

t_list	*gc_init(void)
{
	t_list	*start;

	start = (t_list*) malloc(sizeof(t_list));
	if (start == NULL)
		return (NULL);
	start->ptr = NULL;
	start->next = NULL;
	return (start);
}

void	*gc_malloc(size_t size, t_list *start)
{

}

void	gc_free(void *ptr, t_list *start)
{

}

void	gc_free_all(t_list **start)
{

}
