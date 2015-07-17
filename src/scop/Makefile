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

export DIR_GLFW		:= ../glfw
export DIR_GLEW		:= ../glew

export DIR_LIBFT	:= ../libft
export DIR_LIBMATH	:= ../libmath

LIB_GLFW			:= -L$(DIR_GLFW) -lglfw3 -framework Cocoa -framework IOKit -framework CoreVideo
LIB_GLEW			:= -L$(DIR_GLEW) -lglew
LIB_MATH			:= -L$(DIR_LIBMATH) -lmath
LIB_FT				:= -L$(DIR_LIBFT) -lft

export DIR_LIB 		:= $(patsubst %,../%,$(DIR_LIB))
LIBRARY				:= $(LIB_GLFW) $(LIB_GLEW) -framework OpenGL $(LIB_MATH) \
						$(LIB_FT)
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
