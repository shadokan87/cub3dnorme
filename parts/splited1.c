/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splited1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motoure <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 13:41:48 by motoure           #+#    #+#             */
/*   Updated: 2020/08/14 13:41:51 by motoure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cublib.h"

char	*rmspace(char *str)
{
	char	*ret;
	int		newsize;
	int		i;
	int		y;

	newsize = ft_strlen(str) * 2;
	if (!(ret = malloc(sizeof(char) * newsize)))
		return (NULL);
	i = 0;
	y = 0;
	while (y < newsize - 1)
	{
		if (y % 2 == 0)
		{
			ret[y] = str[i] == ' ' ? '1' : str[i];
			i++;
		}
		else
			ret[y] = ' ';
		y++;
	}
	ret[newsize - 1] = '\0';
	return (ret);
}

char	*norestrict_remove_s(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'S')
			str[i] = '3';
		else if (str[i] == 'N')
			str[i] = '2';
		else if (str[i] == 'W')
			str[i] = '4';
		else if (str[i] == '2')
			str[i] = '6';
		else if (str[i] == 'E')
			str[i] = '5';
		i++;
	}
	return (str);
}

int		containspace(char *str)
{
	int i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (iswall(str[i]) && iswall(str[i + 1]) && iswall(str[i + 2]))
		return (1);
	return (0);
}

char	**convmap(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		str[i] = rmspace(str[i]);
		str[i] = norestrict_remove_s(str[i]);
		ft_fprintf(1, "%s\n", str[i]);
		i++;
	}
	return (str);
}

char	**convspace(char **str)
{
	int i;
	int y;
	int z;

	i = 0;
	y = 0;
	z = 0;
	while (str[i])
	{
		z = spacecount(str[i]);
		while (z > 0 && y < z)
		{
			if (y % 2 == 0)
				str[i][y] = '1';
			y++;
		}
		y = 0;
		i++;
	}
	return (str);
}
