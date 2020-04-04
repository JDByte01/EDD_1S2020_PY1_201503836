#ifndef COLA_FICHAS_H
#define COLA_FICHAS_H

#include <string.h>
#include <iostream>
using namespace std;

#include <Nodo_ficha.h>

class Cola_fichas
{
    public:
        Cola_fichas();
        virtual ~Cola_fichas();

        //Get
        int enCola(){ return this->size; }
        Nodo_ficha* getInicio(){ return this->inicio; }
        //Set
        void setInicio(Nodo_ficha* n){ this->inicio = n; }
        //Otros
        bool estaVacio(){ return this->inicio == NULL; }
        void encolar(Nodo_ficha* n);
        Nodo_ficha* desencolar();

        void imprimir();
        string getGraphviz();
        void vaciar();

    protected:

    private:
        Nodo_ficha* inicio;
        int size;
};

#endif // COLA_FICHAS_H
