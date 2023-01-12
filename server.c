/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgannoun <bgannoun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:31:41 by bgannoun          #+#    #+#             */
/*   Updated: 2023/01/12 20:22:05 by bgannoun         ###   ########.fr       */
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

void	signal_handler(int signum)
{
	static int	indx ;

	if (signum == SIGUSR1)
		g_binary[indx] = '0';
	if (signum == SIGUSR2)
		g_binary[indx] = '1';
	indx++ ;
	if (indx == 8)
	{
		g_binary[indx + 1] = '\0';
		convert_to_char();
		indx = 0;
	}
}

int	main(void)
{
	pid_t	id;

	id = getpid();
	printf("%d\n", id);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		pause();
	return (0);
}
