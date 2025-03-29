/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_three.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 10:38:00 by oyuhi             #+#    #+#             */
/*   Updated: 2025/03/29 18:27:08 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_three(const char *str1,const  char *str2,const  char *str3)
{
	char	*tmp;
	char	*result;

	if (!str1 && !str2 && !str3)
		return (NULL);
	if (!str1)
		str1 = "";
	if (!str2)
		str2 = "";
	if (!str3)
		str3 = "";
	tmp = ft_strjoin(str1, str2);
	if (!tmp)
		return (NULL);
	result = ft_strjoin(tmp, str3);
	free(tmp);
	return (result);
}
