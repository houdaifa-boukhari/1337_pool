/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-bouk <hel-bouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 11:54:38 by hel-bouk          #+#    #+#             */
/*   Updated: 2023/08/28 21:25:32 by hel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc > 1)
	{
		i = argc - 1;
		while (argv[i] != '\0' && i > 0)
		{
			putstr(argv[i]);
			write (1, "\n", 1);
			i--;
		}
	}
	return (0);
}
