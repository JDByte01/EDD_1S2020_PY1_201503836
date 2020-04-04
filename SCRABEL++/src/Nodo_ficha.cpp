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

