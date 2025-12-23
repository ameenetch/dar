/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheker_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchioue <atchioue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 21:01:44 by atchioue          #+#    #+#             */
/*   Updated: 2025/12/23 00:11:01 by atchioue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cheker_bonus.h"
#include "get_next_bonus/get_next_line_bonus.h"

static	void	analyse_arg(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		cheek_string_arg(av[i]);
		i++;
	}
}

static	t_list	*make_stack(char *str, t_list **head)
{
	char	**splits;
	int		i;
	int		nbr;

	i = 0;
	splits = ft_split(str);
	if (!splits)
	{
		lst_clear(head);
		ft_error();
	}
	while (splits[i])
	{
		nbr = ft_atoi(splits[i]);
		add_back(head, nbr);
		i++;
	}
	free_memory(splits);
	return (*head);
}

static	void	do_moves_bonus(char *str, t_list **stack_a, t_list **stack_b)
{
	if (!str)
		return ;
	if (!ft_strcmp(str, "sa\n"))
		sa_move(stack_a);
	else if (!ft_strcmp(str, "sb\n"))
		sb_move(stack_b);
	else if (!ft_strcmp(str, "ss\n"))
		ss_move(stack_a,stack_b);
	else if (!ft_strcmp(str, "ra\n"))
		ra_move(stack_a);
	else if (!ft_strcmp(str, "rb\n"))
		rb_move(stack_b);
	else if (!ft_strcmp(str, "rr\n"))
		rr_bonus(stack_a, stack_b);
	else if (!ft_strcmp(str, "rra\n"))
		rra_move(stack_a);
	else if (!ft_strcmp(str, "rrb\n"))
		rrb_move(stack_b);
	else if (!ft_strcmp(str, "rrr\n"))
		rrr_bonus(stack_a, stack_b);
	else if (!ft_strcmp(str, "pa\n"))
		pa_move(stack_a, stack_b);
	else if (!ft_strcmp(str, "pb\n"))
		pb_move(stack_a, stack_b);
	else
		ft_error();
}

static	int	cheek_if_sorted(t_list **head)
{
	t_list	*current;
	t_list	*nextnode;
	int		flag;

	flag = 0;
	current = *head;
	nextnode = current->next;
	while (current)
	{
		nextnode = current->next;
		if (nextnode && current->nbr > nextnode->nbr)
		{
			flag = 1;
			break ;
		}
		current = nextnode;
	}
	if (flag)
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	int		i;
	char	*str ;
	t_list	*stacka ;
	t_list	*stack_b;

	stack_b = NULL;
	i = 1;
	if (ac >= 2)
	{
		analyse_arg(av);
		while (av[i])
		{
			make_stack(av[i], &stacka);
			i++;
		}
		cheek_double(&stacka);
		cheek_already_sorted(&stacka);
		str = get_next_line(0);
		while (str)
		{
			do_moves_bonus(str, &stacka, &stack_b);
			free(str);
			str = get_next_line(0);
		}
		if ((cheek_if_sorted(&stacka)) && (stack_b == NULL))
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
}
