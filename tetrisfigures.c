/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrisfigures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 20:02:00 by dmontoya          #+#    #+#             */
/*   Updated: 2017/10/20 20:26:06 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	mallocintarray(int **tetconf, int tetcount)
{
	int i;

	i = 0;
	while (tetcount-- > 0)
		tetconf[i++] = (int*)malloc(sizeof(int) * 4);
}

int		ft_hashcount(char *onetet)
{
	int i;
	int hcount;

	i = 0;
	hcount = 0;
	while (i < 21)
	{
		if (onetet[i] == '#')
			hcount += 1;
		i++;
	}
	if (hcount == 4)
		return (1);
	ft_error();
	return (-1);
}

int		ft_checkvalidtet(int *tetconfig)
{
	if (tetconfig[1] == 1)
		if (((tetconfig[2] == 2) && (tetconfig[3] == 6)) || ((tetconfig[2] == 2) && (tetconfig[3] == 3)) || ((tetconfig[2] == 5) && (tetconfig[3] == 10))
         || ((tetconfig[2] == 2) && (tetconfig[3] == 7)) || ((tetconfig[2] == 6) && (tetconfig[3] == 11)) || ((tetconfig[2] == 2) && (tetconfig[3] == 5))
         || ((tetconfig[2] == 5) && (tetconfig[3] == 6)) || ((tetconfig[2] == 6) && (tetconfig[3] == 7)))
            return (0);
	if (((tetconfig[1] == 5) && (tetconfig[2] == 6) && (tetconfig[3] == 10)) ||
			((tetconfig[1] == 5) && (tetconfig[2] == 10) && (tetconfig[3] == 15)) ||
			((tetconfig[1] == 5) && (tetconfig[2] == 6) && (tetconfig[3] == 7)) ||
			((tetconfig[1] == 5) && (tetconfig[2] == 10) && (tetconfig[3] == 11)) ||
			((tetconfig[1] == 5) && (tetconfig[2] == 6) && (tetconfig[3] == 11)))
		return (0);
	if  (((tetconfig[1] == 4) && (tetconfig[2] == 5) && (tetconfig[3] == 6)) ||
			((tetconfig[1] == 4) && (tetconfig[2] == 5) && (tetconfig[3] == 10)) ||
			((tetconfig[1] == 5) && (tetconfig[2] == 9) && (tetconfig[3] == 10)) ||
			((tetconfig[1] == 1) && (tetconfig[2] == 4) && (tetconfig[3] == 5)) ||
			((tetconfig[1] == 4) && (tetconfig[2] == 5) && (tetconfig[3] == 9)))
		return (1);
	if ((tetconfig[1] == 3) && (tetconfig[2] == 4) && (tetconfig[3] == 5))
		return (2);
	ft_error();
	return (-1);
}

int		findfirsthash(char *tetristr)
{
	int i;

	i = 0;
	ft_hashcount(tetristr);
	while (tetristr[i] != '\0')
	{
		if (tetristr[i] == '#')
			return (i);
		i++;
	}
	return (-1);
}

int     **determinefigures(char **tetristr, int tetcount)
{
	int	**tetconf;
	int y;
	int hash;

	y = 0;
//	if (tetcount == 1)
//		ft_onetet();//hardcoding for 1 tet
    tetconf = (int **)malloc(sizeof(int*) * tetcount);
    mallocintarray(tetconf, tetcount);
    while (y < tetcount)
    {
		hash = findfirsthash(tetristr[y]);
		tetconf = ft_tetconfiguration(tetristr, tetconf, y, hash);
		tetconf[y][0] = ft_checkvalidtet(tetconf[y]);
		y++;
	}
    return (tetconf);
}
