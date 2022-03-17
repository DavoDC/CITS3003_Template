// Render to Texture Example

// Create Texture from Sierpinski Gasket
// Diffuse this texture
// Add random points ieach iteration and diffuse them


#include "Angel.h"

using namespace std;

const int NumTimesToSubdivide = 5;
const int NumTriangles = 243;  // 3^5 triangles generated
const int NumVertices  = 3 * NumTriangles;

const int TEXSIZE=512;

vec2 points[NumVertices]; // points for Sierpinski gasket

// Two triangles for quad to draw texture in
// quad[6] extra point used to add random points dynamically

vec2 quad[7] = {vec2(-1.0, -1.0), vec2(-1.0, 1.0), vec2(1.0, 1.0), vec2(1.0, 1.0), vec2(1.0, -1.0), vec2(-1.0, -1.0), vec2(0.0, 0.0)};

// texture coordinares for quad

vec2 tex[6] = {vec2(0.0, 0.0), vec2(0.0, 1.0), vec2(1.0, 1.0), vec2(1.0, 1.0), vec2(1.0, 0.0), vec2(0.0, 0.0)};

int Index = 0;

int texbuffer = 1;

GLuint program1, program2, program3;
GLuint framebuffer, textures[2];
GLuint renderbuffer;
GLuint buffer;
GLuint vao;

// Sierpinski gasket functions

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

   glPointSize(10.0);

   glGenTextures( 2, textures);
   glBindTexture(GL_TEXTURE_2D, textures[0]);
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, TEXSIZE, TEXSIZE, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
   glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE );
   glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE );
   glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );
   glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );

   glBindTexture(GL_TEXTURE_2D, textures[1]);
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, TEXSIZE, TEXSIZE, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
   glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE );
   glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE );
   glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );
   glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );

   glEnable(GL_TEXTURE_2D);
   glActiveTexture(GL_TEXTURE0);

   glBindTexture(GL_TEXTURE_2D, textures[1]);
   glGenRenderbuffers(1, &renderbuffer);
   glBindRenderbuffer(GL_RENDERBUFFER, renderbuffer);

   glGenFramebuffers( 1, &framebuffer);
   glBindFramebuffer( GL_DRAW_FRAMEBUFFER, framebuffer);
   glFramebufferTexture2D(GL_DRAW_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, textures[1], 0);



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
    program1 = InitShader( "vrender21.glsl", "frender21.glsl" );
    program2 = InitShader( "vrender22.glsl", "frender22.glsl" );
    program3 = InitShader( "vrender23.glsl", "frender23.glsl" );



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
    glViewport(0, 0, TEXSIZE, TEXSIZE);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear( GL_COLOR_BUFFER_BIT  );
    glDrawArrays( GL_TRIANGLES, 0, 3*NumTriangles );


    // Bind to window system frame buffer, unbind the texture
    glGenerateMipmap(GL_TEXTURE_2D);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);

    glBufferData(GL_ARRAY_BUFFER, sizeof(quad)+sizeof(tex), NULL, GL_STATIC_DRAW);
    glBufferSubData( GL_ARRAY_BUFFER, 0, sizeof(quad), quad);
    glBufferSubData( GL_ARRAY_BUFFER, sizeof(quad), sizeof(tex), tex);

    glUseProgram(program2);



    glDisableVertexAttribArray(loc);
    GLuint quad_loc = glGetAttribLocation( program2, "vPosition" );
    glEnableVertexAttribArray( quad_loc );
    glVertexAttribPointer( quad_loc, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0) );

    GLuint vTexCoord = glGetAttribLocation( program2, "vTexCoord"); 
    glEnableVertexAttribArray( vTexCoord );
    glVertexAttribPointer( vTexCoord, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(sizeof(quad)) );

    GLuint quad_loc3 = glGetAttribLocation( program3, "vPosition" );
    glEnableVertexAttribArray( quad_loc3 );
    glVertexAttribPointer( quad_loc3, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0) );

    glUniform1i( glGetUniformLocation(program2, "texture"), 0 );
    glUniform1f( glGetUniformLocation(program2, "d"), 1.0/((float) TEXSIZE ) );
    glBindTexture(GL_TEXTURE_2D, textures[1]);

    glViewport(0, 0, TEXSIZE, TEXSIZE);
    glClearColor(0.0, 0.0, 0.0, 1.0);

    glClear( GL_COLOR_BUFFER_BIT );
    glDrawArrays( GL_TRIANGLES, 0, 6 );
    glutSwapBuffers();
}

//---------------------------------------------------------------------------

void
idle( void)

{

   // uncomment for frame by frame display
   // int s;
   //scanf("%d",&s);

// render to texture

   glBindTexture(GL_TEXTURE_2D, textures[texbuffer]);

   glGenRenderbuffers(1, &renderbuffer);
   glBindRenderbuffer(GL_RENDERBUFFER, renderbuffer);

   glGenFramebuffers( 1, &framebuffer);
   glBindFramebuffer( GL_DRAW_FRAMEBUFFER, framebuffer);
   glFramebufferTexture2D(GL_DRAW_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, textures[1-texbuffer], 0);

    glDrawArrays( GL_TRIANGLES, 0, 6 );

// drop in a random point using program 3

    glUseProgram(program3);
    float rx = 2.0*rand()/RAND_MAX-1.0;
    float ry = 2.0*rand()/RAND_MAX-1.0;
    quad[6] = vec2(rx, ry);
    glBufferSubData( GL_ARRAY_BUFFER, 0, sizeof(quad), quad);
    glDrawArrays(GL_POINTS, 6, 1);
    glUseProgram(program2);

// render to display

    glGenerateMipmap(GL_TEXTURE_2D);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);

    glBindTexture(GL_TEXTURE_2D, textures[1-texbuffer]);
    glViewport(0, 0, TEXSIZE, TEXSIZE);
    glClearColor(1.0, 0.0, 0.0, 1.0);
    glClear( GL_COLOR_BUFFER_BIT );
    glDrawArrays( GL_TRIANGLES, 0, 6 );
    glutSwapBuffers();

// swap textures

    if(texbuffer==1) texbuffer = 0;
    else texbuffer = 1;

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
    glutInitDisplayMode( GLUT_RGBA |GLUT_DOUBLE);
    glutInitWindowSize( TEXSIZE, TEXSIZE );
    glutCreateWindow( "Simple GLSL example" );

    init();

    glutDisplayFunc( display );
    glutKeyboardFunc( keyboard );

    glutIdleFunc(idle);

    glutMainLoop();
    return 0;
}
