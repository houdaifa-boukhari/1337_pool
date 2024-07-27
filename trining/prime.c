/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prime.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-bouk <hel-bouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:06:00 by hel-bouk          #+#    #+#             */
/*   Updated: 2023/09/06 17:17:11 by hel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int small_atoi(char *str)
{
	int i = 0;
	int result = 0;

	while(str[i] <= '9' && str[i] >= '0')
	{
		result = result*10 + (str[i] - 48);
		i++;
	}
	return result;
}
void putnbr(int nb)
{
	char digite;
	if(nb >= 10)
	{
		putnbr(nb / 10);
		putnbr(nb % 10);
	}
	else{
		digite = nb + 48;
		write(1,&digite,1);
	}
}
int prime(int nb)
{
	int i = 2;

	if(nb < 1)
		return 0;
	while(i <= (nb / i))
	{
		if(nb % i == 0)
			return 0;
		i++;
	}
	return 1;
}
int main(int argc, char **argv)
{
	int check = 1;
	int div = 2;
	int nb ;

	if(argc != 2)
	{
		write(1,"\n",1);
		return 0;
	}
	if(small_atoi(argv[1]) == 1)
		putnbr(1);
	nb = small_atoi(argv[1]);
	while(div <= nb)
	{
		if(prime(div))
		{
			while(nb % div == 0)
			{
				if(check)
					check = 0;
				else
					write(1,"*",1);
				putnbr(div);
				nb /= div;
			}
		}
		div++;
	}
	write(1,"\n",1);
}
