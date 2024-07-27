/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revverse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-bouk <hel-bouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 19:00:19 by hel-bouk          #+#    #+#             */
/*   Updated: 2023/09/03 19:07:37 by hel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strrev(char *str)
{
	int len = ft_strlen(str) - 1 ;
	int i = 0;
	int tmp;
	while(i < len)
	{
		tmp = str[i];
		str[i] = str[len];
		str[len] = tmp;
		i++;
		len--;
	}
	return str;
}
int main()
{
	char hi[]="hello ,world";
	ft_strrev(hi);
	printf("%s",hi);
}
