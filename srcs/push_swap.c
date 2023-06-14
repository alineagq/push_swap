/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 08:04:01 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/06/14 18:18:31 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void free_list(t_list **head)
{
    if (*head == NULL)
        return;

    t_list *current = *head;
    t_list *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }

    *head = NULL;
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	// t_list	*stack_b;

	if (argc < 2)
		return (0);
	validator(argc, argv);
	stack_a = NULL;
	parsing(argc, argv, stack_a);
	t_list *current = stack_a;
	ft_printf("%d\n", *(int *)(current->content));
    while (current != NULL)
    {
        ft_printf("%d\n", *(int *)(current->content));
        current = current->next;
    }
	ft_lstclear(&stack_a, free);
	return (0);
}
