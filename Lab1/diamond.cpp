
// LINUX ONLY


// Printing
#include <iostream>

// Textbook header file
#include "Angel.h"

// Circle points
const int numPoints = 8;

/*
 * Initialization function
 */
void initS(void) {
	
	
    // Create vertices
    vec3 points[numPoints] = {
        vec3(0.0f, 1.0f, 0.0f),
        vec3(0.5f, 0.5f, 0.0f),
        vec3(1.0f, 0.0f, 0.0f),
        vec3(0.5f, -0.5f, 0.0f),
        vec3(0.0f, -1.0f, 0.0f),
        vec3(-0.5f, -0.5f, 0.0f),
        vec3(-1.0f, 0.0f, 0.0f),
        vec3(-0.5f, 0.5f, 0.0f)
    };

    // Create VAO
    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    // Create VBO
    GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    // Initialise vertex buffer to hold circlePoints
    glBufferData(GL_ARRAY_BUFFER, sizeof (points), points, GL_STATIC_DRAW);

    // Compile shader programs and use resulting program
    GLuint program = InitShader("shaders/vshaderS.glsl", "shaders/fshaderS.glsl");
    glUseProgram(program);

    // Initialize the vertex position attribute from the vertex shader
    // "vPosition" is reference to the vertexS.glsl program
    GLuint vPos = glGetAttribLocation(program, "vPosition");
    glEnableVertexAttribArray(vPos);

    // GL_FLOAT = Type of vertex positions
    // GL_FALSE = The data does not need normalization
    // 0 = There is no stride. Every point is drawn
    // BUFFER_OFFSET(0) = We are drawing from the start, so no offset
    glVertexAttribPointer(vPos, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));

    // Sets background color(RGB values then opacity)
    glClearColor(0.3f, 0.3f, 0.7f, 0.0f);

    // Increase line width
    glLineWidth(6.0f);
}

/*
 * Display function
 */
void displayS(void) {
    // Clear the buffer
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the vertices
    // 0 = Specifies the starting index in the enabled array 
    glDrawArrays(GL_LINE_LOOP, 0, numPoints);

    // Draw now and flush the buffers
    glFlush();
}

/*
 * Main function
 */
int main(int argc, char** argv) {
    // Title
    const char* title = "PurpleDiamond-DC";

    // Starting message
    std::cout << "\n" << title << "\n";

    // Initialize glut and window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA);
    glutInitWindowSize(600, 400);

    // Set version
    glutInitContextVersion(4, 0);
    glutInitContextProfile(GLUT_CORE_PROFILE);

    // Create a window with title 
    glutCreateWindow(title);

    // Initalize glew
    glewInit();

    // Set up OpenGL state and initialize shaders 
    initS();

    // The previous 'display' function will be a callback function,
    // meaning it will be called every time the window is refreshed. 
    glutDisplayFunc(displayS);

    // Enter infinite event loop   
    // If the window changes in any way, it will redraw it 
    glutMainLoop();
}


