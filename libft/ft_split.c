/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndufourn <ndufourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:11:46 by ndufourn          #+#    #+#             */
/*   Updated: 2024/11/22 17:19:57 by ndufourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

static int	count_words(const char *str, char delimiter);
static char	*get_word(const char **str, char delimiter);
static int	fill_str(char **split_str, const char *str, char delimiter);
// void		ft_print_array(char **str, int size, int i);

// int	main(void)
// {
// 	char	*str = " asdas ";
// 	// char	*str = NULL;
// 	if (str == NULL || *str == '\0')
// 	{
// 		printf("NULL or empty string.\n");
// 		return (1);
// 	}
// 	int		size = count_words(str, ' ');
// 	char	**test1 = ft_split(str, ' ');

// 	ft_print_array(test1, size, 0);
// 	free(test1);
// 	return (0);
// }

char	**ft_split(char const *str, char delimiter)
{
	int		word_count;
	char	**split_str;

	word_count = count_words(str, delimiter);
	split_str = (char **)malloc((word_count + 1) * sizeof(char *));
	if (split_str == NULL)
		return (NULL);
	if (fill_str(split_str, str, delimiter) == 1)
		return (NULL);
	split_str[word_count] = NULL;
	return (split_str);
}

static int	count_words(const char *str, char delimiter)
{
	int	word_count;
	int	is_word;

	word_count = 0;
	is_word = 0;
	while (*str != '\0')
	{
		if (*str != delimiter && is_word == 0)
		{
			is_word = 1;
			word_count++;
		}
		else if (*str == delimiter)
			is_word = 0;
		str++;
	}
	return (word_count);
}

static char	*get_word(const char **str, char delimiter)
{
	const char	*start;

	start = *str;
	while (**str != '\0' && **str != delimiter)
		(*str)++;
	return (ft_substr(start, 0, *str - start));
}

static int	fill_str(char **split_str, const char *str, char delimiter)
{
	int	word_index;

	word_index = 0;
	while (*str != '\0')
	{
		while (*str == delimiter)
			str++;
		if (*str != '\0')
		{
			split_str[word_index] = get_word(&str, delimiter);
			if (split_str[word_index] == NULL)
			{
				while (word_index--)
					free(split_str[word_index]);
				free(split_str);
				return (1);
			}
			word_index++;
		}
	}
	return (0);
}

// void	ft_print_array(char **str, int size, int i)
// {
// 	char	**test1;

// 	if (i >= size)
// 		return ;
// 	test1 = ft_split(str[i], ' ');
// 	if (test1 == NULL)
// 		printf("Memory not allocated.\n");
// 	else
// 	{
// 		printf("Memory successfully allocated.\n"
// 			"Before split: %s\nAfter split: ", str[i]);
// 		free(test1[i]);
// 		if (test1[0] != NULL)
// 			printf("%s\n", test1[0]);
// 	}
// 	free(test1);
// 	ft_print_array(str, size, i + 1);
// }
