/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 16:37:08 by yskrypny          #+#    #+#             */
/*   Updated: 2017/05/07 16:37:11 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <errno.h>
# include <unistd.h>
# include "libft/libft.h"
# include "define.h"

typedef struct s_point		t_point;
typedef struct s_line		t_line;
typedef struct s_cfg		t_cfg;
typedef struct s_trv		t_trv;
typedef struct s_id			t_id;
typedef struct s_fl			t_fl;
typedef struct s_d			t_d;
typedef struct s_t			t_t;
typedef struct s_s			t_s;
typedef struct s_r			t_r;
typedef struct s_b			t_b;
typedef struct s_func		t_func;
typedef struct s_compass	t_compass;
typedef struct s_img		t_img;
typedef struct s_mp			t_mp;
typedef struct s_dc			t_dc;

struct	s_func
{
	void (*func)();
};

struct	s_point
{
	double			x;
	double			y;
	double			z;
	unsigned int	c;
};

struct	s_line
{
	int dx;
	int dy;
	int sign_x;
	int sign_y;
	int error;
	int error2;
};

struct	s_fl
{
	int		flag;
	void	(*func)();
};

struct	s_d
{
	int dx;
	int dy;
	int dz;
};

struct	s_t
{
	int tx;
	int ty;
	int tz;
};

struct	s_s
{
	double	sx;
	double	sy;
	double	sz;
	double	w;
};

struct	s_r
{
	double	rx;
	double	ry;
	double	rz;
	double	cos_rx;
	double	sin_rx;
	double	cos_ry;
	double	sin_ry;
	double	cos_rz;
	double	sin_rz;
};

struct	s_b
{
	int bx;
	int by;
	int bz;
};

struct	s_trv
{
	t_d	d;
	t_t	t;
	t_s	s;
	t_r	r;
	t_b	b;
};

struct	s_compass
{
	t_point c;
	t_point x;
	t_point y;
	t_point z;
	t_d		d;
};

struct	s_img
{
	void	*p_img;
	char	*img_d;
	int		bpp;
	int		bs;
	int		line_s;
	int		endian;
	int		w;
	int		h;
	int		px0;
	int		py0;
};

struct	s_mp
{
	t_point	tl;
	t_point	tr;
	t_point	bl;
	t_point	br;
	t_point	mh;
	t_point	lh;
};

struct	s_dc
{
	unsigned int c_low;
	unsigned int c_grnd;
	unsigned int c_mid;
	unsigned int c_high;
};

struct	s_cfg
{
	char			**opt_array;
	int				w_w;
	int				w_h;
	int				px0;
	int				py0;
	int				diff_x;
	int				diff_y;
	double			dgr;
	t_dc			*dc;
	unsigned int	def_bc;
	int				z_b;
	char			*intro;
	char			*intro_h;
	char			*h_btn;
	char			*c_help;
};

struct	s_id
{
	void		*mlx;
	void		*wnd;
	t_img		*img;
	t_cfg		*cfg;
	t_trv		*trv;
	t_point		**map;
	t_mp		*mp;
	t_compass	*com;
	t_fl		*trf;

	int			intro;
	int			map_l;
	int			map_w;
	int			s_hlp;

	int			trpn;
	int			a_flag;
	int			start;
	int			status;
	t_img		*obj_img;
	t_func		*func;
	int			f_cnt;
	char		*xpm_f;

	int			step_x;
	int			step_y;
	int			cen_x;
	int			cen_y;
};

/*
** initialize.c
*/
t_id	*ft_initialize_id_struct(t_id *id, char **av);
void	ft_mlx_param_init(t_id *id);
void	ft_transform_vector_init(t_id *id);
void	ft_create_t_function_array(t_id *id);

/*
** config.c
*/
void	ft_config_init(t_id *id, char *cfg_file);
void	ft_standart_options(t_id *id);
void	ft_option_array(t_id *id);
void	ft_option_list(t_id *id);

/*
** config_parse.c
*/
void	ft_parse_cfgf_int(int *prm, char *opt, char *str, int fd);
void	ft_parse_cfgf_double(double *prm, char *opt, char *str, int fd);
void	ft_parse_cfgf_uint(unsigned int *prm, char *opt, char *str, int fd);
void	ft_parse_cfgf_str(char **prm, char *opt, char *str, int fd);
void	ft_parse_options(t_id *id, int fd);

/*
** map_parser.c
*/
void	ft_map_read(char *map_file, t_id *id);
void	ft_read_map_file(t_id *id, char *map_file);
t_point	*ft_map_parse(t_id *id, t_point *map_ptr, char **array, int col);
int		ft_get_map_z_and_color(t_id *id, t_point *map_ptr, char *map_zc);
int		ft_node_check(t_point *map_ptr, char *map_zc);

/*
** map_parser_check_read.c
*/
void	ft_check_empty_file(char *map_file);
void	ft_check_map_file(t_id *id, char *map_file);
int		ft_count_col(char **array);
void	ft_free_array_and_str(char *str, char **arr);

/*
** intro_and_help.c
*/
void	ft_intro(t_id *id);
void	ft_help(t_id *id);

/*
** main.c
*/
int		main(int ac, char **av);
int		ft_redraw(t_id *id);
int		ft_draw(t_id *id);
void	ft_animation(t_id *id);

/*
** mages_and_xpm.c
*/
void	ft_xpm_to_wnd(t_id *id, char *name, int x, int y);
void	ft_create_image(t_id *id, t_img *img, int w, int h);
void	ft_put_image(t_id *id, t_img *img, int x, int y);
void	ft_map_to_img_and_wnd(t_id *id);
void	ft_put_map_on_image(t_id *id);

/*
** map_recalculation.c
*/
void	ft_prepare_map(t_id *id);
void	ft_check_changes(t_id *id);
void	ft_transparency(t_id *id);
void	ft_clear_trv(t_id *id);
void	ft_prepare_trv(t_id *id);

/*
** point_draw_line.c
*/
void	ft_prepare_line(t_line *line, t_point *p_st, t_point *p_end, t_d *d);
void	ft_draw_line_to_img(t_id *id, t_point p_st, t_point p_end, t_d *d);
void	ft_draw_line_to_wnd(t_id *id, t_point p_st, t_point p_end, t_d *d);

/*
** point_draw.c
*/
void	ft_point_no_shift_to_img(t_point point, t_img *img);
void	ft_point_no_shift_to_wnd(t_id *id, t_point point);
void	ft_point_shift_to_wnd(t_id *id, t_point point, t_d *d);
void	ft_point_shift_to_img(t_point point, t_d *d, t_img *img);

/*
** point_transformation.c
*/
void	ft_transform_point(t_id *id, t_point *point);
void	ft_make_arr_of_transform_functions(t_id *id);
void	ft_arr_function_check_flag_add(t_id *id);

/*
** point_check_vision.c
*/
int		ft_check_vision_wnd(t_id *id, t_point *point);
int		ft_check_vision_img(t_point *point, t_img *img);

/*
** point_scale.c
*/
void	ft_scale_x(t_id *id, t_point *point);
void	ft_scale_y(t_id *id, t_point *point);
void	ft_scale_z(t_id *id, t_point *point);
void	ft_scale_all(t_id *id, t_point *point);

/*
** point_shift.c
*/
void	ft_shift_x(t_id *id, t_point *point);
void	ft_shift_y(t_id *id, t_point *point);
void	ft_shift_z(t_id *id, t_point *point);

/*
** point_rotation.c
*/
void	ft_rotate_x(t_id *id, t_point *point);
void	ft_rotate_y(t_id *id, t_point *point);
void	ft_rotate_z(t_id *id, t_point *point);

/*
** controls.c
*/
int		ft_my_key_function(int keycode, t_id *id);
void	ft_mouse_button_click(int button, int x, int y, t_id *id);
int		ft_my_mouse_function(int button, int x, int y, t_id *id);

/*
** controls_keycode_functions.c
*/
void	ft_general_keys(int keycode, t_id *id);
void	ft_shift_keys(int keycode, t_id *id);
void	ft_rotation_xy_keys(int keycode, t_id *id);
void	ft_rotation_z_scale_keys(int keycode, t_id *id);
void	ft_transparency_animation_keys(int keycode, t_id *id);

/*
** compass.c
*/
void	ft_create_and_prep_compass(t_id *id);
void	ft_compass_rotation(t_id *id);
void	ft_draw_compass(t_id *id);

/*
** additional stuff.c
*/
void	ft_exit_error(int err);
void	ft_string_put(t_id *id, t_point point, t_d d, char *str);

#endif
