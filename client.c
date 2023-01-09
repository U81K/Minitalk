/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgannoun <bgannoun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:32:06 by bgannoun          #+#    #+#             */
/*   Updated: 2023/01/03 20:32:06 by bgannoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>

// int main() {
//   // Send the SIGINT signal to process with ID 12345
//   kill(224, SIGINT);
//   return 0;
// }

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

int	main(int ac, char **av)
{
	pid_t id;

	id = atoi(av[1]);
	kill(id, SIGUSR1);
	// printf("%d\n", id);
	return (0);
}