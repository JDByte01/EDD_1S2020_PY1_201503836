#include <iostream>

#include <string.h>
#include <iostream>

#include <Lista_diccionario.h>
#include <Nodo_palabra.h>
#include <Archivo.h>

#include <Lista_puntajes.h>

#include <Arbol_usuarios.h>
#include <Nodo_usuario.h>


using namespace std;

bool flag = true;
bool j_flag = true;
char c;
char j_c;
string ruta = "";
string defaultPath = "C:\\KByteGt\\usac-ecys";

//Configuración
int dimension_tablero = 0;
Lista_diccionario* diccionario;
Arbol_usuarios* usuarios;

Nodo_usuario* jugador1 = NULL;
Nodo_usuario* jugador2 = NULL;

Archivo* f = new Archivo();

//============================================
void nuevoJugador(){

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

    //usuarios->insertar("Joseph");
    //usuarios->insertar("Ricardo");
    //usuarios->insertar("Marvin");
    //usuarios->insertar("Chris");
    //usuarios->insertar("Daniel");

    Lista_puntajes* tmp = new Lista_puntajes();
    tmp->insertar(10);
    tmp->insertar(2);
    tmp->insertar(0);
    tmp->insertar(5);
    tmp->insertar(25);



    //usuarios->insertar("Daniel");
    //usuarios->insertar("Joseph");
    //usuarios->insertar("Ricardo");
    //usuarios->insertar("Marvin");
    //usuarios->insertar("Chris");

    usuarios->insertar("Heidy");
    usuarios->insertar("Carlos");
    usuarios->insertar("Rodrigo");
    usuarios->insertar("Antonio");
    usuarios->insertar("Eduardo");


    Nodo_usuario* tmp_u = usuarios->buscar("Ricardo");

    if(tmp_u != NULL){
        tmp_u->setLista(tmp);
        tmp_u->getLista()->imprimirLista();
        cout <<" ** Punteo maximo: " << tmp_u->getPunteoMaximo() << endl;
    } else {
        cout << " No se encontro el usuario Ricardo" << endl;
    }


    //usuarios->imprimir();

    //cout << usuarios->getGraphviz("Tree") << endl;
    cout << usuarios->getGraphviz("PreOrder") << endl;
    cout << usuarios->getGraphviz("InOrder") << endl;
    cout << usuarios->getGraphviz("PosOrder") << endl;
    //tmp->imprimirLista();
    //cout << tmp->getGraphviz("daniel") << endl;

    system("pause");
}
//=======================================================
//=======================================================
int main()
{
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




