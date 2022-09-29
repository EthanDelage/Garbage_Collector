/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:18:37 by edelage           #+#    #+#             */
/*   Updated: 2022/09/29 18:21:12 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "ft_gc.h"
#include <stdio.h>

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
	char	**ss;
	t_list	*start;

	start = gc_init();
	printf("start: %p\n", start);
	str = (char *) gc_malloc(sizeof(char) * 3, start);
	printf("s1: %p\n", str);
	str1 = (char *) gc_malloc(sizeof(char) * 8, start);
	printf("s2: %p,\n", str1);
	str2 = (char *) gc_malloc(sizeof(char) * 6, start);
	printf("s3: %p\n", str2);
	ss = (char **) gc_malloc(sizeof(char *) * 4, start);
	printf("ss: %p\n", ss);
	printf("start->next: %p", start->next->ptr);
	ss[0] = str;
	ss[1] = str1;
	ss[2] = str2;
	ss[3] = '\0';
	str = "Ok\0";
	printf("\n%s", str);
	str1 = "Bonjour\0";
	str2 = "Salut\0";
	printf("%s\n", ss[1]);
	display_malloc(start);
//	gc_free(str, start);
	display_malloc(start);
	gc_free_all(&start);
	display_malloc(start);
}
