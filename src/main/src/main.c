#include <SDL.h>
#define GL3_PROTOTYPES 1
#include <GL/gl.h>

#include "scop.h"

int	main(void)
{
	// init sdl
	if(SDL_Init(SDL_INIT_VIDEO) != 0){
		printf("Error init SDL : %s\n", SDL_GetError());
		return -1;
	}

	// init window
	SDL_Window *window;
	window = SDL_CreateWindow("scop", 
			0, // x position
			0, // y position
			100, // width
			100, // height
			SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
	if(!window){
		printf("Error creating window : %s\n", SDL_GetError());
		SDL_Delay(3000); /* Attendre trois secondes, que l'utilisateur voie la fenêtre */
		SDL_DestroyWindow(window);
	}

	// init with opengl
	SDL_GLContext contextOpenGL;
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
	/* SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF); */
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
	contextOpenGL = SDL_GL_CreateContext(window);
	if(contextOpenGL == 0)
	{
		printf("Error init context OpenGl : %s\n", SDL_GetError());
	}

	// program
	int			end = 0;
	SDL_Event	events;
	while(!end)
	{
		SDL_WaitEvent(&events);
		if(events.window.event == SDL_WINDOWEVENT_CLOSE)
			end = 1;
		glClear(GL_COLOR_BUFFER_BIT);
		SDL_GL_SwapWindow(window);
	}

	// quit sdl
	SDL_GL_DeleteContext(contextOpenGL);
	SDL_DestroyWindow(window);
	SDL_Quit();
    return (0);
}
