// 4043.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
// Permite escribir con acentos;
{
    locale::global(locale("spanish"));

    cout << "Nombre: " << endl;
    char nombre[20];
    cin >> nombre;

    cout << "Apellido: " << endl;
    char apellido[20];
    cin >> apellido;

    cout << "Edad: " << endl;
    int edad;
    cin >> edad;

    cout << "Télefono: " << endl;
    char telefono[12];
    cin >> telefono;

    cout << "Nombre:"[apellido][nombre]"."
        << "---" <<
        << "Edad:" << [edad] << "años."
        "Teléfono" : "+52"[teléfono];

    system("pause");

    return 0;
}