/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndufourn <ndufourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:11:38 by ndufourn          #+#    #+#             */
/*   Updated: 2024/11/22 17:20:15 by ndufourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <unistd.h>
#include <limits.h>
// #include <fcntl.h>

// int	main(void)
// {
// 	int	n = '1';
// 	int	fd;
//
// 	fd = open("nbr.txt", O_RDWR | O_CREAT, 0644);
// 	if (fd == -1)
// 		return (1);
// 	ft_putnbr_fd(n, fd);
// 	close(fd);
// 	return (0);
// }

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == INT_MIN)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	c = (n % 10) + 48;
	write(fd, &c, 1);
}
