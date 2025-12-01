/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomin <alexhysel@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 12:57:47 by afomin            #+#    #+#             */
/*   Updated: 2025/12/01 18:56:04 by afomin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

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

int	len(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	log_functions(char *func, char stack_id)
{
	char	nl;

	nl = '\n';
	while (*func)
		write(1, func++, 1);
	write(1, &stack_id, 1);
	write(1, &nl, 1);
}
