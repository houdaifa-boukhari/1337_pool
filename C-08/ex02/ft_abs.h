/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-bouk <hel-bouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 23:24:17 by hel-bouk          #+#    #+#             */
/*   Updated: 2023/09/07 02:26:34 by hel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ABS_H

# define FT_ABS_H

# define ABS(Value) \
    ({ \
        int abs_value = (Value); \
        if (abs_value < 0) { \
            abs_value = -abs_value; \
        } \
        abs_value; \
    })

#endif
