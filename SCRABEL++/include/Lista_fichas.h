#ifndef LISTA_FICHAS_H
#define LISTA_FICHAS_H

#include <string.h>
#include <iostream>
using namespace std;

#include <Nodo_ficha.h>

class Lista_fichas
{
    public:
        Lista_fichas();
        virtual ~Lista_fichas();

        //Otros
        void insertar(Nodo_ficha* n);
        void eliminar(Nodo_ficha* n);
        Nodo_ficha* getInicio(){ return this->inicio; }
        bool estaVacio(){ return this->inicio == NULL; }
        bool buscar(char l);
        void imprimir();
        void vaciar();
        string getGraphviz(string nombre);

    protected:
        Nodo_ficha* inicio;
    private:
};

#endif // LISTA_FICHAS_H
