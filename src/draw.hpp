#ifndef DRAW_H
#define DRAW_H

#include <GL/freeglut.h>

namespace draw {
    GLfloat const white[]   = {1.f, 1.f, 1.f};
    GLfloat const red[]     = {1.f, 0.f, 0.f};
    GLfloat const green[]   = {0.f, 1.f, 0.f};
    GLfloat const blue[]    = {0.f, 0.f, 1.f};

    void rect(float x1, float y1, float x2, float y2, GLfloat const* color = draw::white);
    void circle(float cx, float cy, float cr, GLfloat const *color = draw::white, int num_segments = 16);
}


#endif
