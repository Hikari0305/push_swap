/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshida <hikari.y.0305@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 11:15:53 by hyoshida          #+#    #+#             */
/*   Updated: 2026/06/14 12:46:48 by hyoshida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sa (Swap A) の修正
void    sa(t_stack *stack_a)
{
    int tmp;

    if (!stack_a || !stack_a->next)
        return ;
    tmp = stack_a->value;
    stack_a->value = stack_a->next->value;
    stack_a->next->value = tmp; // ★ l を足して value に修正！
    write(1, "sa\n", 3);
}

// pb (Push B) の修正
void    pb(t_stack **stack_a, t_stack **stack_b) // ★ ここを両方とも ** (ダブルポインタ) にする！
{
    t_stack *tmp;

    if (!stack_a || !*stack_a)
        return ;
    tmp = *stack_a;
    *stack_a = (*stack_a)->next; // ★ これでこの行のエラーも消えます！
    tmp->next = *stack_b;
    *stack_b = tmp;
    write(1, "pb\n", 3);
}

// sb: 引数の名前を「stack_b」にする！
void    sb(t_stack *stack_b)
{
    int tmp;

    if (!stack_b || !stack_b->next)
        return ;
    tmp = stack_b->value;
    stack_b->value = stack_b->next->value;
    stack_b->next->value = tmp;
    write(1, "sb\n", 3);
}

// ss: 第2引数の名前を「stack_b」にする！
void    ss(t_stack *stack_a, t_stack *stack_b)
{
    int tmp;

    if (stack_a && stack_a->next)
    {
        tmp = stack_a->value;
        stack_a->value = stack_a->next->value;
        stack_a->next->value = tmp;
    }
    if (stack_b && stack_b->next)
    {
        tmp = stack_b->value;
        stack_b->value = stack_b->next->value;
        stack_b->next->value = tmp;
    }
    write(1, "ss\n", 3);
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if (!stack_b || !*stack_b)
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = *stack_a;
	*stack_a = tmp;
	write(1, "pa\n", 3);
}

static void	pure_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = first->next;
	first->next = NULL;
	
	// ★ ここからの last の扱いを修正！
	last = *stack; // 最初は先頭の住所を入れる
	while (last->next != NULL) // 一番後ろにたどり着くまでループ
		last = last->next;
	last->next = first; // 一番後ろの次に、元1番目を繋ぐ
}

void	ra(t_stack **stack_a)
{
	pure_rotate(stack_a);
	write(1, "ra\n", 3);
}

void	rb(t_stack **stack_b)
{
	pure_rotate(stack_b);
	write(1, "rb\n", 3);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	pure_rotate(stack_a);
	pure_rotate(stack_b);
	write(1, "rr\n", 3);
}

static void	pure_reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*prev;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	prev = NULL;
	last = *stack; // ★ *stack を代入
	while (last->next != NULL)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack; // ★ *stack に繋ぐ
	*stack = last;
}

void	rra(t_stack **stack_a)
{
	pure_reverse_rotate(stack_a); // ★ reverse になっているか確認！
	write(1, "rra\n", 4);
}

void	rrb(t_stack **stack_b)
{
	pure_reverse_rotate(stack_b); // ★ reverse にして、中身も stack_b に！
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	pure_reverse_rotate(stack_a); // ★ reverse に！
	pure_reverse_rotate(stack_b); // ★ reverse に！
	write(1, "rrr\n", 4);
}
