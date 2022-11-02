/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:46:46 by skoulen           #+#    #+#             */
/*   Updated: 2022/11/02 19:38:22 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <assert.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

# define INIT_LINE_SIZE 32

typedef struct s_stream
{
	char			buffer[BUFFER_SIZE];
	uint32_t		cursor;
	ssize_t			bytes_read;
}	t_stream;

typedef struct s_line
{
	char			*line;
	uint32_t		index;
}	t_line;

uint32_t		gnl_roundpow2(uint32_t n);
void			gnl_strncpy(char *dst, char *src, uint32_t n);
void			gnl_resize_line(t_line *line, uint32_t new_size);

void			gnl_resize_if_necessary(t_line *line, uint32_t count);
void			gnl_init_if_necessary(t_line *line, uint32_t count);
void			gnl_append_from_stream(t_line *line,
					t_stream *s, uint32_t count);
int				gnl_is_eol(t_line line);
unsigned int	gnl_chunk_size(t_stream s);

char			*get_next_line(int fd);

#endif