/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomin afomin@student.42kl.edu.my          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 12:48:23 by afomin            #+#    #+#             */
/*   Updated: 2025/11/28 16:17:52 by afomin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "unistd.h"
#include <stdlib.h>

static void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

t_stack	*stack_create(int *values, int size)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (stack)
	{
		stack->values = values;
		stack->size = size;
	}
	return (stack);
}

void	stack_r(t_stack *stack, char *log)
{
	int	size;
	int	*values;
	int	i;

	size = stack->size;
	values = stack->values;
	i = size;
	while (i > 0)
		swap(&values[0], &values[--i]);
	while (*log)
		write(1, log++, 1);
}

void	stack_p(t_stack *from, t_stack *to, char *log)
{
	int	value;
	int	*new_f;
	int	*new_t;
	int	i;

	value = from->values[0];
	new_f = malloc(sizeof(int) * (from->size - 1));
	new_t = malloc(sizeof(int) * (to->size + 1));
	i = 0;
	while (++i < from->size)
		new_f[i - 1] = from->values[i];
	free(from->values);
	from->values = new_f;
	from->size--;
	i = 0;
	new_t[0] = value;
	while (++i <= to->size)
		new_t[i] = to->values[i - 1];
	free(to->values);
	to->values = new_t;
	to->size++;
	while (*log)
		write(1, log++, 1);
}
