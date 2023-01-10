/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgannoun <bgannoun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:32:06 by bgannoun          #+#    #+#             */
/*   Updated: 2023/01/11 00:40:03 by bgannoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void ft_putchar(int c)
{
	write(1, &c, 1);
}

void ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

int	atoi(char *a)
{
	int sign;
	int i;
	int res;

	i = 0;
	while (a[i] == ' ' || a[i] == '\t' || a[i] == '\v' || a[i] == '\n' || a[i] == '\f' || a[i] == '\r')
		i++;
	sign = 1;
	while (a[i] == '+' || a[i] == '-')
	{
		if (a[i] == '-')
			sign *= -1;
		i++;
	}
	res = 0;
	while (a[i] >= '0' && a[i] <= '9')
	{
		res = res * 10;
		res += a[i] - 48;
		i++;
	}
	return (res * sign);
}

void decimal_to_binary(int decimal, int binary[], pid_t id) 
{
    int i;

	i = 0;
    while (decimal > 0) 
	{
        binary[i] = decimal % 2;
        decimal = decimal / 2;
        i++;
    }
    while (i < 8) 
	{
        binary[i] = 0;
        i++;
    }
	i = 7;
	while (i >= 0)
	{
		if(binary[i] == 0)
			kill(id, SIGUSR1);
		else if (binary[i] == 1)
			kill(id, SIGUSR2);
		i--;
		usleep(300);
	}
}

void send_str(pid_t id, char *str)
{
	int i;
	int bin[8];

	i = 0;
	while (str[i])
	{
		decimal_to_binary(str[i], bin, id);
		i++;
	}
}

int	main(int ac, char **av)
{
	pid_t id;

	if (ac != 3)
		return (1);
	id = atoi(av[1]);
	send_str(id, av[2]);
	// decimal_to_binary('a', bin);
	// send_str(id, av[2]);
	// kill(id, SIGUSR2);
	// printf("%d\n", id);
	return (0);
}