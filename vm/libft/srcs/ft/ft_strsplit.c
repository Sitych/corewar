/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 20:28:18 by snorcros          #+#    #+#             */
/*   Updated: 2019/09/14 13:46:45 by snorcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			count_words(const char *str, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c)
			i++;
		if (str[i] != c && str[i] != '\0')
			count++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (count);
}

static int			*characters_in_word(const char *str,
		int count_words, char c)
{
	int		i;
	int		*counts;
	int		j;
	int		count;

	j = 0;
	i = 0;
	count = 0;
	counts = (int*)malloc(sizeof(int) * count_words);
	if (!counts)
		return (NULL);
	while (str[i] != '\0' && j < count_words)
	{
		while (str[i] == c)
			i++;
		while (str[i] != c && str[i] != '\0')
		{
			count++;
			i++;
		}
		counts[j] = count;
		j++;
		count = 0;
	}
	return (counts);
}

static char			**fill_ans(const char *str, char **ans, char c)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	j = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c)
			i++;
		if (str[i] == '\0')
			break ;
		while (str[i] != c && str[i] != '\0')
		{
			ans[k][j] = str[i];
			j++;
			i++;
		}
		ans[k][j] = '\0';
		k++;
		j = 0;
	}
	return (ans);
}

static void			free_split(char **arr, int position)
{
	int	i;

	i = 0;
	while (i <= position)
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
	arr = NULL;
}

char				**ft_strsplit(char const *s, char c)
{
	char	**ans;
	int		*char_word;
	int		strs;
	int		i;

	i = -1;
	if (!s || !c || (strs = count_words(s, c)) < 0)
		return (NULL);
	if (!(ans = (char **)malloc(sizeof(char *) * (strs + 1))))
		return (NULL);
	if (strs == 0 || !(char_word = characters_in_word(s, strs, c)))
	{
		*ans = NULL;
		return (ans);
	}
	while (++i < strs)
		if (!(ans[i] = (char*)malloc(sizeof(char) * (char_word[i] + 1))))
		{
			free_split(ans, i);
			return (NULL);
		}
	ans = fill_ans(s, ans, c);
	ans[strs] = NULL;
	free(char_word);
	return (ans);
}
