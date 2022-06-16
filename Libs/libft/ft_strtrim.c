/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rharing <rharing@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/19 14:06:56 by rharing       #+#    #+#                 */
/*   Updated: 2022/01/19 14:06:58 by rharing       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_left(char const *s1, char const *set)
{
	size_t	count;

	count = 0;
	while (s1[count] != '\0')
	{
		if (ft_strchr(set, s1[count]) == 0)
			break ;
		count++;
	}
	return (count);
}

static int	ft_right(char const *s1, char const *set)
{
	size_t	count;

	count = ft_strlen(s1);
	while (count > 0)
	{
		if (ft_strchr(set, s1[count - 1]) == 0)
			break ;
		count--;
	}
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	left;
	size_t	right;

	if (!s1)
		return (NULL);
	if (ft_strlen(set) == 0)
		return (ft_strdup(s1));
	if (ft_strlen(s1) == 0 && ft_strlen(set) == 0)
		return (ft_strdup(""));
	left = ft_left(s1, set);
	right = ft_right(s1, set);
	if (left > right)
		return (ft_strdup(""));
	return (ft_substr(s1, left, right - left));
}
