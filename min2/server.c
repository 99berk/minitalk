/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakgun <bakgun@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 13:40:41 by bakgun            #+#    #+#             */
/*   Updated: 2023/09/12 22:57:31 by berk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf/ft_printf.h"
#include <signal.h>
#include <unistd.h>

static int client_pid = 0;

void	bit_print(int i)
{
	static int	bit = 7;
	static int	ascii = 0;

	ascii += (i << bit);
	if (bit == 0)
	{
		if (client_pid == 0)
			client_pid = ascii;
		else
		{
			ft_printf("%c", ascii);
			if (ascii == '\n')
				kill(client_pid, SIGUSR1);
		}
		bit = 7;
		ascii = 0;
	}
	else
		bit--;
}

void	sig_control(int sig)
{
	if (sig == SIGUSR1)
		bit_print(0);
	else
		bit_print(1);
}

int	main(void)
{
	ft_printf("PID: %d\n", getpid());
	signal(SIGUSR1, sig_control);
	signal(SIGUSR2, sig_control);
	while (1)
	{
		pause();
	}
	return (0);
}
