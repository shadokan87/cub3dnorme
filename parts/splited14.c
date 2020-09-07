/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splited14.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motoure <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 13:41:29 by motoure           #+#    #+#             */
/*   Updated: 2020/08/14 13:41:30 by motoure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cublib.h"

void		*ft_memset(void *b, int c, size_t len)
{
	unsigned long	i_array_b;
	unsigned char	*a;

	i_array_b = 0;
	a = (unsigned char *)b;
	while (i_array_b < len)
	{
		a[i_array_b] = (unsigned char)c;
		i_array_b++;
	}
	b = a;
	return (b);
}

int			rgb_int(int red, int green, int blue)
{
	int	rgb;

	rgb = red;
	rgb = (rgb << 8) + green;
	rgb = (rgb << 8) + blue;
	return (rgb);
}

char		*remove_extraspaces(char *str)
{
	char	*return_value;
	int		i;
	int		y;

	i = 0;
	y = 0;
	if (!(return_value = malloc(sizeof(char) * strlen(str))))
		return (0);
	while (str[i])
	{
		if (!(str[i] && str[i] == ' ' && str[i - 1] == ' '))
		{
			return_value[y] = str[i];
			y++;
		}
		i++;
	}
	return (return_value);
}

int			iswall(char c)
{
	if (c == '4')
		return (1);
	else if (c == '5')
		return (5);
	else if (c == '3')
		return (3);
	else if (c == '2')
		return (2);
	else if (c == '1')
		return (1);
	return (0);
}

int			getmapindex(t_var *var)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (var->paramfile && var->paramfile[i])
	{
		if (iswall(var->paramfile[i]) && var->paramfile[i + 1] ==
		' ' && iswall(var->paramfile[i + 2]))
			return (i);
		i++;
	}
	return (-1);
}
