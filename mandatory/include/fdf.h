/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 03:00:55 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/14 13:05:21 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <string.h>
# include <stdio.h>
# include <errno.h>
# include <math.h>
# include "mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include "libft.h"

# define W_WIDTH 1920
# define W_HEIGHT 1080
# define COLOR_BIT_SIZE 32
# define PIXEL_PER_ROTATE 8
# define DEG_TO_RAD 0.01745329251994329547 // (M_PI / 180.0)
# define RAD_TO_DEG 57.29577951308232286465 // (180.0 / M_PI)

typedef struct s_color
{
	double	r;
	double	g;
	double	b;
	int		rgb;
}	t_color;

typedef struct s_4d
{
	double	x;
	double	y;
	double	z;
	double	w;
}	t_4d;

typedef struct s_3d
{
	double	x;
	double	y;
	double	z;
}	t_3d;

typedef struct s_2d
{
	double	x;
	double	y;
}	t_2d;

typedef struct s_screen
{
	int		x;
	int		y;
	double	z_depth;
	t_color	color;
}	t_screen;

typedef struct s_point
{
	t_4d		model;
	t_4d		view;
	t_screen	pixel;
}	t_point;

typedef struct s_affine_matrix
{
	double	m[4][4];
}	t_affine_matrix;

typedef struct s_line
{
	int		abs_dx;
	double	inv_dx;
	int		abs_dy;
	double	inv_dy;
	double	dz_depth;
	int		x_step;
	int		y_step;
	int		error;
	double	alpha;
}	t_line;

typedef struct s_map
{
	t_point	**points;
	int		row_size;
	int		col_size;
}	t_map;

typedef struct s_transform
{
	t_3d			max_3d;
	t_3d			min_3d;
	t_3d			centroid;
	t_2d			max_2d;
	t_2d			min_2d;
	double			model_scale;
	t_affine_matrix	affine_matrix;
}	t_transform;

typedef struct s_img
{
	void	*img_ptr;
	int		width;
	int		height;
	char	*pixel;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	double	**z_buffer;
}	t_img;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		width;
	int		height;
	t_img	model_img;
}	t_mlx;

// argument
void			check_argument(int argc, char **argv);
void			invalid_arguments_count_error(void);
void			invalid_map_file_extension_error(void);

// map
void			create_map(t_map *map, char *map_file_path);
t_list			*read_file_as_lst(char *map_file_path);
void			parse_rgb(t_color *color, char *rgb);
size_t			ft_sizet_lstsize(t_list *lst);
void			free_splitted(char **splitted);
void			clear_map_data(char ***map_data);
bool			check_int(char *num);
void			clear_map(t_map *map);
void			errno_error(char *error_point);
void			invalid_map_error(char *error_msg);

// trasform
void			init_transform(\
					t_map *map, t_transform *transform);
void			calc_centroid(t_map *map, t_transform *transform);
void			calc_iso_projected_bounds(t_map *map, t_transform *transform);
void			transformation(t_map *map, t_transform *transform);
t_affine_matrix	make_identity_matrix(void);
t_affine_matrix	make_scale_matrix(double scale);
t_affine_matrix	make_translation_matrix(t_3d translation);
t_affine_matrix	make_x_rotation_matrix_euler(double deg);
t_affine_matrix	make_y_rotation_matrix_euler(double deg);
t_affine_matrix	make_z_rotation_matrix_euler(double deg);
void			set_matrix_row(double matrix_row[4], double row[4]);
t_3d			invert_pos_3d(t_3d pos);
t_affine_matrix	affine_matrix_multiply(
					t_affine_matrix multiplier, t_affine_matrix multiplicand);
void			affine_transform(t_map *map, t_affine_matrix affine_matrix);
void			apply_affine_transform(t_point *point, double matrix[4][4]);
void			orthographic_projection(t_map *map);

// mlx
void			ft_init_mlx(t_map *map, t_mlx *mlx);
bool			ft_mlx_init_model_image(t_mlx *mlx);
bool			create_z_buffer(t_img *img);
void			ft_mlx_hooks(t_mlx *mlx);
int				expose_hook(t_mlx *mlx);
int				key_press_hook(int keycode, t_mlx *mlx);
void			redraw_window(t_mlx *mlx);
unsigned int	*ft_mlx_get_pixel_addr(t_img img, int x, int y);
void			ft_mlx_destroy(t_mlx *mlx);
void			clear_z_buffer(t_img *img);
void			ft_mlx_error_handler(\
					t_map *map, t_mlx *mlx, void (*ft_error_func)(void));
void			ft_mlx_create_connection_error(void);
void			ft_mlx_create_window_error(void);
void			ft_mlx_create_image_error(void);

// drawer
void			draw_wireframe(t_map *map, t_mlx *mlx);
void			draw_line(t_mlx *mlx, t_point start, t_point end);
int				lerp_color(t_color start, t_color end, double alpha);
t_line			set_line_info(t_screen start, t_screen end);
void			draw_pixel(t_mlx *mlx, t_screen pixel);

#endif