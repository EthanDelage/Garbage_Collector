/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:16:37 by edelage           #+#    #+#             */
/*   Updated: 2022/09/29 17:31:49 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "ft_gc.h"

t_list	*gc_init(void)
{
	t_list	*start;

	start = (t_list *) malloc(sizeof(t_list));
	if (start == NULL)
		return (NULL);
	start->ptr = NULL;
	start->next = NULL;
	return (start);
}

void	*gc_malloc(size_t size, t_list *start)
{
	t_list	*new_alloc;

	if (start == NULL)
		return (NULL);
	new_alloc = (t_list *) malloc(sizeof(t_list));
	if (new_alloc == NULL)
		return (NULL);
	new_alloc->ptr = (void *) malloc(size);
	if (new_alloc->ptr == NULL)
		return (NULL);
	new_alloc->next = start->next;
	start->next = new_alloc;
	return (new_alloc->ptr);
}

void	gc_free(void *ptr, t_list *start)
{
	t_list	*elem_before;

	if (ptr == NULL)
		return ;
	while (start && start->ptr != ptr)
	{
		elem_before = start;
		start = start->next;
	}
	if (start->ptr == ptr)
	{
		elem_before->next = start->next;
		free(start->ptr);
		free(start);
	}
}

void	gc_free_all(t_list **start)
{
	t_list	*elem;
	t_list	*elem_free;

	elem = start[0]->next;
	free(start[0]);
	while (elem)
	{
		elem_free = elem;
		elem = elem->next;
		free(elem_free->ptr);
		free(elem_free);
	}
}
