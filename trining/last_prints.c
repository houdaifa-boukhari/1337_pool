/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_prints.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-bouk <hel-bouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 17:32:25 by hel-bouk          #+#    #+#             */
/*   Updated: 2023/09/04 17:17:50 by hel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int ft_len(char *str)
{
	int i = 0;
	while(str[i])
	{
		i++;
	}
return i;
}

int main(int argc ,char **argv)
{
	if(argc > 1)
	{
		write(1,argv[argc-1],ft_len(argv[argc-1]));
	}
	write(1,"\n",1);
}

