/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-bouk <hel-bouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 19:27:29 by hel-bouk          #+#    #+#             */
/*   Updated: 2023/09/06 02:47:04 by hel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include <stdio.h>

int	ft_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*dest;

	if (src == NULL)
		return (NULL);
	i = ft_len(src) + 1;
	dest = (char *)malloc(sizeof(char) * i);
	if (dest != NULL)
		ft_strcpy(dest, src);
	return (dest);
}
/*int main()
{
	char *hi = "hello";
	printf("%s",ft_strdup(hi));
}*/
