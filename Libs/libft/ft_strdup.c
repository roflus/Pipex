/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rharing <rharing@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/19 14:05:43 by rharing       #+#    #+#                 */
/*   Updated: 2022/01/19 14:05:45 by rharing       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*p;
	size_t	len;

	len = ft_strlen((char *)s1) + 1;
	p = malloc(len);
	if (p == NULL)
		return (NULL);
	ft_memcpy(p, s1, len);
	return (p);
}
