/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_onetet.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 17:01:00 by dmontoya          #+#    #+#             */
/*   Updated: 2017/10/21 17:10:44 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	squareadjust(int *tetconf)
{
	int x;

	x = 2;
	tetconf[x++] = 3;
	tetconf[x] = 4;
}

int		ft_onetet(int **tetconf, int tetcount)
{
	char *grid;

	squareadjust(tetconf[0]);
	grid = squaresize(2);
	tetcount = recursive_backtrack(grid, tetconf, 0, tetcount);
	return (tetcount);
}
