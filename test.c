/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgannoun <bgannoun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:36:14 by bgannoun          #+#    #+#             */
/*   Updated: 2023/01/04 14:36:14 by bgannoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// void char_to_bin(char c)
// {
//     int i;
//     unsigned char mask;

//     i = 7;
//     mask = 1u << i;
//     while (mask)
//     {
//         // s_received = 0;
//         if (mask & c)
//             printf("1");
//         else
//             printf("0");
//         // if (!s_received)
//         //     pause();
//         i--;
//         mask >>= 1;
//     }
// }

// int main(void)
// {
// 	int i;

// 	i = 10;
// 	printf("%d\n", i&2);
// 	// char *str = {"a"};
// 	// // printf("%s", str);
// 	// i = 0;
// 	// while (str[i])
// 	// {
// 	// 	char_to_bin(str[i]);
// 	// 	i++;
// 	// }
// 	// char_to_bin('a');
// 	return (0);
// }

#include <stdio.h>

void char_to_bin(char c) 
{
	int i;
	int bit;

	i = 7;
    while (i >= 0) 
	{
        // Shift c to the right by i bits and mask it with 1
        // to get the value of the i-th bit
        bit = (c >> i) & 1;

        // Print the bit
        // printf("%d", bit);
		if (bit)
			printf("1");
		else
			printf("0");
		i--;
    }
	printf("\n");
}

void send_str(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		char_to_bin(str[i]);
		i++;
	}
}

char bin_to_char(char* binary) {
  int i;
  char c = 0;
  i = 0;
  while (i < 8) 
  {
    c = c * 2 + (binary[i] - '0');
	i++;
  }
  return c;
}

int main() {
    char c = 'a';
    send_str("a");
	printf("%c", bin_to_char("01100001"));
    return 0;
}
