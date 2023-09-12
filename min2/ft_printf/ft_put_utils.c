/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakgun <bakgun@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:39:06 by bakgun            #+#    #+#             */
/*   Updated: 2023/07/26 13:19:54 by bakgun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	i;
	int	tmp;

	i = 0;
	while (s[i])
	{
		tmp = ft_putchar(s[i]);
		if (tmp == -1)
			return (-1);
		i++;
	}
	return (tmp);
}

int	ft_putnbr(int n)
{
	int	len;
	int	tmp;

	len = 1;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		n = n * (-1);
		len++;
	}
	if (n > 9)
	{
		tmp = ft_putnbr((n / 10));
		if (tmp == -1)
			return (-1);
		len += tmp;
	}
	if (ft_putchar((48 + (n % 10))) == -1)
		return (-1);
	return (len);
}
