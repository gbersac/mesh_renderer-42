#include "scop.h"

void error_callback(int error, const char* description)
{
	printf("GLFW error %d : %s\n", error, description);
}

// static const GLfloat triangle_vertexs[] = {
// 	-3.0f, -1.0f, 0.0f,
// 	 3.0f, -1.0f, 0.0f,
// 	 2.0f,  1.0f, 0.0f,
// };

// static const GLfloat triangle_colors[] = {
//     0.673f,  0.211f,  0.457f,
//     0.820f,  0.883f,  0.371f,
//     0.982f,  0.099f,  0.879f
// };

// Our vertices. Tree consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
// A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
static const GLfloat vertexs[] = {
	-1.0f,-1.0f,-1.0f, // triangle 1 : begin
	-1.0f,-1.0f, 1.0f,
	-1.0f, 1.0f, 1.0f, // triangle 1 : end
	1.0f, 1.0f,-1.0f, // triangle 2 : begin
	-1.0f,-1.0f,-1.0f,
	-1.0f, 1.0f,-1.0f, // triangle 2 : end
	1.0f,-1.0f, 1.0f,
	-1.0f,-1.0f,-1.0f,
	1.0f,-1.0f,-1.0f,
	1.0f, 1.0f,-1.0f,
	1.0f,-1.0f,-1.0f,
	-1.0f,-1.0f,-1.0f,
	-1.0f,-1.0f,-1.0f,
	-1.0f, 1.0f, 1.0f,
	-1.0f, 1.0f,-1.0f,
	1.0f,-1.0f, 1.0f,
	-1.0f,-1.0f, 1.0f,
	-1.0f,-1.0f,-1.0f,
	-1.0f, 1.0f, 1.0f,
	-1.0f,-1.0f, 1.0f,
	1.0f,-1.0f, 1.0f,
	1.0f, 1.0f, 1.0f,
	1.0f,-1.0f,-1.0f,
	1.0f, 1.0f,-1.0f,
	1.0f,-1.0f,-1.0f,
	1.0f, 1.0f, 1.0f,
	1.0f,-1.0f, 1.0f,
	1.0f, 1.0f, 1.0f,
	1.0f, 1.0f,-1.0f,
	-1.0f, 1.0f,-1.0f,
	1.0f, 1.0f, 1.0f,
	-1.0f, 1.0f,-1.0f,
	-1.0f, 1.0f, 1.0f,
	1.0f, 1.0f, 1.0f,
	-1.0f, 1.0f, 1.0f,
	1.0f,-1.0f, 1.0f
};

// One color for each vertex. They were generated randomly.
// static const GLfloat colors[] = {
//     0.583f,  0.771f,  0.014f,
//     0.609f,  0.115f,  0.436f,
//     0.327f,  0.483f,  0.844f,
//     0.822f,  0.569f,  0.201f,
//     0.435f,  0.602f,  0.223f,
//     0.310f,  0.747f,  0.185f,
//     0.597f,  0.770f,  0.761f,
//     0.559f,  0.436f,  0.730f,
//     0.359f,  0.583f,  0.152f,
//     0.483f,  0.596f,  0.789f,
//     0.559f,  0.861f,  0.639f,
//     0.195f,  0.548f,  0.859f,
//     0.014f,  0.184f,  0.576f,
//     0.771f,  0.328f,  0.970f,
//     0.406f,  0.615f,  0.116f,
//     0.676f,  0.977f,  0.133f,
//     0.971f,  0.572f,  0.833f,
//     0.140f,  0.616f,  0.489f,
//     0.997f,  0.513f,  0.064f,
//     0.945f,  0.719f,  0.592f,
//     0.543f,  0.021f,  0.978f,
//     0.279f,  0.317f,  0.505f,
//     0.167f,  0.620f,  0.077f,
//     0.347f,  0.857f,  0.137f,
//     0.055f,  0.953f,  0.042f,
//     0.714f,  0.505f,  0.345f,
//     0.783f,  0.290f,  0.734f,
//     0.722f,  0.645f,  0.174f,
//     0.302f,  0.455f,  0.848f,
//     0.225f,  0.587f,  0.040f,
//     0.517f,  0.713f,  0.338f,
//     0.053f,  0.959f,  0.120f,
//     0.393f,  0.621f,  0.362f,
//     0.673f,  0.211f,  0.457f,
//     0.820f,  0.883f,  0.371f,
//     0.982f,  0.099f,  0.879f
// };

static const GLfloat uvs[] = {
    0.000059f, 1.0f-0.000004f,
    0.000103f, 1.0f-0.336048f,
    0.335973f, 1.0f-0.335903f,
    1.000023f, 1.0f-0.000013f,
    0.667979f, 1.0f-0.335851f,
    0.999958f, 1.0f-0.336064f,
    0.667979f, 1.0f-0.335851f,
    0.336024f, 1.0f-0.671877f,
    0.667969f, 1.0f-0.671889f,
    1.000023f, 1.0f-0.000013f,
    0.668104f, 1.0f-0.000013f,
    0.667979f, 1.0f-0.335851f,
    0.000059f, 1.0f-0.000004f,
    0.335973f, 1.0f-0.335903f,
    0.336098f, 1.0f-0.000071f,
    0.667979f, 1.0f-0.335851f,
    0.335973f, 1.0f-0.335903f,
    0.336024f, 1.0f-0.671877f,
    1.000004f, 1.0f-0.671847f,
    0.999958f, 1.0f-0.336064f,
    0.667979f, 1.0f-0.335851f,
    0.668104f, 1.0f-0.000013f,
    0.335973f, 1.0f-0.335903f,
    0.667979f, 1.0f-0.335851f,
    0.335973f, 1.0f-0.335903f,
    0.668104f, 1.0f-0.000013f,
    0.336098f, 1.0f-0.000071f,
    0.000103f, 1.0f-0.336048f,
    0.000004f, 1.0f-0.671870f,
    0.336024f, 1.0f-0.671877f,
    0.000103f, 1.0f-0.336048f,
    0.336024f, 1.0f-0.671877f,
    0.335973f, 1.0f-0.335903f,
    0.667969f, 1.0f-0.671889f,
    1.000004f, 1.0f-0.671847f,
    0.667979f, 1.0f-0.335851f
};

GLFWwindow	*init()
{
	GLFWwindow* window;

	glfwSetErrorCallback(error_callback);
	// Initialise GLFW
	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n" );
		return (NULL);
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Open a window and create its OpenGL context
	window = glfwCreateWindow(WIN_HEIGHT, WIN_WIDTH, "Scop", NULL, NULL);
	if(window == NULL){
		fprintf(stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n" );
		glfwTerminate();
		return (NULL);
	}
	glfwMakeContextCurrent(window);

	// Initialize GLEW
	glewExperimental = 1; // Needed for core profile
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		return (NULL);
	}

	// Ensure we can capture the escape key being pressed below
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	// Enable depth test
	glEnable(GL_DEPTH_TEST);
	// Accept fragment if it closer to the camera than the former one
	glDepthFunc(GL_LESS);

	return (window);
}

int			main()
{
	GLFWwindow* window;

	window = init();
	if (window == NULL)
		return (EXIT_FAILURE);
	// Dark blue background
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

	// Create and compile our GLSL program from the shaders
	t_shader *shader_color = load_shader("src/shaders/simple_transf_color.vert",
			"src/shaders/color.frag");
	t_shader *shader_texture = load_shader("src/shaders/simple_transf_texture.vert",
			"src/shaders/texture.frag");
	if (shader_color == NULL || shader_texture == NULL)
	{
		//TODO free stuff
		printf("Error shader construction\n");
		return (0);
	}

	GLuint vertex_buff = gl_gen_buffer(GL_ARRAY_BUFFER, sizeof(vertexs),
			(void*)vertexs, GL_STATIC_DRAW);
	GLuint uv_buff = gl_gen_buffer(GL_ARRAY_BUFFER, sizeof(uvs),
			(void*)uvs, GL_STATIC_DRAW);
	// GLuint color_buff = gl_gen_buffer(GL_ARRAY_BUFFER, sizeof(colors),
	// 		(void*)colors, GL_STATIC_DRAW);
	// GLuint triangle_buff = gl_gen_buffer(GL_ARRAY_BUFFER, sizeof(triangle_vertexs),
	// 		(void*)triangle_vertexs, GL_STATIC_DRAW);
	// GLuint triangle_color_buff = gl_gen_buffer(GL_ARRAY_BUFFER, sizeof(triangle_colors),
	// 		(void*)triangle_colors, GL_STATIC_DRAW);

	t_mat	*mvp = mvp_matrix();
	mat_print_label(mvp, "mvp");

	//load texture
	GLuint texture = load_bmp("src/uvtemplate.bmp");
	GLuint texture_id  = glGetUniformLocation(shader_texture->program_id,
			"myTextureSampler");

	// Get a handle for our "MVP" uniform. Only at initialisation time.
	GLuint MatrixID = glGetUniformLocation(shader_color->program_id, "MVP");

	// Send our transformation to the currently bound shader, in the "MVP" uniform
	// For each model you render, since the MVP will be different (at least the M part)
	glUniformMatrix4fv(MatrixID, 1, GL_FALSE, mvp->array);
	do{
		// Clear the screen
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Use our shader
		glUseProgram(shader_texture->program_id);

		// Send our transformation to the currently bound shader,
		// in the "MVP" uniform
		glUniformMatrix4fv(MatrixID, 1, GL_FALSE, mvp->array);

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture);
		glUniform1i(texture_id, 0);

		gl_display_object(vertex_buff, uv_buff, 12 * 3);
		// gl_display_object(triangle_buff, triangle_color_buff, 3);

		// Swap buffers
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
		   glfwWindowShouldClose(window) == 0 );

	// Cleanup VBO
	glDeleteBuffers(1, &vertex_buff);
	glDeleteVertexArrays(1, &VertexArrayID);
	glDeleteProgram(shader_color->program_id);

	// Close OpenGL window and terminate GLFW
	glfwTerminate();
// triangle_buff = 0;
// triangle_color_buff = 0;
vertex_buff = 0;
// color_buff = 0;
	return (EXIT_SUCCESS);
}
