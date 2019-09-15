/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 15:15:48 by psprawka          #+#    #+#             */
/*   Updated: 2019/09/15 22:40:34 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		solve_map(char *map, char **array, int mapsize, int brick)
{
	init_map(map, mapsize);
	while (solver(map, array, mapsize, brick) != 1)
	{
		mapsize++;
		free(map);
		map = ft_strnew(mapsize * (mapsize + 1));
		init_map(map, mapsize);
	}
	ft_putstr(map);
}

static char		**split(char *str, char letter, int *bricks)
{
	char	*temp;
	char	*ptr;
	char	**array;

	temp = ft_memalloc(1);
	array = (char**)malloc(sizeof(*array) * (27));
	ptr = str;
	while (*ptr != '\0')
	{
		array[*bricks] = ft_strnew(21);
		array[*bricks] = ft_strsub(ptr, 0, 21);
		if ((array[*bricks][0] == '.') || (array[*bricks][0] == '#'))
		{
			valid_mino(array[*bricks], letter++);
			*bricks += 1;
		}
		if (ptr[19] == '\n' && ptr[20] == '\n' && ptr[21] == '\0')
		{
			ft_putstr_fd("error\n", 1);
			exit(0);
		}
		ptr += 21;
	}
	array[*bricks] = ft_memalloc(1);
	return (array);
}

static char		**read_valid(int fd, int *bricks)
{
	int		ret;
	char	*temp;
	char	*str;
	char	**array;

	temp = malloc(4096);
	str = ft_memalloc(1);
	while ((ret = read(fd, temp, 4096)) > 0)
		str = ft_strjoin(str, temp, true);
	if (valid_map(str))
	{
		ft_putstr_fd("error\n", 1);
		close(fd);
		exit(0);
	}
	array = split(str, 'A', bricks);
	return (array);
}

int				main(int ac, char **av)
{
	int		fd;
	int		mapsize;
	char	**array;
	int		brick;
	char	*map;

	if (ac == 2)
	{
		if ((fd = open(av[1], O_RDONLY)) < 0)
		{
			ft_putstr_fd("error\n", 1);
			close(fd);
			return (1);
		}
		array = read_valid(fd, &brick);
		mapsize = map_size(brick);
		map = ft_strnew(mapsize * (mapsize + 1));
		solve_map(map, array, mapsize, brick);
		close(fd);
	}
	else
		write(1, "usage: ./fillit [filename]\n", 27);
	return (0);
}
