# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/29 14:10:40 by stanaka2          #+#    #+#              #
#    Updated: 2025/11/16 16:12:56 by stanaka2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = cc

# FLAGS
CFLAGS = -Wall -Wextra -Werror
DEPSFLAGS = -MMD
LIBMATH_FLAG = -lm

# libft
LIBFT_DIR = libft
LIBFT = ${LIBFT_DIR}/libft.a
LIBFT_INCLUDE = -I ${LIBFT_DIR}/include

# MINILIBX
MINILIBX_DIR = ${HOME}/minilibx-linux
LIBMLX = ${MINILIBX_DIR}/libmlx.a
MINILIBX_INCLUDE = -I ${MINILIBX_DIR}
MINILIBX_LINK = -lmlx -lXext -lX11 -L ${MINILIBX_DIR}

# INCLUDE
INCLUDE = -I include ${LIBFT_INCLUDE} ${MINILIBX_INCLUDE}

# srcs
SRCDIR = mandatory
SRCS = ${addprefix ${SRCDIR}/, main.c}
SRCS += ${addprefix ${SRCDIR}/argument/, \
			check_argument.c \
		}
SRCS += ${addprefix ${SRCDIR}/drawer/, \
			draw_line_utils.c \
			draw_line.c \
			draw_pixel.c \
			draw_wireframe.c \
			lerp_color.c \
		}
SRCS += ${addprefix ${SRCDIR}/error/, \
			argument_error.c \
			errno_error.c \
			ft_mlx_error.c \
			map_error.c \
		}
SRCS += ${addprefix ${SRCDIR}/map/, \
			clear_map.c \
			create_map_utils.c \
			create_map.c \
			parse_rgb.c \
			read_file_as_lst.c \
		}
SRCS += ${addprefix ${SRCDIR}/mlx/, \
			ft_init_mlx.c \
			ft_mlx_destroy.c \
			ft_mlx_get_pixel_addr.c \
			ft_mlx_hooks.c \
			ft_mlx_image_utils.c \
			redraw_window.c \
			z_buffer_utils.c \
		}
SRCS += ${addprefix ${SRCDIR}/transform/, \
			affine_transform.c \
			calc_centroid.c \
			calc_projected_bounds.c \
			init_transform.c \
			invert_pos.c \
			make_affine_matrix.c \
			make_affine_rotation_matrix.c \
			projection.c \
			transformation.c \
		}
B_SRCDIR = bonus
B_SRCS = ${addprefix ${B_SRCDIR}/, main_bonus.c}
B_SRCS += ${addprefix ${SRCDIR}/argument/, \
			check_argument_bonus.c \
		}
B_SRCS += ${addprefix ${SRCDIR}/drawer/, \
			alpha_blend_bonus.c \
			clip_line_bonus.c \
			draw_control_panel_bonus.c \
			draw_line_bonus.c \
			draw_line_utils_bonus.c \
			draw_pixel_bonus.c \
			draw_status_msg_bonus.c \
			draw_status_msg2_bonus.c \
			draw_wireframe_bonus.c \
			lerp_utils_bonus.c \
		}
B_SRCS += ${addprefix ${SRCDIR}/error/, \
			argument_error_bonus.c \
			errno_error_bonus.c \
			ft_mlx_error_bonus.c \
			map_error_bonus.c \
		}
B_SRCS += ${addprefix ${SRCDIR}/feature/, \
			get_color_set_bonus.c \
			init_modes_bonus.c \
			set_lens_bonus.c \
			set_my_colors_bonus.c \
		}
B_SRCS += ${addprefix ${SRCDIR}/map/, \
			clear_map_bonus.c \
			create_map_utils_bonus.c \
			create_map_bonus.c \
			parse_rgb_bonus.c \
			read_file_as_lst_bonus.c \
		}
B_SRCS += ${addprefix ${SRCDIR}/mlx/, \
			change_player_angle_bonus.c \
			change_player_position_bonus.c \
			change_rotations_bonus.c \
			change_scales_bonus.c \
			change_translations_bonus.c \
			change_value_utils_bonus.c \
			expose_hook_bonus.c \
			ft_init_mlx_bonus.c \
			ft_mlx_destroy_bonus.c \
			ft_mlx_get_pixel_addr_bonus.c \
			ft_mlx_hooks_bonus.c \
			ft_mlx_image_utils_bonus.c \
			key_hook_bonus.c \
			mouse_hook_bonus.c \
			redraw_window_bonus.c \
			z_buffer_utils_bonus.c \
		}
B_SRCS += ${addprefix ${SRCDIR}/transform/, \
			affine_transform_bonus.c \
			calc_centroid_bonus.c \
			calc_projected_bounds_bonus.c \
			fps_transform_utils_bonus.c \
			get_aabb_bonus.c \
			init_transform_utils_bonus.c \
			invert_pos_bonus.c \
			make_affine_clip_matrix_bonus.c \
			make_affine_matrix_bonus.c \
			make_affine_rotation_matrix_bonus.c \
			make_init_view_matrix_bonus.c \
			projection_bonus.c \
			quaternion_utils_bonus.c \
			transform_bonus.c \
		}

# objs
OBJDIR = objs
OBJS = ${addprefix ${OBJDIR}/, ${notdir ${SRCS:.c=.o}}}
B_OBJS	= ${addprefix ${OBJDIR}/, ${notdir ${B_SRCS:.c=.o}}}
# deps
DEPS	= ${addprefix ${OBJDIR}/, ${notdir ${SRCS:.c=.d}}}
B_DEPS	= ${addprefix ${OBJDIR}/, ${notdir ${B_SRCS:.c=.d}}}

# bonus
ifeq ($(MAKECMDGOALS), bonus)
	OBJS	= ${B_OBJS}
	DEPS	= ${B_DEPS}
endif

all: ${NAME}

${NAME}: ${OBJS} ${LIBFT} ${LIBMLX}
	${CC} $^ ${LIBMLX} -o $@ ${MINILIBX_LINK} ${LIBMATH_FLAG}

${LIBFT}:
	@make -C $(LIBFT_DIR)

${LIBMLX}:
	@make -C ${MINILIBX_DIR}

${OBJDIR}:
	-mkdir -p ${OBJDIR}

${OBJDIR}/%.o: ${SRCDIR}/%.c | ${OBJDIR}
	${CC} ${CFLAGS} ${DEPSFLAGS} ${INCLUDE} -c $< -o $@

${OBJDIR}/%.o: ${SRCDIR}/argument/%.c | ${OBJDIR}
	${CC} ${CFLAGS} ${DEPSFLAGS} ${INCLUDE} -c $< -o $@

${OBJDIR}/%.o: ${SRCDIR}/drawer/%.c | ${OBJDIR}
	${CC} ${CFLAGS} ${DEPSFLAGS} ${INCLUDE} -c $< -o $@

${OBJDIR}/%.o: ${SRCDIR}/error/%.c | ${OBJDIR}
	${CC} ${CFLAGS} ${DEPSFLAGS} ${INCLUDE} -c $< -o $@

${OBJDIR}/%.o: ${SRCDIR}/map/%.c | ${OBJDIR}
	${CC} ${CFLAGS} ${DEPSFLAGS} ${INCLUDE} -c $< -o $@

${OBJDIR}/%.o: ${SRCDIR}/mlx/%.c | ${OBJDIR}
	${CC} ${CFLAGS} ${DEPSFLAGS} ${INCLUDE} -c $< -o $@

${OBJDIR}/%.o: ${SRCDIR}/transform/%.c | ${OBJDIR}
	${CC} ${CFLAGS} ${DEPSFLAGS} ${INCLUDE} -c $< -o $@

${OBJDIR}/%.o: ${B_SRCDIR}/%.c | ${OBJDIR}
	${CC} ${CFLAGS} ${DEPSFLAGS} ${INCLUDE} -c $< -o $@

${OBJDIR}/%.o: ${B_SRCDIR}/%.c | ${OBJDIR}
	${CC} ${CFLAGS} ${DEPSFLAGS} ${INCLUDE} -c $< -o $@

${OBJDIR}/%.o: ${B_SRCDIR}/argument/%.c | ${OBJDIR}
	${CC} ${CFLAGS} ${DEPSFLAGS} ${INCLUDE} -c $< -o $@

${OBJDIR}/%.o: ${B_SRCDIR}/drawer/%.c | ${OBJDIR}
	${CC} ${CFLAGS} ${DEPSFLAGS} ${INCLUDE} -c $< -o $@

${OBJDIR}/%.o: ${B_SRCDIR}/error/%.c | ${OBJDIR}
	${CC} ${CFLAGS} ${DEPSFLAGS} ${INCLUDE} -c $< -o $@

${OBJDIR}/%.o: ${B_SRCDIR}/feature/%.c | ${OBJDIR}
	${CC} ${CFLAGS} ${DEPSFLAGS} ${INCLUDE} -c $< -o $@

${OBJDIR}/%.o: ${B_SRCDIR}/map/%.c | ${OBJDIR}
	${CC} ${CFLAGS} ${DEPSFLAGS} ${INCLUDE} -c $< -o $@

${OBJDIR}/%.o: ${B_SRCDIR}/mlx/%.c | ${OBJDIR}
	${CC} ${CFLAGS} ${DEPSFLAGS} ${INCLUDE} -c $< -o $@

${OBJDIR}/%.o: ${B_SRCDIR}/transform/%.c | ${OBJDIR}
	${CC} ${CFLAGS} ${DEPSFLAGS} ${INCLUDE} -c $< -o $@

bonus: ${NAME}

clean:
	@make -C ${LIBFT_DIR} clean
	@make -C ${MINILIBX_DIR} clean
	${RM} ${OBJS} ${B_OBJS} ${DEPS} ${B_DEPS}

fclean: clean
	@make -C ${LIBFT_DIR} fclean
	${RM} -r ${NAME} ${OBJDIR}

re: fclean all

-include $(DEPS)

.PHONY: all bonus clean fclean re
