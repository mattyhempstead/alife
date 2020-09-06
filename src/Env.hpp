#ifndef ENV_H
#define ENV_H

#include <list>
#include "Food.hpp"

class Env {
    public:
        Food* ety;

        std::list<Food*> food_list;
        std::list<Food*>::iterator food_list_iter;

        Env();
        void draw();
};


#endif
