#ifndef LISTA_PUNTAJES_H
#define LISTA_PUNTAJES_H

#include <Nodo_puntajes.h>

#include <string.h>
#include <iostream>
using namespace std;

class Lista_puntajes
{
    public:
        Lista_puntajes();
        virtual ~Lista_puntajes();

        Nodo_puntajes* getInicio() { return inicio; }
        void setInicio(Nodo_puntajes* val) { inicio = val; }

        void insertar(int x);
        bool estaVacio() { return this->inicio == NULL; }
        void imprimirLista();
        string getGraphviz(string nombre);

    protected:

    private:
        Nodo_puntajes* inicio;
};

#endif // LISTA_PUNTAJES_H
