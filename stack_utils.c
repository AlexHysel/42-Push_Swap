/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomin afomin@student.42kl.edu.my          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 15:37:40 by afomin            #+#    #+#             */
/*   Updated: 2025/12/01 19:03:40 by afomin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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

void	get_cheapest(t_stack *a, t_stack *b, short *a_cost, short *b_cost)
{
	short	a_;
	short	b_;
	short	b_steps;
	short	a_steps;
	char	flag;

	b_ = -1;
	flag = 1;
	while (++b_ < b->size)
	{
		a_ = target_index(b->values[b_], a);
		a_steps = distance_to_top(a_, a->size);
		b_steps = distance_to_top(b_, b->size);
		if (flag || get_cost(a_steps, b_steps) < get_cost(*a_cost, *b_cost))
		{
			*a_cost = a_steps;
			*b_cost = b_steps;
			flag = 0;
		}
	}
}
