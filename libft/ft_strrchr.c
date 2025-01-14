/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndufourn <ndufourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:10:00 by ndufourn          #+#    #+#             */
/*   Updated: 2024/10/31 13:35:53 by ndufourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// int	main(void)
// {
// 	char	str[] = "HelloWorld";
// 	char	*test1 = ft_strrchr(str, 'l');

// 	if (test1 != NULL)
// 		printf("Found char at position: %ld\n", test1 - str);
// 	else
// 		printf("Char not found in string\n");
// 	return (0);
// }

char	*ft_strrchr(const char *str, int c)
{
	const char	*last_occ;

	last_occ = NULL;
	while (*str != '\0')
	{
		if (*str == (unsigned char)c)
			last_occ = str;
		str++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)str);
	return ((char *)last_occ);
}
