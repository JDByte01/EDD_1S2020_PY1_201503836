#include "Lista_diccionario.h"

Lista_diccionario::Lista_diccionario()
{
    this->inicio = NULL;
    this->inicio->setSiguiente(NULL);
    this->inicio->setAnterior(NULL);
}

Lista_diccionario::~Lista_diccionario()
{
    //dtor
}

//==========================================
bool Lista_diccionario::estaVacio(){
    return this->inicio == NULL;
}

void Lista_diccionario::insertar(Nodo_palabra* n){
    if(estaVacio()){
        //No hay nada en inicio
        this->inicio = n;
        this->inicio->setSiguiente(n);
        this->inicio->setAnterior(n);
    } else {
        Nodo_palabra* temp = this->inicio;
        while(temp->getSiguiente() != this->inicio){
            temp = temp->getSiguiente();
        }
        //Insertamos nodo N
        temp->setSiguiente(n);
        n->setAnterior(temp);
        n->setSiguiente(this->inicio);
        this->inicio->setAnterior(n);
    }
}

void Lista_diccionario::eliminar(Nodo_palabra* n){
    if(estaVacio()){
        //No hay datos en la lista
        cout << "| ** Error: \n |  - Lista vacia" << endl;
    } else {
        Nodo_palabra* temp;
        if(this->inicio->getPalabra() == n->getPalabra()){
            //El dato a eliminar es el inicio de la lista
            temp = this->inicio;
            this->inicio = this->inicio->getSiguiente();

            this->inicio->setAnterior(temp->getAnterior());
            temp->getAnterior()->setSiguiente(this->inicio);

        } else {
            //Eliminar en cualquier parte

        }
    }
}

