#include "Lista_puntajes.h"

Lista_puntajes::Lista_puntajes()
{
    this->inicio = NULL;
}

Lista_puntajes::~Lista_puntajes()
{
    delete this->inicio;
}

void Lista_puntajes::insertar(int x){
    //Insertar punteo en la lista ordenada
    Nodo_puntajes* nodo = new Nodo_puntajes();
    nodo->setPunteo(x);

    Nodo_puntajes* actual = this->inicio;
    Nodo_puntajes* anterior = NULL;
    bool flag = true;
    if(estaVacio()){
        this->inicio = nodo;
    } else {
        while(actual->getSiguiente() != NULL && flag){
            if(actual->getPunteo() < x){
                flag = false;
            } else {
                anterior = actual;
                actual = actual->getSiguiente();
            }
        }


        if(actual == this->inicio){
            if(actual->getPunteo() < x){
                nodo->setSiguiente(this->inicio);
                this->inicio = nodo;
            } else {
                this->inicio->setSiguiente(nodo);
            }

        } else {
            if(flag){
                actual->setSiguiente(nodo);

            } else {
                nodo->setSiguiente(actual);
                anterior->setSiguiente(nodo);
            }
        }
    }
}

void Lista_puntajes::imprimirLista(){
    //Imprimir Lista
    if(!estaVacio()){
        Nodo_puntajes* tmp = this->inicio;
        while(tmp->getSiguiente() != NULL){
            cout << tmp->imprimir() << "-> ";
            tmp = tmp->getSiguiente();
        }
        cout << tmp->imprimir() << endl;
    } else {
        cout << "\t| ERROR: \n\t - Lista vacia" << endl;
    }
}

string Lista_puntajes::getGraphviz(string nombre){

     //Generar Graphviz
    string graphIn = "digraph G {\n";
    string g_init = "ratio = \"auto\";\nlabel = \"" + nombre + " - score\"; \nrankdir=LR;\n";
    string g_node = "node [fontsize = 12, shape = rect];\n";

    string g_nodes = "";

    if(!estaVacio()){
        Nodo_puntajes* tmp = this->inicio;
        while(tmp->getSiguiente() != NULL){
            g_nodes += tmp->getGraphviz();
            tmp = tmp->getSiguiente();
        }

    } else {
        g_nodes = "vacio";
    }
    return graphIn + g_init + g_node + g_nodes + "}";
}
