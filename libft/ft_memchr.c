/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndufourn <ndufourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:08:54 by ndufourn          #+#    #+#             */
/*   Updated: 2024/11/22 17:19:57 by ndufourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

// int	main(void)
// {
// 	char	str[] = "HelloWorld";
// 	char	*test1 = ft_memchr(str, 'o', 5);

// 	if (test1 != NULL)
// 		printf("Found char at position: %ld\n", test1 - str);
// 	else
// 		printf("Char not found in string\n");
// 	return (0);
// }

void	*ft_memchr(const void *str, int c, size_t n)
{
	const unsigned char	*temp;

	temp = (const unsigned char *)str;
	while (n-- > 0)
	{
		if (*temp == (unsigned char)c)
			return ((void *)temp);
		temp++;
	}
	return (NULL);
}
