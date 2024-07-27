/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-bouk <hel-bouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:33:17 by hel-bouk          #+#    #+#             */
/*   Updated: 2023/09/05 19:26:55 by hel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int not_charcter(char c)
{
	if(c <= 32)
		return 1;
	return 0;
}

int test_base(char c,int index_base)
{
	char digite[17] = "0123456789abcdef";
	char digit2[17] = "0123456789ABCDEF";

	while(index_base--)
	{
		if(digite[index_base] == c || digit2[index_base] == c)
			return 1;
	}
    return 0;
}
int value(char c)
{
    if (c >= '0' && c <= '9')
        return (c - '0');
    else if (c >= 'a' && c <= 'f')
        return (c - 'a' + 10);
    else if (c >= 'A' && c <= 'F')
        return (c - 'A' + 10);
    return (0);
}
int ft_atoi_base(const char *str,int str_base)
{
	int result;
	int signe;

	result = 0;
	while (not_charcter(*str))
        str++;
    signe = (*str == '-') ? -1 : 1;
    (*str == '-' || *str == '+') ? ++str : 0;
    while (test_base(*str, str_base))
        result = result * str_base + value(*str++);
    return (result * signe);
}

#include <stdio.h>

int main() {
    const char *str = "-255A"; // Example input string
    int base = 16; // Base of the input string (hexadecimal)

    int result = ft_atoi_base(str, base);
    printf("Converted number: %d\n", result);

    return 0;
}
