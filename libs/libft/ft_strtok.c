/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 09:10:48 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/06/14 09:11:00 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtok(char *str, const char *c)
{
	static char	*last_token = NULL;
	char		*result;

	if (str)
		last_token = str;
	if (!last_token || !*last_token)
		return (NULL);
	while (*last_token && ft_strchr(c, *last_token))
		last_token++;
	if (!*last_token)
	{
		last_token = NULL;
		return (NULL);
	}
	result = last_token;
	while (*last_token && !ft_strchr(c, *last_token))
		last_token++;
	if (*last_token)
	{
		*last_token = '\0';
		last_token++;
	}
	else
		last_token = NULL;
	return (result);
}