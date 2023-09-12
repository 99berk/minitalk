/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakgun <bakgun@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:06:42 by bakgun            #+#    #+#             */
/*   Updated: 2023/07/27 11:19:39 by bakgun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	count_address_digits(unsigned long address)
{
	int	numdigits;

	numdigits = 0;
	while (address != 0)
	{
		address /= 16;
		numdigits++;
	}
	return (numdigits);
}

static int	print_hex_digit(unsigned long address, int i)
{
	static char	hex_digits[] = "0123456789abcdef";

	while (i-- > 0)
		address /= 16;
	return (write(1, &hex_digits[address % 16], 1));
}

int	ft_print_ptr(void *pointer)
{
	unsigned long	address;
	int				count;
	int				numdigits;

	address = (unsigned long)pointer;
	count = 2;
	if (write(1, "0x", 2) == -1)
		return (-1);
	if (address == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		count++;
	}
	else
	{
		numdigits = count_address_digits(address);
		while (numdigits-- > 0)
		{
			if (print_hex_digit(address, numdigits) == -1)
				return (-1);
			count++;
		}
	}
	return (count);
}
