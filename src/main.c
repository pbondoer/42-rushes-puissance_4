/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 21:22:01 by pbondoer          #+#    #+#             */
/*   Updated: 2016/02/28 00:25:09 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"
#include "libft.h"
#include "get_next_line.h"
#include <string.h>
#include <errno.h>

int		isnumeric(char *str)
{
	while (*str)
		if (!ft_isdigit(*(str++)))
			return (0);
	return (1);
}

int		die(char *str, int i)
{
	ft_putendl(str);
	return (i);
}

void	prompt()
{
	ft_putstr(KGRN);
	ft_putstr("\nPlayer turn > ");
	ft_putstr(KLGR);
}

void	game(t_board *board)
{
	char	*line;
	int		n;
	int		turn;

	(void)board;
	line = NULL;
	turn = 1;
	display_board(board);
	prompt();
	while (get_next_line(1, &line))
	{
		if (*line == 'q')
		{
			return ;
		}
		if (!isnumeric(line) || (n = ft_atoi(line)) < 1 || n > board->cols)
		{
			ft_putstr(KMAG);
			ft_putstr("Please enter a number between 1 and ");
			ft_putnbr(board->cols);
			ft_putendl("!");
			prompt();
			continue;
		}
		if (!drop_piece((turn % 2 ? 'O' : 'X'), n - 1, &board))
		{
			ft_putstr(KMAG);
			ft_putstr("That column is full!\n");
			prompt();
			continue;
		}
		display_board(board);
		prompt();
		turn++;
	}
}

int		main(int ac, char **av)
{
	int		lines;
	int		cols;
	t_board	*board;

	if (ac < 3)
		return (die("usage: puissance4 lines cols [players] [level] [-g]", 0));
	if (!isnumeric(av[1]) || !isnumeric(av[2]))
		return (die("error: lines and columns must be numeric", 1));
	lines = ft_atoi(av[1]);
	cols = ft_atoi(av[2]);
	if (lines < 6 || cols < 7)
		return (die("error: board must be at least 6 lines and 7 columns", 1));
	if (lines > 99 || cols > 99)
		return (die("error: lines and cols must be 99 or less", 1));
	board = get_board(lines, cols);
	if (board == NULL)
		return (die(strerror(errno), 1));
	game(board);
	return (0);
}
