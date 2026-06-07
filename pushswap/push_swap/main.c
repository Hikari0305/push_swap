/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshida <hikari.y.0305@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 14:02:10 by hyoshida          #+#    #+#             */
/*   Updated: 2026/06/07 14:04:44 by hyoshida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_flag(char **arg, int *mode, int *is_bench)
{
	if (ft_strcmp(argv[i], "--simple") == 0)
		mode = MODE_SIMPLE;
	else if (ft_strcmp(argv[i], "--medium") == 0)
		mode = MODE_MEDIUM;
	else if (ft_strcmp(argv[i], "--complex") == 0)
		mode = MODE_COMPLEX;
	else if (ft_strcmp(argv[i], "--adaptive") == 0)
		mode = MODE_ADAPTIVE;
	else if (ft_strcmp(argv[i], "--bench") == 0)
		is_bench = 1;
	else
		return (0);
	return (1);
}

static int	add_to_stack(t_stack **stack, char *arg)
{
	int		value;
	t_stack	*new_node;

	if (is_numeric(arg) == 0 || ft_atoi_check(arg, &value) == 0)
		return (0);
	if (has_duplicate(*stack_a, value) == 1)
		return (0);
	new_node = ft_lstnew(value);
	if (!new_node)
		return (0);
	ft_lstadd_back(stack_a, new_node);
	return (1);
}

int	main(int argc, char **argv)
{
	char	**args;
	int		i;
	int		value;
	int		mode;
	int		is_bench;
	t_stack	*stack_a;

	stack_a = NULL;
	mode = MODE_ADAPTIVE;
	is_bench = 0;
	if (argc == 1)
		return (0);
	i = 1;
	while (i < argc)
	{
		if (check_flag(args[i], &mode, &is_bench))
			continue ;
		if (add_to_stack(&stack_a, args[i]) == 0)
			return (free_args(args), error_exit(&stack_a));
		i++;
	}
	free_args(args);
	free_stack(&stack_a);
	return (0);
}
