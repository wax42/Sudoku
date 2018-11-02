/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   absent.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 19:13:02 by vguerand          #+#    #+#             */
/*   Updated: 2017/07/16 19:14:01 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		absent_ligne(char k, char tab[9][9], int y)
{
	int i;

	i = 0;
	while (i < 9)
	{
		if (tab[y][i] == k)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int		absent_colonne(char k, char tab[9][9], int x)
{
	int i;

	i = 0;
	while (i < 9)
	{
		if (tab[i][x] == k)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int		absent_carre(char k, char tab[9][9], int y, int x)
{
	int i;
	int j;

	y = y - (y % 3);
	i = y;
	while (i < y + 3)
	{
		x = x - (x % 3);
		j = x;
		while (j < x + 3)
		{
			if (tab[i][j] == k)
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
