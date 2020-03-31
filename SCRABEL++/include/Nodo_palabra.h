#ifndef NODO_PALABRA_H
#define NODO_PALABRA_H

#include <string.h>
#include <iostream>
using namespace std;

class Nodo_palabra
{
    public:
        Nodo_palabra();
        virtual ~Nodo_palabra();

        Nodo_palabra(string palabra);
        void setPalabra(string p){ this->palabra = p; }
        void setSiguiente(Nodo_palabra * s){ this->siguiente = s;}
        void setAnterior(Nodo_palabra * a){ this->anterior = a;}
        string getPalabra(){ return this->palabra; }
        Nodo_palabra *getSiguiente(){ return this->siguiente; }
        Nodo_palabra *getAnterior(){ return this->anterior; }

        string imprimir();
        string getGraphviz();

    protected:

    private:
        string palabra;
        Nodo_palabra *siguiente;
        Nodo_palabra *anterior;
};

#endif // NODO_PALABRA_H
