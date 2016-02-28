/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 21:40:00 by pbondoer          #+#    #+#             */
/*   Updated: 2016/02/28 01:01:14 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"
#include "libft.h"

int			drop_piece(char player, int x, t_board **board)
{
	int y;

	y = (*board)->lines - 1;
	while (y >= 0)
	{
		if ((*board)->map[x * (*board)->cols + y] == 0)
		{
			(*board)->map[x * (*board)->cols + y] = player;
			return (x + 1);
		}
		y--;
	}
	return (0);
}

t_board		*get_board(int lines, int cols)
{
	t_board *board;

	board = (t_board *)ft_memalloc(sizeof(t_board));
	if (board == NULL)
		return (NULL);
	board->map = (char *)ft_memalloc(lines * cols * sizeof(char));
	if (board->map == NULL)
	{
		ft_memdel((void **)&board);
		return (NULL);
	}
	board->lines = lines;
	board->cols = cols;
	return (board);
}
