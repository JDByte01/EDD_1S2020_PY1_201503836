#include "Nodo_matriz.h"

Nodo_matriz::Nodo_matriz()
{
    this->id = "";
    this->x = 0;
    this->y = 0;
    //this->puntos = 0;
    //this->multiplicador = 0;
    this->letra = ' ';
    this->arriba = NULL;
    this->abajo = NULL;
    this->derecha = NULL;
    this->izquierda = NULL;
}

Nodo_matriz::~Nodo_matriz()
{
    this->id = "";
    this->x = 0;
    this->y = 0;
    //this->puntos = 0;
    //this->multiplicador = 0;
    this->letra = ' ';
    this->arriba = NULL;
    this->abajo = NULL;
    this->derecha = NULL;
    this->izquierda = NULL;
}

Nodo_matriz::Nodo_matriz(string i, int x, int y, char l){
    this->id = i;
    this->x = x;
    this->y = y;
    //this->puntos = p;
    //this->multiplicador = m;
    this->letra = l;
    this->arriba = NULL;
    this->abajo = NULL;
    this->derecha = NULL;
    this->izquierda = NULL;
}

/////////

string Nodo_matriz::getGraphvizNodo(){
    ///N95 [label = "S" width = 1, group = 9 ];
    string txt = "";
    if(x > 0 && y > 0)
        txt = this->id + " [label = \""+ this->letra +"\", width = 1, group = "+ to_string(this->x) +" ]\n";

    /// Y5  [label = "5"   width = 1.5 style = filled, group = 0 ];
    if(x == 0)
        txt = this->id + " [label = \""+ to_string(this->y) +"\", width = 1.5, style = filled, group = 0 ]\n";

    ///X9 [label = "9"  width = 1 style = filled, group = 9 ];
    if(y == 0)
        txt = this->id + " [label = \""+ to_string(this->x) +"\", width = 1, style = filled, group = "+ to_string(this->x) +" ]\n";

    return txt;
}

string Nodo_matriz::getGraphvizRuta(){
    string temp = "";
    //X8 -> N85;
    if(this->arriba != NULL)
        temp += this->id + " -> " + this->arriba->id + ";\n";

    if(this->abajo != NULL)
        temp += this->id + " -> " + this->abajo->id + ";\n";

    if(this->derecha != NULL)
        temp += this->id + " -> " + this->derecha->id + ";\n";

    if(this->izquierda != NULL)
        temp += this->id + " -> " + this->izquierda->id + ";\n";

    return temp;
}
