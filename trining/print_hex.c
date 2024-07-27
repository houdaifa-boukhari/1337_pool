/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-bouk <hel-bouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 12:34:12 by hel-bouk          #+#    #+#             */
/*   Updated: 2023/09/04 13:53:01 by hel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int short_atoi(char *str)
{
	int i = 0;
	int result = 0;
	while(str[i] >= 48 && str[i] <= 57)
	{
		result = result*10 + (str[i] - 48);
		i++;
	}
	return result;
}
void putnbr(int nb)
{
	char *base = "0123456789abcdef";
	
	if(nb > 16)
	{
		putnbr(nb  / 16);
		putnbr(nb % 16);
	}
	else{
		write(1,&base[nb],1);
	}
}

int main(int argc,char **argv)
{
	if(argc == 2)
	{
		putnbr(short_atoi(argv[1]));
	}
	write(1,"\n",1);
}
