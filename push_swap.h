/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomin afomin@student.42kl.edu.my          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 12:32:42 by afomin            #+#    #+#             */
/*   Updated: 2025/11/28 16:17:16 by afomin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define BIT_32 16777216

typedef struct s_stack
{
	int		*values;
	int		size;
}				t_stack;

//Push_Swap
void	push_swap(t_stack *a, t_stack *b);

//Stack
t_stack	*stack_create(int *values, int size);
void	stack_r(t_stack *stack, char *log);
void	stack_p(t_stack *from, t_stack *to, char *log);

//Args
int		*convert_args(char **args, int argc);

//Utils
int		num_as_str_cmp(char *a, char *b);
int		is_integer(char *num);

#endif
