#include "Archivo.h"

Archivo::Archivo()
{
    //ctor
}

Archivo::~Archivo()
{
    //dtor
}

void Archivo::crearArchivo(string nombre, string ext ,string ruta, string txt){
    //Crear archivo
    ofstream fs(ruta + "\\" + nombre + "." + ext);

    fs << txt << endl;
    // Cerrar el fichero,
    fs.close();
}

void Archivo::crearGrafo(string nombre, string ruta){
system(("dot -Tpng " + ruta + "\\" + nombre + ".dot -o " + ruta + "\\" + nombre + ".png").c_str());
}
