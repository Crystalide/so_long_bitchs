/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndufourn <ndufourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:11:53 by ndufourn          #+#    #+#             */
/*   Updated: 2024/10/28 20:08:09 by ndufourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	ft_f(unsigned int i, char *c);

// int	main(void)
// {
// 	char	str[] = "Hello World";

// 	ft_striteri(str, ft_f);
// 	printf("Modified string: %s\n", str);
// 	return (0);
// }

// void	ft_f(unsigned int i, char *c)
// {
// 	printf("%i, %c", i, *c);
// 	*c = *c + 32;
// }

void	ft_striteri(char *str, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (*str != '\0')
	{
		f(i, str);
		str++;
		i++;
	}
}
