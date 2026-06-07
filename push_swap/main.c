/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshida <hikari.y.0305@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 14:02:10 by hyoshida          #+#    #+#             */
/*   Updated: 2026/05/30 14:31:36 by hyoshida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    free_stack(t_stack **stack)
{
    t_stack *current;
    t_stack *next_node;

    if (!stack || !*stack)
        return ;
    current = *stack;
    while (current != NULL)
    {
        next_node = current->next;
        free(current);
        current = next_node;
    }
    *stack = NULL;
}

int error_exit(t_stack **stack)
{
    free_stack(stack);
    write(2, "Error\n", 6);
    return (1); 
}

static int  has_duplicate(t_stack *stack, int num)
{
    while (stack != NULL)
    {
        if (stack->value == num)
            return (1);
        stack = stack->next;
    }
    return (0);
}

static int  ft_atoi_check(const char *str, int *result)
{
    long long   num;
    int         sign;
    int         i;

    num = 0;
    sign = 1;
    i = 0;
    if (str[i] == '+' || str[i] == '-')
    {
        if (str[i++] == '-')
            sign = -1;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        num = num * 10 + (str[i++] - '0');
        if ((sign == 1 && num > INT_MAX)
            || (sign == -1 && (-num) < INT_MIN))
            return (0);
    }
    *result = (int)(num * sign);
    return (1);
}

static int  is_numeric(char *str)
{
    int i;

    i = 0;
    if (str[i] == '-' || str[i] == '+')
        i++;
    if (str[i] == '\0')
        return (0);
    while (str[i] != '\0')
    {
        if (ft_isdigit(str[i]) == 0)
            return (0);
        i++;
    }
    return (1);
}

int main(int argc, char **argv)
{
    int     i;
    int     value;
    t_stack *stack_a;
    t_stack *new_node;

    stack_a = NULL;
    if (argc == 1)
        return (0);
    i = 1;
    while (i < argc)
    {
        if (is_numeric(argv[i]) == 0 || ft_atoi_check(argv[i], &value) == 0)
            return (error_exit(&stack_a));
        if (has_duplicate(stack_a, value) == 1)
            return (error_exit(&stack_a));
        new_node = ft_lstnew(value);
        if (!new_node)
            return (error_exit(&stack_a));
        
        ft_lstadd_back(&stack_a, new_node);
        i++;
    }
    free_stack(&stack_a);
    return (0);
}