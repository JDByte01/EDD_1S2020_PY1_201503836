#include <iostream>

#include <string.h>
#include <iostream>
#include <stdlib.h>

#include <Lista_diccionario.h>
#include <Nodo_palabra.h>
#include <Archivo.h>

#include <Lista_puntajes.h>
#include <Lista_score.h>

#include <Arbol_usuarios.h>
#include <Nodo_usuario.h>

#include <Nodo_ficha.h>
#include <Cola_fichas.h>
#include <Lista_fichas.h>


using namespace std;

bool flag = true;
bool j_flag = true;
char c;
char j_c;
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

Nodo_usuario* jugador1 = NULL;
int putnos_j1 = 0;
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
void nuevoJugador(){

    llenarCola();
    fichas->imprimir();

    cout << fichas->getGraphviz() << endl;

    system("pause");
}

void escojerJugador(){

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
    diccionario = new Lista_diccionario();
    diccionario->insertar(new Nodo_palabra("Hola"));
    diccionario->insertar(new Nodo_palabra("Mundo"));
    diccionario->insertar(new Nodo_palabra("de"));
    diccionario->insertar(new Nodo_palabra("la"));
    diccionario->insertar(new Nodo_palabra("programacion"));
    diccionario->insertar(new Nodo_palabra("!"));

    cout << "Backward" << endl;
    diccionario->imprimirBackward();
    cout << "Forward" << endl;
    diccionario->imprimirForward();

    //Crear reporte .dot
    f->crearArchivo("ListaDobleCircular", "dot", defaultPath, diccionario->getGraphviz());
    f->crearGrafo("ListaDobleCircular", defaultPath);
    system("pause");
    cout << "Regresando a menu" << endl;
}

void juego(){
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
                nuevoJugador();
                break;
            case '2':
                escojerJugador();
                break;
            case '0':
                j_flag = false;
                break;
            default:
                break;
        }

    } while(j_flag);

    system("pause");
}

void reportes(){
    cout << "\t| Reportes" << endl;

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

    system("pause");
}
//=======================================================
//=======================================================
int main()
{
    fichas = new Cola_fichas();
    do{
        system("cls");
        cin.clear();
        cout << "" << endl;
        cout << "\t|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
        cout << "\t|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
        cout << "\t|%%%%%%%%%%%| SCRABBLE ++ |%%%%%%%%%%%|" << endl;
        cout << "\t|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
        cout << "\t|%%%%%%%%| 1)  Configuracion |%%%%%%%%|" << endl;
        cout << "\t|%%%%%%%%| 2)  Jugar         |%%%%%%%%|" << endl;
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
                juego();
                break;
            case '3':
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

    return 0;
}




