/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchioue <atchioue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 18:12:02 by atchioue          #+#    #+#             */
/*   Updated: 2025/12/16 18:12:02 by atchioue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_list
{
	int				nbr;
	int				index;
	struct s_list	*next;
}	t_list;

/* ************************UTILS****************************** */
int		push_swap(int ac, char **av);
char	**ft_split(char *str);
int		checker(char *str);
int		sps(char c);
void	free_memory(char **split);
int		ft_atoi(const char *str);
void	ft_error(void);
void	indexing(t_list **head);
int		cheek_integer_forme(char *str);
int		ft_strlen(char *str);
void	cheek_string_arg(char *str);
void	cheek_already_sorted(t_list **head);
void	cheek_double(t_list **head);

/* ***********************LINKED LISTS******************************* */

int		ft_lstsize(t_list *head);
t_list	*find_top(t_list *head);
void	remove_first(t_list **head);
t_list	*find_last(t_list *head);
t_list	*find_pre_last(t_list *head);
void	add_back(t_list **head, int data);
void	lst_clear(t_list **head);
void	add_head(t_list **head, int data);

/* ****************************MOVES************************** */

void	sa_move(t_list **head);
void	sb_move(t_list **head);
void	ss_move(t_list **head, t_list **headB);

void	ra_move(t_list **head);
void	rb_move(t_list **head);
void	rr_move(t_list **head, t_list **headB);

void	rra_move(t_list **head);
void	rrb_move(t_list **head);
void	rrr_move(t_list **head, t_list **headB);

void	pa_move(t_list **headA, t_list **headB);
void	pb_move(t_list **stackB, t_list **headA);

/* *******************************SORTING*********************** */

void	sorting_two(t_list **head);
void	sorting_three(t_list **head);
void	sorting_foor(t_list **stackA, t_list **stackB);
void	sorting_five(t_list **stackA, t_list **stackB);
void	sorting_more_five(t_list **stack_a, t_list **stack_b);

/* ****************************************************** */

#endif
