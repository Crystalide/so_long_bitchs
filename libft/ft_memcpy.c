/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndufourn <ndufourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:08:58 by ndufourn          #+#    #+#             */
/*   Updated: 2024/10/28 19:58:42 by ndufourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// int	main(void)
// {
// 	char	src[] = "HelloWorld";
// 	char	dest[20];

// 	printf("Source: %s\nDestination: %s\n", src, dest);
// 	ft_memcpy(dest, src, 15);
//	memcpy(NULL, NULL, 5);
// 	printf("Source: %s\nDestination: %s\n", src, dest);
// 	return (0);
// }

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char			*temp_dest;
	const unsigned char		*temp_src;

	temp_dest = (unsigned char *)dest;
	temp_src = (const unsigned char *)src;
	while (n-- > 0)
		*temp_dest++ = *temp_src++;
	return (dest);
}
