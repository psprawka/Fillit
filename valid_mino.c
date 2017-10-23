/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_mino.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/08 23:27:55 by jchung            #+#    #+#             */
/*   Updated: 2017/10/23 15:44:31 by jchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		valid_map(char *str)
{
	static int		i;
	static int		nl = 1;

	if (str[i] == 0)
		return (1);
	while (str[i] == '.' || str[i] == '#' || str[i] == '\n')
	{
		while (str[i] == '.' || str[i] == '#')
			i++;
		if ((i + nl) % 5 != 0)
			return (1);
		if (str[i++] != '\n')
			return (1);
		if (str[i] == '\0')
			break ;
		if ((i + 1) % 21 == 0)
		{
			if (str[i++] != '\n')
				return (1);
			nl--;
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
	int		dots;

	count = 0;
	dots = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == '#' && count_mino(&str[i], letter) != 4)
		{
			ft_putstr_fd("error\n", 1);
			exit(0);
		}
		if (str[i] == '.')
			dots++;
		count++;
	}
	if (count < 20 || dots != 12)
	{
		ft_putstr_fd("error\n", 1);
		exit(0);
	}
}
