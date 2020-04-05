#ifndef NODO_MATRIZ_H
#define NODO_MATRIZ_H

#include <string.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

class Nodo_matriz
{
    public:
        Nodo_matriz();
        virtual ~Nodo_matriz();
        Nodo_matriz(string i, int x, int y, char l);
        //Get
        string getId(){ return this->id; }
        int getX(){ return this->x; }
        int getY(){ return this->y; }
        ///int getPuntos(){ return this->puntos; }
        ///int getMultiplicador(){ return this->multiplicador; }
        char getLetra(){ return this->letra; }
        Nodo_matriz* getArriba(){ return this->arriba; }
        Nodo_matriz* getAbajo(){ return this->abajo; }
        Nodo_matriz* getDerecha(){ return this->derecha; }
        Nodo_matriz* getIzquierda(){ return this->izquierda; }
        //Set
        void setId(string i){ this->id = i;}
        void setX(int n){ this->x = n; }
        void setY(int n){ this->y = n; }
        ///void setPuntos(int n){ this->puntos = n;}
        ///void setMultiplicador(int n){ this->multiplicador = n; }
        void setLetra(char l){ this->letra = l; }
        void setArriba(Nodo_matriz* n){ this->arriba = n; }
        void setAbajo(Nodo_matriz* n){ this->abajo = n; }
        void setDerecha(Nodo_matriz* n){ this->derecha = n; }
        void setIzquierda(Nodo_matriz* n){ this->izquierda = n; }

        //Otros
        string getGraphvizNodo();
        string getGraphvizRuta();
    protected:

    private:
        string id;
        int x;
        int y;
        ///int puntos;
        ///int multiplicador;
        char letra;

        Nodo_matriz* arriba;
        Nodo_matriz* abajo;
        Nodo_matriz* derecha;
        Nodo_matriz* izquierda;
};

#endif // NODO_MATRIZ_H
