/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndufourn <ndufourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:08:27 by ndufourn          #+#    #+#             */
/*   Updated: 2024/10/24 18:04:47 by ndufourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// int	main(void)
// {
// 	char	char1 = 'H';
// 	char	char2 = '1';
// 	char	char3 = '@';
// 	char	char4 = ' ';

// 	printf("%d\n", ft_isalnum(char1));
// 	printf("%d\n", ft_isalnum(char2));
// 	printf("%d\n", ft_isalnum(char3));
// 	printf("%d\n", ft_isalnum(char4));
// 	return (0);
// }

int	ft_isalnum(int c)
{
	if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')
			|| (c >= '0' && c <= '9')))
		return (0);
	return (1);
}

// int	ft_isalnum(int c)
// {
// 	if (ft_isalpha(c) || ft_isdigit(c))
// 		return (1);
// 	return (0);
// }
