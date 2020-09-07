/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splited12.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motoure <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 13:41:20 by motoure           #+#    #+#             */
/*   Updated: 2020/08/14 13:41:22 by motoure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cublib.h"

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

void	fill_color(t_var *var, int i)
{
	/*
	if (i <= 8 && i != 7)
		var->text_paths[i] = NULL;
	*/
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

int     is_token(char **token, char *str)
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

void	ft_movestr(char **str, char *str2)
{
	int i;

	i = 0;
	while (str2[i])
	{
		ft_putchar_str(str, str2[i]);
		i++;
	}
}

void    check_conf(t_var *var)
{
    int i;
	int ret;
	
	ret = 0;
    i = 0;
	while (var->paramsliced[i])
	{
		if ((ft_strcmp(var->paramsliced[i], "R")) ||
			(ft_strcmp(var->paramsliced[i], "C")) ||
			(ft_strcmp(var->paramsliced[i], "F")))
				ret++;
		if (ret == 3)
			break ;
		i++;
	}
	if (ret != 3)
		closegame(var, "No Res/Color");
}

void	fillloopparams(t_var *var)
{
	int i;

	i = -1;
	check_conf(var);
	while (var->paramsliced[++i] != NULL)
	{
		get_res(var, i);
		if (ft_strcmp(var->paramsliced[i], "NO"))
			var->text_paths[2] = ft_strdup(var->paramsliced[i + 1]);
		if (ft_strcmp(var->paramsliced[i], "SO"))
			var->text_paths[3] = ft_strdup(var->paramsliced[i + 1]);
		if (ft_strcmp(var->paramsliced[i], "WE"))
			var->text_paths[4] = ft_strdup(var->paramsliced[i + 1]);
		if (ft_strcmp(var->paramsliced[i], "EA"))
			var->text_paths[5] = ft_strdup(var->paramsliced[i + 1]);
		if (ft_strcmp(var->paramsliced[i], "S"))
			var->text_paths[6] = ft_strdup(var->paramsliced[i + 1]);
		fill_color(var, i);
	}
}

int		getred(int rgb, t_var *var)
{
	char	str[3];
	char	*hex;
	int		i;

	i = 0;
	hex = ft_putnbr_base(rgb, HEXD);
	if (rgb == 0)
		return (0);
	str[0] = hex[0];
	str[1] = hex[1];
	str[2] = '\0';
	if (str[0] == '0' && str[1] == '0')
		str[1] = '\0';
	while (i < 255)
	{
		if (ft_strcmp(var->hextable[i], str))
			return (i);
		i++;
	}
	return (255);
}

int		getblue(int rgb, t_var *var)
{
	char	str[3];
	char	*hex;
	int		i;

	i = 0;
	hex = ft_putnbr_base(rgb, HEXD);
	if (rgb == 0)
		return (0);
	str[0] = hex[4];
	str[1] = hex[5];
	str[2] = '\0';
	if (str[0] == '0' && str[1] == '0')
		str[1] = '\0';
	while (i < 255)
	{
		if (ft_strcmp(var->hextable[i], str))
			return (i);
		i++;
	}
	return (255);
}

int		getgreen(int rgb, t_var *var)
{
	char	str[3];
	char	*hex;
	int		i;

	i = 0;
	hex = ft_putnbr_base(rgb, HEXD);
	if (rgb == 0)
		return (0);
	str[0] = hex[2];
	str[1] = hex[3];
	str[2] = '\0';
	if (str[0] == '0' && str[1] == '0')
		str[1] = '\0';
	while (i < 255)
	{
		if (ft_strcmp(var->hextable[i], str))
			return (i);
		i++;
	}
	return (255);
}
