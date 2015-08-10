################################################################################
# BASIC VARIABLES															   #
################################################################################

SRCS				:= main.c shader.c mvp_matrix.c gl_gen_buffer.c \
						gl_display_object.c load_bmp.c load_mesh.c \
						generate_mesh.c env.c scan_face.c model_matrix.c \
						key_handler.c resources.c free_mesh.c rotate_mesh.c

PATH_OBJ			:= obj
PATH_OBJT			:= objt
PATH_SRC			:= src
PATH_INC			:= inc
PATH_TEST			:= test

CFLAGS				:= -Wall -Wextra -Werror
OBJECTS				:= $(patsubst %.c, $(PATH_OBJ)/%.o, $(SRCS))
OBJECTS_TEST		:= $(patsubst %.c, $(PATH_OBJT)/%, $(SRCS_TEST))

TEST_CMD			:= $(patsubst %.c, $(PATH_OBJT)/%;, $(SRCS_TEST))

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

export DIR_LIB 		:= $(DIR_LIBFT) $(DIR_LIBMATH)
LIBRARY				:= $(LIB_GLFW) $(LIB_GLEW) -framework OpenGL $(LIB_MATH) \
						$(LIB_FT)
INCLUDES			:= -I$(DIR_GLFW)/inc -I$(DIR_GLEW)/inc \
						-I./$(PATH_INC) $(patsubst %,-I%/inc,$(DIR_LIB))

################################################################################
# BASIC RULES																   #
################################################################################

.PHONY: all test

all: $(APP)

$(APP): $(OBJECTS)
	cc -o $@ $(OBJECTS) $(LIBRARY) $(DEBUG)

test: $(OBJECTS)
	@echo plopasdi
	@rm -rf $(PATH_OBJT)
	@$(MAKE)
	@$(MAKE) $(OBJECTS_TEST)
	@$(TEST_CMD)

$(PATH_OBJT)/%: $(addprefix $(PATH_TEST)/,%.c)
	@mkdir -p $(PATH_OBJT)
	$(CC) -o $@ $^ $(filter-out ,$(VAR)) $(DEBUG) $(LIBRARY) $(INCLUDES) -L. -lmath

$(PATH_OBJ)/%.o: $(addprefix $(PATH_SRC)/,%.c)
	@mkdir -p $(PATH_OBJ)
	cc -c -o $@ $(CFLAGS) $^ $(DEBUG) $(INCLUDES)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(APP)

re: fclean $(APP)
