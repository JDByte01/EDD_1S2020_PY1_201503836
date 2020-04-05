#include "Matriz_tablero.h"

Matriz_tablero::Matriz_tablero()
{
    this->headers = new Nodo_matriz("MT",0,0,' ');
}

Matriz_tablero::~Matriz_tablero()
{
    //dtor
    delete this->headers;
}

bool Matriz_tablero::agregar(int x, int y, char l){
    agregaEjeX(x);
    agregarEjeY(y);

    return insertarNodo(x,y,l);
}

void Matriz_tablero::agregaEjeX(int x){
    string id = "x"+to_string(x);
    Nodo_matriz* temp = this->headers;

    if(temp->getDerecha() == NULL){
        Nodo_matriz* nodo = new Nodo_matriz(id,x,0,' ');
        temp->setDerecha(nodo);
        nodo->setIzquierda(temp);
    } else {
        while(temp->getDerecha() != NULL && temp->getDerecha()->getX() < x){
            temp = temp->getDerecha();
        }

        if(temp->getDerecha() == NULL && temp->getX() != x){
            Nodo_matriz* nodo = new Nodo_matriz(id,x,0,' ');
            temp->setDerecha(nodo);
            nodo->setIzquierda(temp);
        } else if(temp->getDerecha() != NULL && temp->getDerecha()->getX() != x){
            Nodo_matriz* aux = temp->getDerecha();
            Nodo_matriz* nodo = new Nodo_matriz(id,x,0,' ');
            temp->setDerecha(nodo);
            nodo->setIzquierda(temp);
            nodo->setDerecha(aux);
            aux->setIzquierda(nodo);
        } else {
            /**Ya existe - no se hace nada**/
        }
    }
}

void Matriz_tablero::agregarEjeY(int y){
    string id = "y"+to_string(y);
    Nodo_matriz* temp = this->headers;

    if(temp->getAbajo() == NULL){
        Nodo_matriz* nodo = new Nodo_matriz(id,0,y,' ');
        temp->setAbajo(nodo);
        nodo->setArriba(temp);
    } else {
        while(temp->getAbajo() != NULL && temp->getAbajo()->getY() < y){
            temp = temp->getAbajo();
        }

        if(temp->getAbajo() == NULL && temp->getY() != y){
            Nodo_matriz* nodo = new Nodo_matriz(id,0,y,' ');
            temp->setAbajo(nodo);
            nodo->setArriba(temp);
        } else if(temp->getAbajo() != NULL && temp->getAbajo()->getY() != y){
            Nodo_matriz* aux = temp->getAbajo();
            Nodo_matriz* nodo = new Nodo_matriz(id,0,y,' ');
            temp->setAbajo(nodo);
            nodo->setArriba(temp);
            nodo->setAbajo(aux);
            aux->setArriba(nodo);
        }
    }
}

bool Matriz_tablero::insertarNodo(int x, int y, char l){
    bool flag = false;
    Nodo_matriz* temp;
    string id = "n"+to_string(x)+to_string(y);
    Nodo_matriz* casilla = new Nodo_matriz(id,x,y,l);

    /**Insertar x**/
    temp = this->headers;

    while(temp->getDerecha() != NULL && temp->getDerecha()->getX() <= x){
        temp = temp->getDerecha();
    }

    if(temp->getX() == x){
        if(temp->getAbajo() == NULL){
            temp->setAbajo(casilla);
            casilla->setArriba(temp);
            flag = true;
        } else {
            while(temp->getAbajo() != NULL && temp->getAbajo()->getY() < y){
                temp = temp->getAbajo();
            }

            if(temp->getAbajo() == NULL && temp->getY() != y){
                temp->setAbajo(casilla);
                casilla->setArriba(temp);
                flag = true;
            } else if(temp->getAbajo() != NULL && temp->getAbajo()->getY() != y){
                Nodo_matriz* aux = temp->getAbajo();
                temp->setAbajo(casilla);
                casilla->setArriba(temp);
                casilla->setAbajo(aux);
                aux->setArriba(casilla);
                flag = true;
            } else {
                if(temp->getAbajo()->getLetra() == l){
                    flag = true;
                    cout << "\t| > Letra igual en la ubicacion X" << to_string(x) << endl;
                } else {
                    flag = false;
                    cout << "\t| > ERROR: Letra no igual en la ubicacion X" << to_string(x) << endl;
                }
            }
        }
    } else {
        flag = false;
    }

    ///***********************************************************************
    /**Insertar Y**/
    temp = this->headers;

    while(temp->getAbajo() != NULL && temp->getAbajo()->getY() <= y){
        temp = temp->getAbajo();
    }

    if(temp->getY() == y){
        if(temp->getDerecha() == NULL){
            temp->setDerecha(casilla);
            casilla->setIzquierda(temp);
            flag = true;
        } else {
            while(temp->getDerecha() != NULL && temp->getDerecha()->getX() < x){
                temp = temp->getDerecha();
            }

            if(temp->getDerecha() == NULL && temp->getX() != x){
                temp->setDerecha(casilla);
                casilla->setIzquierda(temp);
                flag = true;
            } else if(temp->getDerecha() != NULL && temp->getDerecha()->getX() != x){
                Nodo_matriz* aux = temp->getDerecha();
                temp->setDerecha(casilla);
                casilla->setIzquierda(temp);
                casilla->setDerecha(aux);
                aux->setIzquierda(casilla);
                flag = true;
            } else {
                if(temp->getDerecha()->getLetra() == l){
                    flag = true;
                    cout << "\t| > Letra igual en la ubicacion Y" << to_string(x) << endl;
                } else {
                    flag = false;
                    cout << "\t| > ERROR: Letra no igual en la ubicacion Y" << to_string(y) << endl;
                }
            }
        }
    } else {
        flag = false;
    }

    return flag;
}

string Matriz_tablero::getGraphviz(){
    string g1 = "digraph Sparce_Matrix {\nnode [shape=box]\nMT[ label = \"SCRABBLE++\", width = 1.5, style = filled, group = 0 ];\n";
    string tempN = "";
    string tempR = "";
    string tempI = "";

    Nodo_matriz* temp;
    Nodo_matriz* aux;

    temp = this->headers;
    /**Obtener Nodos**/
    while(temp->getDerecha() != NULL){
        aux = temp;
        while(aux->getAbajo() != NULL){
            if(aux != this->headers)
                tempN += aux->getGraphvizNodo();
            aux = aux->getAbajo();
        }
        tempN += aux->getGraphvizNodo();

        temp = temp->getDerecha();
    }

    while(temp->getAbajo() != NULL){
        if(temp != this->headers)
            tempN += temp->getGraphvizNodo();
        temp = temp->getAbajo();
    }
    tempN += temp->getGraphvizNodo();


    /**Obtener Rutas**/
    temp = this->headers;
    while(temp->getAbajo() != NULL){
        aux = temp;
        tempI += "{ rank = same; ";
        while(aux->getDerecha() != NULL){
            tempI += aux->getId()+";";
            tempR += aux->getGraphvizRuta();

            aux = aux->getDerecha();
        }
        tempI += aux->getId()+";}\n";
        tempR += aux->getGraphvizRuta();

        temp = temp->getAbajo();
    }


    tempI += "{ rank = same; ";
    while(temp->getDerecha() != NULL){
        tempI += temp->getId()+";";
        tempR += temp->getGraphvizRuta();

        temp = temp->getDerecha();
    }
    tempI += temp->getId()+";}\n";
    tempR += temp->getGraphvizRuta();

    return g1 + tempN + tempI + tempR + "\n}";
}
