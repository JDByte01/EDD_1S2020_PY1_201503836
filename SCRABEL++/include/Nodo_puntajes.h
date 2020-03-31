#ifndef NODO_PUNTAJES_H
#define NODO_PUNTAJES_H

#include <string.h>
#include <iostream>
using namespace std;

class Nodo_puntajes
{
    public:
        Nodo_puntajes();
        virtual ~Nodo_puntajes();

        int getPunteo() { return punteo; }
        void setPunteo(int val) { punteo = val; }
        Nodo_puntajes* getSiguiente() { return this->siguiente; }
        void setSiguiente(Nodo_puntajes* val) { this->siguiente = val; }
        string imprimir();
        string getGraphviz();

    protected:

    private:
        int punteo;
        Nodo_puntajes* siguiente;
};

#endif // NODO_PUNTAJES_H
