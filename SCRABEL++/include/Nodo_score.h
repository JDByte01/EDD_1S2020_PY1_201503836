#ifndef NODO_SCORE_H
#define NODO_SCORE_H

#include <string.h>
#include <iostream>
using namespace std;

class Nodo_score
{
    public:
        Nodo_score();
        virtual ~Nodo_score();

        int getPunteo() { return punteo; }
        void setPunteo(int val) { punteo = val; }
        string getJugador(){ return this->jugador; }
        void setJugador(string j){ this->jugador = j; }
        Nodo_score* getSiguiente() { return this->siguiente; }
        void setSiguiente(Nodo_score* val) { this->siguiente = val; }
        string imprimir();
        string getGraphviz();

    protected:

    private:
        int punteo;
        string jugador;
        Nodo_score* siguiente;
};

#endif // NODO_SCORE_H
