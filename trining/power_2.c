/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   power_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-bouk <hel-bouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 12:26:55 by hel-bouk          #+#    #+#             */
/*   Updated: 2023/09/03 13:57:55 by hel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int is_power_2(unsigned int n)
{
	if(n == 0)
	{
		return 0;
	}
	else{
		while(n % 2 == 0)
		{
			n /= 2;
		}
		return ((n == 1)  ? 1 : 0); 
	}
}
#include<stdio.h>
int main() {
    unsigned int num = 262144;
    
    if (is_power_2(num)) {
        printf("%d is a power of 2.\n", num);
    } else {
        printf("%d is not a power of 2.\n", num);
    }

    return 0;
}
