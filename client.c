/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakgun <bakgun@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 13:40:55 by bakgun            #+#    #+#             */
/*   Updated: 2023/09/13 14:34:34 by bakgun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf/ft_printf.h"
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	num;

	i = 0;
	sign = 1;
	num = 0;
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10;
		num = num + (str[i] - '0');
		i++;
	}
	num = num * sign;
	return (num);
}

void	send_signal(int pid, int bit)
{
	if (bit == 0)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	usleep(200);
}

void	message_convert(int pid, char *msg)
{
	int	i;
	int	bit;

	i = 0;
	while (msg[i])
	{
		bit = 7;
		while (bit >= 0)
			send_signal(pid, (msg[i] >> bit--) & 1);
		i++;
	}
	bit = 7;
	while (bit >= 0)
		send_signal(pid, ('\n' >> bit--) & 1);
	bit = 7;
	while (bit >= 0)
		send_signal(pid, ('\0' >> bit--) & 1);
	usleep(1000);
}

int	main(int argc, char *argv[])
{
	int		pid;
	char	*msg;

	if (argc != 3)
	{
		ft_printf("Error: Wrong number of arguments.\n");
		ft_printf("Usage: ./client <PID> <message>\n");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	msg = argv[2];
	message_convert(pid, msg);
	return (0);
}
