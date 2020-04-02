#ifndef LISTA_SCORE_H
#define LISTA_SCORE_H

#include <Nodo_score.h>

#include <string.h>
#include <iostream>
using namespace std;

class Lista_score
{
    public:
        Lista_score();
        virtual ~Lista_score();

        Nodo_score* getInicio(){ return this->inicio; }
        void setInicio(Nodo_score* n){ this->inicio = n; }

        void insertar(string u, int x);
        bool estaVacio(){ return this->inicio == NULL; }
        void imprimirLista();
        string getGraphviz();

    protected:

    private:
        Nodo_score* inicio;
};

#endif // LISTA_SCORE_H
