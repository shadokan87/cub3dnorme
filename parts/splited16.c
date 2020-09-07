/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splited16.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motoure <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 18:01:55 by motoure           #+#    #+#             */
/*   Updated: 2020/09/07 18:25:27 by motoure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cublib.h"

int		ismap(char *str)
{
	if (!str)
		return (0);
	if (ft_strlen(str) < 3)
		return (0);
	if (sip("WENS102", str[0]) && str[1] == ' '
	&& sip("WENS102", str[2]))
		return (1);
	return (0);
}

int		is_token(char **token, char *str)
{
	int i;

	i = 0;
	while (token[i])
	{
		if (ft_strcmp(token[i], str))
			return (1);
		i++;
	}
	return (0);
}

void	fill_color(t_var *var, int i)
{
	if (ft_strcmp(var->paramsliced[i], "F"))
	{
		check_color(var, var->paramsliced[i + 1]);
		var->f_color[0] = ft_atoi(ft_split(var->paramsliced[i + 1], ',')[0]);
		var->f_color[1] = ft_atoi(ft_split(var->paramsliced[i + 1], ',')[1]);
		var->f_color[2] = ft_atoi(ft_split(var->paramsliced[i + 1], ',')[2]);
		return ;
	}
	if (ft_strcmp(var->paramsliced[i], "C"))
	{
		check_color(var, var->paramsliced[i + 1]);
		var->c_color[0] = ft_atoi(ft_split(var->paramsliced[i + 1], ',')[0]);
		var->c_color[1] = ft_atoi(ft_split(var->paramsliced[i + 1], ',')[1]);
		var->c_color[2] = ft_atoi(ft_split(var->paramsliced[i + 1], ',')[2]);
	}
}

void	check_color(t_var *var, char *str)
{
	int i;
	int count;

	i = -1;
	count = 0;
	if (!str)
		closegame(var, "COLOR_ERROR");
	while (str[++i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			continue;
		else if ((str[i] == ',') && (str[i - 1] >=
		'0' && str[i - 1] <= '9'))
			count++;
		else
			closegame(var, "COLOR_aaERROR");
	}
	if (count != 2)
		closegame(var, "COLOR_ERROR");
}

void	get_res(t_var *var, int i)
{
	int y;

	y = -1;
	if (ft_strcmp(var->paramsliced[i], "R"))
	{
		while (var->paramsliced[i + 1][++y])
			if (!(var->paramsliced[i + 1][y] >= '0'
			&& var->paramsliced[i + 1][y] <= '9'))
				closegame(var, "RES_ERROR");
		y = -1;
		while (var->paramsliced[i + 2][++y])
			if (!(var->paramsliced[i + 2][y] >= '0'
				&& var->paramsliced[i + 2][y] <= '9'))
				closegame(var, "RES_ERROR");
		var->s_w = ft_atoi(var->paramsliced[i + 1]);
		var->s_h = ft_atoi(var->paramsliced[i + 2]);
		if (var->s_w < 0 || var->s_h < 0)
		{
			var->s_w = 1914;
			var->s_h = 924;
		}
	}
}
