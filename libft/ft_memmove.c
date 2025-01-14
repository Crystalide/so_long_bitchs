/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndufourn <ndufourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:09:00 by ndufourn          #+#    #+#             */
/*   Updated: 2024/10/24 18:04:47 by ndufourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// int	main(void)
// {
// 	char	src[] = "HelloWorld";
// 	char	dest[20];

// 	printf("Source: %s\nDestination: %s\n", src, dest);
// 	ft_memmove(src + 5, src, 5);
// 	printf("Source: %s\nDestination: %s\n", src, dest);
// 	ft_memmove(dest, src, 10);
// 	printf("Source: %s\nDestination: %s\n", src, dest);
// 	return (0);
// }

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char			*temp_dest;
	const unsigned char		*temp_src;

	temp_dest = (unsigned char *)dest;
	temp_src = (const unsigned char *)src;
	if (temp_src == temp_dest || n == 0)
		return (dest);
	if (temp_src > temp_dest)
	{
		while (n-- > 0)
			*temp_dest++ = *temp_src++;
	}
	else
	{
		temp_src = temp_src + n;
		temp_dest = temp_dest + n;
		while (n-- > 0)
			*--temp_dest = *--temp_src;
	}
	return (dest);
}
