/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splited12.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motoure <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 13:41:20 by motoure           #+#    #+#             */
/*   Updated: 2020/09/07 17:55:32 by motoure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cublib.h"

void	check_conf(t_var *var)
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
