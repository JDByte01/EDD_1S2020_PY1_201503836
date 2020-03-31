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
    if(estaVacio()){
        this->inicio = nodo;
    } else {
        Nodo_puntajes* tmp = this->inicio;
        Nodo_puntajes* n = NULL;
        bool flag = true;
        while(tmp->getSiguiente() != NULL && flag){
            if(tmp->getPunteo() < x){
                flag = false;
            } else {
                n = tmp;
                tmp = tmp->getSiguiente();
            }
        }
        //Insertar dato
        if( n == NULL){
            nodo->setSiguiente(this->inicio);
            this->inicio = nodo;
        } else {
            nodo->setSiguiente(tmp);
            n->setSiguiente(nodo);
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
