/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomin afomin@student.42kl.edu.my          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 13:11:14 by afomin            #+#    #+#             */
/*   Updated: 2025/11/30 17:18:58 by afomin           ###   ########.fr       */
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

/*
static int	is_sorted(t_stack *a, t_stack *b)
{
	int	*values;
	int	i;

	if (b->size)
		return (0);
	values = a->values;
	if (!values)
		return (0);
	i = 0;
	while (++i < a->size)
		if (values[i - 1] > values[i])
			return (0);
	return (1);
}
*/
void	push_swap(t_stack *a, t_stack *b)
{
	stack_push(a->size - 3, a, b);
}
