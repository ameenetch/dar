#include"push_swap.h"
#include"get_next/get_next_line.h"
#include<stdio.h>

static	t_list	*make_stack(char *str, t_list **head)
{
	char	**splits;
	int		i;
	int		j;
	int		nbr;

	i = 0;
	j = 0;
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


void	rrr_bonus(t_list **stack_a, t_list **stack_b)
{
	rra_move(stack_a);
	rrb_move(stack_b);
}

void	rr_bonus(t_list **stack_a, t_list **stack_b)
{
	ra_move(stack_a);
	rb_move(stack_b);
}

int ft_strcmp(char *a , char *b)
{
	int i = 0;
	while(b[i] && a[i] && a[i] == b[i])
		i++;
	return (unsigned char)a[i] - (unsigned char)b[i];
}

void	do_moves_bonus(char *str, t_list **stack_a, t_list **stack_b)
{
	if (!str)
		return ;
	if (!ft_strcmp(str, "sa\n"))
		sa_move(stack_a);
	else if (!ft_strcmp(str, "sb\n"))
		sb_move(stack_b);
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

int	cheek_if_sorted(t_list **head)
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
		return 0 ;
	return 1;
}

////////////////////////////////////////////////////////////////////////////////////////////




void	display(t_list *head)
{
	t_list	*current;

	current = head;
	while (current)
	{
		printf("--->%d", current->nbr);
		current = current->next;
	}
	printf("\n");
}


int main(int ac , char **av)
{
	int i;
	t_list *stacka = NULL;
	t_list	*stack_b = NULL;
	char *str = "";

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
		char *str;

		while ((str = get_next_line(0)))
		{
			do_moves_bonus(str, &stacka, &stack_b);
			free(str);
		}

		if (cheek_if_sorted(&stacka) && stack_b == NULL)
			printf("OK\n");
		else
			printf("KO\n");
	}

}
