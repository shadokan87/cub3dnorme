/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splited9.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motoure <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 13:42:43 by motoure           #+#    #+#             */
/*   Updated: 2020/08/20 00:39:56 by motoure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cublib.h"

void	hit(t_var *var)
{
	while (var->hit == 0)
	{
		var->side = (var->sidedistx < var->sidedisty) ? 0 : 1;
		if (var->sidedistx < var->sidedisty)
		{
			var->sidedistx += var->deltadistx;
			var->mapx += var->stepx;
		}
		else
		{
			var->sidedisty += var->deltadisty;
			var->mapy += var->stepy;
		}
		if (var->map[var->mapx][var->mapy] > 0)
		{
			var->hit = var->map[var->mapx][var->mapy];
			var->wallx = var->hit;
		}
	}
	if (var->side == 0)
		var->perpwalldist = (var->mapx - var->posx + (1 -
		var->stepx) / 2) / var->raydirx;
	else
		var->perpwalldist = (var->mapy - var->posy + (1 -
		var->stepy) / 2) / var->raydiry;
}

void	cls(t_var *var)
{
	int x;

	x = -1;
	var->vc = 0;
	while (++x < var->s_w)
		verline(var, x, 0, var->s_h);
}

void	draw_info(t_var *var)
{
	if (!var->loaded_addr[var->hit] && !var->screenshot)
		closegame(var, "TEXTURE_ERROR");
	var->lineheight = (int)(var->s_h / var->perpwalldist);
	var->drawstart = -var->lineheight / 2 + var->s_h / 2;
	if (var->drawstart < 0)
		var->drawstart = 0;
	var->drawend = var->lineheight / 2 + var->s_h / 2;
	if (var->drawend >= var->s_h)
		var->drawend = var->s_h - 1;
}

void	draw_texture(t_var *var)
{
	int		texx;
	int		texy;
	double	wallx;
	double	step;
	double	texpos;

	draw_info(var);
	if (var->side == 0)
		wallx = var->posy + var->perpwalldist * var->raydiry;
	else
		wallx = var->posx + var->perpwalldist * var->raydirx;
	wallx -= floor(wallx);
	texx = (int)(wallx * (double)var->tex_w);
	(var->side == 0 && var->raydirx > 0) ? texx = var->tex_w - texx - 1 : 0;
	step = 1.0 * var->tex_h / var->lineheight;
	texpos = (var->drawstart - var->s_h / 2 + var->lineheight / 2) * step;
	while (var->drawstart < var->drawend)
	{
		texy = (int)texpos;
		texpos += step;
		pixel_put(var, var->x, var->drawstart,
		var->loaded_addr[var->hit][64 * texy + texx]);
		var->drawstart++;
	}
}

int		convhex(char *hex)
{
	int i;

	i = 0;
	while (!(ft_strcmp(hex, ft_putnbr_base(i, HEXD))))
	{
		if (i > 255)
			return (255);
		i++;
	}
	return (i);
}
