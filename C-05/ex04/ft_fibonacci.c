/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-bouk <hel-bouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 17:02:33 by hel-bouk          #+#    #+#             */
/*   Updated: 2023/08/31 18:35:01 by hel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index == 1)
		return (1);
	if (index == 0)
		return (0);
	return (ft_fibonacci(index - 2) + ft_fibonacci(index - 1));
}

/*int main(void)
{
	int i;
	int index = 9;
	for(i =0 ; i <= index ; i++)
	{
		printf("%d ",ft_fibonacci(i));
	}
}*/
