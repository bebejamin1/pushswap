/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeaurai <bbeaurai@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 17:19:11 by bbeaurai          #+#    #+#             */
/*   Updated: 2025/12/16 15:08:05 by bbeaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static int	del_node(int content)
// {
// 	if (!content)
// 		return ;
// 	free(content);
// }
// static void	*node_change(void *elem)
// {
// 	if (!elem)
// 		return (NULL);
// 	int i;
// 	char *content;

// 	i = 0;
// 	content = (char *)elem;
// 	while(content[i])
// 	{
// 		if (content[i] >= 'a' && content[i]<= 'z')
// 			content[i] = content[i] - 32;
// 		else if (content[i] >= 'A' && content[i]<= 'Z')
// 			content[i] = content[i] + 32;
// 		else
// 			content[i] = 'x';
// 		i++;
// 	}
// 	return (content);
// }
t_list	*ft_lstmap(t_list *lst, int (*f)(int), void (*del)(int))
{
	t_list	*start;
	t_list	*ptr;
	t_list	*new;

	if (lst == NULL)
		return (NULL);
	ptr = lst;
	start = ft_lstnew((*f)(ptr->content));
	if (start == NULL)
		ft_lstclear(&start, del);
	ptr = ptr->next;
	while (ptr != NULL)
	{
		new = ft_lstnew((*f)(ptr->content));
		if (new == NULL)
			ft_lstclear(&start, del);
		ft_lstadd_back(&start, new);
		ptr = ptr->next;
	}
	return (start);
}
// int main()
// {
// 	t_list *lst;
// 	t_list *ptr;
// 	char *str = ft_strdup("aled123");
// 	lst = ft_lstnew(str);
// 	printf("adresse : %p\t", (char *)lst);
// 	printf("Valeur  : %s\n", (char *)lst->content);
// 	ptr = ft_lstmap(lst, node_change, del_node);
// 	printf("adresse : %p\t", (char *)ptr);
// 	printf("Valeur  : %s\n", (char *)ptr->content);
// 	free (str);
// 	free (lst);
// 	free (ptr);
// }