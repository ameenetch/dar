/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchioue <atchioue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 22:23:14 by atchioue          #+#    #+#             */
/*   Updated: 2025/12/17 21:46:47 by atchioue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	exist_new_line(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0 ;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char	*makebuffre(int fd, char *buffer)
{
	ssize_t	index ;
	char	*new_joint ;

	new_joint = malloc((size_t)BUFFER_SIZE + 1);
	if (!new_joint)
		return (NULL);
	while (!exist_new_line(buffer))
	{
		index = read(fd, new_joint, BUFFER_SIZE);
		if (index < 0)
		{
			free(buffer);
			buffer = NULL;
			break ;
		}
		if (index == 0)
			break ;
		new_joint[index] = '\0' ;
		buffer = ft_strjoint(buffer, new_joint);
	}
	free (new_joint);
	return (buffer);
}

static char	*set_buffer_for_next(char *buffer )
{
	int		i ;
	int		j ;
	char	*updated ;

	i = 0 ;
	j = 0 ;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	if (!buffer[i])
		return (free(buffer), NULL);
	updated = malloc(strleen(buffer) - i + 1);
	if (!updated)
		return (free(buffer), NULL);
	while (buffer[i])
		updated[j++] = buffer[i++];
	updated[j] = '\0';
	free(buffer);
	return (updated);
}

static char	*get_that_line(char *line)
{
	int		i ;
	int		j ;
	char	*final_line;

	if (!line)
		return (NULL);
	i = unltil_end(line);
	final_line = malloc(i + 1);
	if (!final_line)
		return (NULL);
	i = 0 ;
	j = 0 ;
	while (line[i])
	{
		if (line[i] == '\n')
		{
			final_line[j++] = '\n';
			break ;
		}
		final_line[j++] = line[i++];
	}
	return (final_line[j] = '\0', final_line);
}

char	*get_next_line(int fd)
{
	static char	*buffer ;
	char		*next_line ;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = makebuffre(fd, buffer);
	if (!buffer)
		return (NULL);
	next_line = get_that_line(buffer);
	if (!next_line)
	{
		free (buffer);
		return (NULL);
	}
	buffer = set_buffer_for_next(buffer);
	return (next_line);
}
