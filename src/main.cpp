#include <iostream>
#include <unistd.h>
#include <GL/freeglut.h>
#include <time.h>

#include "settings.hpp"
#include "View.hpp"
#include "Entity.hpp"

using namespace std;



int main(int argc, char** argv) {
    cout << "Starting Program\n";

    Entity ety(3.0f,4.0f,5.0f);
    Entity ety2(2.0f,5.0f,4.0f);
    Entity ety3(4.0f,3.0f,6.0f);

    ety.print();
    ety2.print();
    ety3.print();

    glutInit(&argc, argv);
    glutCreateWindow("OpenGL Setup Test");
    glutInitWindowSize(1280, 720);
    glutInitWindowPosition(50, 50);
    //glutDisplayFunc(display);
    //glutIdleFunc(loop);
    //glutMainLoop();

    timespec ts = {0, 1000000000/FRAME_RATE};
    while (1) {
        nanosleep(&ts, NULL);
        View::draw();
    }

    return 0;
}
