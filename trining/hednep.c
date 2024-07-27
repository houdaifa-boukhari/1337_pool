/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hednep.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-bouk <hel-bouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:00:22 by hel-bouk          #+#    #+#             */
/*   Updated: 2023/09/05 12:26:20 by hel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int lenght(char *str)
{
	int i = 0;
	
	while(str[i])
		i++;
	return i;

}


int main(int argc, char **argv)
{
	if(argc == 3)
	{
		int i = 0;
		int j = 0;
		int tab[256] = {0};
		int test = 0;
		int len = lenght(argv[1]); 

		while(argv[1][i])
		{
			while(argv[2][j])
			{
				if(argv[1][i] == argv[2][j] && tab[(unsigned char)argv[1][i]] != 1)
				{
					test++;
					tab[(unsigned char)argv[1][i]] = 1;
					break;
				}
				j++;
			}
			i++;
		}
		if(len == test)
			write(1,"1",1);
		else
			write(1,"0",1);
	}
	write(1,"\n",1);
}
