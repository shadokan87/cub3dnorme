/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splited6.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motoure <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 13:42:29 by motoure           #+#    #+#             */
/*   Updated: 2020/09/07 18:39:51 by motoure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cublib.h"

int				listen_keys(t_var *var)
{
	mlx_hook(var->mlx_win, 2, 2, key_pressed, (void *)var);
	mlx_key_hook(var->mlx_win, key_released, (void *)var);
	movement(var);
	return (1);
}

void			load_text(t_var *var)
{
	int i;
	int t_endian;
	int fd;

	i = 1;
	if (!(var->loaded_text = malloc(sizeof(int *) * 9)))
		return ;
	if (!(var->loaded_addr = malloc(sizeof(int *) * 9)))
		return ;
	while (++i <= 6)
	{
		if (var->text_paths[i] && (fd = open(var->text_paths[i],
		O_RDONLY)) != -1)
		{
			ft_fprintf(1, "---->%s |%d|\n", var->text_paths[i], i);
			var->loaded_text[i] = mlx_xpm_file_to_image(var->mlx_ptr,
			var->text_paths[i], &var->tex_w, &var->tex_h);
			var->loaded_addr[i] = (int *)mlx_get_data_addr(var->loaded_text[i],
			&t_endian, &t_endian, &t_endian);
		}
		else if (ft_strlen(var->text_paths[i]) > 0
		&& (fd = open(var->text_paths[i], O_RDONLY)) == -1)
			closegame(var, "TEXT_ERR");
		!(var->text_paths[i]) ? var->loaded_addr[i] = NULL : 0;
	}
}

unsigned int	*getheader(int width, int height, int paddedsize)
{
	unsigned int *headers;

	if (!(headers = malloc(sizeof(unsigned int) * 13)))
		return (0);
	headers[0] = paddedsize + 54;
	headers[1] = 0;
	headers[2] = 54;
	headers[3] = 40;
	headers[4] = width;
	headers[5] = height;
	headers[7] = 0;
	headers[8] = paddedsize;
	headers[9] = 0;
	headers[10] = 0;
	headers[11] = 0;
	headers[12] = 0;
	return (headers);
}

void			writeheader(int fd, unsigned int *headers)
{
	int i;

	i = -1;
	while (++i <= 5)
	{
		ft_fprintf(fd, "%c", headers[i] & 0x000000FF);
		ft_fprintf(fd, "%c", (headers[i] & 0x0000FF00) >> 8);
		ft_fprintf(fd, "%c", (headers[i] & 0x00FF0000) >> 16);
		ft_fprintf(fd, "%c", (headers[i] & (unsigned int)0xFF000000) >> 24);
	}
	ft_fprintf(fd, "%c", 1);
	ft_fprintf(fd, "%c", 0);
	ft_fprintf(fd, "%c", 24);
	ft_fprintf(fd, "%c", 0);
	i = 6;
	while (++i <= 12)
	{
		ft_fprintf(fd, "%c", headers[i] & 0x000000FF);
		ft_fprintf(fd, "%c", (headers[i] & 0x0000FF00) >> 8);
		ft_fprintf(fd, "%c", (headers[i] & 0x00FF0000) >> 16);
		ft_fprintf(fd, "%c", (headers[i] & (unsigned int)0xFF000000) >> 24);
	}
}

void			writecolor(t_var *var, int extrabytes, int fd)
{
	int		y;
	int		x;
	int		i;
	int		count;

	count = 0;
	y = var->s_h;
	i = 0;
	while (--y >= 0)
	{
		x = -1;
		if (count > var->s_h / 2 && count % 100 == 0)
			ft_putstr(1, "Generating BMP almost done, please wait.\n");
		else if (count % 100 == 0)
			ft_putstr(1, "Generating BMP please wait.\n");
		while (++x <= var->s_w - 1)
			pixel_put_fd(var, *(unsigned int*)(var->addr + (y
			* var->line + x * (var->bpp / 8))), fd);
		if (extrabytes)
		{
			while (++i <= extrabytes)
				ft_fprintf(fd, "%c", 0);
		}
		count++;
	}
}
