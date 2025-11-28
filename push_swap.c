/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomin afomin@student.42kl.edu.my          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 13:11:14 by afomin            #+#    #+#             */
/*   Updated: 2025/11/28 16:22:29 by afomin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	max_bit(int *nums, int len)
{
	int				max;
	unsigned int	bit;

	max = -1;
	while (--len >= 0)
		if (max < nums[len])
			max = nums[len];
	if (!max)
		return (1);
	bit = BIT_32;
	while (!(max & bit))
		bit /= 2;
	return (bit);
}

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

void	push_swap(t_stack *a, t_stack *b)
{
	unsigned int	bit;
	unsigned int	m_bit;
	int				i;
	int				size;

	bit = 1;
	m_bit = max_bit(a->values, a->size);
	size = a->size;
	while (bit <= m_bit && !is_sorted(a, b))
	{
		i = 0;
		while (i++ < size && !is_sorted(a, b))
		{
			if (a->values[0] & bit)
				stack_r(a, "ra\n");
			else
				stack_p(a, b, "pb\n");
		}
		while (b->size > 0)
			stack_p(b, a, "pa\n");
		bit *= 2;
	}
}
