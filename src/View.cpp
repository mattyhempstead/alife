#include <iostream>
#include <time.h>
#include <GL/freeglut.h>
#include <ctime>
#include <chrono>

#include "settings.hpp"
#include "draw.hpp"
#include "View.hpp"

using namespace std;

long View::frame_no = 0;
long View::last_frame_no = 0;
int View::last_frame_rate = 0;
int View::curr_frame_time = time(0);


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

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    DRAW::rect();

    glFlush();

}
