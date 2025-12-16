/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeaurai <bbeaurai@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:54:12 by bbeaurai          #+#    #+#             */
/*   Updated: 2025/12/16 14:57:08 by bbeaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static int	del_node(int content)
// {
// 	if (!content)
// 		return ;
// 	free(content);
// }
void	ft_lstdelone(t_list *lst, void (*del)(int))
{
	if (!lst)
		return ;
	del(lst->content);
	free (lst);
}
// int main(void)
// {
// 	t_list *list;
// 	list = ft_lstnew(ft_strdup((char *)"ALED"));
// 	printf("adresse : %p\t", (char *)list->content);
// 	printf("Valeur  : %s\n", (char *)list->content);
// 	ft_lstdelone(list, del_node);
// }