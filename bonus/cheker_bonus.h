/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheker_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchioue <atchioue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 22:05:42 by atchioue          #+#    #+#             */
/*   Updated: 2025/12/23 17:46:23 by atchioue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHEKER_BONUS_H
# define CHEKER_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_list
{
	int				nbr;
	int				index;
	struct s_list	*next;
}	t_list;

/* ****************************MOVES************************** */

void	rr_bonus(t_list **stack_a, t_list **stack_b);
void	rb_move(t_list **stackb);
void	ra_move(t_list **stacka);

void	pa_move(t_list **stack_a, t_list **stack_b);
void	pb_move(t_list **stack_a, t_list **stack_b);

void	rra_move(t_list **stacka);
void	rrb_move(t_list **stackb);
void	rrr_bonus(t_list **stack_a, t_list **stack_b);

void	sa_move(t_list **head);
void	sb_move(t_list **head);
void	ss_move(t_list **heada, t_list **headb);

/* ************************UTILS****************************** */

int		ft_strcmp(char *a, char *b);
int		checker(char *str);
int		cheek_integer_forme(char *str);
void	free_memory(char **split);
void	cheek_string_arg(char *str);
char	**ft_split(char *str);
int		ft_atoi(const char *str);
void	ft_error(void);
int		ft_strlen(char *str);
int		sps(char c);
void	cheek_double(t_list **head);
void	cheek_already_sorted(t_list **head);
int		cheek_if_sorted(t_list **head);

/* ***********************LINKED LISTS******************************* */

void	lst_clear(t_list **head);
void	add_back(t_list **head, int data);
t_list	*find_last(t_list *head);
t_list	*find_pre_last(t_list *head);
t_list	*create_node(int data);

#endif
