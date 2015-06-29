#include "shader.h"

static char	*get_file_as_str(const char *filename)
{
	char *file_content;
	long input_file_size;
	FILE *input_file;

	input_file = fopen(filename, "rb");
	if (input_file == NULL)
	{
		printf("Error: file %s does not exist.\n", filename);
		return NULL;
	}
	fseek(input_file, 0, SEEK_END);
	input_file_size = ftell(input_file);
	rewind(input_file);
	file_content = malloc(input_file_size * (sizeof(char)));
	fread(file_content, sizeof(char), input_file_size, input_file);
	fclose(input_file);
	return (file_content);
}

static void	display_compilation_error(GLuint shader, const char* filename)
{
	GLint	size_str;
	char	*error_str;

	glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &size_str);
	error_str = malloc(size_str * sizeof(char) + 2);
    glGetShaderInfoLog(shader, size_str, &size_str, error_str);
    error_str[size_str] = '\0';
    printf("Error: shader %s compilation error :\n%s\n", filename, error_str);
    free(error_str);
}

static GLuint	compile_shader(GLenum type, const char *filename, int *error)
{
	GLchar	*file_content;
	GLint	compilation_error;
	GLuint	shader_id;

	shader_id = glCreateShader(type);
	compilation_error = 0;
	file_content = (GLchar*)get_file_as_str(filename);
	if (file_content == NULL)
	{
		*error = 1;
		return 0;
	}
	glShaderSource(shader_id, 1, (const GLchar *const *)&file_content, 0);
	glCompileShader(shader_id);
	glGetShaderiv(shader_id, GL_COMPILE_STATUS, &compilation_error);
	free(file_content);
	if (compilation_error != GL_TRUE)
	{
		display_compilation_error(shader_id, filename);
		*error = 1;
		return (0);
	}
	return (shader_id);
}

t_shader	*load_shader(const char *vertex_src, const char *fragment_src)
{
	t_shader	*tr;
	int			error;

	error = 0;
    tr = malloc(1 * sizeof(t_shader));
	tr->vertex_id = compile_shader(GL_VERTEX_SHADER, vertex_src, &error);
	tr->fragment_id = compile_shader(GL_FRAGMENT_SHADER, fragment_src, &error);
	if (error)
	{
		free(tr);
		return (NULL);
	}
    tr->program_id = glCreateProgram();
    glAttachShader(tr->program_id, tr->vertex_id);
    glAttachShader(tr->program_id, tr->fragment_id);
    return (tr);
}
