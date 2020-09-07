/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splited0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motoure <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 13:40:00 by motoure           #+#    #+#             */
/*   Updated: 2020/08/14 13:40:03 by motoure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cublib.h"

void		getmapfromparamfile(t_var *var)
{
	int		i;
	int		index;
	char	**str;

	str = getmapstr(var);
	index = getmapindex(var);
	i = 0;
	if (containspace(str[0]))
		str = convmap(str);
	checkmap(str, var);
	var->m_width = getmapwidth(str);
	ft_fprintf(1, "width = %d\n", var->m_width);
	if (!(var->m_height = getmapheight(str)))
		closegame(var, "MaP_NOT_CLOsEd");
	str = convspace(str);
	while (str[i])
	{
		ft_fprintf(1, "%s\n", str[i]);
		i++;
	}
	duplicate_map(var, str);
	if (var->posx == -1 || var->posy == -1)
		closegame(var, "NO_PLaYER_sTaRT");
	initspritequeue(var);
}

void		checkcolor(t_var *var)
{
	int i;

	i = 0;
	while (i < 3)
	{
		if (!(var->f_color[i] > -1 && var->f_color[i] < 256))
			closegame(var, "COLOR_ERROR");
		i++;
	}
	i = 0;
	while (i < 3)
	{
		if (!(var->c_color[i] > -1 && var->c_color[i] < 256))
			closegame(var, "COLOR_ERROR");
		i++;
	}
}

void		inithextable(t_var *var)
{
	int i;

	i = 0;
	while (i <= 255)
	{
		var->hextable[i] = ft_putnbr_base(i, HEXD);
		i++;
	}
}

static void	init_struct2(t_var *var)
{
	inithextable(var);
	var->posx = -1;
	var->posy = -1;
	var->paramfile = NULL;
	var->paramsliced = NULL;
	var->screenshot = 0;
	var->mlx_win = NULL;
	var->mlx_ptr = NULL;
	var->addr = NULL;
}

void		init_struct(t_var *var, char **argv)
{
	int		fd;
	char	*line;
	int		i;

	i = -1;
	init_struct2(var);
	if (ft_strcmp(argv[1], "--save"))
		var->screenshot = 1;
	fd = open(argv[var->screenshot == 1 ? 2 : 1], O_RDONLY);
	getparamfile(fd, &line, var);
	getmapfromparamfile(var);
	initcolormap(var);
	while (var->paramfile[++i])
		var->paramfile[i] == '\n' ? (var->paramfile[i] = ' ') : 0;
	var->paramsliced = ft_split(var->paramfile, ' ');
	if (!(var->text_paths = malloc(sizeof(char *) * 9)))
		return ;
	fillloopparams(var);
	checkcolor(var);
}
