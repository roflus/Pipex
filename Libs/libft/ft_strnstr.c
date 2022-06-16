/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rharing <rharing@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/19 14:06:44 by rharing       #+#    #+#                 */
/*   Updated: 2022/01/19 14:06:46 by rharing       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		k;

	i = 0;
	k = 0;
	if (!*needle || !needle)
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		while (haystack[i + k] == needle[k] && (i + k) < len)
		{
			if (needle[++k] == '\0')
				return ((char *)&haystack[i]);
		}
		k = 0;
		i++;
	}
	return (0);
}
