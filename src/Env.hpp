#ifndef ENV_H
#define ENV_H

#include "Food.hpp"

class Env {
    public:
        double rectX;
        double rectY;

        Food* ety;

        Env();
        void draw();
};


#endif
