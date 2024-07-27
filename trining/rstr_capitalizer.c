/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-bouk <hel-bouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:43:57 by hel-bouk          #+#    #+#             */
/*   Updated: 2023/09/05 14:22:09 by hel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int main(int argc, char **argv)
{
	int i = 0;
	int j = 1;
	if(argc > 1)
	{
		while(j <= argc - 1)
		{
			i = 0;
			while(argv[j][i])
			{
				if(argv[j][i] >= 'A' && argv[j][i] <= 'Z')
				{
					argv[j][i] += 32;
				}
				if(argv[j][i+1] == 32 || (argv[j][i+1] >= 9 && argv[j][i+1] == 13) 
						|| argv[j][i+1] == 2 ||argv[j][i+1] == 3
						|| argv[j][i+1] == '\0')
				{
					if(argv[j][i] >= 'a' && argv[j][i] <= 'z')
					{
						argv[j][i] -= 32;
						write(1,&argv[j][i],1);
					}
				
				}
				else
					write(1,&argv[j][i],1);
				i++;
			}
			j++;
			write(1,"\n",1);
		}
	}
	if(argc == 1)
		write(1,"\n",1);
}
