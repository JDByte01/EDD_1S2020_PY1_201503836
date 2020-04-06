#include "Cola_fichas.h"

Cola_fichas::Cola_fichas()
{
    this->inicio = NULL;
    this->size = 0;
}

Cola_fichas::~Cola_fichas()
{
    this->inicio = NULL;
    this->size = 0;
}

void Cola_fichas::encolar(Nodo_ficha* n){
    if(!estaVacio()){
        Nodo_ficha* temp = this->inicio;
        while(temp->getSiguiente() != NULL){
            temp = temp->getSiguiente();
        }
        temp->setSiguiente(n);
        n->setAnterior(temp);

        //this->inicio = n;
        //n->setSiguiente(temp);
    } else {
        this->inicio = n;
    }

    this->size += 1;
}

Nodo_ficha* Cola_fichas::desencolar(){
    if(!estaVacio()){
        Nodo_ficha* temp = this->inicio;
        this->inicio = temp->getSiguiente();
        temp->setSiguiente(NULL);
        this->size -= 1;
        return temp;
    } else {
        return NULL;
    }
}

void Cola_fichas::vaciar(){
    this->inicio = NULL;
    this->size = 0;
}

void Cola_fichas::imprimir(){
    if(!estaVacio()){
        Nodo_ficha* temp = this->inicio;
        cout << "\t| Cola de fichas:" << endl;
        while(temp->getSiguiente() != NULL){
            cout << "[" <<temp->getLetra() << "] -> ";
            temp = temp->getSiguiente();
        }
        cout << "[" <<temp->getLetra() << "]" << endl;
    } else {
        cout << "\t| Lista vacia..." << endl;
    }
}

string Cola_fichas::getGraphviz(){
      //Generar Graphviz
    string graphIn = "digraph G {\n";
    string g_init = "ratio = \"auto\";\nlabel = \"Fichas\"; \nrankdir=TD;\n";
    string g_node = "node [fontsize = 12, shape = rect];\n";

    string g_nodes = "";

    int i = 0;
    if(!estaVacio()){
        Nodo_ficha* tmp = this->inicio;
        while(tmp->getSiguiente() != NULL){
            g_nodes += "n"+ to_string(i) + "[label = \""+ tmp->getLetra()+"\" width = 1];\n";
            tmp = tmp->getSiguiente();
            i++;
        }
        g_nodes += "n"+ to_string(i) + "[label = \""+ tmp->getLetra()+"\" width = 1];\n";

        i = 0;

        tmp = this->inicio;
        while(tmp->getSiguiente() != NULL){
            g_node += "n"+ to_string(i) + " -> ";
            tmp = tmp->getSiguiente();
            i++;
        }
        g_node += "n" + to_string(i) + ";\n";
    } else {
        g_nodes = "";
    }
    return graphIn + g_init + g_node + g_nodes + "}";
}
