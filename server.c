/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgannoun <bgannoun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:31:41 by bgannoun          #+#    #+#             */
/*   Updated: 2023/01/11 00:39:27 by bgannoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void signal_handler(int signum) 
{
	if (signum == SIGUSR1)
	{
		write(1,"0",1);
	} 
	else if (signum == SIGUSR2)
	{
		write(1,"1",1);
	}
}

int main(void)
{
	pid_t	id;

	id = getpid();
	printf("%d\n", id);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1){
		pause();
	}
	return (0);
}