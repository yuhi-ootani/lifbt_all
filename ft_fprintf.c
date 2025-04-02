/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knemcova <knemcova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 18:10:48 by knemcova          #+#    #+#             */
/*   Updated: 2025/04/02 16:48:16 by knemcova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static int	ft_fputchar_fd(int fd, char c)
// {
// 	return (write(fd, &c, 1));
// }

// static int	ft_fputstr_fd(int fd, char *str)
// {
// 	int	count;
// 	int	err;

// 	count = 0;
// 	if (!str)
// 		str = "(null)";
// 	while (str[count])
// 	{
// 		err = write(fd, &str[count], 1);
// 		if (count == INT_MAX || err == -1)
// 			return (-1);
// 		count++;
// 	}
// 	return (count);
// }

// static int	ft_fputnbr_fd(int fd, int n)
// {
// 	char	num[12];
// 	int		i;
// 	long	nb;

// 	nb = n;
// 	if (nb == 0)
// 		return (write(fd, "0", 1));
// 	if (nb < 0)
// 	{
// 		write(fd, "-", 1);
// 		nb = -nb;
// 	}
// 	i = 10;
// 	num[11] = '\0';
// 	while (nb > 0)
// 	{
// 		num[i--] = '0' + (nb % 10);
// 		nb /= 10;
// 	}
// 	return (write(fd, &num[i + 1], 10 - i));
// }

// static int	identify_type_fd(int fd, char c, va_list ap)
// {
// 	int	count;

// 	count = 0;
// 	if (c == 'c')
// 		count += ft_fputchar_fd(fd, va_arg(ap, int));
// 	else if (c == 's')
// 		count += ft_fputstr_fd(fd, va_arg(ap, char *));
// 	else if (c == 'd' || c == 'i')
// 		count += ft_fputnbr_fd(fd, va_arg(ap, int));
// 	else if (c == '%')
// 		count += write(fd, "%", 1);
// 	return (count);
// }

// int	ft_fprintf(int fd, const char *format, ...)
// {
// 	va_list	ap;
// 	int		count;
// 	int		tmp;
// 	int		i;

// 	count = 0;
// 	i = 0;
// 	va_start(ap, format);
// 	while (format[i])
// 	{
// 		tmp = 0;
// 		if (format[i] == '%' && format[i + 1])
// 			tmp += identify_type_fd(fd, format[++i], ap);
// 		else if (!(format[i] == '%' && format[i + 1] == '\0'))
// 			tmp += write(fd, &format[i], 1);
// 		if (tmp == -1 || count > INT_MAX - tmp)
// 		{
// 			va_end(ap);
// 			return (-1);
// 		}
// 		count += tmp;
// 		i++;
// 	}
// 	va_end(ap);
// 	return (count);
// }

static int	append_char(t_fprintf_buffer *info, char c)
{
	char	*new_buffer;

	if (info->index >= info->buf_size - 1)
	{
		new_buffer = ft_realloc(info->buffer, info->buf_size, info->buf_size
				* 2);
		if (!new_buffer)
			return (-1);
		info->buffer = new_buffer;
		info->buf_size *= 2;
	}
	info->buffer[info->index++] = c;
	return (0);
}

static int	append_str(t_fprintf_buffer *info, const char *src)
{
	while (*src)
	{
		if (append_char(info, *src++) == -1)
			return (-1);
	}
	return (0);
}

static int	handle_type(t_fprintf_buffer *info, char type, va_list ap)
{
	char	*s;

	if (type == 'c')
		return (append_char(info, va_arg(ap, int)));
	else if (type == 's')
	{
		s = va_arg(ap, char *);
		if (!s)
			s = "(null)";
		return (append_str(info, s));
	}
	else if (type == '%')
		return (append_char(info, '%'));
	return (0);
}

int	process_format_string(const char *data, va_list ap, t_fprintf_buffer *info)
{
	int	i;
	int	status;

	i = 0;
	status = 0;
	while (data[i])
	{
		if (data[i] == '%' && data[i + 1])
			status = handle_type(info, data[++i], ap);
		else if (!(data[i] == '%' && data[i + 1] == '\0'))
			status = append_char(info, data[i]);
		if (status == -1)
			return (-1);
		i++;
	}
	return (info->index);
}

int	ft_fprintf(int fd, const char *format, ...)
{
	va_list				ap;
	t_fprintf_buffer	info;
	int					written;

	info.buf_size = 128;
	info.index = 0;
	info.buffer = malloc(info.buf_size);
	if (!info.buffer)
		return (-1);
	va_start(ap, format);
	written = process_format_string(format, ap, &info);
	va_end(ap);
	if (written == -1 || write(fd, info.buffer, written) == -1)
	{
		free(info.buffer);
		return (-1);
	}
	free(info.buffer);
	return (written);
}
