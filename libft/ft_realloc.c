/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndufourn <ndufourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:45:21 by ndufourn          #+#    #+#             */
/*   Updated: 2025/03/21 16:07:33 by ndufourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_realloc(void *ptr, size_t size, size_t new_size)
{
	void	*new_ptr;

	if (new_size == 0)
		return (free(ptr), NULL);
	if (new_size == size)
		return (ptr);
	if (!ptr)
		return (malloc(new_size));
	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (NULL);
	if (size > new_size)
		size = new_size;
	ft_memcpy(new_ptr, ptr, size);
	free(ptr);
	return (new_ptr);
}
