/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 15:15:48 by psprawka          #+#    #+#             */
/*   Updated: 2017/10/04 15:15:50 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** change_letters: pass 'A' as a char c
** valid_map returns 0 if map is valid
*/

#include "libft/includes/libft.h"
#include "fillit.h"
#include <fcntl.h>
#include <stdio.h>

char	**split(char *str, char letter, int *bricks)
{
	char	*temp;
	char	*ptr;
	char	**array;

	temp = ft_memalloc(1);
	array = (char**)malloc(sizeof(*array) * (27));
	ptr = str;
	while (*ptr != '\0')
	{
		array[*bricks] = (char*)malloc(sizeof(**array) * (22));
		temp = ft_strsub(ptr, 0, 21);
		valid_mino(temp, letter);
		letter++;
		array[*bricks] = temp;
		*bricks += 1;
		ptr += 21;
	}
	array[*bricks] = ft_memalloc(1);
	free(temp);
	return (array);
}

char	**read_valid(int fd, int *bricks)
{
	int		ret;
	char	*temp;
	char	*str;
	char	**array;
	
	temp = malloc(4096);
	str = malloc(1);
	while ((ret = read(fd, temp, 4096)) > 0)
		str = ft_strjoin(str, temp);

	if (valid_map(str))
	{
		ft_putstr_fd("error", 2);
		close(fd);
		exit(0);
	}
	array = split(str, 'A', bricks);
	return (array);
}

int		main(int ac, char **av)
{
	int		fd;
	char	**array;
	int		bricks;

	if (ac == 2)
	{
		if ((fd = open(av[1], O_RDONLY)) < 0)
		{
			ft_putstr_fd("error", 2);
			close(fd);
			return (0);
		}
		array = read_valid(fd, &bricks);
		//place for solid function
		close(fd);
	}
	else
		write(1, "./fillit [filename]\n", 20);
	return (0);
}
