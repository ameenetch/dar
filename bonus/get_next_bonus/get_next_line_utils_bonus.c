/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchioue <atchioue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 15:21:29 by atchioue          #+#    #+#             */
/*   Updated: 2025/12/22 23:48:54 by atchioue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	strleen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	char	*new;
	int		i;

	if (!str)
		return (NULL);
	i = 0;
	new = malloc (strleen(str) + 1);
	if (!new)
		return (NULL);
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

int	unltil_end(char *str)
{
	int	i ;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	return (i);
}

char	*ft_strjoint(char *a, char *b)
{
	int		i;
	char	*new;

	i = 0 ;
	if (!a && !b)
		return (NULL);
	else if (!a)
		return (ft_strdup(b));
	else if (!b)
		return (ft_strdup(a));
	new = malloc(strleen(a) + strleen(b) + 1);
	if (!new)
		return (free(a), NULL);
	while (a[i])
	{
		new[i] = a[i];
		i++;
	}
	while (*b)
		new[i++] = *(b++);
	new[i] = '\0';
	free(a);
	return (new);
}
