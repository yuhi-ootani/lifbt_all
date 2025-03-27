/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_join.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:57:10 by oyuhi             #+#    #+#             */
/*   Updated: 2025/03/27 12:57:37 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_array_join(char **array1, char **array2)
{
	size_t len1;
	size_t len2;
	char **new_array;

	len1 = 0;
	len2 = 0;
	if (array1)
		len1 = ft_array_count_str(array1);
	if (array2)
		len2 = ft_array_count_str(array2);
	new_array = (char **)malloc(sizeof(char *) * (len1 + len2 + 1));
	if (!new_array)
		return (NULL);
	new_array[len1 + len2] = NULL;
	if (!ft_array_range_dup(new_array, array1, 0, len1)
		|| !ft_array_range_dup(new_array, array2, len1, len1 + len2))
	{
		ft_array_free(new_array);
		return (NULL);
	}
	return (new_array);
}