/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakgun <bakgun@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 13:40:41 by bakgun            #+#    #+#             */
/*   Updated: 2023/09/13 14:37:09 by bakgun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf/ft_printf.h"
#include <signal.h>
#include <unistd.h>

int	get_client_pid(int i)
{
	static int	bit2 = 31;
	static int	ascii_pid = 0;
	int			pid_tmp;

	pid_tmp = 0;
	ascii_pid += (i << bit2);
	if (bit2 == 0)
	{
		bit2 = 31;
		pid_tmp = ascii_pid;
		ascii_pid = 0;
		return (pid_tmp);
	}
	else
		bit2--;
	return (pid_tmp);
}

void	bit_print(int i)
{
	static int	bit = 7;
	static int	ascii = 0;
	static int	client_pid = 0;

	if (client_pid == 0)
		client_pid = get_client_pid(i);
	else
	{
		ascii += (i << bit);
		if (bit == 0)
		{
			ft_printf("%c", ascii);
			if (ascii == '\n')
			{
				kill(client_pid, SIGUSR1);
				client_pid = 0;
			}
			ascii = 0;
			bit = 7;
		}
		else
			bit--;
	}
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
		pause();
	return (0);
}
