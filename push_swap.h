/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomin <alexhysel@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 12:32:42 by afomin            #+#    #+#             */
/*   Updated: 2025/11/23 19:09:22 by afomin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

typedef struct s_stack
{
	int		*values;
	int		size;
	void	(*s)(struct s_stack *stack);
}				t_stack;

//Stack
void	stack_init(t_stack *stack, int *values, int size);
void	stack_s(t_stack *stack);
void	stack_r(t_stack *stack);
void	stack_rr(t_stack *stack);
void	stack_p(t_stack *from, t_stack *to);

//Utils
void	swap(int *a, int *b);
int		erase_max(char **nums);

#endif
