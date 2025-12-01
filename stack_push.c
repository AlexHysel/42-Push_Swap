/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomin afomin@student.42kl.edu.my          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 15:24:16 by afomin            #+#    #+#             */
/*   Updated: 2025/12/01 17:28:27 by afomin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static void	stack_p(t_stack *from, t_stack *to)
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
	log_functions("p", to->id);
}

void	stack_push(int repeat, t_stack *from, t_stack *to)
{
	while (repeat-- > 0)
		stack_p(from, to);
}
