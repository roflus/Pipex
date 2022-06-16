/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rharing <rharing@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/19 14:03:41 by rharing       #+#    #+#                 */
/*   Updated: 2022/01/19 14:03:44 by rharing       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*p;
	unsigned char		*k;
	size_t				i;

	i = 0;
	p = (unsigned char *)dst;
	k = (unsigned char *)src;
	if (!dst && !src)
		return (0);
	while (i < n)
	{
		p[i] = k[i];
		i++;
	}
	return (dst);
}
