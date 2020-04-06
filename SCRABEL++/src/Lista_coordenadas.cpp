#include "Lista_coordenadas.h"

Lista_coordenadas::Lista_coordenadas()
{
    this->inicio = NULL;
}

Lista_coordenadas::~Lista_coordenadas()
{
    delete this->inicio;
}

void Lista_coordenadas::agregar(int x, int y){
    Nodo_coordenada* nodo = new Nodo_coordenada(x,y);
    if(this->inicio == NULL){
        this->inicio = nodo;
    } else {
        Nodo_coordenada* temp = this->inicio;
        while(temp->getSiguiente() != NULL){
            temp = temp->getSiguiente();
        }
        temp->setSiguiente(nodo);
    }
}

bool Lista_coordenadas::existe(int x, int y){
    if(this->inicio != NULL){
        Nodo_coordenada* temp = this->inicio;
        while(temp->getSiguiente() != NULL){
            if(temp->getX() == x && temp->getY() == y)
                 return true;
            temp = temp->getSiguiente();
        }
        if(temp->getX() == x && temp->getY() == y)
            return true;
    } else {
        return false;
    }
}

void Lista_coordenadas::vaciar(){
    delete this->inicio;
    this->inicio = NULL;
}

void Lista_coordenadas::imprimir(){
    cout << "\t| Lista de Coordenadas" << endl;
    Nodo_coordenada* temp = this->inicio;
    while(temp->getSiguiente() != NULL){
        cout << "\t| - (" << to_string(temp->getX()) << ", " << to_string(temp->getY()) << ")\n";
        temp = temp->getSiguiente();
    }
    cout << "\t| - (" << to_string(temp->getX()) << ", " << to_string(temp->getY()) << ")\n";
}

