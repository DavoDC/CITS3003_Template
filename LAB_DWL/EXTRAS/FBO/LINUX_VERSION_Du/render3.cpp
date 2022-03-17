/* render3 - We first render a Sierpinksi gasket onto a texture map of size
 * 256 x 256 pixels using program1. We then define two large triangles (see
 * the 'quad' array) that cover the entire texture map and the corresponding
 * texture coordinates (see the 'tex' array). The contents of the 'quad' and
 * 'tex' arrays are copied to the vertex shader vrender21.glsl through
 * program2.  Subsequently, whenever the 'display' callback function needs to
 * redraw the Sierpinkski gasket, rather than drawing many small triangles
 * using program1, all we need to do is use program2 to draw two large
 * triangles as the union of the faces of these triangles contains the
 * Sierpinski gasket. Note the diagonal edges of the Sierpinski gasket are
 * jagged.
 *
 * render3.cpp was modified from render1.cpp. The main differences between
 * these two programs are:
 * 1. a lot of the code in the 'display' callback function of render1.cpp have
 *    been moved to the 'init' function in render3.cpp. We only need to render
 *    the texture map once rather than every time 'display' is called.
 * 2. we don't need a depth buffer and double buffering. So in the 'main'
 *    function, we replace
 *       glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
 *    by
 *       glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
 *    Also, in the 'display' function, we replace
 *       glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 *       glutSwapBuffers();
 *    by
 *       glClear(GL_COLOR_BUFFER_BIT);
 *       glFlush();
 * 3. in render1.cpp, the global variables program1, program2, framebuffer,
 *    texture, buffer, and vao are now declared locally in the 'init'
 *    function here. The variables 'quad' and 'tex' can actually be moved into
 *    there as well.
 *
 * A lot of comments have been inserted into the code to aid understanding.
 *
 * Du Huynh
 * March 216
 */ 

#include "Angel.h"

using namespace std;

const int NumTimesToSubdivide = 5;
const int NumTriangles = 243;  // 3^5 triangles generated
const int NumVertices  = 3 * NumTriangles;

// vertices of the base triangle
vec2 vertices[3] = {
    vec2(-1.0, -1.0), vec2(0.0, 1.0), vec2(1.0, -1.0)
};
// points that form the sierpinksi gasket
vec2 points[NumVertices];

// quad contains the vertices of two right triangles that cover the texture
// map
vec2 quad[6] = {
    vec2(-1.0, -1.0), vec2(-1.0, 1.0), vec2(1.0, 1.0),
    vec2(1.0, 1.0), vec2(1.0, -1.0), vec2(-1.0, -1.0)
};
// the corresponding texture coordinates for the points in the quad array
vec2 tex[6] = {
    vec2(0.0, 0.0), vec2(0.0, 1.0), vec2(1.0, 1.0),
    vec2(1.0, 1.0), vec2(1.0, 0.0), vec2(0.0, 0.0)
};

int Index = 0;

//----------------------------------------------------------------------------

void triangle(const vec2& a, const vec2& b, const vec2& c)
{
    points[Index++] = a;
    points[Index++] = b;
    points[Index++] = c;
}

//----------------------------------------------------------------------------

void divide_triangle(const vec2& a, const vec2& b, const vec2& c, int count)
{
    if (count > 0) {
        vec2 v0 = (a + b) / 2.0;
        vec2 v1 = (a + c) / 2.0;
        vec2 v2 = (b + c) / 2.0;
        divide_triangle(a, v0, v1, count - 1);
        divide_triangle(c, v1, v2, count - 1);
        divide_triangle(b, v2, v0, count - 1);
    }
    else 
        triangle(a, b, c);    // draw triangle at end of recursion
}

//----------------------------------------------------------------------------

void init(void)
{
    GLuint program1, program2;
    GLuint framebuffer, texture;
    GLuint buffer;
    GLuint vao;
    GLuint renderbuffer;

    // Create an Empty texture map
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 256, 256, 0,
                 GL_RGBA, GL_UNSIGNED_BYTE, NULL);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

    glGenRenderbuffers(1, &renderbuffer);
    glBindRenderbuffer(GL_RENDERBUFFER, renderbuffer);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT24, 256, 256);

    glGenFramebuffers(1, &framebuffer);
    glBindFramebuffer(GL_DRAW_FRAMEBUFFER, framebuffer);
    glFramebufferTexture2D(GL_DRAW_FRAMEBUFFER, GL_COLOR_ATTACHMENT0,
                           GL_TEXTURE_2D, texture, 0);
    glFramebufferRenderbuffer(GL_DRAW_FRAMEBUFFER, GL_DEPTH_ATTACHMENT,
                              GL_RENDERBUFFER, renderbuffer);

    int status = glCheckFramebufferStatus(GL_FRAMEBUFFER);
    if (status == GL_FRAMEBUFFER_COMPLETE)
        printf("Frame Buffer Complete\n");

    // construct the vertices of triangles that form the sierpinka gasket
    divide_triangle(vertices[0], vertices[1], vertices[2], NumTimesToSubdivide);

    // Create vertex array objects
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    // Create and initialize a buffer object to store the vertices
    // that form the sierpinski triangle
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(points), NULL, GL_STATIC_DRAW);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(points), points);

    // program1 - we copy the vertices of the small sierpinski triangles 
    // to the vertex shader vrender11.glsl.
    program1 = InitShader("vrender11.glsl", "frender11.glsl");
    GLuint loc = glGetAttribLocation(program1, "vPosition");
    glEnableVertexAttribArray(loc);
    glVertexAttribPointer(loc, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
    // the variable named 'vPosition' is now tied to the buffer which already
    // contains the points for the sierpinksi gasket.

    /* ----- draw and fill the sierpinski gasket ----- */
    glClearColor(1.0, 1.0, 1.0, 1.0); /* white background */
    // draw the sierpinski gasket into the render buffer
    glUseProgram(program1);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBindFramebuffer(GL_DRAW_FRAMEBUFFER, framebuffer);

    glViewport(0, 0, 256, 256);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    // normal render
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glDrawArrays(GL_TRIANGLES, 0, 3*NumTriangles);

    // Bind to window system frame buffer, unbind the texture
    glGenerateMipmap(GL_TEXTURE_2D);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);

    glEnable(GL_TEXTURE_2D);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

    glBufferData(GL_ARRAY_BUFFER, sizeof(quad)+sizeof(tex), NULL,
                 GL_STATIC_DRAW);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(quad), quad);
    glBufferSubData(GL_ARRAY_BUFFER, sizeof(quad), sizeof(tex), tex);

    glActiveTexture(GL_TEXTURE0);

    glDisableVertexAttribArray(loc);

    /* Now the texture map has the drawing of the sierpinksi gasket.
     * From now on (and in the display callback function), we only need to
     * draw two large triangles (stored in the 'quad' array) that span
     * the entire texture map. It is more efficient to draw 2 triangles
     * than drawing NumTriangles triangles. We can therefore forget about
     * program1 and use only program2 from now on.
     */
    program2 = InitShader("vrender12.glsl", "frender12.glsl");
    glUseProgram(program2);

    GLuint quad_loc = glGetAttribLocation(program2, "vPosition");
    glEnableVertexAttribArray(quad_loc);
    glVertexAttribPointer(quad_loc, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));

    GLuint vTexCoord = glGetAttribLocation(program2, "vTexCoord"); 
    glEnableVertexAttribArray(vTexCoord);
    glVertexAttribPointer(vTexCoord, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(sizeof(quad)));

    glUniform1i(glGetUniformLocation(program2, "texture"), 0);
    glBindTexture(GL_TEXTURE_2D, texture);
}

//----------------------------------------------------------------------------

void display(void)
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    glViewport(0, 0, 512, 512);
    glDrawArrays(GL_TRIANGLES, 0, 6);

    glFlush();
}

//----------------------------------------------------------------------------

void keyboard(unsigned char key, int x, int y)
{
    switch (key) {
    case 033: case 'q': case 'Q':
        exit(EXIT_SUCCESS);
        break;
    }
}

//----------------------------------------------------------------------------

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
    glutInitWindowSize(512, 512);
    glutCreateWindow("Sierpinski gasket from a generated texture map");

    init();

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}
