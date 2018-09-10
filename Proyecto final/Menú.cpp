#include <iostream>

using namespace std;

int volver = 0;
int opcion = 0;
void manual();
void menu();
void registro();
void calificaciones();

void main() {
    locale::global(locale("spanish"));

    cout << "Bienvenido al menú principal" << endl;

    system("Pause");

    menu();

}

void menu() {
    system("cls");

    cout << "Ingrese la opcion que usted quiera" << endl;
    cout << "0. Manual de usuario" << endl;
    cout << "1. Datos el alumno" << endl;
    cout << "2. Calificaciones del alumno" << endl;
    cout << "3. Salir del programa" << endl;



    cin >> opcion;


    if (opcion == 0) {
        manual();
    }
    else if (opcion == 1) {

        registro();
    }
    else if (opcion == 2) {
        calificaciones();
    }
}

void manual() {
    system("cls");

    cout << "Bienvenido al manual de usuario, aqui te ayudaremos a identificar las opciones de la agenda escolar" << endl;

    cout << "¿Quieres regresar al menu?" << endl;
    cout << "1. Sí \n2. No" << endl;
    cin >> volver;

    if (volver == 1) {
        menu();
    }
    else {
        manual();
    }
}
void registro() {
    system("cls");

    cout << "Ingrese los datos del alumno" << endl;

    cout << "¿Quieres regresar al menu?" << endl;
    cout << "1. Sí \n2. No" << endl;
    cin >> volver;

    if (volver == 1) {
        menu();
    }
    else {
        registro();
    }


}
void calificaciones() {
    system("cls");

    cout << "Ingrese o edite la califiacion de un alumno" << endl;

    cout << "¿Quieres regresar al menu?" << endl;
    cout << "1. Sí \n2. No" << endl;
    cin >> volver;

    if (volver == 1) {
        menu();
    }
    else {
        calificaciones();
    }

    system("pause");
}