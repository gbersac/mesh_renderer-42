#
# Makefile
# gbersac, 2015-06-29 21:42
#

all:
	clang++ -c shader.cpp -o shader.o -I ~/.brew/include/ -I ~/.brew/include/GLFW -I ../ -L ~/.brew/lib/ -lglfw3 -L ~/.brew/lib/ -lglew  -framework OpenGL
	clang++ tutorial02.cpp shader.o -o triangle -I ~/.brew/include/ -I ~/.brew/include/GLFW -I ../ -L ~/.brew/lib/ -lglfw3 -L ~/.brew/lib/ -lglew  -framework OpenGL



# vim:ft=make
#
