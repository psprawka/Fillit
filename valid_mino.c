/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_mino.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/08 23:27:55 by jchung            #+#    #+#             */
/*   Updated: 2017/10/08 23:44:49 by jchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** After storing all tetriminos in malloc'd array spaces for strings, iterate
** across the string with a flood fill search on the first match for a '#'
** char and return the count for both the number of blocks in the -mino as well
** as the total number of characters until a null terminator.
**
** If the block count isn't 4, it isn't a tetrimino or the count of characters
** isn't 20, the format wasn't valid during the read. Both errors should exit()
** the program.
*/

#include "fillit.h"
#include <stdio.h>

int		valid_map(char *str)
{
	int i;
	int idk;

	i = 0;
	idk = 1;
	while (str[i] == '.' || str[i] == '#' || str[i] == '\n')
	{
		while (str[i] == '.' || str[i] == '#')
			i++;
		if ((i + idk) % 5 != 0)
			return (1);
		if (str[i++] != '\n')
			return (1);
		if (str[i] == '\0')
			break ;
		if ((i + 1) % 21 == 0)
		{
			if (str[i++] != '\n')
				return (1);
			idk--;
		}
	}
	if (str[i] != '\0')
		return (1);
	return (0);
}

int		count_mino(char *str, int letter)
{
	if (str[0] && str[0] == '#')
	{
		str[0] = letter;
		return (1 + count_mino(str - 1, letter) +
				count_mino(str + 1, letter) +
				count_mino(str + 5, letter));
	}
	else
		return (0);
}

void	valid_mino(char *str, int letter)
{
	int		count;
	int		i;

	count = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == '#' && count_mino(&str[i], letter) != 4)
		{
			write(1, "error\n", 6);
			exit(0);
		}
		count++;
	}
}
