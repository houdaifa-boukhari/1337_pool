/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-bouk <hel-bouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:43:12 by hel-bouk          #+#    #+#             */
/*   Updated: 2023/09/06 15:43:16 by hel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int is_prime(int num) {
    if (num <= 1) {
        return 0;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("\n");
        return 0;
    }
    
    int num = atoi(argv[1]);
    if (num <= 1) {
        printf("%d\n", num);
        return 0;
    }

    int first = 1;
    for (int divisor = 2; divisor <= num; divisor++) {
        if (is_prime(divisor)) {
            while (num % divisor == 0) {
                if (first) {
                    first = 0;
                } else {
                    printf("*");
                }
                printf("%d", divisor);
                num /= divisor;
            }
        }
    }
    printf("\n");

    return 0;
}

