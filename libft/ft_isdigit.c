/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndufourn <ndufourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:08:50 by ndufourn          #+#    #+#             */
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

// 	printf("%d\n", ft_isdigit(char1));
// 	printf("%d\n", ft_isdigit(char2));
// 	printf("%d\n", ft_isdigit(char3));
// 	printf("%d\n", ft_isdigit(char4));
// 	return (0);
// }

int	ft_isdigit(int c)
{
	if (!(c >= '0' && c <= '9'))
		return (0);
	return (1);
}
