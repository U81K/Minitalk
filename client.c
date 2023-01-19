/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgannoun <bgannoun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:32:06 by bgannoun          #+#    #+#             */
/*   Updated: 2023/01/19 04:16:14 by bgannoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"

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
	int		j;

	i = 0;
	bin = ft_strdup("00000000");
	char_to_bin(n, bin);
	while (bin[i])
	{
		if (bin[i] == '0')
			j = kill(id, SIGUSR1);
		else if (bin[i] == '1')
			j = kill(id, SIGUSR2);
		i++;
		if (j == -1)
			exit(-1);
		usleep(200);
	}
	free(bin);
}

int	main(int ac, char **av)
{
	pid_t	id;
	int		i;

	if (ac != 3)
		return (1);
	id = ft_atoi(av[1]);
	if (id <= 1)
		exit (-1);
	i = 0;
	while (av[2][i])
	{
		send_char(av[2][i], id);
		i++;
	}
	return (0);
}
