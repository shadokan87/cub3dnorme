/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splited15.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motoure <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 13:41:42 by motoure           #+#    #+#             */
/*   Updated: 2020/08/20 00:40:42 by motoure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cublib.h"

void		initcolormap(t_var *var)
{
	int i;

	i = 0;
	var->colormap = malloc(sizeof(int *) * var->m_height);
	while (i < var->m_height)
	{
		var->colormap[i] = malloc(sizeof(int) * var->m_width);
		i++;
	}
}

int			skip(char ***split)
{
	char *str;

	str = NULL;
	str = **split;
	if (!str)
		return (-1);
	if (str[0] == 'R' || str[0] == 'F'
	|| str[0] == 'C' || str[0] == 'S')
		return (1);
	if ((str[0] == 'S' && str[1] == 'O')
	|| (str[0] == 'N' && str[1] == 'O')
	|| (str[0] == 'W' && str[1] == 'E')
	|| (str[0] == 'E' && str[1] == 'A'))
		return (1);
	return (0);
}

int			checkbottom(char *str)
{
	int i;
	int y;
	int count;

	i = 0;
	y = 0;
	count = 0;
	if (str[i] && str[i] == ' ')
	{
		while (str[i] && str[i] == ' ')
			i++;
	}
	while (str[i])
	{
		if (str[i] == ' ')
			i++;
		if (!iswall(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void		init_sprite_var(t_var *var, int sx, int sy)
{
	var->vmove = 0.5;
	var->spritex = sx - var->posx;
	var->spritey = sy - var->posy;
	var->invdet = 1.0 / (var->planex * var->diry - var->dirx * var->planey);
	var->transformx = var->invdet *
	(var->diry * var->spritex - var->dirx * var->spritey);
	var->transformy = var->invdet *
	(-var->planey * var->spritex + var->planex * var->spritey);
	var->vmovescreen = (int)(var->vmove / var->transformy);
	var->spritescreenx = (int)((var->s_w / 2 *
	(1 + var->transformx / var->transformy)));
	var->spriteheight = abs((int)(var->s_h / (var->transformy)));
	var->drawstarty = -var->spriteheight / 2 + var->s_h / 2 + var->vmovescreen;
	(var->drawstarty < 0) ? var->drawstarty = 0 : 0;
	var->drawendy = var->spriteheight / 2 + var->s_h / 2 + var->vmovescreen;
	(var->drawendy >= var->s_h) ? var->drawendy = var->s_h - 1 : 0;
	var->spritewidth = abs((int)(var->s_h / (var->transformy)));
	var->drawstartx = -var->spritewidth / 2 + var->spritescreenx;
	(var->drawstartx < 0) ? var->drawstartx = 0 : 0;
	var->drawendx = var->spritewidth / 2 + var->spritescreenx;
	(var->drawendx >= var->s_w) ? var->drawendx = var->s_w - 1 : 0;
}

int			sip(char *base, char c)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (1);
		i++;
	}
	return (0);
}
