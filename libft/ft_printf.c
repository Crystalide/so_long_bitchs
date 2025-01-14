/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndufourn <ndufourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:48:57 by ndufourn          #+#    #+#             */
/*   Updated: 2025/01/14 14:17:44 by ndufourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

#include <unistd.h>
#include <stdlib.h>

static int	convert_args(va_list args, const char *format);
static int	handle_specifier(va_list args, const t_format_spec *spec);
static int	nber_spec(va_list args, const t_format_spec *spec, char *buffer);
static char	*base(unsigned long n, size_t base, const char spec, char *buffer);

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	len;

	len = 0;
	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (format[0] != '\0')
	{
		if (format[0] == '%' && format[1] != '\0')
		{
			len = len + convert_args(args, format + 1);
			format++;
		}
		else
		{
			ft_putchar_fd(*format, 1);
			len++;
		}
		format++;
	}
	va_end(args);
	return (len);
}

static int	convert_args(va_list args, const char *format)
{
	size_t				i;
	const t_format_spec	format_table[] = {
	{"c", 0}, {"s", 0}, {"d", 10}, {"i", 10}, {"u", 10}, {"x", 16},
	{"X", 16}, {"p", 16}, {"%", 0}, {0, 0}};

	i = 0;
	while (format_table[i].specifier)
	{
		if (ft_strncmp(format, format_table[i].specifier,
				ft_strlen(format_table[i].specifier)) == 0)
			return (handle_specifier(args, &format_table[i]));
		i++;
	}
	return (write(1, "%", 1) + write(1, &format[0], 1));
}

static int	handle_specifier(va_list args, const t_format_spec *spec)
{
	char	buffer[33];
	char	*str;
	void	*ptr;

	if (spec->specifier[0] == '%')
		return (ft_putchar_fd('%', 1), 1);
	if (spec->specifier[0] == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1), 1);
	if (spec->specifier[0] == 's')
	{
		str = va_arg(args, void *);
		if (str == NULL)
			return (ft_putstr_fd("(null)", 1), 6);
		return (ft_putstr_fd(str, 1), ft_strlen(str));
	}
	if (spec->specifier[0] == 'p')
	{
		ptr = va_arg(args, void *);
		if (ptr == NULL)
			return (ft_putstr_fd("(nil)", 1), 5);
		str = base((unsigned long)ptr, 16, spec->specifier[0], buffer);
		return (ft_putstr_fd("0x", 1), ft_putstr_fd(str, 1),
			(2 + ft_strlen(str)));
	}
	return (nber_spec(args, spec, buffer));
}

static int	nber_spec(va_list args, const t_format_spec *spec, char *buffer)
{
	char	*str;
	size_t	len;

	if (spec->specifier[0] == 'd' || spec->specifier[0] == 'i'
		|| spec->specifier[0] == 'u')
	{
		if (spec->specifier[0] == 'u')
			str = ft_utoa(va_arg(args, unsigned int));
		else
			str = ft_itoa(va_arg(args, int));
		if (str == NULL)
			return (-1);
		len = ft_strlen(str);
		ft_putstr_fd(str, 1);
		free(str);
		return (len);
	}
	str = base(va_arg(args, unsigned int),
			spec->base, spec->specifier[0], buffer);
	return (ft_putstr_fd(str, 1), ft_strlen(str));
}

static char	*base(unsigned long n, size_t base, const char spec, char *buffer)
{
	const char	*digits;
	size_t		i;

	i = 32;
	if (base == 10)
		digits = "0123456789";
	else if (base == 16)
	{
		if (spec == 'X')
			digits = "0123456789ABCDEF";
		else
			digits = "0123456789abcdef";
	}
	else if (base == 2)
		digits = "01";
	buffer[i--] = '\0';
	if (n == 0)
		buffer[i--] = digits[0];
	while (n > 0 && i >= 0)
	{
		buffer[i--] = digits[n % base];
		n = n / base;
	}
	return (&buffer[i + 1]);
}
