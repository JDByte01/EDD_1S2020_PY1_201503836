#include "Lista_diccionario.h"

Lista_diccionario::Lista_diccionario()
{
    this->inicio = NULL;
}

Lista_diccionario::~Lista_diccionario()
{
    delete this->inicio;
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

            delete temp;

        } else {
            //Eliminar en cualquier parte
            temp = this->inicio;
            while(temp->getSiguiente() != this->inicio && temp->getPalabra() != n->getPalabra()){
                temp = temp->getSiguiente();
            }
            //Evaluar palabra
            if(temp->getPalabra() == n->getPalabra()){
                //Es igual
                temp->getAnterior()->setSiguiente(temp->getSiguiente());
                temp->getSiguiente()->setAnterior(temp->getAnterior());

                delete temp;
            } else {
                //No existe la palabra a eliminar
                cout << " | ** Error: \n |  - No existe el dato a eliminar" << endl;
            }
        }
    }
}

void Lista_diccionario::imprimirForward(){
    if(!estaVacio()){
        Nodo_palabra* tmp = this->inicio;
         cout << "\t| Lista de palabras\n";
        while(tmp->getSiguiente() != this->inicio){
            cout << "\t| - " << tmp->imprimir() << endl;
            tmp = tmp->getSiguiente();
        }
        cout << "\t| - " << tmp->imprimir() << endl;
    }
}

void Lista_diccionario::imprimirBackward(){
    if(!estaVacio()){
        Nodo_palabra* tmp = this->inicio->getAnterior();
        cout << "\t| Lista de palabras\n";
        while(tmp != this->inicio){
            cout << "\t| - " << tmp->imprimir() << endl;
            tmp = tmp->getAnterior();
        }
        cout << "\t| - " << tmp->imprimir() << endl;
    }
}

string Lista_diccionario::getGraphviz(){
    //Generar Graphviz
    string g_nombre = "\"Diccionario de palabras - Lista doble enlazada circular\"";

    string graphIn = "digraph G {\n";
    string g_init = "ratio = \"auto\";\n layout = \"circo\";\nlabel = " + g_nombre + "; \nrankdir=LR;\n";
    string g_node = "node [shape = doublecircle]; \"" + this->inicio->getPalabra() + "\";\nnode [fontsize = 12, shape = rect];\n";

    string g_nodes = "";

    Nodo_palabra* tmp = this->inicio;
    while(tmp->getSiguiente() != this->inicio){
        g_nodes += tmp->getGraphviz();
        tmp = tmp->getSiguiente();
    }
    g_nodes += tmp->getGraphviz();

    return graphIn + g_init + g_node + g_nodes + "}";
}

void Lista_diccionario::vaciarLista(){
    delete this->inicio;
}

