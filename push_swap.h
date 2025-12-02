/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomin afomin@student.42kl.edu.my          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 12:32:42 by afomin            #+#    #+#             */
/*   Updated: 2025/12/02 12:59:34 by afomin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
	int		*values;
	int		size;
	char	id;
}				t_stack;

//Push_Swap
void	push_swap(t_stack *a, t_stack *b);
t_stack	*stack_create(int *values, int size, char id);

//Stack
void	stacks_rotate(int repeat, t_stack *a, t_stack *b);
void	stack_rotate(int repeat, t_stack *stack);
void	stack_push(int repeat, t_stack *from, t_stack *to);
int		distance_to_top(int size, int index);
int		target_index(int num, t_stack *a);
int		get_cost(short a_cost, short b_cost);
void	get_cheapest(t_stack *a, t_stack *b, short *a_cost, short *b_cost);

//Args
int		*convert_args(char **args, int argc);

//Utils
void	swap(int *a, int *b);
void	log_functions(char *func, char stack_id);
int		len(char *str);
int		get_max(t_stack *stack);
int		get_min(t_stack *stack);

#endif
