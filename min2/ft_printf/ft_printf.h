/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakgun <bakgun@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 12:18:26 by bakgun            #+#    #+#             */
/*   Updated: 2023/07/26 13:17:33 by bakgun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_print_ptr(void *ptr);
int	ft_print_hex(unsigned int number, int upper_case);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(int n);

#endif
