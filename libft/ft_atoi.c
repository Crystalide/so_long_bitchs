/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndufourn <ndufourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:08:10 by ndufourn          #+#    #+#             */
/*   Updated: 2024/11/22 17:21:03 by ndufourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <limits.h>

// int	main(void)
// {
// 	const char	str[] = "   ----+-21474836sbajhe765";
// 	const char	str1[] = "  -21484830sbajhe765";

// 	printf("The converted number is %d.\n", atoi(str));
// 	printf("The converted number is %d.\n", atoi(str1));
// 	printf("The converted number is %d.\n", ft_atoi(str));
// 	printf("The converted number is %d.\n", ft_atoi(str1));
// 	return (0);
// }

int	ft_atoi(const char *str)
{
	int		sign;
	long	number;

	sign = 1;
	number = 0;
	while ((*str <= 13 && *str >= 9) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (number > (INT_MAX - (*str - 48)) / 10)
		{
			if (sign == 1)
				return (INT_MAX);
			else
				return (INT_MIN);
		}
		number = (number * 10) + *str++ - 48;
	}
	return (number * sign);
}
