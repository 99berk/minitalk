/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakgun <bakgun@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:03:51 by bakgun            #+#    #+#             */
/*   Updated: 2023/07/27 11:02:28 by bakgun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_digit(unsigned int number, int index, char *digits)
{
	while (index-- > 0)
		number /= 16;
	return (digits[number % 16]);
}

static int	count_hex_digits(unsigned int number)
{
	int	numdigits;

	numdigits = 0;
	while (number != 0)
	{
		number /= 16;
		numdigits++;
	}
	return (numdigits);
}

static char	*ft_digits(int upper_case)
{
	static char	upper_digits[] = "0123456789ABCDEF";
	static char	lower_digits[] = "0123456789abcdef";

	if (upper_case == 1)
		return (upper_digits);
	else
		return (lower_digits);
	return (0);
}

int	ft_print_hex(unsigned int number, int upper_case)
{
	char	*digits;
	int		numdigits;
	int		count;

	count = 0;
	digits = ft_digits(upper_case);
	if (number == 0)
		return (ft_putchar(digits[0]));
	numdigits = count_hex_digits(number);
	while (numdigits-- > 0)
	{
		if (ft_putchar(get_digit(number, numdigits, digits)) == -1)
			return (-1);
		else
			count++;
	}
	return (count);
}
