#include "Nodo_palabra.h"

Nodo_palabra::Nodo_palabra()
{
    this->palabra = "";
    this->siguiente = NULL;
    this->anterior = NULL;
}

Nodo_palabra::~Nodo_palabra()
{
    //dtor
}

Nodo_palabra::Nodo_palabra(string p){
    this->palabra = p;
    this->siguiente = NULL;
    this->anterior = NULL;
}

void Nodo_palabra::imprimir(){
    cout << "\t|-> [" << this->palabra << "] " << endl;
}

string Nodo_palabra::getGraphviz(){

    return "\"" + this->palabra + "\" -> \"" + this->siguiente->palabra + "\";\n \"" + this->palabra + "\" -> \"" + this->anterior->palabra + "\";\n";
}
