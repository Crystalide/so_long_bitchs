/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndufourn <ndufourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:23:28 by ndufourn          #+#    #+#             */
/*   Updated: 2025/02/07 16:20:33 by ndufourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

// int	main(void)
// {
// 	char	str[] = "HelloWorld";
// 	t_list	*test1 = ft_lstnew(str);

// 	if (test1 != NULL)
// 		printf("New node: %s\n", (char *)test1->content);
// 	else
// 		printf("Node creation failed\n");
// 	free(test1);
// 	return (0);
// }

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
