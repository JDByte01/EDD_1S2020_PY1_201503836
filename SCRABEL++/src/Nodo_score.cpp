#include "Nodo_score.h"

Nodo_score::Nodo_score()
{
    this->punteo = 0;
    this->jugador = "";
    this->siguiente = NULL;
}

Nodo_score::~Nodo_score()
{
    //dtor
}

string Nodo_score::imprimir(){
    return "[" + to_string(this->punteo) + "] " + this->jugador;
}

string Nodo_score::getGraphviz(){
    if(this->siguiente == NULL){
        return "\n\"" + to_string(this->punteo) + "\" [ label = \"" + this->jugador + " | " + to_string(this->punteo) + " pts\" ];";
    } else {
        return "\n\"" + to_string(this->punteo) + "\" [ label = \"" + this->jugador + " | " + to_string(this->punteo) + " pts\" ];\n \"" + to_string(this->punteo) + "\" -> \"" + to_string(this->siguiente->punteo) + "\";";
    }
}

