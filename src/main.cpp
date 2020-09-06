#include <iostream>
#include <unistd.h>
#include <GL/freeglut.h>
#include <time.h>

#include "settings.hpp"
#include "View.hpp"
#include "Sim.hpp"
#include "Env.hpp"
#include "Entity.hpp"

using namespace std;


int main(int argc, char** argv) {
    cout << "Starting Program\n";

    // Entity ety(3.0f,4.0f,5.0f);
    // ety.print();

    Sim::env = new Env();
    

    View::init(argc, argv);

    timespec ts = {0, 1000000000/FRAME_RATE};
    while (1) {
        nanosleep(&ts, NULL);
        Sim::tick();
        View::draw();
    }

    cout << "Quitting\n";

    return 0;
}
