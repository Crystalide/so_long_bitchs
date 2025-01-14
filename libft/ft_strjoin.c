/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndufourn <ndufourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:11:56 by ndufourn          #+#    #+#             */
/*   Updated: 2024/11/22 17:19:57 by ndufourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

// int	main(void)
// {
// 	char	str1[] = "Hello";
// 	char	str2[] = "World";
// 	char	*res;

// 	res = ft_strjoin(str1, str2);
// 	if (res == NULL)
// 		printf("Memory not allocated.\n");
// 	else
// 		printf("Memory successfully allocated.\n"
// 			"String 1: %s\nString 2: %s\nJoined string: %s\n", str1, str2, res);
// 	free(res);
// 	return (0);
// }

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*new_str;

	len = ft_strlen(s1) + ft_strlen(s2);
	new_str = malloc(len + 1);
	if (new_str == NULL)
		return (NULL);
	ft_strlcpy(new_str, s1, ft_strlen(s1) + 1);
	ft_strlcpy(new_str + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	return (new_str);
}
