/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 16:23:03 by mchi              #+#    #+#             */
/*   Updated: 2019/03/03 22:47:52 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define PI 3.14159265359
# define MAGENTA 0x00FF00

# define X 0
# define Y 1
# define Z 2

# define MIN(a,b) (((a)<(b))?(a):(b))
# define MAX(a,b) (((a)>(b))?(a):(b))

# include <mlx.h>
# include <stdlib.h>
# include <libft.h>
# include <math.h>

typedef unsigned int	t_uint;

typedef struct	s_matrix
{
	double val[4][4];
}				t_matrix;

typedef struct	s_vector
{
	double x;
	double y;
	double z;
	double w;
}				t_vector;

typedef struct	s_quad
{
	t_uint index[4];
}				t_quad;

/*
**	x-axis rotation
**	y-axis rotation
**	kept as rad
**	dist == distance to origin
*/
typedef struct	s_cam
{
	double	x;
	double	y;
	double	dist;
}				t_cam;

typedef struct	s_img
{
	char	*ptr;
	char	*data_addr;
	int		sl;
	int		bpp;
	int		endian;
}				t_img;


typedef struct	s_app
{
	void		*mlx_handle;
	void		*wnd_handle;
	t_uint		width;
	t_uint		height;
	t_vector	*vertex_buffer;
	t_vector	*eval_vertex_buffer;
	t_uint		vertex_count;
	t_quad		*quad_buffer;
	t_uint		quad_count;
	t_cam		cam;
	int			prev_x;
	int			prev_y;
	int			x;
	int			y;
	int			rotate;
	int			zoom;
	double		zoom_factor;
	int			x_dim;
	int			y_dim;
	t_img		img;
	int			max_z;
	int			min_z;
	t_uint		min_color;
	t_uint		max_color;
}				t_app;

int				init_app(t_app **app);
int				read_file(t_app *app, char *file);

t_uint			hex_to_uint(char *str);
int				app_expose(void *param);
int				app_looper(void *param);
int				app_key_press(int keycode, void *param);
int				app_key_release(int keycode, void *param);
void			init_img(t_app *app);

int				app_mouse_press(int button, int x, int y, void *param);
int				app_mouse_release(int button, int x, int y, void *param);
int				app_mouse_move(int x, int y, void *param);

t_matrix		matrix_mul(t_matrix lhs, t_matrix rhs);
void			vector_transform(t_vector *ret, t_vector *vec, t_matrix *mat);
t_matrix		rotation_matrix(double x, double y, double z);
void			assign_vector_to_matrix(t_matrix *mat, t_vector *vec, int x);
void			matrix_identity(t_matrix *mat);

double			vector_abs(t_vector vec);
t_vector		vector_normal(t_vector vec);
double			vector_dot(t_vector *lhs, t_vector *rhs);
t_vector		vector_cross(t_vector lhs, t_vector rhs);
t_vector		assign_vector(double x, double y, double z, double w);

void			enter_vector(t_app *app, int i, int j, double z);
void			enter_quad(t_app *app);
void			draw_quad(t_app *app, t_quad quad);

t_matrix		look_at(t_cam cam);
t_matrix		perspective(t_app *app);
t_matrix		screen_mapping(t_app *app);

char			*ft_itoa(int n);
int				ft_count_digit(int n);

void			img_pixel_put(t_app *app, int x, int y, int color);

#endif
