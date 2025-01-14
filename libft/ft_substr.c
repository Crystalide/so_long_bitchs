/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndufourn <ndufourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:07:51 by ndufourn          #+#    #+#             */
/*   Updated: 2024/11/22 17:19:57 by ndufourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

// int	main(void)
// {
// 	char	str[] = "HelloWorld";
// 	char	*substr;

// 	substr = ft_substr(str, 5, 4);
// 	if (substr == NULL)
// 		printf("Memory not allocated for substring.\n");
// 	else
// 		printf("Memory successfully allocated for substring.\n"
// 			"String: %s\nSubstring: %s\n", str, substr);
// 	free(substr);
// 	return (0);
// }

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	size_t	strlen;
	char	*substr;

	strlen = ft_strlen(str);
	if (start >= strlen)
		return (ft_strdup(""));
	if (len > strlen - start)
		len = strlen - start;
	substr = malloc(len + 1);
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, str + start, len + 1);
	return (substr);
}
