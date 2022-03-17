/* sierpinski gasket with vertex arrays */

#include "Angel.h"

using namespace std;

const int NumTimesToSubdivide = 5;
const int NumTriangles = 243;  // 3^5 triangles generated
const int NumVertices  = 3 * NumTriangles;

vec2 points[NumVertices];
vec2 quad[6] = {vec2(-1.0, -1.0), vec2(-1.0, 1.0), vec2(1.0, 1.0), vec2(1.0, 1.0), vec2(1.0, -1.0), vec2(-1.0, -1.0)};
vec2 tex[6] = {vec2(0.0, 0.0), vec2(0.0, 1.0), vec2(1.0, 1.0), vec2(1.0, 1.0), vec2(1.0, 0.0), vec2(0.0, 0.0)};
int Index = 0;


GLuint program1, program2;
GLuint framebuffer, texture;
    GLuint buffer;
    GLuint vao;

//----------------------------------------------------------------------------

void
triangle( const vec2& a, const vec2& b, const vec2& c )
{
    points[Index++] = a;
    points[Index++] = b;
    points[Index++] = c;
}

//----------------------------------------------------------------------------

void
divide_triangle( const vec2& a, const vec2& b, const vec2& c, int count )
{
    if ( count > 0 ) {
        vec2 v0 = ( a + b ) / 2.0;
        vec2 v1 = ( a + c ) / 2.0;
        vec2 v2 = ( b + c ) / 2.0;
        divide_triangle( a, v0, v1, count - 1 );
        divide_triangle( c, v1, v2, count - 1 );
        divide_triangle( b, v2, v0, count - 1 );
    }
    else {
        triangle( a, b, c );    // draw triangle at end of recursion
    }
}

//----------------------------------------------------------------------------

void
init( void )
{
    GLuint renderbuffer;

   glGenTextures( 1, &texture);
   glBindTexture(GL_TEXTURE_2D, texture);
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 256, 256, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );

   glGenRenderbuffers(1, &renderbuffer);
   glBindRenderbuffer(GL_RENDERBUFFER, renderbuffer);
   glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT24, 256, 256);

   glGenFramebuffers( 1, &framebuffer);
   glBindFramebuffer( GL_DRAW_FRAMEBUFFER, framebuffer);
   glFramebufferTexture2D(GL_DRAW_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texture, 0);
   glFramebufferRenderbuffer(GL_DRAW_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, renderbuffer);


   int status = glCheckFramebufferStatus(GL_FRAMEBUFFER);
   if(status == GL_FRAMEBUFFER_COMPLETE) printf("Frame Buffer Complete\n" );
    // Create an Empty Texture

    glEnable(GL_DEPTH_TEST);



   // Create a depth buffer for frame buffer

   
   // Attach texture and depth buffers to renderbuffer





    vec2 vertices[3] = {
        vec2( -1.0, -1.0 ), vec2( 0.0, 1.0 ), vec2( 1.0, -1.0 )
    };

    // Subdivide the original triangle
    divide_triangle( vertices[0], vertices[1], vertices[2],
                     NumTimesToSubdivide );

    // Create vertex array objects
    glGenVertexArraysAPPLE( 1, &vao );
    glBindVertexArrayAPPLE( vao );

    // Create and initialize a buffer object
    glGenBuffers( 1, &buffer );
    glBindBuffer( GL_ARRAY_BUFFER, buffer );
    glBufferData( GL_ARRAY_BUFFER, sizeof(points), NULL, GL_STATIC_DRAW );
    glBufferSubData( GL_ARRAY_BUFFER, 0, sizeof(points), points);


    // Load shaders 
    program1 = InitShader( "vrender11.glsl", "frender11.glsl" );
    program2 = InitShader( "vrender12.glsl", "frender12.glsl" );



    // Initialize the vertex position attribute from the vertex shader    


    glClearColor( 1.0, 1.0, 1.0, 1.0 ); /* white background */
}

//----------------------------------------------------------------------------

void
display( void )
{

    // render into render buffer

    glUseProgram( program1 );


    // Initialize the vertex position attribute from the vertex shader    
    GLuint loc = glGetAttribLocation( program1, "vPosition" );
    glEnableVertexAttribArray( loc );
    glVertexAttribPointer( loc, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0) );


    glBindBuffer( GL_ARRAY_BUFFER, buffer);

    glBindFramebuffer(GL_DRAW_FRAMEBUFFER, framebuffer);
    glViewport(0, 0, 256, 256);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    // normal render
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glDrawArrays( GL_TRIANGLES, 0, 3*NumTriangles );


    // Bind to window system frame buffer, unbind the texture
    glGenerateMipmap(GL_TEXTURE_2D);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);

    glEnable(GL_TEXTURE_2D);
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );



    glBufferData(GL_ARRAY_BUFFER, sizeof(quad)+sizeof(tex), NULL, GL_STATIC_DRAW);
    glBufferSubData( GL_ARRAY_BUFFER, 0, sizeof(quad), quad);
    glBufferSubData( GL_ARRAY_BUFFER, sizeof(quad), sizeof(tex), tex);

    glActiveTexture(GL_TEXTURE0);
    glUseProgram(program2);



    glDisableVertexAttribArray(loc);
    GLuint quad_loc = glGetAttribLocation( program2, "vPosition" );
    glEnableVertexAttribArray( quad_loc );
    glVertexAttribPointer( quad_loc, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0) );

    GLuint vTexCoord = glGetAttribLocation( program2, "vTexCoord"); 
    glEnableVertexAttribArray( vTexCoord );
    glVertexAttribPointer( vTexCoord, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(sizeof(quad)) );


    glUniform1i( glGetUniformLocation(program2, "texture"), 0 );
    glBindTexture(GL_TEXTURE_2D, texture);

    glViewport(0, 0, 512, 512);
    glClearColor(0.0, 0.0, 0.0, 1.0);

    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glDrawArrays( GL_TRIANGLES, 0, 6 );
    glutSwapBuffers();
}

//----------------------------------------------------------------------------

void
keyboard( unsigned char key, int x, int y )
{
    switch ( key ) {
    case 033: case 'q': case 'Q':
        exit( EXIT_SUCCESS );
        break;
    }
}

//----------------------------------------------------------------------------

int
main( int argc, char **argv )
{
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_RGBA | GLUT_DEPTH |GLUT_DOUBLE);
    glutInitWindowSize( 512, 512 );
    glutCreateWindow( "Simple GLSL example" );

    init();

    glutDisplayFunc( display );
    glutKeyboardFunc( keyboard );

    glutMainLoop();
    return 0;
}
