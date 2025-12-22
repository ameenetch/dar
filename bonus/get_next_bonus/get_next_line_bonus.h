/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchioue <atchioue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 22:10:10 by atchioue          #+#    #+#             */
/*   Updated: 2025/12/22 23:53:40 by atchioue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 7
# endif

# include <unistd.h>
# include <stdlib.h>

char	*ft_strjoint(char *a, char *b);
int		strleen(char *str);
char	*ft_strdup(char *str);
char	*get_next_line(int fd);
int		unltil_end(char *str);

#endif
