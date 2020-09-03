#include <iostream>
#include <time.h>
#include <GL/freeglut.h>

#include "settings.hpp"
#include "draw.hpp"
#include "View.hpp"

using namespace std;

long View::frame_no = 0;
long View::last_frame_no = 0;
int View::last_frame_rate = 0;
int View::curr_frame_time = time(0);

double View::zoom = 1;


void View::init(int argc, char** argv) {
    cout << "Initialising View\n";

    glutInit(&argc, argv);
    glutCreateWindow("OpenGL Setup Test");
    glMatrixMode(GL_PROJECTION);

    glutReshapeFunc(View::reshapeCallback);
    glutDisplayFunc([]{}); // Dummy function, needed for reshape callback


    // glutInitWindowSize(640, 480);
    // glutInitWindowPosition(0, 0);
    //glutDisplayFunc(display);
    //glutIdleFunc(loop);
    // glutMainLoop();

    // glRectf

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void View::draw() {
    // Track frames and frame rate
    frame_no++;
    if (curr_frame_time < time(0)) {
        last_frame_rate = frame_no - last_frame_no;
        last_frame_no = frame_no;
        curr_frame_time = time(0);
        cout << "FPS: " << last_frame_rate << "\n";
    }
    //cout << "Draw " << last_frame_rate << " " << frame_no << "\n";


    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2i(-50, -50);
    glVertex2i( 50, -50);
    glVertex2i( 50,  50);
    glVertex2i(-50,  50);
    glEnd();

    DRAW::rect();


    glFlush();
    glutMainLoopEvent();
}

void View::reshapeCallback(int w, int h) {
    cout << "Resizing window: " << w << " " << h << "\n";
    
    glLoadIdentity(); 
    glViewport(0,0,w,h);
    gluOrtho2D(
        -w/2/zoom,
        w/2/zoom, 
        -h/2/zoom, 
        h/2/zoom
    );
    cout << "Func " << glutGet(GLUT_WINDOW_WIDTH) << " " << glutGet(GLUT_WINDOW_HEIGHT) << "\n";
}
