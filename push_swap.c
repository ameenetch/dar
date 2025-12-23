/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchioue <atchioue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 17:07:54 by atchioue          #+#    #+#             */
/*   Updated: 2025/12/23 00:15:45 by atchioue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include<stdio.h>

// void	display(t_list *head)
// {
// 	t_list	*current;

// 	current = head;
// 	while (current)
// 	{
// 		printf("--->%d", current->nbr);
// 		current = current->next;
// 	}
// 	printf("\n");
// }

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

static	void	sort(t_list **stacka, t_list **stackb)
{
	int	len;

	len = ft_lstsize(*stacka);
	if (len == 2)
		sorting_two(stacka);
	else if (len == 3)
		sorting_three(stacka);
	else if (len == 4)
		sorting_foor(stacka, stackb);
	else if (len == 5)
		sorting_five(stacka, stackb);
	else if (len > 5)
		sorting_more_five(stacka, stackb);
}

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

int	main(int ac, char **av)
{
	int		i;
	t_list	*stacka;
	t_list	*stackb;

	i = 1;
	stacka = NULL;
	stackb = NULL;
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
		sort(&stacka, &stackb);
		lst_clear(&stacka);
		lst_clear(&stackb);
	}
	return (0);
}
