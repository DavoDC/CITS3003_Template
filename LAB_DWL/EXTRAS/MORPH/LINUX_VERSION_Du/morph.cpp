/* Simple morphing of one triangle into another */

/* sets up elapsed time parameter for use by shaders */

#include "Angel.h"

using namespace Angel;

GLint          timeParam;
GLint          vertices_one_location;
GLint          vertices_two_location;

typedef vec2 point2;

point2 vertices_one[3] = {vec2(-1.0, -1.0), vec2(0.0,1.0), vec2(1.0, -1.0)};
point2 vertices_two[3] = {vec2(1.0, -1.0), vec2(0.0,-1.0), vec2(1.0, 1.0)};

void init()
{

    GLuint vao;
    glGenVertexArrays( 1, &vao );
    glBindVertexArray( vao );

    // Create and initialize a buffer object
    GLuint buffer;
    glGenBuffers( 1, &buffer );
    glBindBuffer( GL_ARRAY_BUFFER, buffer );
    glBufferData( GL_ARRAY_BUFFER, sizeof(vertices_one) + sizeof(vertices_two), NULL, GL_STATIC_DRAW );
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices_one), vertices_one);
    glBufferSubData(GL_ARRAY_BUFFER, sizeof(vertices_one),  sizeof(vertices_two), vertices_two);

    // Load shaders and use the resulting shader program
    GLuint program = InitShader( "vmorph.glsl", "fmorph.glsl" );
    glUseProgram( program );

    // Initialize the vertex position attribute from the vertex shader
    GLuint vertices_one_location = glGetAttribLocation( program, "vertices1" );
    glEnableVertexAttribArray( vertices_one_location );
    glVertexAttribPointer( vertices_one_location, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0) );

    GLuint vertices_two_location = glGetAttribLocation( program, "vertices2" );
    glEnableVertexAttribArray( vertices_two_location );
    glVertexAttribPointer( vertices_two_location, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(sizeof(vertices_one)));
    glClearColor( 1.0, 1.0, 1.0, 1.0 ); /* white background */


}

static void draw(void)
{
    /* send elapsed time to shaders */

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glUniform1f(timeParam, glutGet(GLUT_ELAPSED_TIME));

    glDrawArrays(GL_LINE_LOOP, 0, 3);

    glutSwapBuffers();
}


static void keyboard(unsigned char key, int x, int y)
{
    switch (key) {
    case 27:
    case 'Q':
    case 'q':
        exit(EXIT_SUCCESS);
        break;
    default:
        break;
    }
}

void idle()
{
   glUniform1f(timeParam, glutGet(GLUT_ELAPSED_TIME));
   glutPostRedisplay();
}

int main(int argc, char** argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE );
    glutInitWindowSize(512, 512);
    glutCreateWindow("Simple GLSL morphing");
    glutDisplayFunc(draw);
    glutKeyboardFunc(keyboard);
    glutIdleFunc(idle);

    init();
   

    glutMainLoop();
    return 0;
}
