#ifndef ENTITY_H
#define ENTITY_H

class Entity {
    public:
        Entity(float x, float y, float r);
        void draw();
        void print();
        
        float x;
        float y;
        float r;
};


#endif
