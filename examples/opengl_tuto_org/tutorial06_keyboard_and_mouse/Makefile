#
# Makefile
# gbersac, 2015-06-29 21:42
#

all:
	# clang++ -c shader.cpp -o shader.o -I ~/.brew/include/ -I ~/.brew/include/GLFW -I ../ -L ~/.brew/lib/ -lglfw3 -L ~/.brew/lib/ -lglew  -framework OpenGL
	clang++ tutorial06.cpp texture.cpp shader.cpp objLoader.cpp controls.cpp -o triangle -I ~/.brew/include/ -I ~/project/mesh_renderer-42/src/glew/inc -I ~/project/mesh_renderer-42/src/glfw/inc -I ../ -L ~/project/mesh_renderer-42/src/glfw -lglfw3 -framework Cocoa -framework IOKit -framework CoreVideo -L ~/project/mesh_renderer-42/src/glew -lglew -framework OpenGL 



# vim:ft=make
#
