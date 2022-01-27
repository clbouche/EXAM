/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro_paint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 09:24:04 by clbouche          #+#    #+#             */
/*   Updated: 2022/01/27 11:20:20 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> 

char	*drawing;
char	main_background, type, background;
int		main_width, main_height;
float	x, y, width, height;

int	ft_strlen(char *s)
{
	int i = 0;
	while(s[i])
		i++;
	return (i);
}
int	ft_putstr_error(char *s)
{
	write(1, s, ft_strlen(s));
	return (1);
}

int	checker(float i, float j)
{
	if (i < x || j < y || i > (x + width) || j > (y + height)) //in
		return (0);
	else if (i - x < 1 || j - y < 1 || (x + width) - i < 1 || (y + height) - j < 1) //border
		return (1);
	return (2); //out
}

void	draw_box(void)
{
	int i, j = 0, check = 0;

	while(j < main_height)
	{
		i = 0;
		while(i < main_width)
		{
			check = checker(i, j);
			if (check == 1 || (check == 2 && type == 'R'))
				drawing[(j * main_width) + i] = background;
			i++;
		}
		j++;
	}
}

void	print(void)
{
	int i = -1;
	
	while (++i < main_height)
	{
		write(1, (drawing + i * main_width), main_width);
		write(1, "\n", 1);
	}
	
}

int	parser(FILE *file)
{
	int rslt = 0;
	
	if (fscanf(file, "%d %d %c\n", &main_width, &main_height, &main_background) != 3)
		return (1);
	if (main_width < 1 || main_width >= 300 || main_height < 1 || main_height >= 300)
		return (1);
	if (!(drawing = malloc(main_width * main_height)))
		return (1);
	for (int i = 0; i < (main_height * main_width); i++)
		drawing[i] = main_background;
	while ((rslt = fscanf(file, "%c %f %f %f %f %c\n", &type, &x, &y, &width, &height, &background)) == 6)
	{
		if (width < 1 || height < 1 || (type != 'r' && type != 'R'))
			return (1);
		draw_box();
	}
	if (rslt == EOF)
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
		return(ft_putstr_error("Error : argument\n"));
	if (!(file = fopen(argv[1], "r")) || parser(file))
		return (ft_putstr_error("Error : Operation file corrupted\n"));
	free(drawing);
	fclose(file);
	return (0);
}