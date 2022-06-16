/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rharing <rharing@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/19 14:05:54 by rharing       #+#    #+#                 */
/*   Updated: 2022/01/19 14:06:03 by rharing       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char		*comb;
	int			i;
	int			k;

	i = 0;
	k = 0;
	if (!s1 || !s2)
		return (NULL);
	comb = (char *) malloc(sizeof(char) * ft_strlen((char *) s1) \
			+ ft_strlen((char *) s2) + 1);
	if (!comb)
		return (NULL);
	while (s1[i] != '\0')
	{
		comb[i] = s1[i];
		i++;
	}
	while (s2[k] != '\0')
	{
		comb[i] = s2[k];
		k++;
		i++;
	}
	comb[i] = '\0';
	return (comb);
}
