/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-bouk <hel-bouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:36:00 by hel-bouk          #+#    #+#             */
/*   Updated: 2023/09/05 15:22:19 by hel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void putnbr(int nb)
{
	char digite ;
	if(nb > 10)
	{
		putnbr(nb / 10);
		putnbr(nb % 10);
	}
	else
	{
		digite = nb + 48;
		write(1,&digite,1);
	}
}
int atoi(char *str)
{
	int result = 0;
	int i = 0;
	while(str[i] <= '9' && str[i] >= '0')
	{
		result = result*10 + str[i] - 48;
		i++;
	}
	return result;
}

int ft_len(char *str)
{
	int i = 0;
	while(str[i])
		i++;
	return i;
}
int main(int argc , char **argv)
{
	int i = 1;
	char digit;
	if (argc == 2)
	{
		while(i <= 9)
		{
			digit = i + 48;
			write(1,argv[1],ft_len(argv[1]));
			write(1," x ",3);
			write(1,&digit,1);
			write(1," = ",3);
			putnbr(atoi(argv[1]) * i);
			write(1,"\n",1);
			i++;
		}
	}
	if(argc != 2)
		write(1,"\n",1);
}
