/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndufourn <ndufourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:08:56 by ndufourn          #+#    #+#             */
/*   Updated: 2024/10/24 18:04:47 by ndufourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// int	main(void)
// {
// 	char	str1[] = "hello";
// 	char	str2[] = "hello";
// 	char	str3[] = "helloworld";

// 	printf("Result 1: %i\n", ft_memcmp(str1, str2, 7));
// 	printf("Result 2: %i\n", ft_memcmp(str1, str3, 5));
// 	printf("Result 3: %i\n", ft_memcmp(str3, str1, 6));
// 	printf("Result 4: %i\n", ft_memcmp(str1, str3, 9));
// 	printf("Result 1: %i\n", memcmp(str1, str2, 7));
// 	printf("Result 2: %i\n", memcmp(str1, str3, 5));
// 	printf("Result 3: %i\n", memcmp(str3, str1, 6));
// 	printf("Result 4: %i\n", memcmp(str1, str3, 9));
// 	return (0);
// }

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*temp_s1;
	const unsigned char	*temp_s2;

	temp_s1 = (const unsigned char *)s1;
	temp_s2 = (const unsigned char *)s2;
	if (n == 0)
		return (0);
	while (n-- > 1 && (*temp_s1 == *temp_s2))
	{
		temp_s1++;
		temp_s2++;
	}
	return (*temp_s1 - *temp_s2);
}
