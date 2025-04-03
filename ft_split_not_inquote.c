/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_not_inquote.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:58:16 by oyuhi             #+#    #+#             */
/*   Updated: 2025/04/03 13:34:52 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, const char *delimiters)
{
	size_t	words;
	bool	in_word;
	bool	in_quote;
	size_t	i;

	i = 0;
	words = 0;
	in_word = false; 
	in_quote = false;
	while (s[i])
	{
		if (s[i] == '"')
			in_quote = !in_quote;
		if (!ft_strchr(delimiters, s[i]) && !in_word)
		{
			in_word = true;
			words++;
		}
		if (!in_quote && ft_strchr(delimiters, s[i]))
			in_word = false;
		i++;
	}
	return (words);
}

static void	ft_free(char **arr, size_t num)
{
	size_t	i;

	i = 0;
	while (i < num)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

size_t	get_end_of_str(const char *s, size_t i, const char *delimiters,
		bool *in_quote)
{
	while (s[i])
	{
		if (s[i] == '"')
			*in_quote = !*in_quote;
		if (ft_strchr(delimiters, s[i]) && !*in_quote)
			break ;
		i++;
	}
	return (i);
}

static int	ft_insert_word(char **result, const char *s, const char *delimiters)
{
	size_t	i;
	size_t	start;
	size_t	index;
	bool	in_quote;

	i = 0;
	index = 0;
	in_quote = false;
	while (s[i])
	{
		while (s[i] && ft_strchr(delimiters, s[i]) && !in_quote)
			i++;
		if (!s[i])
			break ;
		start = i;
		i = get_end_of_str(s, i, delimiters, in_quote);
		result[index] = ft_strndup(s + start, i - start);
		if (!result[index])
		{
			ft_free(result, index);
			return (0);
		}
		index++;
	}
	return (1);
}

char	**ft_split_not_inquote(char const *s, const char *delimiters)
{
	char	**result;
	size_t	words;

	if (!s)
		return (NULL);
	words = ft_count_words(s, delimiters);
	result = (char **)malloc((words + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	result[words] = NULL;
	if (!ft_insert_word(result, s, delimiters))
		return (NULL);
	return (result);
}

// #include <stdio.h>
// #include <stdlib.h>

// // Function prototypes (assuming they're in another file)
// char			**ft_split(char const *s, char *delimiters);
// void			ft_free(char **arr, size_t num);

// // Helper function to print the result of `ft_split`
// void	print_split_result(char *input, char *delimiters)
// {
// 	char	**result;
// 	int		i;

// 	result = ft_split(input, delimiters);
// 	if (!result)
// 	{
// 		printf("Error: ft_split returned NULL\n");
// 		return ;
// 	}
// 	printf("Input: \"%s\" | Delimiters: \"%s\"\n", input, delimiters);
// 	i = 0;
// 	while (result[i])
// 	{
// 		printf("Token %d: \"%s\"\n", i, result[i]);
// 		free(result[i]); // Free individual tokens
// 		i++;
// 	}
// 	free(result); // Free array
// 	printf("\n");
// }

// int	main(void)
// {
// 	printf("==== Testing ft_split ====\n");
// 	// ✅ Basic Test Cases
// 	print_split_result("hello world", " ");
// 	print_split_result("hello,world", ",");
// 	print_split_result("this|is|a|test", "|");
// 	print_split_result("split:me:properly", ":");
// 	// ✅ Multiple delimiters
// 	print_split_result("one,two;three four", ",; ");
// 	// ✅ Multiple spaces
// 	print_split_result("   multiple   spaces  ", " ");
// 	// ✅ Empty input
// 	print_split_result("", " ");
// 	print_split_result(" ", " ");
// 	// ✅ No delimiters found
// 	print_split_result("no_delimiters_here", ",");
// 	// ✅ Leading/trailing delimiters
// 	print_split_result(",start,with,comma,", ",");
// 	print_split_result("  space before", " ");
// 	print_split_result("ends with space ", " ");
// 	// ✅ Special characters
// 	print_split_result("abc\tdef\nghi", "\t\n");
// 	printf("==== Tests Completed ====\n");
// 	return (0);
// }
