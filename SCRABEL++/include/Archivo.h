#ifndef ARCHIVO_H
#define ARCHIVO_H

#include <iostream>
#include <fstream>
using namespace std;

class Archivo
{
    public:
        Archivo();
        virtual ~Archivo();

        void crearArchivo(string nombre, string ext, string ruta, string txt);
        void crearGrafo(string nombre, string ruta);
        string leerArchivo(string ruta);

    protected:

    private:
};

#endif // ARCHIVO_H
