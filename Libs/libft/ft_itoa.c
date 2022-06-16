/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rharing <rharing@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/19 14:01:59 by rharing       #+#    #+#                 */
/*   Updated: 2022/01/19 14:02:02 by rharing       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lenght(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static int	ft_negnum(int pm)
{
	if (pm < 0)
		return (pm * -1);
	return (pm);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	str = malloc(ft_lenght(n) + 1);
	if (str == NULL)
		return (0);
	str[ft_lenght(n)] = '\0';
	len = ft_lenght(n) - 1;
	if (n < 0)
		str[0] = '-';
	while (n < -9 || n > 9)
	{
		str[len] = ft_negnum(n % 10) + '0';
		n = n / 10;
		len--;
	}
	str[len] = ft_negnum(n) + '0';
	return (str);
}
