#ifndef ARBOL_USUARIOS_H
#define ARBOL_USUARIOS_H

#include <Nodo_usuario.h>
#include <Lista_score.h>
#include <string.h>
#include <iostream>
#include <cstring>
using namespace std;

class Arbol_usuarios
{
    public:
        Arbol_usuarios();
        virtual ~Arbol_usuarios();

        //Get
        Nodo_usuario* getRaiz(){ return this->raiz; }
        Nodo_usuario* getActual(){ return this->actual; }
        //Set
        void setRaiz(Nodo_usuario* r){ this->raiz = r; }
        void setActual(Nodo_usuario* a){ this->raiz = a; }
        //Otros
        bool estaVacio(){ return this->raiz == NULL; }
        void insertar(string usuario);
        void insertar_r(string x, Nodo_usuario* n);
        Nodo_usuario* buscar(string usuario);
        Nodo_usuario* buscar_r(string x, Nodo_usuario* n);
        bool existe(string usuario);

        void imprimir();
        void imprimir_r(Nodo_usuario* n);
        string getGraphviz(string op); //tree, inorder, preorder, posorder
        string inOrder(Nodo_usuario* n, string txt);
        string preOrder(Nodo_usuario* n, string txt);
        string posOrder(Nodo_usuario* n, string txt);
        string tree(Nodo_usuario* n, string txt);

        void getScoreBoard(Lista_score* l);
        void scoreBoard_r(Nodo_usuario* n, Lista_score* l);
    protected:

    private:
        Nodo_usuario* raiz;
        Nodo_usuario* actual;

        //Lista_score* score;
};

#endif // ARBOL_USUARIOS_H
