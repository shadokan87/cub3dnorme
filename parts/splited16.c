/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splited16.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motoure <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 00:35:36 by motoure           #+#    #+#             */
/*   Updated: 2020/08/20 00:36:35 by motoure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cublib.h"

int	ismap(char *str)
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