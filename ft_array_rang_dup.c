/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_rang_dup.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:58:02 by oyuhi             #+#    #+#             */
/*   Updated: 2025/03/27 12:58:50 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_array_range_dup(char **dst, char **src, size_t dst_start,
		size_t dst_end)
{
	size_t dst_i;
	size_t src_i;

	dst_i = dst_start;
	src_i = 0;
	if (!dst || !src)
		return (false);
	while (dst_i < dst_end && src[src_i])
	{
		dst[dst_i] = ft_strdup(src[src_i]);
		if (!dst[dst_i])
		{
			while (dst_i > 0)
				free(dst[dst_i--]);
			return (false);
		}
		dst_i++;
		src_i++;
	}
	return (true);
}