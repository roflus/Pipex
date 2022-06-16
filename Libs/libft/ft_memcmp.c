/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rharing <rharing@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/19 14:03:32 by rharing       #+#    #+#                 */
/*   Updated: 2022/01/19 14:03:37 by rharing       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p;
	unsigned char	*k;
	size_t			i;

	p = (unsigned char *)s1;
	k = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (p[i] != k[i])
			return (p[i] - k[i]);
		i++;
	}
	return (0);
}
