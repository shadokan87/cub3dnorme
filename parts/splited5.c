/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splited5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motoure <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 13:42:17 by motoure           #+#    #+#             */
/*   Updated: 2020/08/14 13:42:19 by motoure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cublib.h"

void	drawbmp(char *filename, t_var *var)
{
	unsigned int	*headers;
	int				extrabytes;
	int				paddedsize;
	int				fd;

	fd = open(filename, O_TRUNC | O_RDWR | O_APPEND | O_CREAT);
	extrabytes = 4 - ((var->s_w * 3) % 4) % 4;
	if (extrabytes == 4)
		extrabytes = 0;
	paddedsize = ((var->s_w * 3) + extrabytes) * var->s_h;
	headers = getheader(var->s_w, var->s_h, paddedsize);
	ft_fprintf(fd, "BM");
	writeheader(fd, headers);
	writecolor(var, extrabytes, fd);
	close(fd);
	closegame(var, "--save done\nif the image is corrupt, try again");
	return ;
}

int		screenshot(t_var *var)
{
	int i;

	i = 0;
	raycast(var);
	while (i < var->spritenum)
	{
		var->dist = getdist(var);
		draw_sprite(var, var->spritequeue[var->spriteorder[i]][0],
		var->spritequeue[var->spriteorder[i]][1]);
		i++;
	}
	drawbmp("screenshot.bmp", var);
	return (1);
}

int		run(t_var *var)
{
	int i;

	i = -1;
	var->tex_h = 64;
	var->tex_w = 64;
	var->img_data = (int *)mlx_get_data_addr(var->img,
	&var->t_bpp, &var->t_line, &var->t_endian);
	if (var->screenshot)
		screenshot(var);
	listen_keys(var);
	if (var->s || var->w || var->d || var->a
	|| var->r_r || var->l_r)
		cls(var);
	raycast(var);
	while (++i < var->spritenum)
	{
		var->dist = getdist(var);
		draw_sprite(var, var->spritequeue[var->spriteorder[i]][0],
		var->spritequeue[var->spriteorder[i]][1]);
	}
	mlx_put_image_to_window(var->mlx_ptr, var->mlx_win, var->img, 0, 0);
	return (1);
}

int		start(t_var *var)
{
	load_text(var);
	mlx_loop_hook(var->mlx_ptr, run, (void *)var);
	mlx_loop(var->mlx_ptr);
	return (1);
}

int		**copymap(int height, int width, int index, t_var *var)
{
	int		**map;
	char	**str;
	int		i;
	int		y;

	i = -1;
	y = 0;
	if (!(map = malloc(sizeof(int *) * height)))
		return (0);
	str = ft_split(&var->paramfile[index], '\n');
	while (++i < height)
		if (!(map[i] = malloc(sizeof(int) * width)))
			return (0);
	i = 0;
	while (str[i])
	{
		while (ft_split(str[i], ' ')[y])
		{
			map[i][y] = (ft_split(str[i], ' '))[y][0] - 0;
			y++;
		}
		y = 0;
		i++;
	}
	return (map);
}
