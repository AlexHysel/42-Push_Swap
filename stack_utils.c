/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomin afomin@student.42kl.edu.my          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 15:37:40 by afomin            #+#    #+#             */
/*   Updated: 2025/11/30 17:57:48 by afomin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max(t_stack *stack)
{
	int	max;
	int	i;

	max = 0;
	i = -1;
	while (++i <= stack->size)
		if (stack->values[i] > stack->values[max])
			max = i;
	return (max);
}

int	distance_to_top(int size, int index)
{
	if (index > size / 2)
		return (-index + 1);
	else
		return (index);
}

int	get_target(int num, t_stack *a)
{
	int	target;
	int	i;

	target = 0;
	i = -1;
	while (++i < a->size)
		if (a->values[i] <= a->values[target] && a->values[i] >= num)
			target = i;
	if (a->values[target] < num)
		return (0);
	return (target);
}

int	get_cost(int a_cost, int b_cost)
{
	if (a_cost < 0)
		a_cost = -a_cost;
	if (b_cost < 0)
		b_cost = -b_cost;
	return (b_cost + a_cost);
}
