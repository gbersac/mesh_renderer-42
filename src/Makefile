################################################################################
# BASIC VARIABLES															   #
################################################################################

export DEBUG		:= -g -O0

################################################################################
# LIBRARY VARIABLES															   #
################################################################################

export DIR_GLFW		:= glfw
export DIR_GLEW		:= glew

export DIR_LIBFT	:= libft
export DIR_LIBMATH	:= libmath
export DIR_LIB		:= $(DIR_LIBMATH) $(DIR_LIBFT)
export APP			:= scop

################################################################################
# RULES																		   #
################################################################################

.PHONY: all $(APP) $(DIR_LIB)

all:  $(APP)

$(DIR_LIB):
	@echo
	@echo \	MAKE $(RULE) in directory : $@
	@$(MAKE) --directory=$@  $(RULE)

$(APP): $(DIR_LIB)
	@echo
	@echo \	MAKE $(RULE) in directory : $@
	@$(MAKE) --directory=$@  $(RULE)

clean:
	@make RULE=clean

fclean:
	@make RULE=fclean

re:
	@make RULE=re

test:
	@make RULE=test
