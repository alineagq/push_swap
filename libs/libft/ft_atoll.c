/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 11:15:26 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/06/14 11:16:43 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long ft_atoll(const char *str) {
    long long result = 0;
    int sign = 1;
    int i = 0;

    // Skip leading whitespace
    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n') {
        i++;
    }

    // Check sign
    if (str[i] == '+' || str[i] == '-') {
        if (str[i] == '-') {
            sign = -1;
        }
        i++;
    }

    // Process digits
    while (str[i] >= '0' && str[i] <= '9') {
        result = result * 10 + (str[i] - '0');
        i++;
    }

    return result * sign;
}