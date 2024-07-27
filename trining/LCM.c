/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LCM.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-bouk <hel-bouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:17:26 by hel-bouk          #+#    #+#             */
/*   Updated: 2023/09/06 13:07:07 by hel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int    HCF(unsigned int a, unsigned int b)
{
	unsigned int i;

	if(a == 0 || b == 0)
		return 0;
	if(a > b)
		i = a - 1;
	else
		i = b - 1;
	 while(i != 1)
	 {
		 if(a % i == 0 && b % i == 0)
			 return i;
		 i--;
	 }
	 return 0;
}
unsigned lcm(unsigned int a,unsigned int b)
{
	return ((a * b)/HCF(a,b));
}
#include <stdio.h>

int main()
{
	printf("%d",lcm(12,8));

}
