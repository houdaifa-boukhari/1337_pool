/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-bouk <hel-bouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 13:00:52 by hel-bouk          #+#    #+#             */
/*   Updated: 2023/08/28 21:57:15 by hel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putstr(char *str1)
{
	while (*str1)
	{
		write(1, str1, 1);
		str1++;
	}
	write(1, "\n", 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] == s1[i])
	{
		i++;
	}
	if (s1[i] == s2[i])
		return (0);
	else
		return (s1[i] - s2[i]);
}

void	ft_swap(char **str1, char **str2)
{
	char	*x;

	x = *str1;
	*str1 = *str2;
	*str2 = x;
}

int	main(int argc, char **argv)
{
	int	i;
	int	x;

	if (argc > 1)
	{
		i = 1;
		while (i < argc -1)
		{
			x = i + 1;
			while (x < argc)
			{
				if (ft_strcmp(argv[i], argv[x]) > 0)
					ft_swap(&argv[i], &argv[x]);
				x++;
			}
			i++;
		}
		i = 1;
		while (i < argc)
		{
			putstr(argv[i]);
			i++;
		}
	}
	return (0);
}
