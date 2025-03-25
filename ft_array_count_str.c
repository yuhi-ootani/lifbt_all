/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_count_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knemcova <knemcova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:08:37 by knemcova          #+#    #+#             */
/*   Updated: 2025/03/25 14:09:36 by knemcova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_array_count_str(char **array)
{
	size_t	count;

	count = 0;
	while (array && array[count])
	{
		count++;
	}
	return (count);
}
