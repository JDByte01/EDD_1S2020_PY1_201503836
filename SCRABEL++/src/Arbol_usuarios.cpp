#include "Arbol_usuarios.h"

Arbol_usuarios::Arbol_usuarios()
{
    this->raiz = NULL;
    this->actual = NULL;
}

Arbol_usuarios::~Arbol_usuarios()
{
    delete this->raiz;
    delete this->actual;
}

/**
 * Insertar
 **/

void Arbol_usuarios::insertar(string usuario){
    if(estaVacio()){
        Nodo_usuario* n = new Nodo_usuario();
        n->setNickname(usuario);
        this->raiz = n;
    } else {
        insertar_r(usuario,this->raiz);
    }
}

void Arbol_usuarios::insertar_r(string x, Nodo_usuario* n){
    if(strcmp(x.c_str(), n->getNickname().c_str()) < 0){
        //Izquierda
        if(n->getIzquierda() != NULL){
            insertar_r(x, n->getIzquierda());
        } else {
            Nodo_usuario* temp = new Nodo_usuario();
            temp->setNickname(x);
            n->setIzquierda(temp);
        }
    } else if(strcmp(x.c_str(), n->getNickname().c_str()) > 0){
        //Derecha
        if(n->getDerecha() != NULL){
            insertar_r(x, n->getDerecha());
        } else {
            Nodo_usuario* temp = new Nodo_usuario();
            temp->setNickname(x);
            n->setDerecha(temp);
        }
    } else {
        cout << "\t| **ERROR: Ya existe el Usuario " << x << endl;
    }
}

/**
 * Buscar
 **/

Nodo_usuario* Arbol_usuarios::buscar(string usuario){
    if(estaVacio()){
        return NULL;
    } else {
        return buscar_r(usuario,this->raiz);
    }
}

Nodo_usuario* Arbol_usuarios::buscar_r(string x, Nodo_usuario* n){
    if(strcmp(x.c_str(), n->getNickname().c_str()) < 0){
        //Izquierda
        if(n->getIzquierda() != NULL){
            return buscar_r(x, n->getIzquierda());
        } else {
            return NULL;
        }
    } else if(strcmp(x.c_str(), n->getNickname().c_str()) > 0){
        //Derecha
        if(n->getDerecha() != NULL){
            return buscar_r(x, n->getDerecha());
        } else {
            return NULL;
        }
    } else {
        if(n->getNickname() == x){
            return n;
        } else {
            return NULL;
        }
    }
}

bool Arbol_usuarios::existe(string usuario){
    return buscar(usuario) != NULL;
}

/**
 * Otros
 **/

void Arbol_usuarios::imprimir(){
    if(!estaVacio()){
        imprimir_r(this->raiz);
        cout << " InOrder" << endl;
    } else {
        cout << "\t| ERROR: Arbol vacio para imprimir" << endl;
    }

}

void Arbol_usuarios::imprimir_r(Nodo_usuario* n){
    if(n->getIzquierda() != NULL){
        imprimir_r(n->getIzquierda());
    }

    cout << n->imprimir();

    if(n->getDerecha() != NULL){
        imprimir_r(n->getDerecha());
    }
}

/**
 * Graphviz
 **/
string Arbol_usuarios::getGraphviz(string op){
    //Generar Graphviz
    string graphIn = "digraph G {\n";
    string g_init = "ratio = \"auto\";\nlabel = \"" + op + " - Usuarios\"; \nrankdir=LR;\n";
    string g_node = "node [shape = point]; \"" + op + "\";\nnode [fontsize = 12, shape = rect];\n";

    string g_nodes = "";

    if(op == "Tree"){
        g_init = "ratio = \"auto\";\nlabel = \"" + op + " - Usuarios\";\n";
        g_node = "node [fontsize = 12, shape = oval];\n";

        g_nodes += tree(this->raiz, "");
    } else {
        if(op == "InOrder"){
            g_nodes += inOrder(this->raiz, "") + "\"" + op + "\"";
        } else if(op == "PreOrder"){
            g_nodes += preOrder(this->raiz, "") + "\"" + op + "\"";
        } else if(op == "PosOrder"){
            g_node += posOrder(this->raiz, "") + "\"" + op + "\"";
        } else {
            cout << "\tError: Valor no valido\n\t\tIngresar (Tree/InOrder/PreOrder/PosOrder)" << endl;
        }
    }
    return graphIn + g_init + g_node + g_nodes + "}";
}

string Arbol_usuarios::inOrder(Nodo_usuario* n, string txt){
    if(n->getIzquierda() != NULL){
        txt = inOrder(n->getIzquierda(), txt);
    }

    txt += "\"" + n->getNickname() + "\" -> ";

    if(n->getDerecha() != NULL){
        txt = inOrder(n->getDerecha(), txt);
    }

    return txt;
}

string Arbol_usuarios::preOrder(Nodo_usuario* n, string txt){

    txt += "\"" + n->getNickname() + "\" -> ";

    if(n->getIzquierda() != NULL){
        txt = preOrder(n->getIzquierda(), txt);
    }

    if(n->getDerecha() != NULL){
        txt = preOrder(n->getDerecha(), txt);
    }

    return txt;
}

string Arbol_usuarios::posOrder(Nodo_usuario* n, string txt){
    if(n->getIzquierda() != NULL){
        txt = posOrder(n->getIzquierda(), txt);
    }

    if(n->getDerecha() != NULL){
        txt = posOrder(n->getDerecha(), txt);
    }

    txt += "\"" + n->getNickname() + "\" -> ";

    return txt;
}

string Arbol_usuarios::tree(Nodo_usuario* n, string txt){
    if(n->getIzquierda() != NULL){
        txt = tree(n->getIzquierda(), txt);
    }

    txt += n->getGraphviz();

    if(n->getDerecha() != NULL){
        txt = tree(n->getDerecha(), txt);
    }

    return txt;
}

void Arbol_usuarios::getScoreBoard(){

}
