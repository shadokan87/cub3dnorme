/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cublib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motoure <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 13:43:52 by motoure           #+#    #+#             */
/*   Updated: 2020/09/07 18:40:42 by motoure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBLIB_H
# define CUBLIB_H
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include "gnl_working/get_next_line.h"
# include "ft_fprintf/lprintf.h"
# include "mlx/mlx.h"
# include <math.h>
# include <unistd.h>
# include <stdint.h>
# define ROTSPEED 0.1
# define MOVESPEED 0.1

typedef struct	s_var
{
	double		vmove;
	double		spritex;
	double		spritey;
	double		invdet;
	double		transformx;
	double		transformy;
	int			vmovescreen;
	int			spriteheight;
	int			drawstarty;
	int			drawendy;
	int			spritewidth;
	int			drawstartx;
	int			vc;
	int			drawendx;
	int			texx;
	int			texy;
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	double		time;
	double		camerax;
	double		raydirx;
	double		raydiry;
	double		sidedistx;
	double		sidedisty;
	double		deltadistx;
	double		deltadisty;
	double		perpwalldist;
	char		*hextable[255];
	float		step;
	int			screenshot;
	int			mapx;
	int			mapy;
	int			stepx;
	int			stepy;
	int			hit;
	int			wallx;
	int			ompx;
	int			ompy;
	int			tex_y;
	int			texpos;
	int			tex_x;
	int			tex_h;
	int			tex_w;
	int			**spritequeue;
	int			*queue;
	double		*dist;
	void		*t_img;
	int			*t_addr;
	int			spritehit;
	int			side;
	int			lineheight;
	int			drawstart;
	int			drawend;
	int			*img_data;
	int			color;
	int			esc;
	int			w;
	int			a;
	int			s;
	int			d;
	int			l_r;
	int			r_r;
	void		*img;
	int			t_endian;
	int			**colormap;
	int			t_bpp;
	int			t_line;
	int			endian;
	int			bpp;
	int			line;
	int			offset;
	int			x;
	int			s_h;
	int			s_w;
	int			m_width;
	int			m_height;
	char		**text_paths;
	int			**loaded_text;
	int			**loaded_addr;
	char		*paramfile;
	int			f_color[3];
	int			c_color[3];
	char		**paramsliced;
	double		zbuffer[10000];
	int			y;
	int			spritenum;
	int			*sx;
	int			*sy;
	int			spritescreenx;
	double		s_spritex;
	double		s_spritey;
	int			*spriteorder;
	char		*addr;
	void		*mlx_ptr;
	void		*mlx_win;
	int			**map;
}				t_var;

int				ismap(char *str);
int				is_token(char **token, char *str);
void			fill_color(t_var *var, int i);
void			get_res(t_var *var, int i);
void			check_color(t_var *var, char *str);
void			closegame(t_var *var, char *message);
void			*ft_memset(void *b, int c, size_t len);
int				rgb_int(int red, int green, int blue);
char			*remove_extraspaces(char *str);
int				iswall(char c);
int				getmapindex(t_var *var);
int				nospacegetmapindex(char *str);
char			*removes(char *str, t_var *var);
void			getparamfile(int fd, char **line, t_var *var);
int				ft_strcmp(char *str, char *str2);
void			fill_color(t_var *var, int i);
void			fillloopparams(t_var *var);
int				getred(int rgb, t_var *var);
int				getblue(int rgb, t_var *var);
int				getgreen(int rgb, t_var *var);
int				sip(char *base, char c);
int				ismap(char *str);
void			pixel_put_fd(t_var *var, int color, int fd);
void			pixel_put(t_var *var, int x, int y, int color);
int				verline(t_var *var, int x, int draw_start,
int draw_end);
void			init_raycast(t_var *var);
void			step(t_var *var);
int				*cpy(t_var *var, int *tab);
double			*sortqueue(t_var *var, double *dist);
double			*getdist(t_var *var);
void			init_sprite_var(t_var *var, int sx, int sy);
void			draw_sprite(t_var *var, int sx, int sy);
void			hit(t_var *var);
void			cls(t_var *var);
void			draw_info(t_var *var);
void			draw_texture(t_var *var);
int				convhex(char *hex);
void			draw(t_var *var);
void			raycast(t_var *var);
void			init_keys(t_var *var, int key_number);
int				key_pressed(int keycode, t_var *var);
int				key_released(int keycode, t_var *var);
int				move_is_possible(int pos);
void			fwd_bckwrd(t_var *var);
void			x_y(t_var *var);
void			l_r(t_var *var);
int				movement(t_var *var);
int				listen_keys(t_var *var);
void			load_text(t_var *var);
unsigned int	*getheader(int width, int height, int paddedsize);
void			writeheader(int fd, unsigned int *headers);
void			writecolor(t_var *var, int extrabytes, int fd);
void			drawbmp(char *filename, t_var *var);
int				screenshot(t_var *var);
int				run(t_var *var);
int				start(t_var *var);
int				**copymap(int height, int width, int index, t_var *var);
int				spacecount(char *str);
int				checkline(char *str, int y);
int				*init_to_fill(t_var *var);
int				getmapheight(char **str);
int				getmapwidth(char **str);
void			initspritequeue(t_var *var);
void			duplicate_map(t_var *var, char **str2);
int				skip(char ***split);
char			**getmapstr(t_var *var);
int				checkbottom(char *str);
int				checktop(char *str);
int				issymbol(char c);
void			lineisok(char *str, t_var *var);
void			checkmiddle(char **str, t_var *var);
void			checkmap(char **str, t_var *var);
char			*rmspace(char *str);
char			*norestrict_remove_s(char *str);
int				containspace(char *str);
char			**convmap(char **str);
char			**convspace(char **str);
void			getmapfromparamfile(t_var *var);
void			checkcolor(t_var *var);
void			inithextable(t_var *var);
void			initcolormap(t_var *var);
void			init_struct(t_var *var, char **argv);

#endif
