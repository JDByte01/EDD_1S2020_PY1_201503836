#ifndef MATRIZ_TABLERO_H
#define MATRIZ_TABLERO_H

#include <string.h>
#include <iostream>
using namespace std;

#include <Nodo_matriz.h>

class Matriz_tablero
{
    public:
        Matriz_tablero();
        virtual ~Matriz_tablero();

        //
        bool agregar(int x, int y, char l);
        void agregaEjeX(int x);
        void agregarEjeY(int y);
        bool insertarNodo(int x, int y, char l);

        string getGraphviz();

    protected:

    private:
        Nodo_matriz* headers;
};

#endif // MATRIZ_TABLERO_H
