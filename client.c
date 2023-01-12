/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgannoun <bgannoun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:32:06 by bgannoun          #+#    #+#             */
/*   Updated: 2023/01/12 20:15:10 by bgannoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"

int	ft_atoi(char *a)
{
	int	sign;
	int	i;
	int	res;

	i = 0;
	while (a[i] == ' ' || a[i] == '\t' || a[i] == '\v' || a[i] == '\n'
		|| a[i] == '\f' || a[i] == '\r')
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

void	char_to_bin(int n, char *bin)
{
	int	i;

	i = 7;
	while (n > 0)
	{
		bin[i] = n % 2 + 48;
		n = n / 2;
		i--;
	}
}

void	send_char(int n, pid_t id)
{
	char	*bin;
	int		i;

	i = 0;
	bin = strdup("00000000");
	char_to_bin(n, bin);
	while (bin[i])
	{
		if (bin[i] == '0')
			kill(id, SIGUSR1);
		else if (bin[i] == '1')
			kill(id, SIGUSR2);
		i++;
		usleep(200);
	}
}

int	main(int ac, char **av)
{
	pid_t	id;
	int		i;

	if (ac != 3)
		return (1);
	id = ft_atoi(av[1]);
	i = 0;
	while (av[2][i])
	{
		send_char(av[2][i], id);
		i++;
	}
	return (0);
}
