/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rharing <rharing@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/19 14:06:09 by rharing       #+#    #+#                 */
/*   Updated: 2022/01/19 14:06:11 by rharing       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	p;
	size_t	j;

	i = 0;
	p = ft_strlen(dst);
	j = ft_strlen(dst);
	if (dstsize <= p)
		return (dstsize + ft_strlen((char *)src));
	while (src[i] != '\0' && (p) < (dstsize - 1))
	{
		dst[p] = src[i];
		i++;
		p++;
	}
	dst[p] = '\0';
	return (j + ft_strlen((char *)src));
}
