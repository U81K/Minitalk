/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgannoun <bgannoun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:31:41 by bgannoun          #+#    #+#             */
/*   Updated: 2023/01/03 20:31:41 by bgannoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void sigint_handler(int signu) {
  // Handle the SIGINT signal
  printf("%d\n", signu);
}

// int main() {
//   // Set up the SIGINT signal handler
//   signal(SIGINT, sigint_handler);
//   // Wait for a signal to be received
//   pause();
//   return 0;
// }

int main(void)
{
	pid_t	id;

	id = getpid();
	printf("%d\n", id);
	signal(SIGUSR1, sigint_handler);
	pause();
	return (0);
}
