/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chekker_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchioue <atchioue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:33:56 by atchioue          #+#    #+#             */
/*   Updated: 2025/12/17 16:51:42 by atchioue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_memory(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	cheek_integer_forme(char *str)
{
	int	nbr ;

	nbr = ft_atoi(str);
	return (0);
}

int	sps(char c)
{
	return (9 <= c && c <= 13 || c == 32);
}
