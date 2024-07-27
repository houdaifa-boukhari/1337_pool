/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-bouk <hel-bouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 10:52:49 by hel-bouk          #+#    #+#             */
/*   Updated: 2023/08/22 12:07:37 by hel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	test;

	i = 0;
	test = 0;
	while (str[i] != '\0')
	{
		if (test == 0 && str[i] <= 'z' && str[i] >= 'a')
			str[i] -= 32;
		else if (test == 1 && str[i] <= 'Z' && str[i] >= 'A')
			str[i] += 32;
		if (!((str[i] >= '0' && str[i] <= '9')
				|| (str[i] <= 'Z' && str[i] >= 'A')
				|| (str[i] <= 'z' && str[i] >= 'a')))
			test = 0;
		else 
			test = 1;
		i++;
	}
	return (str);
}
