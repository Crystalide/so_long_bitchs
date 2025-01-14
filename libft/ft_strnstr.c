/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndufourn <ndufourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:09:57 by ndufourn          #+#    #+#             */
/*   Updated: 2024/10/24 18:04:47 by ndufourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// int	main(void)
// {
// 	char	str_haystack[] = "HelloWorld";
// 	char	str_needle[] = "H";
// 	char	*test1 = ft_strnstr(str_haystack, str_needle, 5);

// 	if (test1 != NULL)
// 		printf("Found needle at position: %ld\n", test1 - str_haystack);
// 	else
// 		printf("needle not found in haystack\n");
// 	printf("Result: %s\n", test1);
// 	return (0);
// }

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack != '\0' && len > 0)
	{
		i = 0;
		while (needle[i] != '\0' && len > i && haystack[i] == needle[i])
			i++;
		if (needle[i] == '\0')
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
