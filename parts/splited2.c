/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splited2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motoure <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 13:41:53 by motoure           #+#    #+#             */
/*   Updated: 2020/08/14 13:41:56 by motoure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cublib.h"

int		checktop(char *str)
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

int		issymbol(char c)
{
	if (c == '4')
		return (1);
	else if (c == '5')
		return (1);
	else if (c == '6')
		return (1);
	else if (c == '2')
		return (1);
	else if (c == '1')
		return (1);
	else if (c == '3')
		return (1);
	else if (c == '0')
		return (1);
	return (0);
}

void	lineisok(char *str, t_var *var)
{
	int i;

	i = 0;
	if (str[i] && str[i] == ' ')
	{
		while (str[i] && str[i] == ' ')
			i++;
	}
	if (!iswall(str[i]))
		closegame(var, "MaP_NOT_CLOsEd");
	while (str[i])
	{
		if (str[i] == ' ')
			i++;
		if (!issymbol(str[i]))
			closegame(var, "MaP_sYMBOL_UNKNOwN");
		i++;
	}
	if (!iswall(str[i - 1]))
		closegame(var, "MaP_NOT_CLOsEd");
}

void	checkmiddle(char **str, t_var *var)
{
	int i;
	int y;

	i = 0;
	y = 0;
	while (str[i + 1])
	{
		lineisok(str[i], var);
		i++;
	}
}

void	checkmap(char **str, t_var *var)
{
	int i;

	i = 0;
	if (!checktop(str[0]))
		closegame(var, "MaP_NOT_CLOsEd");
	checkmiddle(str, var);
	while (str[i])
		i++;
	if (!(checkbottom(str[i - 1])))
		closegame(var, "MaP_NOT_CLOsEd");
}
