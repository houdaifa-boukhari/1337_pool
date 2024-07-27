/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-bouk <hel-bouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 19:17:20 by hel-bouk          #+#    #+#             */
/*   Updated: 2023/09/06 19:37:49 by hel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int lenght(char *str)
{
	int i = 0;

	while(str[i])
		i++;
	return i;
}

int main(int argc, char **argv)
{
	if(argc == 2)
	{
	int i = lenght(argv[1]) + 1;
	char *str;
	int j = 0;
	str = malloc(sizeof(char)*i);
	while(argv[1][i])
	{
		while(argv[1][i] >= 32 && argv[1][i] <= 126)
			i--;
		if(argv[1][i] == 32)
		{
			i++;
			while(argv[1][i])
			{
				str[j] = argv[1][i];
				i++;
				j++;
			}
		}
		str[j] = '\0';
		printf("%s",str);	
	}
	}
}

