#ifndef SHADER_H
# define SHADER_H

# define GL3_PROTOTYPES 1
# include <OpenGL/gl.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct	s_shader
{
    GLuint	vertex_id;
    GLuint	fragment_id;
    GLuint	program_id;
}				t_shader;

t_shader	*load_shader(const char *vertex_src, const char *fragment_src);
// GLuint LoadShaders(const char * vertex_file_path,const char * fragment_file_path);

#endif
