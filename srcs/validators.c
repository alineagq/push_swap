/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 10:26:33 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/05/30 11:51:30 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_numbers(char *str)
{
	int	i;

	i = 0;
	if (!str || !*str)
		return (0);
	if (*str == '-' || *str == '+')
		str++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (i);
}

int	find_duplicate(char **args, int i)
{
	int		j;
	size_t	len;
	size_t	len_cmp;

	j = i + 1;
	len = ft_strlen(args[i]);
	while (args[j])
	{
		len_cmp = ft_strlen(args[j]);
		if (len > len_cmp)
			len_cmp = len;
		if (!ft_strncmp(args[i], args[j], len_cmp))
			return (0);
		j++;
	}
	return (1);
}

int	invalid_int(char *num, int places)
{
	ssize_t	n;

	n = ft_atoi(num);
	if (places > 10)
		return (1);
	else if (n < -(long)((unsigned int)(1 << 31)))
		return (1);
	else if (n > (ssize_t)((unsigned int) ~ (1 << 31)))
		return (1);
	return (0);
}

void	print_error(void)
{
	ft_printf("Error!\n");
	exit(0);
}

void	validator(char **argv)
{
	int	i;
	int	places;

	i = 1;
	while (argv[i])
	{
		places = check_numbers(argv[i]);
		if (!check_numbers(argv[i]))
			print_error();
		if (!find_duplicate(argv, i))
			print_error();
		if (invalid_int(argv[i], places))
			print_error();
		i++;
	}
}
