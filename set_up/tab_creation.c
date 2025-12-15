/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_creation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchy <nbuchy@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:26:21 by nbuchy            #+#    #+#             */
/*   Updated: 2025/12/04 10:21:18 by nbuchy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

long	*argv_to_tab(char **str, int lenght)
{
	long	*tab;
	int		i;

	i = 0;
	tab = NULL;
	tab = malloc(lenght * sizeof(long));
	if (tab == NULL)
		return (NULL);
	while (i < lenght)
	{
		tab[i] = ft_atoi(str[i]);
		i++;
	}
	return (tab);
}

char	**str_to_tab(char *str, long *length)
{
	char	**tab_str;
	int		i;

	i = 0;
	tab_str = ft_split(str, ' ');
	if (tab_str == NULL)
		return (NULL);
	while (tab_str[i] != NULL)
		i++;
	*length = i;
	return (tab_str);
}

void	free_argv(char **argv, int argc, long tab_size)
{
	int	i;

	i = 0;
	if (argc != 2)
		return ;
	while (i < tab_size)
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

t_list	*creat_lst(long *tab, int lenght, void (*del)(int))
{
	int		i;
	int		content;
	t_list	*start;
	t_list	*new_node;

	i = 0;
	content = 0;
	start = NULL;
	new_node = NULL;
	while (i < lenght && tab != NULL)
	{
		content = tab[i];
		new_node = ft_lstnew(content);
		new_node->weight = -1;
		if (new_node == NULL)
		{
			ft_lstclear(&start, del);
			return (NULL);
		}
		ft_lstadd_back(&start, new_node);
		i++;
	}
	return (start);
}

void	kitchen_scale(t_list *lst, int lst_length)
{
	int		i;
	int		weight;
	t_list	*min;
	t_list	*head;

	i = 0;
	weight = 0;
	while (i < lst_length)
	{
		min = NULL;
		head = lst;
		while (head != NULL)
		{
			if (head->weight == -1 && (min == NULL
					|| head->content < min->content))
				min = head;
			head = head->next;
		}
		min->weight = i;
		i++;
	}
}
