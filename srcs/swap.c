/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:43:15 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/06/14 18:23:20 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap_a(t_list *stack_a)
{
	t_list	*aux;
	t_list	*aux2;

	aux = *stack_a;
	aux2 = aux->next;
	*stack_a = aux2;
	aux->next = aux2->next;
	aux2->next = aux;
	write(1, "sa\n", 3);
}

void	swap_b(t_list *stack_b)
{
	t_list	*aux;
	t_list	*aux2;

	aux = *stack_b;
	aux2 = aux->next;
	*stack_b = aux2;
	aux->next = aux2->next;
	aux2->next = aux;
	write(1, "sb\n", 3);
}

void	swap_s(t_list *stack_a, t_list *stack_b)
{
	t_list	*aux;
	t_list	*aux2;

	aux = *stack_a;
	aux2 = aux->next;
	*stack_a = aux2;
	aux->next = aux2->next;
	aux2->next = aux;
	aux = NULL;
	aux2 = NULL;
	aux = *stack_b;
	aux2 = aux->next;
	*stack_b = aux2;
	aux->next = aux2->next;
	aux2->next = aux;
	write(1, "ss\n", 3);
}
