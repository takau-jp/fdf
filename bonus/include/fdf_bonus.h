/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 03:00:49 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/22 21:32:40 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

# include <fcntl.h>
# include <string.h>
# include <stdio.h>
# include <errno.h>
# include <math.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
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
# define TRANSLATION_LIMIT 100000
# define Z_NEAR_CLIP 1.0
# define INSIDE_OUTCODE 0 // 0000
# define LEFT_OUTCODE 1 // 0001
# define RIGHT_OUTCODE 2 // 0010
# define BOTTOM_OUTCODE 4 // 0100
# define TOP_OUTCODE 8 // 1000
# define CP_WIDTH 300
# define CP_PARALLEL_HEIGHT 380
# define CP_PERSPECTIVE_HEIGHT 420
# define CP_FPS_HEIGHT 260
# define CP_WINDOW_OFFSET 50
# define CP_COLOR 0x222222
# define CP_ALPHA 0.5
# define MSG_COLOR 0xFFFFFF
# define MSG_LINE_HEIGHT 20
# define MSG_CONTROL_PANEL "Control Panel Show/Hide [SPACE KEY]"
# define MSG_RESET "Reset Transforms [BACKSPACE KEY]"
# define MSG_PROJECTION_MODE "Projection Mode [P]:"
# define MSG_COLOR_MODE "Color Mode [C]:"
# define MSG_LENS_MODE "Lens Mode [L]:"
# define MSG_SCALE_MODE "Scale Mode [S]:"
# define MSG_SCALE_CONTROL "   |  + / - [Scroll]"
# define MSG_ZOOM_SCALE "   |- Zoom Scale:"
# define MSG_MODEL_SCALE "   |- Model Scale:"
# define MSG_TRANSLATION_MODE "Translation Mode [T]:"
# define MSG_TRANSLATION_CONTROL "   |  + / - [X-Y-Z KEY] / [SHIFT & X-Y-Z KEY]"
# define MSG_MODEL_TRANSLATION "   |- Model X / Y / Z:"
# define MSG_VIEW_TRANSLATION "   |- View X / Y / Z:"
# define MSG_ROTATION_MODE "Rotation Mode [R]:"
# define MSG_ROTATION_CONTROL "   | [Mouse Drag (RIGHT CLICK)]"
# define MSG_MODEL_ROTATION "   |- Model X / Y / Z:"
# define MSG_VIEW_ROTATION "   |- View X / Y / Z:"
# define MSG_SCREEN_TRANSLATION "Screen Translation"
# define MSG_SCREEN_TRANSLATION_CONTROL "   |  [ARROW KEYS]"
# define MSG_SCREEN_TRANSLATION_STATUS "   |- Screen X / Y:"
# define MSG_FPS_PLAYER_POS "Player Position X / Z:"
# define MSG_FPS_PLAYER_POS_CONTROL "   |  [ARROW KEYS]"
# define MSG_FPS_PLAYER_ANGLE "Player Angle X / Y:"
# define MSG_FPS_PLAYER_ANGLE_CONTROL "   | [Mouse Drag (RIGHT CLICK)]"

enum e_projection_mode
{
	PARALLEL,
	PERSPECTIVE,
	FPS,
};

enum e_color_mode
{
	DEFAULT,
	SET_1,
	SET_2,
	SET_3,
	GEOMETRIC,
};

enum e_translation_mode
{
	MODEL_TRANSLATION,
	VIEW_TRANSLATION,
};

enum e_rotation_mode
{
	NORMAL_ROTATION,
	MODEL_ROTATION,
	VIEW_ROTATION,
};

enum e_lens_mode
{
	STANDARD,
	WIDE,
	SUPER_WIDE,
	TELEPHOTO,
	SUPER_TELEPHOTO,
};

enum e_scale_mode
{
	ZOOM_SCALE,
	MODEL_SCALE,
};

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

typedef struct s_player_pos
{
	int		x;
	int		z;
}	t_player_pos;

typedef struct s_quaternion
{
	double	w;
	double	x;
	double	y;
	double	z;
}	t_quaternion;

typedef struct s_euler_angle
{
	double	x;
	double	y;
	double	z;
}	t_euler_angle;

// Axis-Aligned Bounding Box
typedef struct s_aabb
{
	t_3d	max;
	t_3d	min;
}	t_aabb;

typedef struct s_point
{
	t_4d		model;
	t_4d		view;
	t_4d		clip;
	t_screen	pixel;
	t_color		colors[5];
	bool		out_of_fov;
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
	int		size;
	int		row_size;
	int		col_size;
	double	max_height;
	double	min_height;
}	t_map;

typedef struct s_transform
{
	t_3d			max_3d;
	t_3d			min_3d;
	t_3d			centroid;
	t_2d			max_2d;
	t_2d			min_2d;
	t_3d			model_translation;
	t_quaternion	model_rotation;
	t_euler_angle	model_angle;
	t_3d			view_translation;
	t_quaternion	view_rotation;
	t_euler_angle	view_angle;
	t_2d			screen_translation;
	double			model_scale;
	double			model_scale_max;
	double			zoom_scale;
	double			zoom_x;
	double			zoom_y;
	double			near;
	double			far;
	t_player_pos	player;
	t_euler_angle	player_angle;
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

typedef struct s_mode
{
	char	msg[256];
	bool	control_panel_visible;
	int		projection;
	int		color;
	int		translation;
	int		rotation;
	int		lens;
	int		scale;
}	t_mode;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		width;
	int		height;
	t_img	model_img;
	bool	is_shift_pressed;
	t_2d	mouse;
}	t_mlx;

typedef struct s_ctx
{
	t_map			*map;
	t_mlx			*mlx;
	t_transform		*transform;
	t_mode			*mode;
}	t_ctx;

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
					t_map *map, t_transform *transform, t_mode *mode);
void			calc_centroid(t_map *map, t_transform *transform);
void			calc_iso_projected_bounds(t_map *map, t_transform *transform);
void			reset_transform(t_transform *transform, t_mode *mode);
void			transform(t_map *map, t_transform *transform, t_mode *mode);
t_affine_matrix	make_identity_matrix(void);
t_affine_matrix	make_scale_matrix(double scale);
t_affine_matrix	make_rotation_matrix_quaternion(t_quaternion quaternion);
t_affine_matrix	make_translation_matrix(t_3d translation);
t_affine_matrix	make_x_rotation_matrix_euler(double deg);
t_affine_matrix	make_y_rotation_matrix_euler(double deg);
t_affine_matrix	make_z_rotation_matrix_euler(double deg);
void			set_matrix_row(double matrix_row[4], double row[4]);
t_affine_matrix	make_init_view_matrix(void);
t_aabb			get_aabb(t_map *map);
t_affine_matrix	make_calc_w_matrix(void);
t_affine_matrix	make_clip_matrix(t_transform *transform);
t_affine_matrix	make_player_angle_matrix(t_transform *transform);
t_3d			set_player_pos(t_map *map, t_transform *transform);
t_affine_matrix	affine_matrix_multiply(
					t_affine_matrix multiplier, t_affine_matrix multiplicand);
void			affine_transform(t_map *map, t_affine_matrix affine_matrix);
void			apply_affine_transform(t_point *point, double matrix[4][4]);
void			orthographic_projection(\
					t_map *map, t_transform *transform, t_mode *mode);
void			perspective_projection(\
					t_map *map, t_transform *transform, t_mode *mode);
t_quaternion	make_quaternion(char axis, double deg);
t_quaternion	quaternion_multiply(
					t_quaternion multiplier, t_quaternion multiplicand);
void			quaternion_normalize(t_quaternion *q);
t_3d			invert_pos_3d(t_3d pos);

// mlx
void			ft_init_mlx(t_map *map, t_mlx *mlx);
bool			ft_mlx_init_model_image(t_mlx *mlx);
bool			create_z_buffer(t_img *img);
bool			ft_mlx_reset_model_image(t_mlx *mlx);
void			reset_z_buffer(t_img *img);
void			ft_mlx_hooks(t_map *map, t_transform *transform, \
								t_mlx *mlx, t_mode *mode);
int				expose_hook(t_ctx *ctx);
int				key_press_hook(int keycode, t_ctx *ctx);
void			change_model_translation(\
					int keycode, t_mlx *mlx, t_transform *transform);
void			change_view_translation(\
					int keycode, t_mlx *mlx, t_transform *transform);
void			change_screen_translation(int keycode, t_transform *transform);
int				key_release_hook(int keycode, t_ctx *ctx);
int				button_press_hook(\
					unsigned int button, int x, int y, t_ctx *ctx);
bool			change_model_scale(unsigned int button, t_transform *transform);
bool			change_zoom_scale(\
					unsigned int button, t_transform *transform, t_mode *mode);
int				button1_motion_hook(int x, int y, t_ctx *ctx);
bool			change_normal_rotation(int x, int y, t_ctx *ctx);
bool			change_view_rotation(int x, int y, t_ctx *ctx);
bool			change_model_rotation(int x, int y, t_ctx *ctx);
bool			change_player_angle(int x, int y, t_ctx *ctx);
bool			change_player_position(\
					int keycode, t_map *map, t_transform *transform);
void			redraw_window(t_ctx *ctx);
unsigned int	*ft_mlx_get_pixel_addr(t_img img, int x, int y);
void			ft_mlx_destroy(t_mlx *mlx);
void			clear_z_buffer(t_img *img);
void			increment_in_range(int *value, int min, int max);
void			decrement_in_range(int *value, int min, int max);
void			change_with_limit(int *value, int delta, int min, int max);
void			change_double_with_limit(double *value, double delta, \
					double min, double max);
void			change_euler_angle(double *angle, double delta);
void			ft_mlx_error_handler(\
					t_map *map, t_mlx *mlx, void (*ft_error_func)(void));
void			ft_mlx_create_connection_error(void);
void			ft_mlx_create_window_error(void);
void			ft_mlx_create_image_error(void);

// feature
void			init_modes(t_map *map, t_transform *transform, t_mode *mode);
void			set_my_colors(t_map *map);
void			set_lens(t_transform *transform, t_mode *mode, int lens_type);
void			set_scale_mode(t_transform *transform, t_mode *mode);
int				get_geometric_color(double geo_level);
int				get_color_set1(double color_level);
int				get_color_set2(double color_level);
int				get_color_set3(double color_level);

// drawer
void			draw_wireframe(t_ctx *ctx);
void			draw_line(t_ctx *ctx, t_point start, t_point end);
t_point			lerp_to_near_clip(t_ctx *ctx, t_point out, t_point in);
bool			clip_line(t_screen *start, t_screen *end);
t_screen		lerp_pixel(t_screen	start, t_screen end, double alpha);
int				lerp_color(t_color start, t_color end, double alpha);
t_line			set_line_info(t_screen start, t_screen end);
void			draw_pixel(t_mlx *mlx, t_screen pixel);
void			draw_control_panel(t_mlx *mlx, t_mode *mode);
int				source_over_alpha_blend(int dst_rgb, double dst_alpha, \
					int src_rgb, double src_alpha);
void			draw_status(t_ctx *ctx);
void			draw_control_panel_msg(t_ctx *ctx, int x, int *y);
void			draw_projection_mode_msg(t_ctx *ctx, int x, int *y);
void			draw_color_mode_msg(t_ctx *ctx, int x, int *y);
void			draw_lens_mode_msg(t_ctx *ctx, int x, int *y);
void			draw_scale_mode_msg(t_ctx *ctx, int x, int *y);
void			draw_translation_mode_msg(t_ctx *ctx, int x, int *y);
void			draw_rotation_mode_msg(t_ctx *ctx, int x, int *y);
void			draw_screen_translation_msg(t_ctx *ctx, int x, int *y);
void			draw_fps_mode_msg(t_ctx *ctx, int x, int *y);
void			draw_msg(t_mlx *mlx, int x, int *y, char *msg);

#endif