#include <iostream>
#include <GL/freeglut.h>
#include "draw.h"

using namespace std;

void display() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    DRAW::rect();

    glFlush();
}

int main(int argc, char** argv) {
    cout << "Hello World\n";

    glutInit(&argc, argv);
    glutCreateWindow("OpenGL Setup Test");
    glutInitWindowSize(320, 320);
    glutInitWindowPosition(50, 50);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
