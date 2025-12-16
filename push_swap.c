/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeaurai <bbeaurai@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 14:42:21 by bbeaurai          #+#    #+#             */
/*   Updated: 2025/12/16 15:21:58 by bbeaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	del_c(int content)
{
	content = 0;
}

long	*set_up(int argc, char ***argv, long *tab_size, t_list **a)
{
	long	*tab;

	if (argc == 2)
		*argv = str_to_tab((*argv)[0], tab_size);
	else
		*tab_size = argc - 1;
	tab = argv_to_tab(*argv, *tab_size);
	*a = creat_lst(tab, *tab_size, &del_c);
	if (*a == NULL || checker(tab, *argv, *tab_size) == 0)
	{
		write(2, "Error\n", 6);
		ft_lstclear(a, &del_c);
		free(tab);
		free_argv(*argv, argc, *tab_size);
		return (NULL);
	}
	kitchen_scale(*a, *tab_size);
	return (tab);
}

int	main(int argc, char **argv)
{
	long	*tab;
	long	tab_size;
	t_list	*a;
	t_list	*b;

	tab = NULL;
	b = NULL;
	argv = argv + 1;
	if (argc > 1)
	{
		tab = set_up(argc, &argv, &tab_size, &a);
		if (tab == NULL)
			return (1);
		if (tab_size == 3)
			sort_three(&a);
		else if (tab_size == 5)
			sort_five(&a, &b);
		else
			radix(&a, &b);
		ft_lstclear(&a, &del_c);
		ft_lstclear(&b, &del_c);
		free_argv(argv, argc, tab_size);
		free(tab);
	}
	return (0);
}