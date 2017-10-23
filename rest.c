/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rest.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 15:15:48 by psprawka          #+#    #+#             */
/*   Updated: 2017/10/16 03:01:14 by jchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		map_size(int bricks)
{
	int		i;

	i = 1;
	while (i * i < bricks * 4)
		i++;
	return (i);
}

void	init_map(char *str, int size)
{
	int		i;

	i = -1;
	while (++i < (size * (size + 1)))
		str[i] = (i % (size + 1) == size ? '\n' : '.');
	str[i] = '\0';
}

char	find_what_letter(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		if (str[i] != '\n' && str[i] != '.')
			return (str[i]);
	}
	return (0);
}
