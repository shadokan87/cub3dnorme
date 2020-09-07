/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splited7.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motoure <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 13:42:36 by motoure           #+#    #+#             */
/*   Updated: 2020/08/14 13:42:37 by motoure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cublib.h"

int			move_is_possible(int pos)
{
	if (pos == 1 || pos == 4)
		return (0);
	return (1);
}

void		fwd_bckwrd(t_var *var)
{
	if (var->w)
	{
		if (var->map[(int)(var->posx + var->dirx * MOVESPEED)]
		[(int)(var->posy)] == 0)
			var->posx += var->dirx * MOVESPEED * 0.5;
		if (var->map[(int)(var->posx)]
		[(int)(var->posy + var->diry * MOVESPEED)] == 0)
			var->posy += var->diry * MOVESPEED * 0.5;
	}
	if (var->s)
	{
		if (var->map[(int)(var->posx - var->dirx * MOVESPEED)]
		[(int)(var->posy)] == 0)
			var->posx -= var->dirx * MOVESPEED * 0.5;
		if (var->map[(int)(var->posx)]
		[(int)(var->posy - var->diry * MOVESPEED)] == 0)
			var->posy -= var->diry * MOVESPEED * 0.5;
	}
}

void		x_y(t_var *var)
{
	if (var->a)
	{
		if (var->map[(int)(var->posx)]
		[(int)(var->posy + var->dirx * MOVESPEED)] == 0)
			var->posy += var->dirx * MOVESPEED * 0.5;
		if (var->map[(int)(var->posx - var->diry * MOVESPEED)]
		[(int)(var->posy)] == 0)
			var->posx -= var->diry * MOVESPEED * 0.5;
	}
	if (var->d)
	{
		if (var->map[(int)(var->posx)]
		[(int)(var->posy - var->dirx * MOVESPEED)] == 0)
			var->posy -= var->dirx * MOVESPEED * 0.5;
		if (var->map[(int)(var->posx + var->diry * MOVESPEED)]
		[(int)(var->posy)] == 0)
			var->posx += var->diry * MOVESPEED * 0.5;
	}
}

void		l_r(t_var *var)
{
	double old_dir;
	double old_plane;
	double rot_speed;

	old_dir = var->dirx;
	old_plane = var->planex;
	rot_speed = 0.1;
	if (var->r_r)
	{
		var->dirx = (var->dirx * cos(-ROTSPEED)) - var->diry * sin(-ROTSPEED);
		var->diry = (old_dir * sin(-ROTSPEED) + var->diry * cos(-ROTSPEED));
		var->planex = (var->planex * cos(-ROTSPEED)
		- var->planey * sin(-ROTSPEED));
		var->planey = (old_plane * sin(-ROTSPEED)
		+ var->planey * cos(ROTSPEED));
	}
	if (var->l_r)
	{
		var->dirx = (var->dirx * cos(ROTSPEED)) - var->diry * sin(ROTSPEED);
		var->diry = (old_dir * sin(ROTSPEED) + var->diry * cos(ROTSPEED));
		var->planex = (var->planex * cos(ROTSPEED)
		- var->planey * sin(ROTSPEED));
		var->planey = (old_plane * sin(ROTSPEED) + var->planey * cos(ROTSPEED));
	}
}

int			movement(t_var *var)
{
	fwd_bckwrd(var);
	x_y(var);
	l_r(var);
	return (1);
}
