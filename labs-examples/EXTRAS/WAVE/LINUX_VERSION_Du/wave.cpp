/* sets up flat mesh */
/* sets up elapsed time parameter for use by shaders */
/* vertex shader varies height of mesh sinusoidally */
/* uses a pass through fragment shader */

#include "Angel.h"

typedef Angel::vec4 point4;

#define N 64

const GLdouble nearVal     = 1.0; /* near distance */
const GLdouble farVal      = 20.0; /* far distance */
GLuint         program     = 0; /* program object id */
GLint          timeParam;

GLfloat data[N][N]; /* array of data heights */

point4 points[6*N*N];


GLuint MVP_loc;

/* GLSL initialization */

int Index = 0;
void mesh()
{
    int i,j;
    for(i=0; i<N; i++) for(j=0; j<N;j++)
    {
       points[Index] = vec4((float)i/N, data[i][j], (float)j/N, 1.0); Index++;
       points[Index] = vec4((float)i/N, data[i][j], (float)(j+1)/N, 1.0); Index++;
       points[Index] = vec4((float)(i+1)/N, data[i][j], (float)(j+1)/N, 1.0); Index++;
       points[Index] = vec4((float)(i+1)/N, data[i][j], (float)(j+1)/N, 1.0); Index++;
       points[Index] = vec4((float)(i+1)/N, data[i][j], (float)j/N, 1.0); Index++;
       points[Index] = vec4((float)i/N, data[i][j], (float)j/N, 1.0); Index++;
    }
}

// OpenGL initialization
void
init()
{
    mesh();

    // Create a vertex array object
    GLuint vao;
    glGenVertexArrays( 1, &vao );
    glBindVertexArray( vao );

    // Create and initialize a buffer object
    GLuint buffer;
    glGenBuffers( 1, &buffer );
    glBindBuffer( GL_ARRAY_BUFFER, buffer );
    glBufferData( GL_ARRAY_BUFFER, sizeof(points), points, GL_STATIC_DRAW ); 

    // Load shaders and use the resulting shader program
    GLuint program = InitShader( "vmesh.glsl", "fmesh.glsl" );
    glUseProgram( program );

    // set up vertex arrays
    GLuint vPosition = glGetAttribLocation( program, "vPosition" );
    glEnableVertexAttribArray( vPosition );
    glVertexAttribPointer( vPosition, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0) );

    timeParam = glGetUniformLocation(program, "time");
    MVP_loc = glGetUniformLocation(program, "ModelViewProjection");
    
    glClearColor( 1.0, 1.0, 1.0, 1.0 );
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}


static void draw(void)
{
    /* send elapsed time to shaders */

    mat4 MVP;
    MVP=Ortho(-0.75,0.75,-0.75,0.75,-5.5,5.5)*LookAt(vec4(2.0, 2.0, 2.0, 1.0), vec4(0.5, 0.0, 0.5, 1.0), vec4(0.0, 1.0, 0.0, 1.0));
    glUniformMatrix4fv(MVP_loc, 1, GL_TRUE, MVP);
    glUniform1f(timeParam, glutGet(GLUT_ELAPSED_TIME));
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //for(int i =0; i< 4*N*N; i+=3) glDrawArrays(GL_LINE_LOOP, i, 3);
    glDrawArrays(GL_TRIANGLES, 0, 6*N*N);
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
   glUniform1f(timeParam, (GLfloat) glutGet(GLUT_ELAPSED_TIME));
   glutPostRedisplay();
}

int main(int argc, char** argv)
{
    int i,j;

    /* flat mesh */ 

    for(i=0;i<N;i++) for(j=0;j<N;j++) data[i][j]=0.0;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glutInitWindowSize(512, 512);
    glutCreateWindow("waving mesh example");
    glutDisplayFunc(draw);
    glutKeyboardFunc(keyboard);
    glutIdleFunc(idle);

    init();
    InitShader("vmesh.glsl", "fmesh.glsl");

    glutMainLoop();
}
