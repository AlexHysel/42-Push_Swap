/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomin afomin@student.42kl.edu.my          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 12:48:23 by afomin            #+#    #+#             */
/*   Updated: 2025/11/30 18:10:20 by afomin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>

static void	stack_r(t_stack *stack, int display)
{
	int	size;
	int	*values;
	int	i;

	size = stack->size;
	values = stack->values;
	i = size;
	while (i > 0)
		swap(&values[0], &values[--i]);
	if (display)
		log_functions("r", stack->id);
}

static void	stack_rr(t_stack *stack, int display)
{
	int	last_index;
	int	*values;
	int	i;

	last_index = stack->size - 1;
	values = stack->values;
	i = -1;
	while (++i < last_index)
		swap(&values[i], &values[last_index]);
	if (display)
		log_functions("rr", stack->id);
}

void	stacks_rotate(int repeat, t_stack *a, t_stack *b)
{
	if (repeat < 0)
	{
		while (repeat++ < 0)
		{
			stack_rr(a, 0);
			stack_rr(b, 0);
			log_functions("rr", 'r');
		}
	}
	else
	{
		while (repeat-- > 0)
		{
			stack_r(a, 0);
			stack_r(b, 0);
			log_functions("r", 'r');
		}
	}
}

void	stack_rotate(int repeat, t_stack *stack)
{
	if (repeat < 0)
		while (repeat++ < 0)
			stack_rr(stack, 1);
	else
		while (repeat-- > 0)
			stack_r(stack, 1);
}
