################################################################################
# SOURCES       															   #
################################################################################

SRCS		= mat_basics.c mat_print.c
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

.PHONY: all

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar rc $@ $(OBJECTS)
	@ranlib $(NAME)
	@echo Creating Library $(NAME) $(words $(OBJECTS)) files inside

test: $(NAME) $(OBJECTS_TEST)
	$(TEST_CMD)

$(PATH_OBJT)/%: $(addprefix $(PATH_TEST)/,%.c)
	@echo $(shell pwd) 
	@mkdir -p $(PATH_OBJT)
	$(CC) -o $@ $(CFLAGS) $^ $(DEBUG)  -I $(PATH_INC)/ -L. -lmath

$(PATH_OBJ)/%.o: $(addprefix $(PATH_SRC)/,%.c)
	@mkdir -p $(PATH_OBJ)
	$(CC) -c -o $@ $(CFLAGS) $^ $(DEBUG)  -I $(PATH_INC)/

clean:
	@rm -f $(OBJECTS)
	@echo Delete $(words $(OBJECTS)) object file

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)
