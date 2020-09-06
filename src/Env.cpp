#include <iostream>
#include <GL/freeglut.h>

#include "Env.hpp"

using namespace std;

Env::Env() {
    cout << "Env created\n";


    Env::ety = new Food(-200, -200);

    for (int i = 0; i < 3; i++) {
        food_list.push_back(new Food(100*i, 50*i));
    }
    cout << food_list.size() << " food\n";

}

void Env::draw() {
    ety->draw();

    for (food_list_iter = food_list.begin(); food_list_iter != food_list.end(); food_list_iter++) {
        Food* food = *(food_list_iter);
        food->draw();
    }

}
