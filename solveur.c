/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 19:14:49 by vguerand          #+#    #+#             */
/*   Updated: 2017/07/16 19:20:24 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		absent_ligne(char k, char tab[9][9], int y);

int		absent_carre(char k, char tab[9][9], int y, int x);

int		absent_colonne(char k, char tab[9][9], int x);

int		ft_solv2(char tab[9][9], int position, int y, int x)
{
	char k;

	y = position / 9;
	x = position % 9;
	if (position == 0)
		return (1);
	if (tab[y][x] != '.')
		return (ft_solv2(tab, position - 1, 0, 0));
	k = '1';
	while (k <= '9')
	{
		if (absent_ligne(k, tab, y) == 1 && absent_colonne(k, tab, x) == 1)
		{
			if (absent_carre(k, tab, y, x) == 1)
			{
				tab[y][x] = k;
				if (ft_solv2(tab, position - 1, 0, 0) == 1)
					return (1);
			}
		}
		k++;
	}
	tab[y][x] = '.';
	return (0);
}

int		ft_solv(char tab[9][9], int position, int y, int x)
{
	char k;

	y = position / 9;
	x = position % 9;
	if (position == 9 * 9)
		return (1);
	if (tab[y][x] != '.')
		return (ft_solv(tab, position + 1, 0, 0));
	k = '1';
	while (k <= '9')
	{
		if (absent_ligne(k, tab, y) == 1 && absent_colonne(k, tab, x) == 1)
		{
			if (absent_carre(k, tab, y, x) == 1)
			{
				tab[y][x] = k;
				if (ft_solv(tab, position + 1, 0, 0) == 1)
					return (1);
			}
		}
		k++;
	}
	tab[y][x] = '.';
	return (0);
}
