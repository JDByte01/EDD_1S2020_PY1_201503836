#ifndef NODO_FICHA_H
#define NODO_FICHA_H

#include <string.h>
#include <iostream>
using namespace std;

class Nodo_ficha
{
    public:
        Nodo_ficha();
        virtual ~Nodo_ficha();

        Nodo_ficha(int x, char c);
        //Set
        void setPuntos(int x){ this->puntos = x; }
        void setLetra(char c){ this->letra = c; }
        void setSiguiente(Nodo_ficha* n){ this->siguiente = n;}
        void setAnterior(Nodo_ficha* n){ this->anterior = n;}
        //Get
        int getPuntos(){ return this->puntos; }
        char getLetra(){ return this->letra; }
        Nodo_ficha* getSiguiente(){ return this->siguiente; }
        Nodo_ficha* getAnterior(){ return this->anterior; }
        //Otros
        string getGraphviz(int x);

    protected:

    private:
        int puntos;
        char letra;
        Nodo_ficha* siguiente;
        Nodo_ficha* anterior;
};

#endif // NODO_FICHA_H
