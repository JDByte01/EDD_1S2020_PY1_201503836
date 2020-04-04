#include "Lista_fichas.h"

Lista_fichas::Lista_fichas()
{
    this->inicio = NULL;
}

Lista_fichas::~Lista_fichas()
{
    delete this->inicio;
    this->inicio = NULL;
}

void Lista_fichas::insertar(Nodo_ficha* n){
    if(estaVacio()){
        this->inicio = n;
    } else {
        Nodo_ficha* temp = this->inicio;
        while(temp->getSiguiente() != NULL){
            temp = temp->getSiguiente();
        }
        temp->setSiguiente(n);
        n->setAnterior(temp);
    }
}

void Lista_fichas::eliminar(Nodo_ficha* n){
    if(!estaVacio()){
        Nodo_ficha* temp = this->inicio;
        bool f = true;
        while(temp->getSiguiente() != NULL && f){
            if(temp->getLetra() == n->getLetra()){
                f = false;
            } else {
                temp = temp->getSiguiente();
            }
        }

        if(temp->getLetra() == n->getLetra()){

            if(temp == inicio){
                this->inicio = temp->getSiguiente();
                this->inicio->setAnterior(NULL);
            } else if(temp->getSiguiente() == NULL){
                temp->getAnterior()->setSiguiente(NULL);
            } else {
                Nodo_ficha* siguiente;
                Nodo_ficha* anterior;
                siguiente = temp->getSiguiente();
                anterior = temp->getAnterior();

                anterior->setSiguiente(siguiente);
                siguiente->setAnterior(anterior);
            }
            delete temp;
        }
        // No elimina nada
    }
}

void Lista_fichas::imprimir(){
    if(!estaVacio()){
        Nodo_ficha* temp = this->inicio;
        cout << "\t| Fichas en el atril: \n\t| ";
        while(temp->getSiguiente() != NULL){
            cout << "[" << temp->getLetra() << "] ";
            temp = temp->getSiguiente();
        }
        cout << "[" << temp->getLetra() << "] " << endl;
    } else {
        cout << "\t| **No hay fichas en el atril" << endl;
    }
}

string Lista_fichas::getGraphviz(string nombre){
    //Generar Graphviz
    string graphIn = "digraph G {\n";
    string g_init = "ratio = \"auto\";\nlabel = \"Fichas - " + nombre + "\"; \nrankdir=TD;\n";
    string g_node = "node [fontsize = 12, shape = rect];\n";

    string g_nodes = "";

    int i = 0;
    if(!estaVacio()){
        Nodo_ficha* tmp = this->inicio;
        while(tmp->getSiguiente() != NULL){
            g_nodes += tmp->getGraphviz(i);
            tmp = tmp->getSiguiente();
            i++;
        }
        g_nodes += tmp->getGraphviz(i);

    } else {
        g_nodes = "";
    }
    return graphIn + g_init + g_node + g_nodes + "}";
}
