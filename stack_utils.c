/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomin afomin@student.42kl.edu.my          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 15:37:40 by afomin            #+#    #+#             */
/*   Updated: 2025/12/01 17:32:49 by afomin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	get_max(t_stack *stack)
{
	int	max;
	int	i;

	max = 0;
	i = 0;
	while (++i < stack->size)
		if (stack->values[i] > stack->values[max])
			max = i;
	return (max);
}

int	get_min(t_stack *stack)
{
	int	min;
	int	i;

	min = 0;
	i = 0;
	while (++i < stack->size)
		if (stack->values[i] < stack->values[min])
			min = i;
	return (min);
}

int	distance_to_top(int index, int size)
{
	if (index > size / 2)
		return (index - size);
	else
		return (index);
}

int	target_index(int num, t_stack *a)
{
	int	target;
	int	i;

	target = get_max(a);
	i = -1;
	while (++i < a->size)
		if (a->values[i] < a->values[target] && a->values[i] > num)
			target = i;
	if (a->values[target] < num)
		target = get_min(a);
	return (target);
}

int	get_cost(short a_cost, short b_cost)
{
	if (a_cost < 0)
		a_cost = -a_cost;
	if (b_cost < 0)
		b_cost = -b_cost;
	return (b_cost + a_cost);
}

int	get_cheapest(t_stack *a, t_stack *b, short *a_cost)
{
	short	b_cost;
	short	b_steps;
	short	a_steps;
	char	flag = 1;

	b_steps = -1;
	while (++b_steps < b->size)
	{
		a_steps = target_index(b->values[b_steps], a);
		if (flag || get_cost(a_steps, b_steps) < get_cost(*a_cost, b_cost))
		{
			*a_cost = distance_to_top(a_steps, a->size);
			b_cost = distance_to_top(b_steps, b->size);
			flag = 0;
		}
	}
	return (b_cost);
}
