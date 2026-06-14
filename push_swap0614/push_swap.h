/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshida <hikari.y.0305@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 13:57:26 by hyoshida          #+#    #+#             */
/*   Updated: 2026/06/14 12:42:22 by hyoshida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#define MODE_ADAPTIVE 0
#define MODE_SIMPLE   1
#define MODE_MEDIUM   2
#define MODE_COMPLEX  3

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <stddef.h>

typedef struct  s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

void	free_stack(t_stack **stack);
int		error_exit(t_stack **stack);
void		free_args(char **args);
int		has_duplicate(t_stack *stack, int num);
int		ft_atoi_check(const char *str, int *result);
int		is_numeric(char *str);
char	**prepare_arguments(int argc, char **argv);
int		ft_isdigit(int c);
t_stack	*ft_lstnew(int value);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_lstlast(t_stack *lst);
int  ft_strcmp(const char *s1, const char *s2);
// ★ push_swap.h の中にこれを追加！
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
/* --- Swap Operations --- */
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
/* --- Push Operations --- */
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
/* --- Rotate Operations --- */
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
/* --- Reverse Rotate Operations --- */
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

#endif
