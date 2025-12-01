/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomin afomin@student.42kl.edu.my          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 13:11:14 by afomin            #+#    #+#             */
/*   Updated: 2025/12/01 19:23:14 by afomin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

t_stack	*stack_create(int *values, int size, char id)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (stack)
	{
		stack->values = values;
		stack->size = size;
		stack->id = id;
	}
	return (stack);
}

static void	sort_3(t_stack *a)
{
	int	max;

	max = get_max(a);
	if (max == 0)
		stack_rotate(1, a);
	else if (max == 1)
		stack_rotate(-1, a);
	if (a->values[0] > a->values[1])
	{
		swap(&a->values[0], &a->values[1]);
		log_functions("s", a->id);
	}
}

void	final_rotate(t_stack *a)
{
	short	min_index;

	min_index = get_min(a);
	stack_rotate(distance_to_top(min_index, a->size), a);
}

void	push_swap(t_stack *a, t_stack *b)
{
	short	a_cost;
	short	b_cost;

	stack_push(a->size - 3, a, b);
	sort_3(a);
	while (b->size)
	{
		get_cheapest(a, b, &a_cost, &b_cost);
		if ((a_cost >= 0 && b_cost >= 0) || (a_cost < 0 && b_cost < 0))
		{
			if (a_cost >= b_cost)
			{
				a_cost -= b_cost;
				stacks_rotate(b_cost, a, b);
				b_cost = 0;
			}
			else if (b_cost > a_cost)
			{
				b_cost -= a_cost;
				stacks_rotate(a_cost, a, b);
				a_cost = 0;
			}
		}
		stack_rotate(a_cost, a);
		stack_rotate(b_cost, b);
		stack_push(1, b, a);
	}
	final_rotate(a);
}
