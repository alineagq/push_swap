/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 12:13:22 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/06/14 18:14:40 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	parsing(int argc, char **argv, t_list *stack_a)
{
    int i;
    for (i = 1; i < argc; i++)
    {
        int *num = (int *)malloc(sizeof(int));
        if (num)
        {
            *num = atoi(argv[i]);
            ft_lstadd_back(&stack_a, ft_lstnew(argv[i]));
        }
    }
}
