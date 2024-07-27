/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-bouk <hel-bouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 12:39:11 by hel-bouk          #+#    #+#             */
/*   Updated: 2023/09/06 12:00:24 by hel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include <stdlib.h>

int	ft_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*new_string(int size, char **strs, char *sep)
{
	char	*str;
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (i < size)
	{
		count += ft_len(strs[i]);
		i++;
	}
	count += ft_len(sep) * (size - 1);
	str = (char *) malloc(count + 1);
	if (!str)
		return (NULL);
	str[0] = '\0';
	return (str);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		i;

	result = new_string(size, strs, sep);
	i = 0;
	while (i < size)
	{
		ft_strcat(result, strs[i]);
		if (i < size - 1)
			ft_strcat(result, sep);
		i++;
	}
	return (result); 
}

/*int main()
{
    char *strings[] = {"Hello", "world", "this", "is", "a", "test"};
    char *separator = "--";
    char *result = ft_strjoin(6, strings, separator);
    printf("%s\n", result);
    return 0;
}*/
