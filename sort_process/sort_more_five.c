/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchioue <atchioue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 16:57:29 by atchioue          #+#    #+#             */
/*   Updated: 2025/12/20 22:01:23 by atchioue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	range(t_list **head)
{
	int	len;

	len = ft_lstsize(*head);
	if (len > 100)
		return (33);
	else if (len <= 100)
		return (16);
	return (0);
}

static int	soo_far(t_list **stack_a)
{
	int		l;
	int		count;
	t_list	*aa;

	count = 0;
	aa = (*stack_a);
	while (aa && aa->next != NULL)
	{
		l = aa->nbr - aa->next->nbr;
		if (l == 2 || l == 3 || l == 4)
		{
			count++;
		}
		aa = aa->next;
	}
	if (count >= 15 && count < 499)
		return (1);
	return (0);
}

void	part_tree(int pos, int len, t_list **stackb)
{
	if (pos <= len / 2)
	{
		while (pos > 0)
		{
			rb_move(stackb);
			pos--;
		}
	}
	else
	{
		while (pos != len)
		{
			rrb_move(stackb);
			pos++;
		}
	}
}

void	part_two(t_list **stacka, t_list **stackb)
{
	int		len ;
	int		x ;
	int		pos ;
	t_list	*a ;

	indexing(stackb);
	while (*stackb)
	{
		len = ft_lstsize(*stackb);
		x = len - 1;
		a = (*stackb);
		pos = 0;
		while (a->index != x)
		{
			pos++;
			a = a->next;
		}
		part_tree(pos, len, stackb);
		pa_move(stacka, stackb);
	}
}

void	sorting_more_five(t_list **stack_a, t_list **stack_b)
{
	int	i;
	int	rang;

	rang = range(stack_a);
	i = 0;
	indexing(stack_a);
	while (*stack_a)
	{
		if ((*stack_a)->index <= i)
		{
			pb_move(stack_a, stack_b);
			i++;
		}
		else if ((*stack_a)->index <= (i + rang))
		{
			pb_move(stack_a, stack_b);
			rb_move(stack_b);
			i++;
		}
		else if (soo_far(stack_a))
			rra_move(stack_a);
		else
			ra_move(stack_a);
	}
	part_two(stack_a, stack_b);
}
