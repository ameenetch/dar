/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheker_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchioue <atchioue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 21:01:44 by atchioue          #+#    #+#             */
/*   Updated: 2025/12/23 17:53:55 by atchioue         ###   ########.fr       */
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
	if (!ft_strcmp(str, "sa\n"))
		sa_move(stack_a);
	else if (!ft_strcmp(str, "sb\n"))
		sb_move(stack_b);
	else if (!ft_strcmp(str, "ss\n"))
		ss_move(stack_a, stack_b);
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

static	void	doing_moves(t_list **stacka, t_list **stack_b)
{
	char	*str;

	str = get_next_line(0);
	while (str)
	{
		do_moves_bonus(str, stacka, stack_b);
		free(str);
		str = get_next_line(0);
	}
	free(str);
}

int	main(int ac, char **av)
{
	int		i;
	t_list	*stacka ;
	t_list	*stack_b;

	stack_b = NULL;
	stacka = NULL;
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
		doing_moves(&stacka, &stack_b);
		if ((cheek_if_sorted(&stacka)) && (stack_b == NULL))
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
		lst_clear(&stacka);
		lst_clear(&stack_b);
	}
}
