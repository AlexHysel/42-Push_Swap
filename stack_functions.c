/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomin <alexhysel@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 12:48:23 by afomin            #+#    #+#             */
/*   Updated: 2025/11/24 15:32:47 by afomin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	i = 1;
	while (i < size)
		swap(&values[0], &values[i++]);
	printstr(log);
}

void	stack_p(t_stack *from, t_stack *to, char *log)
{
	int	value;
	int	*new_f;
	int	*new_t;
	int	i;

	value = from->values[from->size - 1];
	new_f = malloc(sizeof(int) * (from->size - 1));
	new_t = malloc(sizeof(int) * (to->size + 1));
	i = -1;
	while (++i < from->size - 1)
		new_f[i] = from->values[i];
	free(from->values);
	from->values = new_f;
	from->size--;
	i = -1;
	while (++i < to->size)
		new_t[i] = to->values[i];
	new_t[i] = value;
	free(to->values);
	to->values = new_t;
	to->size++;
	printstr(log);
}
