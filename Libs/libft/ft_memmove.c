/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rharing <rharing@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/19 14:03:48 by rharing       #+#    #+#                 */
/*   Updated: 2022/01/19 14:03:50 by rharing       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_if(void *dst, const void *src, size_t len)
{
	unsigned char			*p;
	unsigned char			*k;
	size_t					i;

	i = 0;
	p = (unsigned char *)dst;
	k = (unsigned char *)src;
	while (i < len)
	{
		p[i] = k[i];
		i++;
	}
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char			*p;
	const unsigned char		*k;
	size_t					i;

	i = 0;
	p = dst;
	k = src;
	if (!dst && !src)
		return (0);
	if (dst < src)
		ft_if(p, k, len);
	else
	{
		while (len > 0)
		{
			len--;
			p[len] = k[len];
		}
	}	
	return (dst);
}
