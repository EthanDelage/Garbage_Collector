/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:18:37 by edelage           #+#    #+#             */
/*   Updated: 2022/10/13 12:23:02 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "ft_gc.h"
#include <stdio.h>
#include <string.h>

void	display_malloc(t_list *start)
{
	if (start == NULL)
		return ;
	start = start->next;
	while (start != NULL)
	{
		printf("%s -> ", (char *) start->ptr);
		start = start->next;
	}
	printf("\n");
}

int	main(void)
{
	char	*str;
	char	*str1;
	char	*str2;
	t_list	*start;

	start = gc_init();
	printf("start: %p\n", start);
	str = (char *) gc_malloc(sizeof(char) * 3, start);
	printf("s1: %p\n", str);
	str1 = (char *) gc_malloc(sizeof(char) * 8, start);
	printf("s2: %p,\n", str1);
	str2 = (char *) gc_malloc(sizeof(char) * 6, start);
	printf("s3: %p\n", str2);
	printf("start->next: %p\n", start->next->ptr);
	strcpy(str, "Ok");
	strcpy(str1, "Bonjour");
	strcpy(str2, "Salut");
	display_malloc(start);
	gc_free(str, start);
	display_malloc(start);
	gc_free_all(&start);
	display_malloc(start);
}
