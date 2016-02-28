/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puissance4.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 21:26:21 by pbondoer          #+#    #+#             */
/*   Updated: 2016/02/27 23:45:03 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUISSANCE4_H
# define PUISSANCE4_H
#define KNRM "\x1B[0m"
#define KRED "\x1B[31m"
#define KGRN "\x1B[32m"
#define KYEL "\x1B[33m"
#define KBLU "\x1B[34m"
#define KMAG "\x1B[35m"
#define KCYN "\x1B[36m"
#define KWHT "\x1B[37m"
#define KGRY "\x1B[90m"
#define KLBL "\x1B[94m"
#define KLYE "\x1B[93m"
#define KLRE "\x1B[91m"
#define KLGR "\x1B[92m"

typedef struct	s_board
{
	char		*map;
	int			lines;
	int			cols;
}				t_board;

void			display_board(t_board *board);
t_board			*get_board(int lines, int cols);
int				drop_piece(char player, int y, t_board **board);
#endif
