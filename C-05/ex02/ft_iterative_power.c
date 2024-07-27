/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-bouk <hel-bouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 16:19:05 by hel-bouk          #+#    #+#             */
/*   Updated: 2023/08/31 18:29:57 by hel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int	i;

	if (power == 0)
	{
		nb = 1;
	}
	else if (power < 0)
	{
		nb = 0;
	}
	else
	{
		i = nb;
		power--;
		while (power > 0)
		{
			nb = i * nb;
			power--;
		}
	}
	return (nb);
}
/*int main(void)
{
	printf("%d",ft_iterative_power(2,4));
}*/
