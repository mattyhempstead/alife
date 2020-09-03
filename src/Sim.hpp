#ifndef SIM_H
#define SIM_H

#include "Env.hpp"

/**
 * A static class to handle updating of the simulation.
 */
class Sim {
    public:
        static Env env;

        static void tick();
};


#endif
