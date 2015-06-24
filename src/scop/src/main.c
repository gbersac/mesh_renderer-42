#include <SDL.h>
#define GL3_PROTOTYPES 1
#include <OpenGL/gl.h>

#include "scop.h"

int main()
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

    // Vertices et coordonnées
    float vertices[] = {-0.5, -0.5,   0.0, 0.5,   0.5, -0.5};

    // program
    int         end = 0;
    SDL_Event   events;
    while(!end)
    {
        // Gestion des évènements
        SDL_WaitEvent(&events);
        if(events.window.event == SDL_WINDOWEVENT_CLOSE)
            end = 1;

        // Nettoyage de l'écran
        glClear(GL_COLOR_BUFFER_BIT);


        // On remplie puis on active le tableau Vertex Attrib 0
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, vertices);
        glEnableVertexAttribArray(0);


        // On affiche le triangle
        glDrawArrays(GL_TRIANGLES, 0, 3);


        // On désactive le tableau Vertex Attrib puisque l'on n'en a plus besoin
        glDisableVertexAttribArray(0);


        // Actualisation de la fenêtre
        SDL_GL_SwapWindow(window);
    }

    // quit sdl
    SDL_GL_DeleteContext(contextOpenGL);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return (0);
}
