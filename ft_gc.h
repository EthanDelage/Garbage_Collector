/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gc.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:16:52 by edelage           #+#    #+#             */
/*   Updated: 2022/09/29 12:44:24 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GC_H
# define FT_GC_H
#include <stdlib.h>

typedef struct s_list t_list;
struct	s_list
{
	void	*ptr;
	t_list	*next;
};

t_list	*gc_init(void);
void	*gc_malloc(size_t size, t_list *start);
void	gc_free(void *ptr, t_list *start);
void	gc_free_all(t_list **start);

#endif
