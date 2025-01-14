/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndufourn <ndufourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:11:14 by ndufourn          #+#    #+#             */
/*   Updated: 2024/11/22 17:19:57 by ndufourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <unistd.h>

// #include <fcntl.h>

// int	main(void)
// {
// 	char	c = 'c';
// 	int		fd;
//
// 	fd = open("char.txt", O_RDWR | O_CREAT, 0644);
// 	if (fd == -1)
// 		return (1);
// 	ft_putchar_fd(c, fd);
// 	close(fd);
// 	return (0);
// }

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
