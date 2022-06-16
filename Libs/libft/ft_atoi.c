/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rharing <rharing@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/19 13:58:19 by rharing       #+#    #+#                 */
/*   Updated: 2022/01/19 13:59:04 by rharing       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	count;
	int	res;
	int	neg_num;

	count = 0;
	res = 0;
	neg_num = 1;
	while (str[count] == '\t' || str[count] == ' ' || str[count] == '\n' || \
	str[count] == '\v' || str[count] == '\f' || str[count] == '\r')
		count++;
	if (str[count] == '-' || str[count] == '+')
	{
		if (str[count] == '-')
			(neg_num *= -1);
		count++;
	}
	while (str[count] >= '0' && str[count] <= '9')
	{
		res = (str[count] - '0') + (res * 10);
		count++;
	}
	return (res * neg_num);
}
