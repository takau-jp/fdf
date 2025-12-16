# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/16 14:03:35 by stanaka2          #+#    #+#              #
#    Updated: 2025/12/16 15:07:28 by stanaka2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -------------------------- #
#         Phony Rules        #
# -------------------------- #

.PHONY: all clean fclean re bonus norm debug asan sbuild

# -------------------------- #
#      Makefile Setting      #
# -------------------------- #

SHELL =	/bin/bash

ifeq ($(filter re,$(MAKECMDGOALS)),re)
MAKEFLAGS += --no-print-directory
else
MAKEFLAGS += --no-print-directory -j
endif

RM = rm -f

# -------------------------- #
#           Target           #
# -------------------------- #

NAME = fdf

# -------------------------- #
#           LIBFT            #
# -------------------------- #

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_INCLUDE_DIR = $(LIBFT_DIR)/include

# -------------------------- #
#         MINILIBX           #
# -------------------------- #

MINILIBX_DIR	= ${HOME}/minilibx-linux
LIBMLX			= ${MINILIBX_DIR}/libmlx.a
MINILIBX_INCLUDE_DIR	= -I ${MINILIBX_DIR}
MINILIBX_LINK			= -lmlx -lXext -lX11 -L ${MINILIBX_DIR}

# -------------------------- #
# 　　　Compiler Flags        #
# -------------------------- #

CC		= cc
CFLAGS	= -Wall -Werror -Wextra
LIBMATH_FLAG = -lm

ifeq ($(filter asan,$(MAKECMDGOALS)),asan)
CFLAGS += -g -fsanitize=address
else ifeq ($(filter debug,$(MAKECMDGOALS)),debug)
CFLAGS += -g
endif

# -------------------------- #
#          Include           #
# -------------------------- #

INCLUDE_DIR 	= mandatory/include
INCLUDE			= -I $(INCLUDE_DIR) -I $(LIBFT_INCLUDE_DIR) ${MINILIBX_INCLUDE_DIR}
B_INCLUDE_DIR	= bonus/include
B_INCLUDE		= -I $(B_INCLUDE_DIR) -I $(LIBFT_INCLUDE_DIR) ${MINILIBX_INCLUDE_DIR}

# -------------------------- #
#     Source Directories     #
# -------------------------- #

SRC_DIRS 	=	mandatory/src \
				$(addprefix mandatory/src/, \
					argument \
					drawer \
					error \
					map \
					mlx \
					transform \
				)

B_SRC_DIRS	=	bonus/src \
				$(addprefix bonus/src/, \
					argument \
					drawer \
					error \
					feature \
					map \
					mlx \
					transform \
				)

# -------------------------- #
#       Bonus Switching      #
# -------------------------- #

ifeq ($(filter bonus,$(MAKECMDGOALS)),bonus)
SRC_DIRS = $(B_SRC_DIRS)
endif

# -------------------------- #
#        Source Files        #
# -------------------------- #

# mandatory
SRCS	=	main.c
# argument
SRCS	+=	check_argument.c
# drawer
SRCS	+=	draw_line.c  draw_line_utils.c  draw_pixel.c  draw_wireframe.c  lerp_color.c
# error
SRCS	+=	argument_error.c  errno_error.c  ft_mlx_error.c  map_error.c
# map
SRCS	+=	clear_map.c  create_map.c  create_map_utils.c  parse_rgb.c  read_file_as_lst.c
# mlx
SRCS	+=	ft_init_mlx.c     ft_mlx_get_pixel_addr.c  ft_mlx_image_utils.c  z_buffer_utils.c \
			ft_mlx_destroy.c  ft_mlx_hooks.c           redraw_window.c
# transform
SRCS	+=	affine_transform.c       init_transform.c      make_affine_rotation_matrix.c \
			calc_centroid.c          invert_pos.c          projection.c \
			calc_projected_bounds.c  make_affine_matrix.c  transformation.c

# bonus
B_SRCS	=	main_bonus.c
# argument
B_SRCS	+=	check_argument_bonus.c
# drawer
B_SRCS	+=	alpha_blend_bonus.c         draw_line_bonus.c        draw_status_msg2_bonus.c  lerp_utils_bonus.c \
			clip_line_bonus.c           draw_line_utils_bonus.c  draw_status_msg_bonus.c \
			draw_control_panel_bonus.c  draw_pixel_bonus.c       draw_wireframe_bonus.c
# error
B_SRCS	+=	argument_error_bonus.c  errno_error_bonus.c  ft_mlx_error_bonus.c  map_error_bonus.c
# feature
B_SRCS	+=	get_color_set_bonus.c  init_modes_bonus.c  set_lens_bonus.c  set_my_colors_bonus.c
# map
B_SRCS	+=	clear_map_bonus.c   create_map_utils_bonus.c  read_file_as_lst_bonus.c \
			create_map_bonus.c  parse_rgb_bonus.c
# mlx
B_SRCS	+=	change_player_angle_bonus.c     expose_hook_bonus.c            key_hook_bonus.c \
			change_player_position_bonus.c  ft_init_mlx_bonus.c            mouse_hook_bonus.c \
			change_rotations_bonus.c        ft_mlx_destroy_bonus.c         redraw_window_bonus.c \
			change_scales_bonus.c           ft_mlx_get_pixel_addr_bonus.c  z_buffer_utils_bonus.c \
			change_translations_bonus.c     ft_mlx_hooks_bonus.c \
			change_value_utils_bonus.c      ft_mlx_image_utils_bonus.c
# transform
B_SRCS	+=	affine_transform_bonus.c       init_transform_utils_bonus.c         make_init_view_matrix_bonus.c \
			calc_centroid_bonus.c          invert_pos_bonus.c                   projection_bonus.c \
			calc_projected_bounds_bonus.c  make_affine_clip_matrix_bonus.c      quaternion_utils_bonus.c \
			fps_transform_utils_bonus.c    make_affine_matrix_bonus.c           transform_bonus.c \
			get_aabb_bonus.c               make_affine_rotation_matrix_bonus.c

# -------------------------- #
#        VPATH Setup         #
# -------------------------- #

$(foreach dir,$(SRC_DIRS), $(eval vpath %.c $(dir)))

# -------------------------- #
#     Object & Dependency    #
# -------------------------- #

OBJ_DIR		=	.obj
OBJS		=	$(patsubst %.c, $(OBJ_DIR)/%.o, $(notdir $(SRCS)))
B_OBJS		=	$(patsubst %.c, $(OBJ_DIR)/%.o, $(notdir $(B_SRCS)))

DEP_DIR		=	.dep
DEPFLAGS	=	-MT $@ -MMD -MP -MF $(DEP_DIR)/$*.d
DEPS		=	$(patsubst %.c, $(DEP_DIR)/%.d, $(notdir $(SRCS)))
B_DEPS		=	$(patsubst %.c, $(DEP_DIR)/%.d, $(notdir $(B_SRCS)))

# -------------------------- #
#       Bonus Switching      #
# -------------------------- #

ifeq ($(filter bonus,$(MAKECMDGOALS)),bonus)
INCLUDE = $(B_INCLUDE)
OBJS = $(B_OBJS)
DEPS = $(B_DEPS)
endif

# -------------------------- #
#    ANSI Escape Sequence    #
# -------------------------- #

DEF_COLOR	= \033[0;39m
GRAY 		= \033[0;90m
RED 		= \033[0;91m
GREEN 		= \033[0;92m
YELLOW 		= \033[0;93m
BLUE 		= \033[0;94m
MAGENTA 	= \033[0;95m
CYAN 		= \033[0;96m
WHITE 		= \033[0;97m

# -------------------------- #
#        Main Targets        #
# -------------------------- #

all	: $(NAME)

bonus: $(NAME)

$(NAME): $(OBJS) $(LIBFT) ${LIBMLX}
	@$(CC) $(CFLAGS) ${LIBMATH_FLAG} ${MINILIBX_LINK} $^ ${LIBMLX} -o $@ 
	@echo -e "[FDF] $(GREEN)Build Complete:$(DEF_COLOR) $@"

# -------------------------- #
#        Build Rules         #
# -------------------------- #

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR) $(DEP_DIR)
	@$(CC) $(CFLAGS) $(DEPFLAGS) $(INCLUDE) -c $< -o $@

$(OBJ_DIR):
	@-mkdir -p $@

$(DEP_DIR):
	@-mkdir -p $@

# -------------------------- #
#         LIBFT Rule         #
# -------------------------- #

$(LIBFT):
	@echo -e "[FDF] $(YELLOW)Build:$(DEF_COLOR) $@"
ifeq ($(filter asan,$(MAKECMDGOALS)),asan)
	@$(MAKE) -C $(LIBFT_DIR) asan
else ifeq ($(filter debug,$(MAKECMDGOALS)),debug)
	@$(MAKE) -C $(LIBFT_DIR) debug
else
	@$(MAKE) -C $(LIBFT_DIR)
endif

# -------------------------- #
#       MINILIBX Rule        #
# -------------------------- #

${LIBMLX}:
	@make -C ${MINILIBX_DIR}

# -------------------------- #
#         Debug Rules        #
# -------------------------- #

asan:	$(NAME)

debug:  $(NAME)

sbuild:
	@$(MAKE) fclean
	/usr/lib/llvm-12/bin/scan-build make
	@$(MAKE) fclean
	/usr/lib/llvm-12/bin/scan-build make bonus
	@$(MAKE) fclean

norm:
	@norminette -o mandatory bonus $(LIBFT_DIR) | grep Error || true

# -------------------------- #
#       Cleanup Rules        #
# -------------------------- #

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C ${MINILIBX_DIR} clean
	@$(RM) $(OBJS) $(DEPS) $(B_OBJS) $(B_DEPS)
	@echo -e "[FDF] $(BLUE)Deleted Compiled Files$(DEF_COLOR): *.o *.d"

fclean:
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(RM) $(OBJS) $(DEPS) $(B_OBJS) $(B_DEPS)
	@echo -e "[FDF] $(BLUE)Deleted Compiled Files$(DEF_COLOR): *.o *.d"
	@$(RM) -r $(NAME) $(OBJ_DIR) $(DEP_DIR)
	@echo -e "[FDF] $(BLUE)Deleted Target File and Object File Dir$(DEF_COLOR): $(NAME) $(OBJ_DIR) $(DEP_DIR)"

re:	fclean all

# -------------------------- #
#  Include Dependency Files  #
# -------------------------- #

-include $(DEPS) $(B_DEPS)
