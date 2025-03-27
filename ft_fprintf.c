/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knemcova <knemcova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 18:10:48 by knemcova          #+#    #+#             */
/*   Updated: 2025/03/26 18:22:35 by knemcova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_fputchar_fd(int fd, char c)
{
	return (write(fd, &c, 1));
}

static int	ft_fputstr_fd(int fd, char *str)
{
	int	count;
	int	err;

	count = 0;
	if (!str)
		str = "(null)";
	while (str[count])
	{
		err = write(fd, &str[count], 1);
		if (count == INT_MAX || err == -1)
			return (-1);
		count++;
	}
	return (count);
}

static int	ft_fputnbr_fd(int fd, int n)
{
	char	num[12];
	int		i;
	long	nb;

	nb = n;
	if (nb == 0)
		return (write(fd, "0", 1));
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = -nb;
	}
	i = 10;
	num[11] = '\0';
	while (nb > 0)
	{
		num[i--] = '0' + (nb % 10);
		nb /= 10;
	}
	return (write(fd, &num[i + 1], 10 - i));
}

static int	identify_type_fd(int fd, char c, va_list ap)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_fputchar_fd(fd, va_arg(ap, int));
	else if (c == 's')
		count += ft_fputstr_fd(fd, va_arg(ap, char *));
	else if (c == 'd' || c == 'i')
		count += ft_fputnbr_fd(fd, va_arg(ap, int));
	else if (c == '%')
		count += write(fd, "%", 1);
	return (count);
}

int	ft_fprintf(int fd, const char *format, ...)
{
	va_list	ap;
	int		count;
	int		tmp;
	int		i;

	count = 0;
	i = 0;
	va_start(ap, format);
	while (format[i])
	{
		tmp = 0;
		if (format[i] == '%' && format[i + 1])
			tmp += identify_type_fd(fd, format[++i], ap);
		else if (!(format[i] == '%' && format[i + 1] == '\0'))
			tmp += write(fd, &format[i], 1);
		if (tmp == -1 || count > INT_MAX - tmp)
		{
			va_end(ap);
			return (-1);
		}
		count += tmp;
		i++;
	}
	va_end(ap);
	return (count);
}
