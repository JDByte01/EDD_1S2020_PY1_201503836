#include "Nodo_ficha.h"

Nodo_ficha::Nodo_ficha()
{
    this->puntos = 0;
    this->letra = ' ';
    this->siguiente = NULL;
    this->anterior = NULL;
}

Nodo_ficha::~Nodo_ficha()
{
    //dtor
    this->siguiente = NULL;
    this->anterior = NULL;
}

Nodo_ficha::Nodo_ficha(int x, char c){
    this->puntos = x;
    this->letra = c;
    this->siguiente = NULL;
    this->anterior = NULL;
}

string Nodo_ficha::getGraphviz(int x){
    if(this->anterior == NULL){
        return  "n"+ to_string(x) + "[label = \""+ this->letra+"\" width = 1];\nn"+ to_string(x) +" -> n"+ to_string(x + 1) +";";
    } else if(this->siguiente == NULL){
        return  "n"+ to_string(x) + "[label = \""+ this->letra+"\" width = 1];\nn"+ to_string(x +1) +" -> n"+ to_string(x) +";";
    } else {
        return  "n"+ to_string(x) + "[label = \""+ this->letra+"\" width = 1];\nn"+ to_string(x) +" -> n"+ to_string(x + 1) +";\nn"+ to_string(x +1) +" -> n"+ to_string(x) +";";
    }
}

