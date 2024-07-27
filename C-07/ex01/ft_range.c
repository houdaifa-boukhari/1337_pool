/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-bouk <hel-bouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 21:19:18 by hel-bouk          #+#    #+#             */
/*   Updated: 2023/09/05 23:35:14 by hel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	j;
	int	a;
	int	*range;

	a = 0;
	j = min;
	i = max - min;
	if (min >= max)
		return (NULL);
	range = (int *) malloc(sizeof(int) * i);
	if (!range)
		return (NULL);
	while (a < i)
	{
		range[a] = j;
		a++;
		j++;
	}
	return (range);
}

/*int main(void)
{
	int min;
	int max;
	int size;
	int i;
	
	min = 2 ;
	max = 9;
	size = max -min;
	int *tab = ft_range(min, max);

	for (i = 0; i < size; i++)
   	{
            printf("%d ", tab[i]);
    }
}*/
