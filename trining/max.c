/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-bouk <hel-bouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 23:29:14 by hel-bouk          #+#    #+#             */
/*   Updated: 2023/09/03 11:37:42 by hel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void swap(int *a , int *b)
{
	int temp;
	
	temp = *a;
	*a = *b;
	*b = temp;
}


int max(int *tab , unsigned int len)
{
	unsigned int i = 0;
	unsigned int j = 0;

	while(i < len - 1)
	{
	  	j = i + 1;	
		while(j < len - 1)
		{
			if(tab[i] < tab[j + 1])
				swap(&tab[i],&tab[j+1]);
			j++;
		}
		break;
	}
	return tab[0];
}
int main()
{
	int tab[] = {1,8,9,57,2,98};

	printf("%d",max(tab ,6));
}
