#ifndef NODO_USUARIO_H
#define NODO_USUARIO_H

#include <Lista_puntajes.h>
#include <string.h>
#include <iostream>
using namespace std;


class Nodo_usuario
{
    public:
        Nodo_usuario();
        Nodo_usuario(string name, Nodo_usuario* izq, Nodo_usuario* der, Lista_puntajes* lista);
        virtual ~Nodo_usuario();

        //Get
        string getNickname(){ return this->nickname; }
        Nodo_usuario* getIzquierda(){ return this->izquierda; }
        Nodo_usuario* getDerecha(){ return this->derecha; }
        Lista_puntajes* getLista(){ return this->puntajes; }
        //SET
        void setNickname(string n){ this->nickname = n; }
        void setIzquierda(Nodo_usuario* i){ this->izquierda = i; }
        void setDerecha(Nodo_usuario* d){ this->derecha = d; }
        void setLista(Lista_puntajes* l){ this->puntajes = l; }
        //Otos
        int getPunteoMaximo();
        void ingresarPunteo(int x);
        string imprimir();
        string getGraphviz();

    protected:

    private:
        string nickname;
        Nodo_usuario* izquierda;
        Nodo_usuario* derecha;

        Lista_puntajes* puntajes;
};

#endif // NODO_USUARIO_H
