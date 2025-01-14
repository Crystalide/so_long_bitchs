/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndufourn <ndufourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:11:10 by ndufourn          #+#    #+#             */
/*   Updated: 2024/11/22 17:19:57 by ndufourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>
#include <limits.h>

static size_t	ft_len(int n);
static char		*ft_itoa_recursion( char *str, int n, size_t len);
// void		ft_print_array(int *str, int size, int i);

// int	main(void)
// {
// 	int		str[] = {42, -42, 0, 123456789, -123456789, INT_MAX, INT_MIN};
// 	int		size = sizeof(str) / sizeof(str[0]);

// 	ft_print_array(str, size, 0);
// 	return (0);
// }

char	*ft_itoa(int n)
{
	size_t	len;
	char	*str;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	len = ft_len(n);
	str = malloc(len + 1);
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	return (ft_itoa_recursion(str, n, len));
}

static char	*ft_itoa_recursion(char *str, int n, size_t len)
{
	len--;
	if (n >= 10)
		ft_itoa_recursion(str, n / 10, len);
	str[len] = (n % 10) + 48;
	return (str);
}

static size_t	ft_len(int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
	{
		len = 1;
		if (n == 0)
			return (len);
		n = -n;
	}
	while (n > 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

// void	ft_print_array(int *str, int size, int i)
// {
// 	char	*test1;

// 	if (i >= size)
// 		return ;
// 	test1 = ft_itoa(str[i]);
// 	if (test1 == NULL)
// 		printf("Memory not allocated.\n");
// 	else
// 		printf("Memory successfully allocated.\n"
// 			"Original: %d\nConverted: %s\n", str[i], test1);
// 	free(test1);
// 	ft_print_array(str, size, i + 1);
// }
