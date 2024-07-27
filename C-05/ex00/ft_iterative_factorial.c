/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-bouk <hel-bouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 12:07:20 by hel-bouk          #+#    #+#             */
/*   Updated: 2023/09/02 14:22:58 by hel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	factoriel;

	i = 1;
	factoriel = 1;
	if (nb < 0)
		return (0);
	if (nb == 0 || nb == 1)
	{
		factoriel = 1;
	}
	else
	{
		while (i <= nb)
		{
			factoriel *= i;
			i++;
		}
	}
	return (factoriel);
}
/*int main(void)
{
	printf("%d",ft_iterative_factorial(-5));
}*/
