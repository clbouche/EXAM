/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_paint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 09:24:00 by clbouche          #+#    #+#             */
/*   Updated: 2022/01/24 17:29:03 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int		main_w, main_h;
float	x, y, radius;
char	main_background, type, background;
char	*draw;

int	ft_strlen(char *s)
{
	int i = 0;
	while(s[i])
		i++;
	return (i);
}

int	ft_error(char *s)
{
	write(1, s, ft_strlen(s));
	return (1);
}

void	print(void)
{
	int i = -1;
	
	while(++i < main_w)
	{
		write(1, (draw + i * main_w), main_w);
		write(1, "\n", 1);
	}
}

int		checker(float i, float j)
{
	float	dist = sqrtf((i - x) * (i - x) + (j - y) * (j - y));

	if (dist <= radius)
	{
		if (radius - dist < 1)
			return (2); //border
		return (1); //in
	}
	return (0); //out
}

void	draw_circle(void)
{
	int i, j = 0, check = 0;
	while(j < main_w)
	{
		i = 0;
		while(i < main_h)
		{
			check = checker(i, j);
			if (check == 2 || (check == 1 && background == 'C'))
				draw[j + i * main_w] = background;
			i++;
		}
		j++;
	}
}

int	parser(FILE *file)
{
	int rtn = 0;

	if (fscanf(file, "%d %d %c\n", &main_w, &main_h, &main_background) != 3)
		return (1);
	if (main_w < 1 || main_w >= 300 || main_h < 1 || main_h >= 300)
		return (1);
	if (!(draw = malloc(main_w * main_h)))
		return (1);
	for (int i = 0; i < (main_w * main_h); i++)
		draw[i] = main_background;
	while((rtn = fscanf(file, "%c %f %f %f %c\n", &type, &x, &y, &radius, &background)) == 5)
	{
		if ((type != 'C' && type != 'c') || radius < 1)
			return (1);
		draw_circle();
	}
	if (rtn == EOF)
	{
		print();
		return (0);
	}
	else
		return (1);
}

int main(int argc, char **argv)
{
	FILE	*file;

	if (argc != 2)
		return(ft_error("Error : argument\n"));
	if (!(file = fopen(argv[1], "r")) || parser(file))
		return (ft_error("Error: Operation file corrupted"));
	free(draw);
	fclose(file);
	return (0);
}