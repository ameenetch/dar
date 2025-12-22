/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchioue <atchioue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:48:22 by atchioue          #+#    #+#             */
/*   Updated: 2025/12/16 17:48:22 by atchioue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cheker_bonus.h"

int	counte_words(char *str)
{
	int	i ;
	int	cnt ;

	i = 0 ;
	cnt = 0 ;
	while (str[i])
	{
		while (str[i] && sps(str[i]))
			i++;
		if (str[i])
		{
			cnt++;
			while (str[i] && !sps(str[i]))
				i++;
		}
	}
	return (cnt);
}

void	full(char *dest, char *src, int len)
{
	int	i ;

	i = 0;
	while (*src && i < len)
	{
		*(dest + i) = *(src + i);
		i++;
	}
	dest[i] = '\0';
}

int	allocat_and_full(char **rslt, char *str)
{
	int	j ;
	int	len ;

	j = 0 ;
	while (*str)
	{
		while (*str && sps(*str))
			str++;
		if (*str)
		{
			len = 0 ;
			while (*str && !sps(*str))
			{
				str++;
				len++;
			}
			rslt[j] = malloc(len + 1);
			if (!rslt[j])
				free_memory(rslt);
			full(rslt[j++], str - len, len);
		}
	}
	rslt[j] = NULL ;
	return (1);
}

char	**process(char *str, char **rslt, int words)
{
	rslt = malloc(sizeof(char *) * 2);
	if (!rslt)
		return (NULL);
	rslt[0] = malloc(ft_strlen(str) + 1);
	if (!rslt[0])
	{
		free_memory(rslt);
		return (NULL);
	}
	full(rslt[0], str, ft_strlen(str));
	rslt[1] = NULL;
	return (rslt);
}

char	**ft_split(char *str)
{
	char	**rslt ;
	int		words ;

	if (!str)
		return (NULL);
	words = counte_words(str) + 1;
	if (words == 1)
		return (process(str, rslt, words));
	rslt = malloc(sizeof(char *) * words);
	if (!rslt)
		return (NULL);
	if (!allocat_and_full(rslt, str))
		return (NULL);
	return (rslt);
}
