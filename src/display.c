/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 21:36:58 by pbondoer          #+#    #+#             */
/*   Updated: 2016/02/28 00:59:59 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "puissance4.h"

void	put_boardchar(t_board *board, int x, int y)
{
	char	c;

	c = board->map[x * board->cols + y];
	if (c)
	{
		ft_putstr(c == 'O' ? KRED : KYEL);
		ft_putchar(c);
	}
	else
	{
		ft_putstr(x % 2 ? (y % 2 ? KBLU : KGRY) : (y % 2 ? KLBL : KWHT));
		ft_putchar('.');
	}
	if (x != board->cols - 1)
		ft_putchar(' ');
}

void	number_line(int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		i++;
		ft_putstr((n % 2 ? (i + 1) % 2 : i % 2) ? KGRY : KNRM);
		ft_putnbr(i % 10 ? i - (i / 10 * 10) : i);
		if (i % 10 < 9)
			ft_putchar(' ');
	}
	ft_putstr(KNRM);
	ft_putchar('\n');
}

void	display_board(t_board *board)
{
	int x;
	int y;

	y = 0;
	number_line(board->cols);
	while (y < board->lines)
	{
		x = 0;
		while (x < board->cols)
		{
			put_boardchar(board, x, y);
			x++;
		}
		ft_putstr("\n");
		y++;
	}
	number_line(board->cols);
}
