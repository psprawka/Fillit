/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 15:17:30 by psprawka          #+#    #+#             */
/*   Updated: 2017/10/22 17:35:39 by jchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/includes/libft.h"

int		map_size(int bricks);
int		valid_map(char *str);
int		count_mino(char *str, int letter);
int		check(char *map, char *block, int size);
int		solver(char *map, char **minos, int size, int m_itr);
char	*find_block(char *str);
char	find_what_letter(char *str);
void	init_map(char *str, int size);
void	valid_mino(char *str, int letter);
void	remove_mino(char *map, char *block, int size);

#endif
