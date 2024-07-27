/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_rev.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-bouk <hel-bouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 21:27:52 by hel-bouk          #+#    #+#             */
/*   Updated: 2023/09/06 22:31:32 by hel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

int  is_whitespace(char c) {
    if( c == ' ' || c == '\t')
		return 1;
	return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        write(1, "\n", 1);
        return 0;
    }

    char *str = argv[1];
    int length = 0;

    while (str[length]) {
        length++;
    }

	char *result = (char *)malloc(length + 1);
    int word_start = length - 1;
    int word_end = length - 1;
	int i = length - 1;
	int result_index = 0;
	while(i >= 0)
	{
        if (is_whitespace(str[i]) || i == 0) 
		{
            word_start = (i == 0) ? 0 : i + 1;

			int j = word_start;
            while (j <= word_end)
		   	{
                result[result_index++] = str[j];
				j++;
          	}

            if (i != 0)
                result[result_index++] = ' ';

            word_end = i - 1;
        }
		i--;
    }
	
	result[result_index] = '\0';
	write(1, result, result_index);
    write(1, "\n", 1);

	free(result);

    return 0;
}

