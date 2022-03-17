
#include "Angel.h"

// Number of points
const int NumPoints = 6;

// Params shared with shader
GLint multipliersP;

//----------------------------------------------------------------------------

void
init(void) {

    // Points for square
    vec3 points[NumPoints] = {
        vec3(-0.5, -0.5, 0.0), vec3(-0.5, 0.5, 0.0), vec3(0.5, -0.5, 0.0),
        vec3(0.5, 0.5, 0.0), vec3(0.5, -0.5, 0.0), vec3(-0.5, 0.5, 0.0)
    };

    // Array of random colors
    vec3 colors[NumPoints];
    srand((unsigned) time(NULL));
    for (int i = 0; i < NumPoints/2; i++) {
        float r = (float) rand() / RAND_MAX;
        float g = (float) rand() / RAND_MAX;
        float b = (float) rand() / RAND_MAX;
        vec3 col = vec3(r, g, b);
        // Pairs of triangle vertices have the same color
        colors[i] = col;
        colors[i + 3] = col;
    }

    // Create a vertex array object
    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    // Create and initialize a buffer object
    GLuint buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);

    // First, we create an empty buffer of the size we need by passing
    //   a NULL pointer for the data values
    glBufferData(GL_ARRAY_BUFFER, sizeof (points) + sizeof (colors),
            NULL, GL_STATIC_DRAW);

    // Next, we load the real data in parts.  We need to specify the
    //   correct byte offset for placing the color data after the point
    //   data in the buffer.  Conveniently, the byte offset we need is
    //   the same as the size (in bytes) of the points array, which is
    //   returned from "sizeof(points)".
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof (points), points);
    glBufferSubData(GL_ARRAY_BUFFER, sizeof (points), sizeof (colors), colors);

    // Load shaders and use the resulting shader program
    GLuint program = InitShader("vshader1.glsl", "../fshader.glsl");
    glUseProgram(program);

    // Initialize the vertex position attribute from the vertex shader    
    GLuint vPosition = glGetAttribLocation(program, "vPosition");
    glEnableVertexAttribArray(vPosition);
    glVertexAttribPointer(vPosition, 3, GL_FLOAT, GL_FALSE, 0,
            BUFFER_OFFSET(0));

    // Likewise, initialize the vertex color attribute.  Once again, we
    //    need to specify the starting offset (in bytes) for the color
    //    data.  Just like loading the array, we use "sizeof(points)"
    //    to determine the correct value.
    GLuint vColor = glGetAttribLocation(program, "vColor");
    glEnableVertexAttribArray(vColor);
    glVertexAttribPointer(vColor, 3, GL_FLOAT, GL_FALSE, 0,
            BUFFER_OFFSET(sizeof (points)));

    //glEnable(GL_DEPTH_TEST);

    // Register params with shader variables
    multipliersP = glGetUniformLocation(program, "multipliers");

    glClearColor(1.0, 1.0, 1.0, 1.0); /* white background */
}
//----------------------------------------------------------------------------

void
display(void) {

    // Clear the window
    glClear(GL_COLOR_BUFFER_BIT);

    // Angle
    float angle = 0.001 * glutGet(GLUT_ELAPSED_TIME);

    // Update shader variables
    mat2 multipliers_mat = mat2(vec2(cos(angle), -sin(angle)),
            vec2(sin(angle), cos(angle)));
    glUniformMatrix2fv(multipliersP, 1, GL_TRUE, multipliers_mat);

    // Draw the points
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    // Double buffering
    glutSwapBuffers();
}

//----------------------------------------------------------------------------

void idle(void) {
    /*
    Calling glutPostRedisplay tells GLUT that the window needs to be redisplayed. Here we call
it in the idle function because there is constant motion, so we want to redisplay whenever
GLUT/OpenGL has nothing else to do and is idle. The actual redisplay will happen at some point
after the idle function returns, when GLUT is ready to redraw the window.
More generally, if you only require redrawing when a mouse event causes an object to move, or
similar, you should only call glutPostRedisplay() when such a change occurs. Calling it
multiple times is fine if multiple changes occur before a redraw happens - it just sets a variable
that GLUT uses to remember that a redraw is required.]
     */
    glutPostRedisplay();
}

//----------------------------------------------------------------------------

void
keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 033:
            exit(EXIT_SUCCESS);
            break;
    }
}

//----------------------------------------------------------------------------

int
main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glutInitWindowSize(600, 600);

    // If you are using freeglut, the next two lines will check if 
    // the code is truly 3.2. Otherwise, comment them out

    glutInitContextVersion(4, 0);
    glutInitContextProfile(GLUT_CORE_PROFILE);

    glutCreateWindow("Scene");

    glewInit();

    init();

    glutIdleFunc(idle);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}
