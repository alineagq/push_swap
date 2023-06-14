/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 10:26:33 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/06/14 10:08:58 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	check_numbers(char **argv)
{
	int		i;

	i = 1;
	while (argv[i])
	{
		if (*argv[i] == '-' || *argv[i] == '+')
			argv[i]++;
		while (ft_isdigit(*argv[i]))
			argv[i]++;
		if (*argv[i] != '\0')
			raise_error(EINVAL);
		i++;
	}
}

void find_duplicate(char **args)
{
    int i = 1;

    while (args[i] != NULL)
    {
        int j = i + 1;

        while (args[j] != NULL)
        {
            int num1 = ft_atoi(args[i]);
            int num2 = ft_atoi(args[j]);

            if (num1 == num2)
            {
                ft_printf("Error: Duplicate numbers found!\n");
                exit(1);
            }

            j++;
        }

        i++;
    }
}

void invalid_int(char **argv)
{
	int i = 1;

	while (argv[i])
	{
		const char *num = argv[i];
		int places = 0;
		char c;

		if (*num == '-' || *num == '+')
			num++;

		while ((c = num[places]))
		{
			if (!ft_isdigit(c))
			{
				ft_printf("Error: Invalid number format!\n");
				exit(1);
			}

			places++;
		}

		ssize_t n = ft_atoi(argv[i]);

		if (places > 10 || n < -(long)((unsigned int)(1 << 31)) || n > (ssize_t)((unsigned int)~(1 << 31)))
		{
			ft_printf("Error: Invalid integer value!\n");
			exit(1);
		}

		i++;
	}
}

void validator(char **argv)
{
	check_numbers(argv);
	find_duplicate(argv);
	invalid_int(argv);
}
