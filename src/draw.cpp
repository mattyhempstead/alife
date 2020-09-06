#include "draw.hpp"
#include <GL/freeglut.h>
#include "math.h"
#include <iostream>

namespace draw {

    void rect(float x1, float y1, float x2, float y2, GLfloat const* color) {
        glColor3fv(color);
        glRectf(x1, y1, x2, y2);
    }

    void circle(float cx, float cy, float cr, GLfloat const *color, int num_segments) {
        glColor3fv(color);
        glBegin(GL_POLYGON);

        for (int i = 0; i < num_segments; i++)   {
            float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);
            float x = cr * cosf(theta);
            float y = cr * sinf(theta);
            glVertex2f(x + cx, y + cy);
        }

        glEnd();
    }

}

