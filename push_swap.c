/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomin afomin@student.42kl.edu.my          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 13:11:14 by afomin            #+#    #+#             */
/*   Updated: 2025/12/02 13:24:40 by afomin           ###   ########.fr       */
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

static void	final_rotate(t_stack *a)
{
	short	min_index;

	min_index = get_min(a);
	stack_rotate(distance_to_top(min_index, a->size), a);
}

static short	get_common(short *a_cost, short *b_cost)
{
	short	common;

	common = 0;
	if ((*a_cost > 0 && *b_cost > 0) || (*a_cost < 0 && *b_cost < 0))
	{
		if (*a_cost > *b_cost)
		{
			*a_cost -= *b_cost;
			common = *b_cost;
			*b_cost = 0;
		}
		else
		{
			*b_cost -= *a_cost;
			common = *a_cost;
			*a_cost = 0;
		}
	}
	return (common);
}

void	push_swap(t_stack *a, t_stack *b)
{
	short	a_cost;
	short	b_cost;
	short	common;

	if (a->size > 2)
	{
		stack_push(a->size - 3, a, b);
		sort_3(a);
		while (b->size)
		{
			get_cheapest(a, b, &a_cost, &b_cost);
			common = get_common(&a_cost, &b_cost);
			stacks_rotate(common, a, b);
			stack_rotate(a_cost, a);
			stack_rotate(b_cost, b);
			stack_push(1, b, a);
		}
	}
	final_rotate(a);
}
