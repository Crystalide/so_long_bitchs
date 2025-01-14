/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndufourn <ndufourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:11:35 by ndufourn          #+#    #+#             */
/*   Updated: 2024/11/22 17:19:57 by ndufourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <unistd.h>
// #include <fcntl.h>

// int	main(void)
// {
// 	char	str[] = "HelloWorld";
// 	int		fd;

// 	c = 'c';
// 	fd = open("endl.txt", O_RDWR | O_CREAT, 0644);
// 	if (fd == -1)
// 		return (1);
// 	ft_putendl_fd(str, fd);
// 	close(fd);
// 	return (0);
// }

void	ft_putendl_fd(char *str, int fd)
{
	write(fd, str, ft_strlen(str));
	write(fd, "\n", 1);
}
