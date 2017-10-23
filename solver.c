/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 21:28:42 by jchung            #+#    #+#             */
/*   Updated: 2017/10/23 15:19:03 by jchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check(char *pos, char *block, int size)
{
	if (pos[0] == '.' && (block[0] && block[0] > 64))
	{
		pos[0] = block[0];
		if (block[5])
			return (1 + check(pos + 1, block + 1, size) +
				check(pos - 1, block - 1, size) +
				check(pos + size + 1, block + 5, size));
		else
			return (1 + check(pos + 1, block + 1, size) +
					check(pos - 1, block - 1, size));
	}
	else
		return (0);
}

void	remove_mino(char *pos, char *block, int size)
{
	if (pos[0] == block[0] && pos[0] != '\n')
	{
		pos[0] = '.';
		remove_mino(pos - size - 1, block, size);
		remove_mino(pos + 1, block, size);
		remove_mino(pos - 1, block, size);
		remove_mino(pos + size + 1, block, size);
	}
}

char	*find_block(char *str)
{
	while (*str && (*str == '.' || *str == '\n'))
		str++;
	return (str);
}

int		solver(char *str, char **minos, int size, int bricks)
{
	int		i;
	int		blockcount;
	char	*block;

	if (minos[0] == '\0')
		return (1);
	block = find_block(*minos);
	i = -1;
	while (str[++i])
	{
		blockcount = check(&str[i], block, size);
		if (blockcount != 4)
			remove_mino(&str[i], block, size);
		else
		{
			if (bricks == find_what_letter(minos[0]) - 64)
				return (1);
			if (!solver(str, &(minos[1]), size, bricks))
				remove_mino(&str[i], block, size);
			else
				return (1);
		}
	}
	return (0);
}
