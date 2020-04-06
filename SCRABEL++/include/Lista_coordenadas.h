#ifndef LISTA_COORDENADAS_H
#define LISTA_COORDENADAS_H

#include <string.h>
#include <iostream>
using namespace std;

#include <Nodo_coordenada.h>

class Lista_coordenadas
{
    public:
        Lista_coordenadas();
        virtual ~Lista_coordenadas();
        void agregar(int x, int y);
        bool existe(int x, int y);
        void vaciar();
        void imprimir();

    protected:

    private:
        Nodo_coordenada* inicio;
};

#endif // LISTA_COORDENADAS_H
