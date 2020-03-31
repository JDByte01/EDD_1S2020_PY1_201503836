#include "Nodo_puntajes.h"

Nodo_puntajes::Nodo_puntajes()
{
    this->punteo = 0;
    this->siguiente = NULL;
}

Nodo_puntajes::~Nodo_puntajes()
{
    //dto

}

string Nodo_puntajes::imprimir(){
    return "[" + to_string(this->punteo) + "]";
}

string Nodo_puntajes::getGraphviz(){
    return "\"" + to_string(this->punteo) + "\" -> \"" + to_string(this->siguiente->punteo) + "\";";
}
