#include "Nodo_usuario.h"

Nodo_usuario::Nodo_usuario()
{
    this->nickname = "";
    this->izquierda = NULL;
    this->derecha = NULL;
    this->puntajes = new Lista_puntajes();
}

Nodo_usuario::~Nodo_usuario()
{
    //dtor
}

//===============================
Nodo_usuario::Nodo_usuario(string name, Nodo_usuario* izq, Nodo_usuario* der, Lista_puntajes* lista){
    this->nickname = name;
    this->izquierda = izq;
    this->derecha = der;
    this->puntajes = lista;
}

int Nodo_usuario::getPunteoMaximo(){
    int tmp = 0;

    if(this->puntajes != NULL){
        tmp = this->puntajes->getInicio()->getPunteo();
    }

    return tmp;
}

void Nodo_usuario::ingresarPunteo(int x){
    this->puntajes->insertar(x);
}

string Nodo_usuario::imprimir(){
     return "\t| -> [" + this->nickname + "]";
}

string Nodo_usuario::getGraphviz(){
    string temp = "";
    if(this->derecha != NULL){
        temp += "\"" + this->nickname + "\" -> \"" + this->derecha->nickname + "\";\n";
    }

    if(this->izquierda != NULL){
        temp += "\"" + this->nickname + "\" -> \"" + this->izquierda->nickname + "\";\n";
    }
    return temp;
}
