/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndufourn <ndufourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:10:03 by ndufourn          #+#    #+#             */
/*   Updated: 2024/10/24 18:04:44 by ndufourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// int	main(void)
// {
// 	char	str[] = "HelloWorld";
// 	char	*temp = str;

// 	while (*temp != '\0')
// 	{
// 		*temp = ft_toupper(*temp);
// 		temp++;
// 	}
// 	printf("%s\n", str);
// 	return (0);
// }

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c = c - ('a' - 'A');
	return (c);
}
