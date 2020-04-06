#ifndef NODO_COORDENADA_H
#define NODO_COORDENADA_H

#include <string.h>
#include <iostream>
using namespace std;

class Nodo_coordenada
{
    public:
        Nodo_coordenada(int x, int y);
        virtual ~Nodo_coordenada();

        void setX(int x){ this->x = x; }
        void setY(int y){ this->y = y; }
        void setSiguiente(Nodo_coordenada* n){ this->siguiente = n;}
        int getX(){ return this->x; }
        int getY(){ return this->y; }
        Nodo_coordenada* getSiguiente(){ return this->siguiente; }
    protected:

    private:
        int x;
        int y;

        Nodo_coordenada* siguiente;
};

#endif // NODO_COORDENADA_H
