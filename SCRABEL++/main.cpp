#include <iostream>

#include <string.h>
#include <iostream>

#include <Lista_diccionario.h>
#include <Nodo_palabra.h>
#include <Archivo.h>

#include <Lista_puntajes.h>

using namespace std;

bool flag = true;
char c;
string ruta = "";
string defaultPath = "C:\\KByteGt\\usac-ecys";

int dimension_tablero = 0;
Lista_diccionario* diccionario;

Archivo* f = new Archivo();



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
    cout << "\t| Jugar" << endl;

    Lista_puntajes* tmp = new Lista_puntajes();
    tmp->insertar(10);
    tmp->insertar(8);
    tmp->insertar(12);
    tmp->insertar(5);
    tmp->insertar(20);

    tmp->imprimirLista();
    cout << tmp->getGraphviz("daniel") << endl;
    system("pause");
}

void reportes(){
    cout << "\t| Reportes" << endl;

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




