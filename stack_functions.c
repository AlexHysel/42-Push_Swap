/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomin <alexhysel@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 12:48:23 by afomin            #+#    #+#             */
/*   Updated: 2025/11/23 19:21:36 by afomin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_init(t_stack *stack, int *values, int size)
{
	stack->values = values;
	stack->size = size;
	stack->s = stack_s;
}

void	stack_s(t_stack *stack)
{
	int	size;
	int	*values;

	size = stack->size;
	values = stack->values;
	if (values && size >= 2)
		swap(&values[size - 1], &values[size - 2]);
}

void	stack_r(t_stack *stack)
{
	int	size;
	int	*values;
	int	i;

	size = stack->size;
	values = stack->values;
	i = 1;
	while (i < size)
		swap(&values[0], &values[i++]);
}

void	stack_rr(t_stack *stack)
{
	int	end_i;
	int	*values;
	int	i;

	end_i = stack->size - 1;
	values = stack->values;
	i = end_i - 1;
	while (i >= 0)
		swap(&values[end_i], &values[i--]);
}

void	stack_p(t_stack *from, t_stack *to)
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
}
