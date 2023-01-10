/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_to_bin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgannoun <bgannoun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 09:55:46 by bgannoun          #+#    #+#             */
/*   Updated: 2023/01/10 10:21:16 by bgannoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void decimal_to_binary(int decimal, int binary[]) {
    int i = 0;
    while (decimal > 0) {
        binary[i] = decimal % 2;
        decimal = decimal / 2;
        i++;
    }
    while (i < 8) {
        binary[i] = 0;
        i++;
    }
}

int main() {
    int width = 8;
    int binary[width];
    decimal_to_binary(97, binary);

	int i;
	i = 7;
    while (i >= 0) 
        printf("%d", binary[i--]);
    printf("\n");
    return 0;
}
