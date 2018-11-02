/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 09:49:40 by vguerand          #+#    #+#             */
/*   Updated: 2017/07/16 19:28:36 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_aff(char tab[9][9]);

int		ft_solv(char tab[9][9], int position, int y, int x);

int		ft_solv2(char tab[9][9], int position, int y, int x);

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (*str++ != '\0')
	{
		i++;
	}
	return (i);
}

int		creer_tab(int argc, char **argv, char tab[9][9])
{
	int i;
	int j;

	i = 1;
	j = 0;
	if (argc >= 2 && argc <= 11)
	{
		while (argc != i)
		{
			if (ft_strlen(argv[i]) != 9)
				return (0);
			while (j < 9)
			{
				if ((argv[i][j] > '9' || argv[i][j] < '1') && argv[i][j] != '.')
					return (0);
				tab[i - 1][j] = argv[i][j];
				j++;
			}
			j = 0;
			i++;
		}
	}
	return (1);
}

int		ft_count(char tab[9][9])
{
	int		y;
	int		x;
	char	count;

	y = 0;
	while (y < 9)
	{
		count = 0;
		x = 0;
		while (x < 9)
		{
			count = count + tab[y][x];
			x++;
		}
		if (count != -35)
			return (0);
		y++;
	}
	return (1);
}

int		ft_compare(char tab[9][9], char tab2[9][9])
{
	int		y;
	int		x;

	y = 0;
	while (y < 9)
	{
		x = 0;
		while (x < 9)
		{
			if (tab[y][x] != tab2[y][x])
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int		main(int argc, char **argv)
{
	char	tab[9][9];
	char	tab2[9][9];

	if (creer_tab(argc, argv, tab) == 1 && creer_tab(argc, argv, tab2) == 1)
	{
		if (ft_solv(tab, 0, 0, 0) == 1 && ft_solv2(tab2, 81, 0, 0) == 1)
		{
			if (ft_compare(tab, tab2) == 1)
			{
				if (ft_count(tab) == 1)
					ft_aff(tab);
				else
					write(1, "Error\n", 6);
			}
			else
				write(1, "Error\n", 6);
		}
		else
			write(1, "Error\n", 6);
	}
	else
		write(1, "Error\n", 6);
	return (0);
}
