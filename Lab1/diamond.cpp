
/*
 * Name: diamond.cpp
 * Author: David
 * Notes:
 * - Intended for direct use on Linux
 * - Can work on Mac with some changes
 * - Mac users should search for 'Mac' to make the necessary code changes
 */

// $$$$$$$$$$$$$$$$$ NOT NEEDED? TEST!!!!!
// Include C++ iostream library so we can print
// https://www.cplusplus.com/reference/iostream/
//#include <iostream>


// ### Include textbook header file
// - Reading/understanding the header files is pretty much optional
// - This file can be found in the 'include' folder in 'LAB_DWL`
// - This header file includes other header files and some inbuilt libraries
#include "Angel.h"

// The number of points we will be using
// Make sure you update this if you change the number of points
const int numPoints = 8;

/*
 * Initialization function
 *
 * Typically does the following:
 * - Defines points/vertices
 * - Sets up VAO and VBO
 * - Compiles shaders and registers shader program
 * - Registers shader variables
 *
 * I added an 'S' to the function name to demonstrate that this function can have any name
 */
void initS(void) {

    // ### Defining vertices
    //
    // 'vec3' is a datatype for points defined in the textbook header.
    // http://learnwebgl.brown37.net/12_shader_language/glsl_data_types.html
    //
    // The three values are x,y and z respectively.
    // The z value is 0,
    // showing how 2D graphics is a special case of 3D graphics.
    //
    // If you are wondering what coordinate system these points are relative to,
    // or having trouble visualizing them,
    // see the left part of this image:
    // https://drive.google.com/file/d/19McUFvDrPRGlvVqOERCsi9KP2AEjozjA
    //
    // # Method 1
    vec3 points[numPoints] = {
        //    X     Y     Z
        vec3(0.0f, 1.0f, 0.0f), // The top point
        vec3(0.5f, 0.5f, 0.0f), // The middle of top right quadrant
        vec3(1.0f, 0.0f, 0.0f), // The rightmost point
        vec3(0.5f, -0.5f, 0.0f), // The middle of bottom right quadrant

        vec3(0.0f, -1.0f, 0.0f), // The bottom point
        vec3(-0.5f, -0.5f, 0.0f), // The middle of the bottom left quadrant
        vec3(-1.0f, 0.0f, 0.0f), // The leftmost point
        vec3(-0.5f, 0.5f, 0.0f) // The middle of the top left quadrant
    };
	//
	//
    // # Method 2
    // This is another way to initialize points
    // vec3 points[numPoints];
    // points[0] = vec3(0.0f, 1.0f, 0.0f);
    // points[1] = vec3(0.5f, 0.5f, 0.0f);
    // points[2] = vec3(1.0f, 0.0f, 0.0f);
    // points[3] = vec3(0.5f, -0.5f, 0.0f);
    //
    // points[4] = vec3(0.0f, -1.0f, 0.0f);
    // points[5] = vec3(-0.5f, -0.5f, 0.0f);
    // points[6] = vec3(-1.0f, 0.0f, 0.0f);
    // points[7] = vec3(-0.5f, 0.5f, 0.0f);
    //
	//
    // # Method 3
    // An equivalent way to initialize the points using vec2's
    // If you want to try this,
    // you will need to change glVertexAttribPointer()'s 2nd argument.
    // Scroll down to see more info about that function.
	//
    // vec2 points[numPoints] = {
    //    vec2(0.0f, 1.0f),
    //    vec2(0.5f, 0.5f),
    //    vec2(1.0f, 0.0f),
    //    vec2(0.5f, -0.5f),
    //
    //    vec2(0.0f, -1.0f),
    //    vec2(-0.5f, -0.5f),
    //    vec2(-1.0f, 0.0f),
    //    vec2(-0.5f, 0.5f)
    // };




    // ### Create a vertex array object (VAO)
    // A holder/reference integer
    GLuint vao;

    // glGenVertexArrays() sets the type to a vertex array
    // - 1 = The number of VAOs we want
    // - &vao = The address to the holder
    // https://docs.gl/gl4/glGenVertexArrays
    glGenVertexArrays(1, &vao);

    // glBindVertexArray() binds the vertex array
    // - vao = A reference to the VAO holder
    // https://docs.gl/gl4/glBindVertexArray
    glBindVertexArray(vao);



    // ### Create a vertex buffer object (VBO)
    // A holder/reference integer
    GLuint buffer;

    // glGenBuffers() sets the type to a buffer
    // - 1 = The number of VBOs we want
    // - &buffer = The address to the holder
    // https://docs.gl/gl4/glGenBuffers
    glGenBuffers(1, &buffer);

    // glBindBuffer() binds the buffer
    // - GL_ARRAY_BUFFER = Means we are storing vertex attributes
    // - buffer = A reference to the VBO holder
    // https://docs.gl/gl4/glBindBuffer
    glBindBuffer(GL_ARRAY_BUFFER, buffer); // Bind


    // ### Initialise vertex buffer
    // https://docs.gl/gl4/glBufferData
    glBufferData(GL_ARRAY_BUFFER, sizeof (points), points, GL_STATIC_DRAW);



    // ### Load shaders and use the resulting shader program
    // The shaders are located in my shaders folder
    GLuint program = InitShader("shaders/vshaderS.glsl", "shaders/fshaderS.glsl");
    // https://docs.gl/gl4/glUseProgram
    glUseProgram(program);



    // ### Initialize the vertex position attribute for the vertex shader
    // "vPosition" is reference to the vertexS.glsl program

    // glGetAttribLocation()
    // https://docs.gl/gl4/glGetAttribLocation
    GLuint vPos = glGetAttribLocation(program, "vPosition");

    // glEnableVertexAttribArray()
    // https://docs.gl/gl4/glEnableVertexAttribArray
    glEnableVertexAttribArray(vPos);

    // glVertexAttribPointer()
    // https://docs.gl/gl4/glVertexAttribPointer
    // - vPos (GLuint index) = The identifier/index for the vertex position attribute
    //
    // - 3 (GLint size) = Number of components per vertex
    //   -> We use 3 because vec3 in use. Would be 2 for vec2, 4 for vec4 etc.
    //   -> If not set correctly, makes points show up strangely
    //
    // - GL_FLOAT (GLenum type) = Data type of array elements
    //   -> We use GL_FLOAT because our vec3's contain floats
    //
    // - GL_FALSE (GLboolean normalized) = Does data does not need normalization?
    //   -> We use GL_FALSE because we don't need normalization
    //
    // - 0 (GLsizei stride) = Byte offset between consecutive vertices
    //   -> We use a stride of 0 because we want every point to be drawn/used
    //
    // - BUFFER_OFFSET(0) (const GLvoid* pointer) = Offset of 1st vertex in buffer
    //   -> We use an offset of 0 because we want to draw from the start
	//   -> BUFFER_OFFSET() is actually a macro from Angel.h
    glVertexAttribPointer(vPos, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));

    // If you wanted to use vec2, for example:
    // glVertexAttribPointer(vPos, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));


    // ### Extra Settings

    // Sets background color to purple
    // 4 values represent RGB values then opacity
    // https://docs.gl/gl4/glClearColor
    glClearColor(0.3f, 0.3f, 0.7f, 0.0f);

    // Increase line width
    // https://docs.gl/gl4/glLineWidth
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
    const char* title = "Diamond";

    // Starting message
    std::cout << "\n" << title << "\n";
	
	// TRY Print(x)  and angel namespace!

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

    // Call the initilization function
    initS();

    // The previous 'display' function will be a callback function,
    // meaning it will be called every time the window is refreshed.
    glutDisplayFunc(displayS);

    // Enter infinite event loop
    // If the window changes in any way, it will redraw it
    glutMainLoop();
}


