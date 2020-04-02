#include "Lista_score.h"

Lista_score::Lista_score()
{
    this->inicio = NULL;
}

Lista_score::~Lista_score()
{
    delete this->inicio;
}

void Lista_score::insertar(string u, int x){
    //Insertar punteo en la lista ordenada
    Nodo_score* nodo = new Nodo_score();
    nodo->setPunteo(x);
    nodo->setJugador(u);

    Nodo_score* actual = this->inicio;
    Nodo_score* anterior = NULL;
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

void Lista_score::imprimirLista(){
    //Imprimir Lista
    if(!estaVacio()){
        Nodo_score* tmp = this->inicio;
        while(tmp->getSiguiente() != NULL){
            cout << tmp->imprimir() << "-> ";
            tmp = tmp->getSiguiente();
        }
        cout << tmp->imprimir() << endl;
    } else {
        cout << "\t| ERROR: \n\t - Lista vacia" << endl;
    }
}

string Lista_score::getGraphviz(){
    //Generar Graphviz
    string graphIn = "digraph G {\n";
    string g_init = "ratio = \"auto\";\nlabel = \"Scoreboard\"; \nrankdir=LR;\n";
    string g_node = "node [shape = point]; \"0\";\nnode [fontsize = 12, shape = record];\n";

    string g_nodes = "";

    if(!estaVacio()){
        Nodo_score* tmp = this->inicio;
        while(tmp->getSiguiente() != NULL){
            g_nodes += tmp->getGraphviz();
            tmp = tmp->getSiguiente();
        }
        g_nodes += tmp->getGraphviz();
    } else {
        g_nodes = "vacio";
    }
    return graphIn + g_init + g_node + g_nodes + "}";
}
