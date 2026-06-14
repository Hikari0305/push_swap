/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshida <hikari.y.0305@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 14:02:10 by hyoshida          #+#    #+#             */
/*   Updated: 2026/06/14 12:48:43 by hyoshida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int  check_flag(char *arg, int *mode, int *is_bench) // ★ char *arg に修正
{
    if (ft_strcmp(arg, "--simple") == 0)
        *mode = MODE_SIMPLE;       // ★ * をつける
    else if (ft_strcmp(arg, "--medium") == 0)
        *mode = MODE_MEDIUM;       // ★ * をつける
    else if (ft_strcmp(arg, "--complex") == 0)
        *mode = MODE_COMPLEX;      // ★ * をつける
    else if (ft_strcmp(arg, "--adaptive") == 0)
        *mode = MODE_ADAPTIVE;     // ★ * をつける
    else if (ft_strcmp(arg, "--bench") == 0)
        *is_bench = 1;             // ★ * をつける
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
	if (has_duplicate(*stack, value) == 1)
		return (0);
	new_node = ft_lstnew(value);
	if (!new_node)
		return (0);
	ft_lstadd_back(stack, new_node);
	return (1);
}

int	main(int argc, char **argv)
{
	char	**args;
	int		i;
	int		mode;
	int		is_bench;
	t_stack	*stack_a;

	stack_a = NULL;
	mode = MODE_ADAPTIVE;
	is_bench = 0;
	if (argc == 1)
		return (0);
	args = prepare_arguments(argc, argv);
	if (!args)
		return (0);
	i = 0;
	while (args[i] != NULL)
	{
		if (check_flag(args[i], &mode, &is_bench))
		{
			i++;
			continue ;
		}
		if (add_to_stack(&stack_a, args[i]) == 0)
			return (free_args(args), error_exit(&stack_a));
		i++;
	}
	free_args(args);
	t_stack *stack_b = NULL; 
    // --- ここから実験タイム！ ---
    sa(stack_a);              // Aの先頭2つを入れ替える
    pb(&stack_a, &stack_b);   // Aの先頭をBへプッシュ
    pb(&stack_a, &stack_b);   // もういっちょBへプッシュ
    sb(stack_b);              // Bの先頭2つを入れ替える
    ra(&stack_a);             // Aを回転
    rrb(&stack_b);            // Bを逆回転
    pa(&stack_a, &stack_b);   // Bの先頭をAに戻す
    // ----------------------------
    // 最後のお片付け
    free_stack(&stack_b);
    free_stack(&stack_a);
    // 最後のお片付け
    free_stack(&stack_b);
    free_stack(&stack_a);
	return (0);
}
