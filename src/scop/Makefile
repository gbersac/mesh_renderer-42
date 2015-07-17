# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/04/22 13:15:39 by gbersac           #+#    #+#              #
#    Updated: 2015/07/17 13:22:39 by gbersac          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
# BASIC VARIABLES															   #
################################################################################

SRCS				:= main.c shader.c

PATH_OBJ			:= obj
PATH_SRC			:= src
PATH_INC			:= inc

CFLAGS				:= -Wall -Wextra -Werror
OBJECTS				:= $(patsubst %.c, $(PATH_OBJ)/%.o, $(SRCS))

################################################################################
# LIBRARY VARIABLES															   #
################################################################################

export DIR_SDL		:= ../sdl2
export DIR_GLFW		:= ../glfw
export DIR_GLEW		:= ../glew

LIB_SDL				:= -L$(DIR_SDL) -lSDL2
LIB_GLFW			:= -L$(DIR_GLFW) -lglfw3 -framework Cocoa -framework IOKit -framework CoreVideo 
LIB_GLEW			:= -L$(DIR_GLEW) -lglew

export DIR_LIB 		:= $(patsubst %,../%,$(DIR_LIB))
LIBRARY				:= $(LIB_GLFW) $(LIB_GLEW) -framework OpenGL
INCLUDES			:= -I$(DIR_GLFW)/inc -I$(DIR_GLEW)/inc \
						-I./$(PATH_INC) $(patsubst %,-I%/inc,$(DIR_LIB))

################################################################################
# BASIC RULES																   #
################################################################################

.PHONY: all

all: $(APP)

$(APP): $(OBJECTS)
	cc -o $@ $(OBJECTS) $(LIBRARY) $(DEBUG)

$(PATH_OBJ)/%.o: $(addprefix $(PATH_SRC)/,%.c)
	@mkdir -p $(PATH_OBJ)
	cc -c -o $@ $(CFLAGS) $^ $(DEBUG) $(INCLUDES)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(APP)

re: fclean $(APP)
