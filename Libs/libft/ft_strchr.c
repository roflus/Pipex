/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rharing <rharing@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/19 14:05:38 by rharing       #+#    #+#                 */
/*   Updated: 2022/01/19 14:05:40 by rharing       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (i >= 0)
	{
		if (s[i] == (unsigned char) c)
			return (&((char *)s)[i]);
		if (s[i] == '\0')
			return (0);
		i++;
	}	
	return (0);
}
