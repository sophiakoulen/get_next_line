/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:46:53 by skoulen           #+#    #+#             */
/*   Updated: 2022/11/02 19:28:40 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
	if n < 32, returns 32
	else
		if n is a pow 2, return n
		else, return nextpow2
*/
uint32_t	gnl_roundpow2(uint32_t n)
{
	if (n < INIT_LINE_SIZE)
		return (INIT_LINE_SIZE);
	n--;
	n |= n >> 1;
	n |= n >> 2;
	n |= n >> 4;
	n |= n >> 8;
	n |= n >> 16;
	n++;
	return (n);
}

void	gnl_strncpy(char *dst, char *src, uint32_t n)
{
	uint32_t	i;

	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
}

void	gnl_resize_line(t_line *line, uint32_t new_size)
{
	char	*tmp;

	tmp = malloc(sizeof(*tmp) * new_size);
	if (!tmp)
		free(line->line);
	else
	{
		gnl_strncpy(tmp, line->line, line->index);
		free(line->line);
	}
	line->line = tmp;
}

void	gnl_resize_if_necessary(t_line *line, uint32_t count)
{
	uint32_t	occupied;

	if (!line->line)
		return ;
	occupied = line->index + 1;
	if (occupied + count > gnl_roundpow2(occupied))
		gnl_resize_line(line, gnl_roundpow2(occupied + count));
}

void	gnl_init_if_necessary(t_line *line, uint32_t count)
{
	if (!line->line && count > 0)
		line->line = malloc(sizeof(char) * INIT_LINE_SIZE);
}
