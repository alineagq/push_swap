/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 10:26:33 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/06/14 12:11:40 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	check_numbers(char *argv[])
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i] != NULL)
	{
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		while (argv[i][j] != '\0')
		{
			if (!ft_isdigit(argv[i][j]))
				raise_error(EINVAL);
			j++;
		}
		i++;
	}
}


static void	check_duplicates(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_strcmp(argv[i], argv[j]) == 0)
				raise_error(EINVAL);
			j++;
		}
		i++;
	}
}

static void	check_integer_bounds(int argc, char *argv[])
{
	long long	num;

	if (argc <= 1)
		return ;

	num = ft_atoll(argv[1]);
	if (num > SIZE_MAX || num < SIZE_MIN)
		raise_error(EINVAL);
	check_integer_bounds(argc - 1, argv + 1);
}

void	validator(int argc, char **argv)
{
	check_numbers(argv);
	check_duplicates(argc, argv);
	check_integer_bounds(argc, argv);
}
