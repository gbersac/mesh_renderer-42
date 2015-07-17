.PHONY: all

all: prog

prog:
	@make -C src $(RULE)

clean:
	@make RULE=clean

fclean:
	@make RULE=fclean

re:
	@make RULE=re

test:
	@make RULE=test

