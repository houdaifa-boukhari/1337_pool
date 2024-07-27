/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-bouk <hel-bouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 22:35:40 by hel-bouk          #+#    #+#             */
/*   Updated: 2023/09/05 23:35:26 by hel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	j;
	int	a;

	a = 0;
	j = min;
	i = max - min;
	if (i <= 0)
	{
		*range = NULL;
		return (0);
	}
	*range = (int *)malloc (sizeof(int) * i);
	if (*range == NULL)
	{
		return (-1);
	}
	while (a < i)
	{
		(*range)[a] = j;
		a++;
		j++;
	}
	return (i);
}
/*int main(void)
{
	int i;
	int min = 2;
	int max = 9;
	int *range = NULL;;
	int count = ft_ultimate_range(&range, min, max);

	for (i = 0; i < count ; i++)
   	{
            printf("%d ", range[i]);
    }
	free(range);
	return 0;
}*/
