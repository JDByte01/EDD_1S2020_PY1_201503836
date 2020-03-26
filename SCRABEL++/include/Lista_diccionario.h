#ifndef LISTA_DICCIONARIO_H
#define LISTA_DICCIONARIO_H

#include <Nodo_palabra.h>

#include <string.h>
#include <iostream>
using namespace std;

class Lista_diccionario
{
    public:
        Lista_diccionario();
        virtual ~Lista_diccionario();

        void setInicio(Nodo_palabra *i){ this->inicio = i; }
        Nodo_palabra* getInicio(){ return this->inicio; }
        void insertar(Nodo_palabra *n);
        void eliminar(Nodo_palabra *n);
        bool estaVacio();
        void imprimir(string dir);
        string getGraphviz();

    protected:

    private:
        Nodo_palabra *inicio;
};

#endif // LISTA_DICCIONARIO_H
