#include <iostream>

#include <string.h>
#include <iostream>
#include <stdlib.h>

#include <Lista_diccionario.h>
#include <Nodo_palabra.h>
#include <Archivo.h>
#include <Matriz_tablero.h>

#include <Lista_puntajes.h>
#include <Lista_score.h>

#include <Arbol_usuarios.h>
#include <Nodo_usuario.h>

#include <Nodo_ficha.h>
#include <Cola_fichas.h>
#include <Lista_fichas.h>

#include "rapidjson/document.h"

using namespace rapidjson;

using namespace std;

bool flag = true;
bool j_flag = true;
bool r_flag = true;
bool nj_flag = true;
bool ej_flag = true;
bool f_jugador1 = false;
bool f_jugador2 = false;
bool f_play = false;
bool f_turno = false;
bool f_pass1 = false;
bool f_pass2 = false;
char c;
char j_c;
char op_c;
string ruta = "";
string defaultPath = "C:\\KByteGt\\usac-ecys";

//Configuración
char letrasAZ[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','Ñ','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
int puntosAZ[] = {1,3,3,2,1,4,2,4,1,8,0,1,3,1,8,1,3,5,1,1,1,1,4,0,8,4,10};
int cantidadAZ[] = {12,2,4,5,12,1,2,2,6,1,0,4,2,5,1,9,2,1,5,6,4,5,1,0,1,1,1};
int a_cantidad[27];

int dimension_tablero = 0;
Lista_diccionario* diccionario;
Arbol_usuarios* usuarios;
Lista_score* scoreboard;
Cola_fichas* fichas;
Matriz_tablero* tablero;

Nodo_usuario* jugador1 = new Nodo_usuario();
int puntos_j1 = 0;
Lista_fichas* atril1 = NULL;
Nodo_usuario* jugador2 = NULL;
int puntos_j2 = 0;
Lista_fichas* atril2 = NULL;

Archivo* f = new Archivo();

//============================================
int getRandom(){
    int r = 0;
    int a = rand() % 10 + 1;
    int b = rand() % 10 + 1;
    int c = rand() % 10;

    r = a + b + c;
    if (r > 26){
        r = a + b;
    }

    return r;
}

void llenarCola(){
    for(int ii = 0; ii < 26; ii++){
        a_cantidad[ii] = cantidadAZ[ii];
    }

    fichas->vaciar();

    int x = 0;
    for(int i = 0; i < 222; i++){
        x = getRandom();
        if(a_cantidad[x] > 0){
            fichas->encolar(new Nodo_ficha(puntosAZ[x], letrasAZ[x]));
            a_cantidad[x]--;
        } else {
            x = getRandom();
            if(a_cantidad[x] > 0){
                fichas->encolar(new Nodo_ficha(puntosAZ[x], letrasAZ[x]));
                a_cantidad[x]--;
            }
        }
    }
    cout << "\t| Cola de fichas llena." << endl;
}
//============================================
void scrabble() {
    string palabra = "";
    Nodo_ficha* temp;
    llenarCola();
    f_pass1 = false;
    f_pass2 = false;
    /**Determinar jugador que empieza**/
    temp = fichas->desencolar();
    puntos_j1 = temp->getPuntos();
    fichas->encolar(temp);

    temp = fichas->desencolar();
    puntos_j2 = temp->getPuntos();
    fichas->encolar(temp);

    temp = NULL;

    if(puntos_j1 > puntos_j2){
        f_turno = true;
    }
    puntos_j1 = 0;
    puntos_j2 = 0;

    /** Llenar atriles primeras 7 letras**/
    atril1->insertar(fichas->desencolar());
    atril1->insertar(fichas->desencolar());
    atril1->insertar(fichas->desencolar());
    atril1->insertar(fichas->desencolar());
    atril1->insertar(fichas->desencolar());
    atril1->insertar(fichas->desencolar());
    atril1->insertar(fichas->desencolar());

    atril2->insertar(fichas->desencolar());
    atril2->insertar(fichas->desencolar());
    atril2->insertar(fichas->desencolar());
    atril2->insertar(fichas->desencolar());
    atril2->insertar(fichas->desencolar());
    atril2->insertar(fichas->desencolar());
    atril2->insertar(fichas->desencolar());

    do{
        system("cls");
        cout << "\t_______________________________________________________________" << endl;
        cout << "\t|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
        cout << "\t|%%%%%%%%%%%%|  |%%|    S C R A B B L E    |%%|  |%%%%%%%%%%%%|" << endl;
        cout << "\t|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
        cout << "\t|%%| |%%%%| |%%%| |%%%| |%%%| |%%| |%%%| |%%%| |%%%| |%%%| |%%|" << endl;
        cout << "\t|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
        cout << "\t|%%| ----------------------------------------------------- |%%|" << endl;
        cout << "\t|%%| 0) Terminar juego  |1) Pasar turno |2) Cambiar fichas |%%|" << endl;
        cout << "\t|%%| ----------------------------------------------------- |%%|" << endl;
        cout << "\t|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|\n" << endl;


        if(f_turno){
            cout << "\t|%%| > Turno de Jugador 1 - [" << jugador1->getNickname() << "] [" << to_string(puntos_j1) << "]" << endl;
            atril1->imprimir();
        } else {
            cout << "\t|%%| > Turno de Jugador 2 - [" << jugador2->getNickname() << "] [" << to_string(puntos_j2) << "]" << endl;
            atril2->imprimir();
        }


        cout << "\t|%%| > Palabra a formar:\n\t    ** La palabra tiene que formarse por las letras del atril **" << endl;
        cout << "\t| > ";
        cin >> palabra;

        switch(palabra.size()){
            case 1:
                /**Validar comando**/
                if(palabra == "0"){
                    /**Terminar Juego**/
                    f_play = false;
                } else if(palabra == "1"){
                    /**Pasar turno**/
                    if(!f_turno){
                        /**Jugador 1**/
                        f_pass1 = !f_pass1;

                    } else {
                        /**Jugador 2**/
                        f_pass2 = !f_pass2;
                    }

                } else if(palabra == "2"){
                    /**Cambiar atril**/
                    if(!f_turno){
                        /**Jugador 1**/
                    } else {
                        /**Jugador 2**/
                    }
                }else {
                    /**Comando no valido**/
                }
                break;
            default:
                /**Validar palabra**/
                if(!f_turno){
                    /**Jugador 1**/
                } else {
                    /**Jugador 2**/
                }
                break;
        }
        /**Validar doble Pass**/
        if(f_pass1 && f_pass2){
            f_play = false;
        }
        /**Cambiar de turno**/
        f_turno = !f_turno;
    } while(f_play);

    cout << "\t|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
    cout << "\t|%%%%%%%%%%%%|  |%%|    Juego Terminado    |%%|  |%%%%%%%%%%%%|" << endl;
    cout << "\t|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;

    if(puntos_j1 > puntos_j2){
        cout << "\t|%%%%%%%%%%%%|--|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|--|%%%%%%%%%%%%|" << endl;
        cout << "\t|%%%%%%%%%%%%|--|%%|   Ganador Jugador 1   |%%|--|%%%%%%%%%%%%|" << endl;
        cout << "\t|%%%%%%%%%%%%|--|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|--|%%%%%%%%%%%%|" << endl;
    } else {
        cout << "\t|%%%%%%%%%%%%|--|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|--|%%%%%%%%%%%%|" << endl;
        cout << "\t|%%%%%%%%%%%%|--|%%|   Ganador Jugador 2   |%%|--|%%%%%%%%%%%%|" << endl;
        cout << "\t|%%%%%%%%%%%%|--|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|--|%%%%%%%%%%%%|" << endl;
    }

    cout << "\n\t|%%|--|%%|> RESULTADOS:" << endl;
    cout << "\t|%%|--|%%|> " << jugador1->getNickname() << " - " << to_string(puntos_j1) << " pts" << endl;
    cout << "\t|%%|--|%%|> " << jugador2->getNickname() << " - " << to_string(puntos_j2) << " pts" << endl;

    /**Termina Juego**/
    f_jugador1 = false;
    f_jugador2 = false;
    ej_flag = false;
    j_flag = false;

    system("pause");

}
void nuevoJugador(){
    string temporal = "";
    do{
        system("cls");
        cout << "\t|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
        cout << "\t|%%%%%%%%%%| Nuevo usuario |%%%%%%%%%%|" << endl;
        cout << "\t|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
        cout << "\t|%%| 0 - Regresar a menu juego     |%%|" << endl;
        cout << "\t|%%| ----------------------------- |%%|" << endl;
        cout << "\t|%%| Nickname mayor a 3 caracteres |%%|" << endl;
        cout << "\t|%%| * - Ingresar el Nickname      |%%|" << endl;
        cout << "\t|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
        cout << "\t| > ";
        cin >> temporal;

        switch(temporal.size()){
            case 1:
                if(temporal == "0")
                    nj_flag = false;

                break;
            default:
                /**Validar nickname**/
                if(temporal.size() >= 3){
                     if(!usuarios->existe(temporal)){
                        ///Insertar nickname
                        usuarios->insertar(temporal);
                    } else {
                        cout << "\t| ERROR:\n\tYa existe el Nickname" << endl;
                    }
                } else {
                    cout << "\t| ERROR:\n\tNickname invalido" << endl;
                }
                break;
        }

    } while(nj_flag);
}

void escojerJugador(){
    string temporal = "";
    do{
        if(f_jugador1 && f_jugador2){
            /**Empezar a jugar**/
            f_play = true;
            scrabble();
        } else {
            /**Solicitar usuarios para jugar**/
            system("cls");
            cout << "\t|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
            cout << "\t|%%%%%%%%%| Escoger usuario |%%%%%%%%%|" << endl;
            cout << "\t|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
            if(!f_jugador1){
                cout << "\t|%%| 1 - Jugador 1 **              |%%|" << endl;
            } else {
                cout << "\t|%%| 1 - Jugador 1                 |%%|" << endl;
            }

            if(!f_jugador2){
                cout << "\t|%%| 2 - Jugador 2 **              |%%|" << endl;
            } else {
                cout << "\t|%%| 2 - Jugador 2                 |%%|" << endl;
            }

            cout << "\t|%%| ----------------------------- |%%|" << endl;
            cout << "\t|%%| 0 - Regresar a menu juego     |%%|" << endl;
            cout << "\t|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
            if(jugador1 != NULL && f_jugador1){
                 cout << "\t| > J1 - " << jugador1->getNickname() << endl;
            }
            if(jugador2 != NULL && f_jugador2){
                 cout << "\t| > J2 - " << jugador2->getNickname() << endl;
            }

            cout << "\t| > ";
            cin.get(op_c);

            switch(op_c){
                case '0':
                    ej_flag = false;
                    break;
                case '1':
                    /**Escoger nickname para jugador 1**/

                    if(!usuarios->estaVacio()){
                        usuarios->imprimir();
                        cout << "\t|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
                        cout << "\t|%%|  Escribir Nickname a escoger  |%%|" << endl;
                        cout << "\t|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
                        cout << "\t| > ";
                        cin >> temporal;
                        if(jugador2->getNickname() == temporal){
                            cout << "\t| - Nickname no disponible" << endl;
                            system("pause");
                        } else {
                            jugador1 = usuarios->buscar(temporal);
                            f_jugador1 = true;
                        }
                    } else {
                        cout << "\n\t|%%| *No hay usuarios disponibles* |%%|" << endl;
                        cout << "\n\t";
                        system("pause");
                    }
                    break;
                case '2':
                    /**Escoger nickname para jugador 2**/
                    if(!usuarios->estaVacio()){
                        usuarios->imprimir();
                        cout << "\t|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
                        cout << "\t|%%|  Escribir Nickname a escoger  |%%|" << endl;
                        cout << "\t|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
                        cout << "\t| > ";
                        cin >> temporal;
                        if(jugador1->getNickname() == temporal){
                            cout << "\t| - Nick name no disponible" << endl;
                            system("pause");
                        } else {
                            jugador2 = usuarios->buscar(temporal);
                            f_jugador2 = true;
                        }
                    } else {
                        cout << "\n\t|%%| *No hay usuarios disponibles* |%%|" << endl;
                        cout << "\n\t";
                        system("pause");
                    }
                    break;
                default:

                    break;
            }
        }
    } while(ej_flag);
}

//============================================
void configuracion(){
    cout << "\t|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
    cout << "\t|%%%%%%%%%%| Configuracion |%%%%%%%%%%|" << endl;
    cout << "\t|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
    cout << "\t|%%| Ingresar ruta de archivo JSON |%%|" << endl;
    cout << "\t|-------------------------------------|" << endl;
    cout << "\t| > ";
    cin >> ruta;

    cout << "\t| Ruta ingresada: " << ruta << endl;
    //Leer archivo JSON
    //Insertar datos en lista doble diccionario
    diccionario->vaciarLista();
    dimension_tablero = 20;

    diccionario->insertar(new Nodo_palabra("Hola"));
    diccionario->insertar(new Nodo_palabra("Mundo"));
    diccionario->insertar(new Nodo_palabra("de"));
    diccionario->insertar(new Nodo_palabra("la"));
    diccionario->insertar(new Nodo_palabra("programacion"));
    diccionario->insertar(new Nodo_palabra("estructuras"));
    diccionario->insertar(new Nodo_palabra("cola"));
    diccionario->insertar(new Nodo_palabra("pila"));
    diccionario->insertar(new Nodo_palabra("enero"));
    diccionario->insertar(new Nodo_palabra("febrero"));
    diccionario->insertar(new Nodo_palabra("marzo"));
    diccionario->insertar(new Nodo_palabra("abril"));
    diccionario->insertar(new Nodo_palabra("mayo"));
    diccionario->insertar(new Nodo_palabra("junio"));
    diccionario->insertar(new Nodo_palabra("julio"));
    diccionario->insertar(new Nodo_palabra("agosto"));
    diccionario->insertar(new Nodo_palabra("septiembre"));
    diccionario->insertar(new Nodo_palabra("octubre"));
    diccionario->insertar(new Nodo_palabra("noviembre"));
    diccionario->insertar(new Nodo_palabra("diciembre"));
    diccionario->insertar(new Nodo_palabra("zanahoria"));
    diccionario->insertar(new Nodo_palabra("zapato"));
    diccionario->insertar(new Nodo_palabra("caña"));

    cout << "\t| Datos ingresados correctamente" << endl;
    system("pause");
}

void juego(){
    /**
     ** Nuevo juego
     ** Se reinician variables
     **/
    fichas->vaciar();
    jugador1 = new Nodo_usuario();
    jugador2 = new Nodo_usuario();
    f_jugador1 = false;
    f_jugador2 = false;
    puntos_j1 = 0;
    puntos_j2 = 0;
    atril1->vaciar();
    atril2->vaciar();

    do{
        system("cls");
        cout << "\t|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
        cout << "\t|%%%%%%%%%%|     Juego     |%%%%%%%%%%|" << endl;
        cout << "\t|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
        cout << "\t|%%| 1 - Nuevo usuario             |%%|" << endl;
        cout << "\t|%%| 2 - Escojer usuario           |%%|" << endl;
        cout << "\t|%%| ----------------------------- |%%|" << endl;
        cout << "\t|%%| 0 - Regresar a menu           |%%|" << endl;
        cout << "\t|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
        cout << "\t| > ";
        cin.get(j_c);

        switch(j_c){
            case '1':
                nj_flag = true;
                nuevoJugador();
                break;
            case '2':
                ej_flag = true;
                escojerJugador();
                break;
            case '0':
                j_flag = false;
                break;
            default:
                break;
        }

    } while(j_flag);
}

void reportes(){
    do{
        system("cls");
        cout << "\t|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
        cout << "\t|%%%%%%%%|      Reportes     |%%%%%%%%|" << endl;
        cout << "\t|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
        cout << "\t|%%| 01 - Diccionario              |%%|" << endl;
        cout << "\t|%%| 02 - Fichas disponible        |%%|" << endl;
        cout << "\t|%%| 03 - Arbol binario (ABB)      |%%|" << endl;
        cout << "\t|%%| 04 - ABB - recorrido preorden |%%|" << endl;
        cout << "\t|%%| 05 - ABB - recorrido inorden  |%%|" << endl;
        cout << "\t|%%| 06 - ABB - recorrido postorden|%%|" << endl;
        cout << "\t|%%| 07 - Historial de puntos (J)  |%%|" << endl;
        cout << "\t|%%| 08 - Scoreboard               |%%|" << endl;
        cout << "\t|%%| 09 - Fichas disponible (J1)   |%%|" << endl;
        cout << "\t|%%| 10 - Fichas disponible (J2)   |%%|" << endl;
        cout << "\t|%%| ----------------------------- |%%|" << endl;
        cout << "\t|%%| 0 - Regresar a menu           |%%|" << endl;
        cout << "\t|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
        cout << "\t| > ";
        cin.get(j_c);

        switch(j_c){
            case '1':
                /**DICCIONARIO**/
                f->crearArchivo("ListaDobleCircular", "dot", defaultPath, diccionario->getGraphviz());
                f->crearGrafo("ListaDobleCircular", defaultPath);
                f->abrirArchivo("ListaDobleCircular.png", defaultPath);

                break;
            case '2':
                /**COLA DE FICHAS**/
                f->crearArchivo("ListaDobleCircular", "dot", defaultPath, diccionario->getGraphviz());
                f->crearGrafo("ListaDobleCircular", defaultPath);
                break;
            case '3':
                /**ARBOL BINARIO DE BUSQUEDA**/
                f->crearArchivo("ListaDobleCircular", "dot", defaultPath, diccionario->getGraphviz());
                f->crearGrafo("ListaDobleCircular", defaultPath);
                break;
            case '4':
                /**ABB - PREORDEN**/
                f->crearArchivo("ListaDobleCircular", "dot", defaultPath, diccionario->getGraphviz());
                f->crearGrafo("ListaDobleCircular", defaultPath);
                break;
            case '5':
                /**ABB - INORDEN**/
                f->crearArchivo("ListaDobleCircular", "dot", defaultPath, diccionario->getGraphviz());
                f->crearGrafo("ListaDobleCircular", defaultPath);
                break;
            case '6':
                /**ABB - POSTORDEN**/
                f->crearArchivo("ListaDobleCircular", "dot", defaultPath, diccionario->getGraphviz());
                f->crearGrafo("ListaDobleCircular", defaultPath);
                break;
            case '7':
                /**HISTORIAL DE PUNTOS X JUGADOR**/
                f->crearArchivo("ListaDobleCircular", "dot", defaultPath, diccionario->getGraphviz());
                f->crearGrafo("ListaDobleCircular", defaultPath);
                break;
            case '8':
                /**SCOREBOARD**/
                f->crearArchivo("ListaDobleCircular", "dot", defaultPath, diccionario->getGraphviz());
                f->crearGrafo("ListaDobleCircular", defaultPath);
                break;
            case '9':
                /**FICHAS DISPONIBLE J1**/
                f->crearArchivo("ListaDobleCircular", "dot", defaultPath, diccionario->getGraphviz());
                f->crearGrafo("ListaDobleCircular", defaultPath);
                break;
            case '10':
                /**FICHAS DISPONIBLES J2**/
                f->crearArchivo("ListaDobleCircular", "dot", defaultPath, diccionario->getGraphviz());
                f->crearGrafo("ListaDobleCircular", defaultPath);
                break;
            case '0':
                r_flag = false;
                break;
            default:
                break;
        }

    } while(r_flag);
}
//=======================================================
//=======================================================
int main()
{
    diccionario = new Lista_diccionario();
    usuarios = new Arbol_usuarios();
    fichas = new Cola_fichas();
    atril1 = new Lista_fichas();
    atril2 = new Lista_fichas();

    do{
        system("cls");
        cin.clear();
        cout << "" << endl;
        cout << "\t|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
        cout << "\t|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
        cout << "\t|%%%%%%%%%%%| SCRABBLE ++ |%%%%%%%%%%%|" << endl;
        cout << "\t|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
        cout << "\t|%%%%%%%%| 1)  Configuracion |%%%%%%%%|" << endl;
        cout << "\t|%%%%%%%%| 2)  Nuevo juego   |%%%%%%%%|" << endl;
        cout << "\t|%%%%%%%%| 3)  Reportes      |%%%%%%%%|" << endl;
        cout << "\t|%%%%%%%%| 4)  Salir         |%%%%%%%%|" << endl;
        cout << "\t|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
        cout << "\t|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
        cout << "\t|%%%%%%%|  Escoja una opcion  |%%%%%%%|" << endl;
        cout << "\t|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
        cout << "\t| > ";
        cin.get(c);

        switch(c){
            case '1':
                configuracion();
                break;
            case '2':
                j_flag = true;
                juego();
                break;
            case '3':
                r_flag = true;
                reportes();
                break;
            case '4':
                flag = false;
                cout << "\t|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
                cout << "\t|%%%%%%| **Gracias por jugar** |%%%%%%|" << endl;
                cout << "\t|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
                break;
            default:
               break;
        }
    } while(flag);

    /**Prueba de la matriz**/
    tablero = new Matriz_tablero();
    if(tablero->agregar(8,5,'O'))
        cout << "\t| Agregado..." << endl;
    if(tablero->agregar(9,5,'S'))
        cout << "\t| Agregado..." << endl;
    if(tablero->agregar(10,5,'O'))
        cout << "\t| Agregado..." << endl;

    if(tablero->agregar(10,4,'H'))
        cout << "\t| Agregado..." << endl;
    if(tablero->agregar(10,5,'O'))
        cout << "\t| Agregado..." << endl;
    if(tablero->agregar(10,6,'L'))
        cout << "\t| Agregado..." << endl;
    if(tablero->agregar(10,7,'A'))
        cout << "\t| Agregado..." << endl;

    if(tablero->agregar(10,7,'I'))
        cout << "\t| Agregado..." << endl;

    cout <<"\n" << tablero->getGraphviz() << endl;

    return 0;
}

/**
usuarios = new Arbol_usuarios();
    scoreboard = new Lista_score();
    Nodo_usuario* tmp_u;

    usuarios->insertar("Daniel");
    usuarios->insertar("Joseph");
    usuarios->insertar("Ricardo");
    usuarios->insertar("Marvin");
    usuarios->insertar("Chris");

    //usuarios->insertar("Heidy");
    //usuarios->insertar("Carlos");
    //usuarios->insertar("Rodrigo");
    //usuarios->insertar("Antonio");
    //usuarios->insertar("Eduardo");


    tmp_u = usuarios->buscar("Ricardo");

    if(tmp_u != NULL){
        //tmp_u->setLista(tmp);
        jugador1 = tmp_u;
        jugador1->ingresarPunteo(10);
        jugador1->ingresarPunteo(2);
        jugador1->ingresarPunteo(0);
        jugador1->ingresarPunteo(5);

        tmp_u->getLista()->imprimirLista();

    }

    tmp_u = usuarios->buscar("Joseph");
    if(tmp_u != NULL){
        tmp_u->ingresarPunteo(50);
    }

    tmp_u = usuarios->buscar("Marvin");
    if(tmp_u != NULL){
        tmp_u->ingresarPunteo(24);
    }

    tmp_u = usuarios->buscar("Chris");
    if(tmp_u != NULL){
        tmp_u->ingresarPunteo(12);
    }

    tmp_u = usuarios->buscar("Daniepp");
    if(tmp_u != NULL){
        tmp_u->ingresarPunteo(5);
    }

    jugador1->ingresarPunteo(25);
    jugador1->getLista()->imprimirLista();

    usuarios->getScoreBoard(scoreboard);
    scoreboard->imprimirLista();
    cout << scoreboard->getGraphviz() << endl;

    //scoreboard->insertar("Daniel", 50);
    //scoreboard->insertar("Genesis", 20);
    //scoreboard->insertar("kbyteGt", 70);
    //scoreboard->imprimirLista();
    //cout << scoreboard->getGraphviz() << endl;


    //usuarios->imprimir();

    //cout << usuarios->getGraphviz("Tree") << endl;
    //cout << usuarios->getGraphviz("PreOrder") << endl;
    //cout << usuarios->getGraphviz("InOrder") << endl;
    //cout << usuarios->getGraphviz("PosOrder") << endl;
    //tmp->imprimirLista();
    //cout << tmp->getGraphviz("daniel") << endl;


    fichas->imprimir();
    atril1->imprimir();
    atril2->imprimir();
**/



