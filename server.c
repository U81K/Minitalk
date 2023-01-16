/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgannoun <bgannoun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:31:41 by bgannoun          #+#    #+#             */
/*   Updated: 2023/01/17 00:13:24 by bgannoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"

char	g_binary[9];

int	ft_pow(int nb, int power)
{
	int	i;
	int	fixe;

	fixe = nb;
	i = 1;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (i < power)
	{
		nb = nb * fixe;
		i++;
	}
	return (nb);
}

void	convert_to_char(void)
{
	int		decimal;
	int		j;
	char	result;

	j = 0;
	decimal = 0;
	while (j < 8)
	{
		if (g_binary[j] == '1')
			decimal += ft_pow(2, 8 - 1 - j);
		j++;
	}
	result = (char)decimal;
	write(1, &result, 1);
}

void	signal_handler(int signum, siginfo_t *signal, void *oldact)
{
	static int		index ;
	static pid_t	actpid;

	(void)oldact;
	if (signal->si_pid != actpid)
	{
		actpid = signal->si_pid;
		index = 0;
	}
	if (signum == SIGUSR1)
		g_binary[index] = '0';
	if (signum == SIGUSR2)
		g_binary[index] = '1';
	index++ ;
	if (index == 8)
	{
		g_binary[index + 1] = '\0';
		convert_to_char();
		index = 0;
	}
}

int	main(void)
{
	pid_t				id;
	struct sigaction	act;

	act.sa_sigaction = &signal_handler;
	act.sa_flags = SA_RESTART;
	id = getpid();
	printf("%d\n", id);
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		pause();
	return (0);
}
