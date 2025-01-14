/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndufourn <ndufourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:08:46 by ndufourn          #+#    #+#             */
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

// 	printf("%d\n", ft_isalpha(char1));
// 	printf("%d\n", ft_isalpha(char2));
// 	printf("%d\n", ft_isalpha(char3));
// 	printf("%d\n", ft_isalpha(char4));
// 	return (0);
// }

int	ft_isalpha(int c)
{
	if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')))
		return (0);
	return (1);
}
