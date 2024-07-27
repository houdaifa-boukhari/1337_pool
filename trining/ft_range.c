/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-bouk <hel-bouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 19:10:39 by hel-bouk          #+#    #+#             */
/*   Updated: 2023/09/03 19:18:34 by hel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int     *ft_range(int start, int end)
{
	int i = end - start;
	int *tab;
	int j = 0;

	tab = malloc(4*(i - 1))
	
	while(j < i)
	{
		tab[j] = start;
		start++;
	}
	tab[j] ='\0';
}
