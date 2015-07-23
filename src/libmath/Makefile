################################################################################
# SOURCES       															   #
################################################################################

SRCS		= mat_basics.c mat_print.c mat_identity.c mat_perspective.c \
				mat_are_equal.c mat_zero.c mat_multi.c mat_lookat.c vec_new.c \
				vec_new3.c vec_length.c vec_normalize.c vec_cross.c
SRCS_TEST	= test_matrix.c

################################################################################
# BASIC VARIABLES															   #
################################################################################

PATH_OBJ	= obj
PATH_OBJT	= objt
PATH_SRC	= src
PATH_INC	= inc
PATH_TEST	= test

NAME		= libmath.a
CFLAGS		= -Wall -Wextra -Werror
OBJECTS		= $(patsubst %.c, $(PATH_OBJ)/%.o, $(SRCS))
OBJECTS_TEST= $(patsubst %.c, $(PATH_OBJT)/%, $(SRCS_TEST))
DEBUG		= -g -O0

TEST_CMD	= $(patsubst %.c, $(PATH_OBJT)/%;, $(SRCS_TEST))

################################################################################
# RULES																		   #
################################################################################

.PHONY: all test

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar rc $@ $(OBJECTS)
	@ranlib $(NAME)
	@echo Creating Library $(NAME) $(words $(OBJECTS)) files inside

test:
	@rm -rf $(PATH_OBJT)
	@$(MAKE)
	@$(MAKE) $(OBJECTS_TEST)
	@$(TEST_CMD)

$(PATH_OBJT)/%: $(addprefix $(PATH_TEST)/,%.c)
	@mkdir -p $(PATH_OBJT)
	$(CC) -o $@ $^ $(DEBUG) -I $(PATH_INC)/ -L. -lmath

$(PATH_OBJ)/%.o: $(addprefix $(PATH_SRC)/,%.c)
	@mkdir -p $(PATH_OBJ)
	$(CC) -c -o $@ $(CFLAGS) $^ $(DEBUG)  -I $(PATH_INC)/

clean:
	@rm -f $(OBJECTS)
	@echo Delete $(words $(OBJECTS)) object file

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)
