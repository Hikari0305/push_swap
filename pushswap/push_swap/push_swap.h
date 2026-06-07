/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshida <hikari.y.0305@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 13:57:26 by hyoshida          #+#    #+#             */
/*   Updated: 2026/06/07 14:06:20 by hyoshida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

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

#endif
