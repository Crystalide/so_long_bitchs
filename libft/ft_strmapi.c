/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndufourn <ndufourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:12:02 by ndufourn          #+#    #+#             */
/*   Updated: 2024/11/22 17:19:57 by ndufourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

// char	ft_f(unsigned int i, char c);

// int	main(void)
// {
// 	char	str1[] = "Hello";
// 	char	*test1;

// 	test1 = ft_strmapi(str1, ft_f);
// 	if (test1 == NULL)
// 		printf("Memory not allocated.\n");
// 	else
// 		printf("Memory successfully allocated.\n"
// 			"Original string: %s\nModified string: %s\n", str1, test1);
// 	free(test1);
// 	return (0);
// }

// char	ft_f(unsigned int i, char c)
// {
// 	printf("%i, %c", i, c);
// 	return (c + 32);
// }

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	size_t			len;
	unsigned int	i;
	char			*new_str;

	i = 0;
	len = ft_strlen(str);
	new_str = malloc((len + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	while (i < len)
	{
		new_str[i] = f(i, str[i]);
		i++;
	}
	new_str[len] = '\0';
	return (new_str);
}
