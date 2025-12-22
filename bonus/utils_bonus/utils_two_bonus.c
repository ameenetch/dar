/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchioue <atchioue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 22:09:24 by atchioue          #+#    #+#             */
/*   Updated: 2025/12/22 23:55:55 by atchioue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cheker_bonus.h"

int	empthy_str(char *str)
{
	if (*str == '\0')
		return (1);
	return (0);
}

int	space_string(char *str)
{
	int	i;
	int	cnt;

	i = 0 ;
	cnt = 0;
	while (str[i])
	{
		if (!sps(str[i]))
			cnt++;
		i++;
	}
	if (cnt)
		return (0);
	return (1);
}

int	double_signed(char *str)
{
	int	i ;
	int	cnt ;
	int	flag ;

	i = 0 ;
	cnt = 0 ;
	flag = 1 ;
	while (str[i])
	{
		if ((str[i] == '+' || str[i] == '-')
			&& !('0' <= str[i + 1] && str[i + 1] <= '9'))
			return (1);
		else if ((str[i] == '+' || str[i] == '-') && flag)
			flag = 0 ;
		else if ((str[i] == '+' || str[i] == '-') && !flag)
			return (1);
		i++;
	}
	return (0);
}

int	alpha_exist(char *str)
{
	int	i;

	i = 0 ;
	while (str[i])
	{
		if (('0' <= str[i] && str[i] <= '9') || str[i] == '+' || str[i] == '-')
			i++;
		else
			return (1);
	}
	return (0);
}

int	checker(char *str)
{
	if (!str || empthy_str(str) || double_signed(str) || space_string(str)
		|| alpha_exist(str) || cheek_integer_forme(str))
		return (0);
	return (1);
}
