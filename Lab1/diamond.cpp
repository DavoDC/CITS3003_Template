
/*
 * Name: diamond.cpp
 *
 * Author: David
 *
 * Usage:
 * - Compile using: make diamond
 * - Run using:  ./diamond
 *
 * Notes:
 * - Intended for direct use on Linux
 * - But can work on Mac with some small edits, search for 'MAC USERS'
 */

// ### Include textbook header file
// - Reading/understanding the header files is pretty much optional
// - This file can be found in the 'include' folder in 'LAB_DWL`
// - This header file includes other header files and some inbuilt libraries
#include "Angel.h"

// ### The number of points we will be using
// Make sure you update this if you change the number of points
const int numPoints = 8;

/**
 * Initialization function
 *
 * Typically does the following:
 * - Defines points/vertices
 * - Sets up VAO and VBO
 * - Compiles shaders and registers shader program
 * - Registers shader variables
 *
 * I added an 'S' to the function name to demonstrate
 * that this function can have any name.
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
    // or having trouble visualizing them, see the left part of this image:
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
    // You can find that function lower down in this function.
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
    // - 1 (GLsizei n) = The number of VAOs we want
    // - &vao (GLuint* arrays) = The address to the holder
    // https://docs.gl/gl4/glGenVertexArrays
    glGenVertexArrays(1, &vao);

    // glBindVertexArray() binds the vertex array
    // - vao (GLuint array) = A reference to the VAO holder
    // https://docs.gl/gl4/glBindVertexArray
    glBindVertexArray(vao);

    // # Create VAO on Mac
    // MAC USERS should:
    // - Uncomment these 3 lines below
    // - Comment out the 3 previous, similar lines
    //
    // GLuint vao[1];
    // glGenVertexArraysAPPLE( 1, vao );
    // glBindVertexArrayAPPLE( vao[0] );



    // ### Create a vertex buffer object (VBO)
    // A holder/reference integer
    GLuint buffer;

    // glGenBuffers() sets the type to a buffer
    // - 1 (GLsizei n) = The number of VBOs we want
    // - &buffer (GLuint* buffers) = The address to the holder
    // https://docs.gl/gl4/glGenBuffers
    glGenBuffers(1, &buffer);

    // glBindBuffer() binds the buffer
    // - GL_ARRAY_BUFFER (GLenum target) = Store vertex attributes
    // - buffer (GLuint buffer) = A reference to the VBO holder
    // https://docs.gl/gl4/glBindBuffer
    glBindBuffer(GL_ARRAY_BUFFER, buffer);


    // ### Initialise vertex buffer
    // - GL_ARRAY_BUFFER (GLenum target) = Store vertex attributes
    // - sizeof (points) (GLsizeiptr size) = Size in bytes of VBO's new data store
    // - points (const GLvoid * data) = Pointer to vertice data
    // - GL_STATIC_DRAW (GLenum usage) = Expected usage pattern
    //  > Composed of two keywords:
    //  > STATIC: The data store contents will be modified once and used many times.
    //  > DRAW: The data store contents are modified by the application,
    //          and used as the source for GL drawing and image specification commands.
    // https://docs.gl/gl4/glBufferData
    glBufferData(GL_ARRAY_BUFFER, sizeof (points), points, GL_STATIC_DRAW);



    // ### Load/compile shaders and use the resulting shader program
    // InitShader() is a function from the textbook files.
    // Specifically, InitShader.cpp in the Common folder.
    // It abstracts away some of the complexity involved in compiling shaders.
    // The shaders have the extension "GLSL",
    // which means "OpenGL Shader Language".
    //
    // I've put the shaders in a folder and renamed them to
    // demonstrate that this is possible.
    //
    // - "shaders/vshaderS.glsl" = Path to the vertex shader
    // - "shaders/fshaderS.glsl" = Path to the fragment shader
    // - program = A GLuint that represents a GLSL program
    GLuint program = InitShader("shaders/vshaderS.glsl", "shaders/fshaderS.glsl");
    //
    // glUseProgram() registers the generated GLSL program
    // - program (GLuint program) = Program object handle
    // https://docs.gl/gl4/glUseProgram
    glUseProgram(program);



    // ### Initialize the vertex position attribute for the vertex shader
    //
    // glGetAttribLocation() registers a shader variable.
    // - The 2nd argument string *must* match a shader variable name.
    // - Here, "vPosition" will be a variable in the vertex shader,
    //   used for transferring vertices from the program to the vertex shader.
    // https://docs.gl/gl4/glGetAttribLocation
    GLuint vPos = glGetAttribLocation(program, "vPosition");
    //
    // glEnableVertexAttribArray() enables the vertex array
    // https://docs.gl/gl4/glEnableVertexAttribArray
    glEnableVertexAttribArray(vPos);
    //
    // glVertexAttribPointer() defines the array of vertex attribute data
    // https://docs.gl/gl4/glVertexAttribPointer
    // - vPos (GLuint index) = The identifier for the vertex position attribute
    //
    // - 3 (GLint size) = Number of components per vertex
    //   -> We use 3 because vec3 in use. Would be 2 for vec2, 4 for vec4 etc.
    //   -> If not set correctly, makes points show up strangely
    //
    // - GL_FLOAT (GLenum type) = Data type of array elements
    //   -> We use GL_FLOAT because our vec3's contain floats
    //
    // - GL_FALSE (GLboolean normalized) = Whether data needs normalization
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
    // The 4 values represent RGB values then opacity
    // (Bit of red, bit of green and more blue = Purple)
    // https://docs.gl/gl4/glClearColor
    glClearColor(0.3f, 0.3f, 0.7f, 0.0f);

    // Increase line width
    // https://docs.gl/gl4/glLineWidth
    glLineWidth(6.0f);
}

/**
 * The display callback function.
 * Called every time the window is refreshed.
 * I added an 'S' to the function name to demonstrate
 * that this function can have any name.
 */
void displayS(void) {

    // ### Clear the buffer
    // GL_COLOR_BUFFER_BIT = Clear buffers currently enabled for color writing
    // https://docs.gl/gl4/glClear
    glClear(GL_COLOR_BUFFER_BIT);

    // ### Draw the vertices
    // - GL_LINE_LOOP = <The Drawing Mode>, Draw the points as a line loop
    // - 0 = Start from the first index of the vertex array
    // - numPoints = The number of points to draw
    // https://docs.gl/gl4/glDrawArrays
    glDrawArrays(GL_LINE_LOOP, 0, numPoints);
    //
    // You can draw the same points in different ways/modes
    // e.g. To draw the points as triangles:
    // glDrawArrays(GL_TRIANGLES, 0, numPoints);
    //
    // Experiment with the drawing modes!
    // You can find out more about them here:
    // https://www.khronos.org/opengl/wiki/Primitive
    //
    // You can also make multiple glDrawArrays() calls here at once.

    // ### Draw now and flush the buffers
    // https://docs.gl/gl4/glFlush
    glFlush();
}

/**
 * The Main function.
 * The 'entrypoint' for this program.
 * This function is called first when you execute the program.
 *
 * @param argc The number of arguments
 * @param argv The arguments array
 * @return 0 if ran successfully
 */
int main(int argc, char** argv) {

    // Set title string
    const char* titleS = "OpenGL Program: Diamond";

    // ### Print title
    // I've included a few different ways to print out values for future reference
    //
    // # Method 1 = C printing technique
    // printf is from the <stdio> library included indirectly via Angel.h
    // https://www.educative.io/edpresso/how-to-use-printf-in-c
    printf("\n%s\n", titleS);

    // # Method 2 = C++ printing technique
    // cout is from the <iostream> library included directly via Angel.h
    // https://www.cplusplus.com/doc/tutorial/basic_io/
    // std::cout << "\n" << title << "\n";

    // # Method 3 = Angel.h macro printing technique
    // Uses C++-like technique under-the-hood
    // Print(titleS);

    // ### Initialize GLUT (OpenGL Utility Toolkit)
    // - Provide CLI arguments
    // https://www.opengl.org/resources/libraries/glut/spec3/node10.html
    glutInit(&argc, argv);
    // - Set display mode, how scene should be rendered
    // https://www.opengl.org/resources/libraries/glut/spec3/node12.html
    glutInitDisplayMode(GLUT_RGBA);
    // - Set window size
    // https://www.opengl.org/resources/libraries/glut/spec3/node11.html
    glutInitWindowSize(600, 600);

    // Ask FreeGLUT to return a forward-compatible OpenGL 4.0 core-profile context
    // (No documentation available for FreeGLUT extensions)
    //
    // MAC USERS should comment out both of these 'glutInitContext...' lines
    glutInitContextVersion(4, 0);
    glutInitContextProfile(GLUT_CORE_PROFILE);

    // Create a window, setting title to title string
    // https://www.opengl.org/resources/libraries/glut/spec3/node16.html
    glutCreateWindow(titleS);

    // Initialize GLEW (OpenGL Extension Wrangler)
    // http://glew.sourceforge.net/basic.html
    //
    // MAC USERS should comment out the glewInit() line
    glewInit();

    // Call our custom initialization function
    initS();

    // ### Register callback functions
    // glutDisplayFunc takes a function pointer as an argument.
    // The function given will be called every time the window is refreshed.
    // Here we register the displayS() function from higher up (in the code)
    // as the display callback function.
    // https://www.opengl.org/resources/libraries/glut/spec3/node46.html
    glutDisplayFunc(displayS);
    //
    // There are similar functions which register callbacks for other events.
    // e.g. glutKeyboardFunc() registers the function that should be
    // called when a key is pressed.
    // More examples:
    // https://www.opengl.org/resources/libraries/glut/spec3/node45.html

    // ### Enter infinite event loop.
    // If the window changes in any way, it will redraw it.
    // https://www.opengl.org/resources/libraries/glut/spec3/node14.html
    glutMainLoop();
}


