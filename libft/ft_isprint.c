/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndufourn <ndufourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:08:52 by ndufourn          #+#    #+#             */
/*   Updated: 2024/10/28 20:07:12 by ndufourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// int	main(void)
// {
// 	char	char1 = 'H';
// 	char	char2 = '1';
// 	char	char3 = '@';
// 	char	char4 = '\n';

// 	printf("%d\n", ft_isprint(char1));
// 	printf("%d\n", ft_isprint(char2));
// 	printf("%d\n", ft_isprint(char3));
// 	printf("%d\n", ft_isprint(char4));
// 	printf("%d\n", ft_isprint(257));
// 	return (0);
// }

int	ft_isprint(int c)
{
	if (!(c >= 32 && c < 127))
		return (0);
	return (1);
}
