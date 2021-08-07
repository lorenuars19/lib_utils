# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/10 13:37:24 by lorenuar          #+#    #+#              #
#    Updated: 2021/08/07 17:09:00 by lorenuar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ================================ VARIABLES ================================= #

# The name of your executable
NAME	= libutils.a

SHELL	= /bin/bash
# Compiler and compiling flags
CC	= gcc
CFLAGS	= -Wall -Werror -Wextra

AR = ar
ARFLAGS = -rcs

# Debug, use with`make DEBUG=1`
ifeq ($(DEBUG),1)
CFLAGS	+= -g3
endif
ifeq ($(DEBUG),2)
CFLAGS	+= -g3 -fsanitize=address
endif
ifeq ($(DEBUG),3)
CFLAGS	+= -g3 -fsanitize=address -fsanitize=leak
endif

# Folder name
SRCDIR	= src/
INCDIR	= includes/
OBJDIR	= bin/

# Add include folder
CFLAGS	+= -I $(INCDIR)

# Linking stage flags
LDFLAGS =

###▼▼▼<src-updater-do-not-edit-or-remove>▼▼▼
# **************************************************************************** #
# **   Generated with https://github.com/lorenuars19/makefile-src-updater   ** #
# **************************************************************************** #

SRCS = \
	./src/nbr/nbr_to_str.c \
	./src/nbr/put_nbr_fd.c \
	./src/nbr/put_nbr.c \
	./src/nbr/nbr_len.c \
	./src/nst/nst_get_size.c \
	./src/nst/nst_free.c \
	./src/nst/nst_pop.c \
	./src/nst/nst_rotate.c \
	./src/nst/nst_from.c \
	./src/nst/nst_swap.c \
	./src/nst/nst_new_resize.c \
	./src/nst/nst_shift.c \
	./src/nst/nst_push.c \
	./src/mem/mem_set.c \
	./src/mem/mem_cpy.c \
	./src/mem/mem_mov.c \
	./src/list/lst_map.c \
	./src/list/lst_size.c \
	./src/list/lst_last.c \
	./src/list/lst_new.c \
	./src/list/lst_push.c \
	./src/list/lst_pop.c \
	./src/list/lst_iter.c \
	./src/list/lst_clear.c \
	./src/list/lst_remove.c \
	./src/gst/gst_swap.c \
	./src/gst/gst_get_size.c \
	./src/gst/gst_new_resize.c \
	./src/gst/gst_pop.c \
	./src/gst/gst_push.c \
	./src/gst/gst_shift.c \
	./src/gst/gst_rotate.c \
	./src/gst/gst_free.c \
	./src/str/str_skipto.c \
	./src/str/str_split.c \
	./src/str/str_cmp.c \
	./src/str/str_eat_nbr.c \
	./src/str/str_has.c \
	./src/str/str_len.c \
	./src/str/str_to_nbr.c \
	./src/str/str_dupli.c \
	./src/str/str_jointo.c \
	./src/io/put_str_times.c \
	./src/io/get_next_line.c \
	./src/io/error_put.c \
	./src/io/put_chr.c \
	./src/io/put_str.c \
	./src/ft_printf/unsigned.c \
	./src/ft_printf/ft_printf.c \
	./src/ft_printf/format.c \
	./src/ft_printf/strings.c \
	./src/ft_printf/call_dispatch.c \
	./src/ft_printf/utils/extra.c \
	./src/ft_printf/utils/num.c \
	./src/math/min.c \
	./src/math/abs.c \
	./src/math/max.c \
	./src/chr/is_charset.c \
	./src/chr/is_ascii.c \
	./src/chr/is_digit.c \
	./src/chr/is_alnum.c \
	./src/chr/is_print.c \
	./src/chr/is_alpha.c \
	./src/chr/is_wsp.c \

HEADERS = \
	./includes/lib_list.h\
	./includes/lib_ansi.h\
	./includes/lib_nbr.h\
	./includes/lib_math.h\
	./includes/lib_gst.h\
	./includes/lib_io.h\
	./includes/lib_mem.h\
	./includes/lib_chr.h\
	./includes/lib_nst.h\
	./includes/lib_str.h\
	./includes/ft_printf.h\
	./includes/libutils.h\

###▲▲▲<src-updater-do-not-edit-or-remove>▲▲▲

# String manipulation magic
SRC		:= $(notdir $(SRCS))
OBJ		:= $(SRC:.c=.o)
OBJS	:= $(addprefix $(OBJDIR), $(OBJ))

# Colors
GR	= \033[32;1m
RE	= \033[31;1m
YE	= \033[33;1m
CY	= \033[36;1m
RC	= \033[0m

# Implicit rules
VPATH := $(SRCDIR) $(OBJDIR) $(shell find $(SRCDIR) -type d)

# ================================== RULES =================================== #

# This specifies the rules that does not correspond to any filename
.PHONY	= all run clean fclean re

all : $(OBJDIR) $(NAME)

$(OBJDIR) :
	@mkdir -p $(OBJDIR)

# Compiling
$(OBJDIR)%.o : %.c
	@printf "$(GR)+$(RC)"
	@$(CC) $(CFLAGS) -c $^ -o $@

# Archiving
$(NAME)	: $(SRCS) $(HEADERS) $(OBJS)
	@printf "\n$(GR)=== Compiled [$(CC) $(CFLAGS)] ===\n--- $(SRC)$(RC)\n"
	@rm -f $(NAME)
	@$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	@printf "$(YE)&&& Archived [$(AR) $(ARFLAGS)] &&&\n--- $(NAME)$(RC)\n"

# Cleaning
clean :
	@printf "$(RE)--- Removing $(OBJDIR)$(RC)\n"
	@rm -rf $(OBJDIR)

fclean : clean
	@printf "$(RE)--- Removing $(NAME)$(RC)\n"
	@rm -f $(NAME)

# Special rule to force to remake everything
re : fclean all

test : all
	rm -f test.exec
	$(CC) $(CFLAGS) main.c libutils.a -o test.exec
ifeq ($(DEBUG),2)
		-gdb --args ./test.exec main.c
endif
	-./test.exec
	rm -f test.exec
