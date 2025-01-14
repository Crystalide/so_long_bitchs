/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndufourn <ndufourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:41:21 by ndufourn          #+#    #+#             */
/*   Updated: 2024/11/22 17:19:57 by ndufourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

char			*ft_utoa(unsigned long n);
static size_t	ft_len(unsigned long n);
static char		*ft_utoa_recursion( char *str, unsigned long n, size_t len);
// void		ft_print_array(int *str, int size, int i);

// int	main(void)
// {
// 	int		str[] = {42, -42, 0, 123456789, -123456789, INT_MAX, INT_MIN};
// 	int		size = sizeof(str) / sizeof(str[0]);

// 	ft_print_array(str, size, 0);
// 	return (0);
// }

char	*ft_utoa(unsigned long n)
{
	size_t	len;
	char	*str;

	len = ft_len(n);
	str = malloc(len + 1);
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	return (ft_utoa_recursion(str, n, len));
}

static char	*ft_utoa_recursion(char *str, unsigned long n, size_t len)
{
	len--;
	if (n >= 10)
		ft_utoa_recursion(str, n / 10, len);
	str[len] = (n % 10) + 48;
	return (str);
}

static size_t	ft_len(unsigned long n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
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
// 	test1 = ft_utoa(str[i]);
// 	if (test1 == NULL)
// 		printf("Memory not allocated.\n");
// 	else
// 		printf("Memory successfully allocated.\n"
// 			"Original: %d\nConverted: %s\n", str[i], test1);
// 	free(test1);
// 	ft_print_array(str, size, i + 1);
// }
