/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rharing <rharing@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/19 14:06:27 by rharing       #+#    #+#                 */
/*   Updated: 2022/01/19 14:06:31 by rharing       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		k;
	char	*new;

	i = 0;
	k = 0;
	if (!s || !f)
		return (NULL);
	new = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!new)
		return (NULL);
	while (s[i] != '\0')
	{
		new[k] = f(i, ((char *)s)[i]);
		i++;
		k++;
	}
	new[k] = '\0';
	return (new);
}
