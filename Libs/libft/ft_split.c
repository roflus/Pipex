/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rharing <rharing@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/19 14:04:32 by rharing       #+#    #+#                 */
/*   Updated: 2022/03/16 11:28:39 by rharing       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordcount(char const *s, char c)
{
	int	counter;
	int	words;

	words = 0;
	counter = 0;
	while (s[counter] != '\0')
	{
		if (s[counter] != c)
			words++;
		while (s[counter] != c && s[counter + 1])
			counter++;
		counter++;
	}
	return (words);
}

static int	ft_wordlength(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

static void	ft_clean(char **out, int i)
{
	while (i)
	{
		free(out[i]);
		i--;
	}
	free(out);
}

static char	**ft_storage(int wordcount, char **out, char const *s, char c)
{
	int		i;
	int		count1;
	int		length;

	count1 = 0;
	i = 0;
	while (i < wordcount)
	{
		while (s[count1] == c)
			count1++;
		length = ft_wordlength(&s[count1], c);
		out[i] = (char *)malloc(sizeof(char) * (length + 1));
		if (!out[i])
			ft_clean(out, i);
		ft_strlcpy(out[i], &s[count1], length + 1);
		out[i][length] = '\0';
		i++;
		count1 += length;
	}
	out[i] = 0;
	return (out);
}

char	**ft_split(char const *s, char c)
{
	char	**out;
	int		wordcount;

	if (s == 0)
		return (0);
	wordcount = ft_wordcount(s, c);
	out = malloc(sizeof(char *) * (wordcount + 1));
	if (!out)
		return (0);
	out = ft_storage(wordcount, out, s, c);
	return (out);
}
