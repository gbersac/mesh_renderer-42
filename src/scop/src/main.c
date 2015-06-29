#include <SDL.h>
#define GL3_PROTOTYPES 1
#include <OpenGL/gl.h>

#include "scop.h"
#include "shader.h"

int main()
{
	// init sdl
	if(SDL_Init(SDL_INIT_VIDEO) != 0){
		printf("Error init SDL : %s\n", SDL_GetError());
		return -1;
	}

	//init opengl version
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	// SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

	// init window
	SDL_Window *window;
	window = SDL_CreateWindow("scop",
			0, // x position
			0, // y position
			100, // width
			100, // height
			SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
	if(!window)
	{
		printf("Error creating window : %s\n", SDL_GetError());
		SDL_DestroyWindow(window);
	}

	// init with opengl
	SDL_GLContext contextOpenGL;
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
	contextOpenGL = SDL_GL_CreateContext(window);
	if(contextOpenGL == 0)
	{
		printf("Error init context OpenGl : %s\n", SDL_GetError());
	}

	// Vertices : 3 2d points
	float vertices[] = {0.0, 1.0,   0.5, 0.0,   0.0, -1.0,  -0.5, -0.0};
	// float color[] = {1.0, 0.0, 0.0,  0.0, 1.0, 0.0,  0.0, 0.0, 1.0};

	//shader
	// t_shader	*shader1 = load_shader("src/shaders/couleur2D.vert",
	// 		"src/shaders/couleur2D.frag");
	// if (shader1 == NULL)
	// 	return (0);

	// program
	int         end = 0;
	SDL_Event   events;
	while(!end)
	{
		//events
		SDL_WaitEvent(&events);
		switch(events.type) {
			case SDL_KEYDOWN:
			    switch(events.key.keysym.sym) {
				    case SDLK_ESCAPE:
				        end = 1;
				        break;
			    }
			    break;
		}
		if(events.window.event == SDL_WINDOWEVENT_CLOSE)
			end = 1;

		//cleaning screen
		glClear(GL_COLOR_BUFFER_BIT);

		// glUseProgram(shader1->program_id);

			//Put the vertice tab in the openGL vertices index
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, vertices);
			glEnableVertexAttribArray(0);
			// glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, color);
   //          glEnableVertexAttribArray(1);

			//display triangle
			glDrawArrays(GL_TRIANGLES, 0, 3);

			//deactive vertex attribute
			// glDisableVertexAttribArray(1);
			glDisableVertexAttribArray(0);

		// glUseProgram(0);

		//refresh window
		SDL_GL_SwapWindow(window);
	}

	// quit sdl
	SDL_GL_DeleteContext(contextOpenGL);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return (0);
}
