#include <iostream>
#include <time.h>
#include <GL/freeglut.h>
#include <sstream>

#include "settings.hpp"
#include "draw.hpp"
#include "View.hpp"

using namespace std;

long View::frame_no = 0;
long View::last_frame_no = 0;
int View::last_frame_rate = 0;
int View::curr_frame_time = time(0);

double View::zoom = 1;

int View::window_width = 0;
int View::window_height = 0;

void View::init(int argc, char** argv) {
    cout << "Initialising View\n";

    glutInit(&argc, argv);
    glutCreateWindow("OpenGL Setup Test");
    glMatrixMode(GL_PROJECTION);

    glutReshapeFunc(View::reshapeCallback);
    glutMouseFunc(View::mouseCallback);
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
    }

    glClear(GL_COLOR_BUFFER_BIT);

    glLoadIdentity(); 
    glViewport(0, 0, window_width, window_height);
    gluOrtho2D(-window_width/2/zoom, window_width/2/zoom, -window_height/2/zoom, window_height/2/zoom);


    glBegin(GL_POLYGON);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2i(-50, -50);
    glVertex2i( 50, -50);
    glVertex2i( 50,  50);
    glVertex2i(-50,  50);
    glEnd();

    DRAW::rect();


    stringstream ss;
    ss << "ALife" << "\n\n";
    ss << "FPS: " << last_frame_rate << "\n";

    // Draw text with the top left at (0,0)
    glLoadIdentity();
    gluOrtho2D(0, window_width, window_height, 0);
    glColor4f(1.0f,1.0f,1.0f,1.0f);
    glRasterPos2i(5, 15);
    glutBitmapString(GLUT_BITMAP_9_BY_15, (const unsigned char*)ss.str().c_str());

    glFlush();
    glutMainLoopEvent();
}

void View::reshapeCallback(int w, int h) {
    window_width = w;
    window_height = h;

    // cout << "Resizing window: " << w << " " << h << "\n";
    // glLoadIdentity(); 
    // glViewport(0,0,w,h);
    // gluOrtho2D(-w/2/zoom, w/2/zoom, -h/2/zoom, h/2/zoom);
}

void View::mouseCallback(int button, int state, int x , int y) {
    // cout << button << " " << state << " " << x << " " << y << "\n";
    if ((button == 3 || button == 4) && state) {
        zoom *= (button == 3) ? 1.0/(1 - ZOOM_RATE) : (1 - ZOOM_RATE);
        reshapeCallback(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
    }
}
