#include <iostream>
#include <string>
#include<stdio.h>
#include <fstream>
using namespace std;

int o;
int c;

struct persona {
    int id;
    string nombre;
    string apellido;
    string correo;
    string matricula;
    char tel[15];
    int cal1;
    int cal2;
    int cal3;
    string calle;
    int numcasa;
    string colonia;

};

persona p[100];

void menu();
void manual();
void registrar();
void mostrarTodos();
void buscar();
void buscarmat();
void modificar();
void eliminar();
void archivito();
void excelo();

void main() {
    locale::global(locale("spanish"));
    c = 0;
    system("color FD");
    ifstream lectura;

    lectura.open("Alumnos.txt", ios::binary);
    if (lectura.is_open()) {

        while (!lectura.eof()) {
            lectura.read((char*)&p, sizeof(persona));
        }
    }
    else {
        cout << "El archivo no existe o hay problemas para abrirlos." << endl;
        system("pause>nul");
    }

    lectura.close();

    for (int i = 1; i < 100; i++)
    {
        if (p[i].cal != -1) {
            id++;
        }
    }
    menu();
}

void menu() {
    system("cls");
    cout << "MEN� PRINCIPAL" << endl << endl;
    cout << "�Qu� quieres hacer?" << endl;
    cout << "1. Manual de usuario \n2. Registrar \n3. Mostrar todos \n4. Buscar nombre \n5. Buscar matricula \n6. Modificar \n7. Eliminar \n8. Salir" << endl;
    cin >> o;

    switch (o)
    {
    case 1:
        manual();
        break;

    case 2:
        registrar();
        break;

    case 3:
        mostrarTodos();
        break;

    case 4:
        buscar();
        break;

    case 5:
        buscarmat();
        break;

    case 6:
        modificar();
        break;
    case 7:
        eliminar();
        break;

    case 8:
        system("cls");
        cout << "Aiooooos";
        system("pause>nul");
    default:
        break;
    }
}

void manual() {
    system("cls");

    cout << "OwO" << endl;


    system("pause");
    system("cls");


    menu();
}

void registrar() {
    system("cls");
    cout << "REGISTRO" << endl << endl;
    p[c].id = c;

    cout << "Apellido: ";
    cin >> p[c].apellido;

    cin.ignore();

    cout << "Nombre: ";
    getline(cin, p[c].nombre);

    cout << "Correo electr�nico: ";
    cin >> p[c].correo;

    cout << "Tel�fono: ";
    cin >> p[c].tel;

    cout << "Matr�cula: ";
    cin >> p[c].matricula;

    cout << "Direcci�n:" << endl << "Calle: ";
    cin >> p[c].calle;
    cout << "N�mero: ";
    cin >> p[c].numcasa;
    cout << "Colonia: ";
    cin >> p[c].colonia;

    cout << "Calificaci�n 1: ";
    cin >> p[c].cal1;
    cout << "Calificaci�n 2: ";
    cin >> p[c].cal2;
    cout << "Calificaci�n 3: ";
    cin >> p[c].cal3;

    c++;
    menu();
}

void mostrarTodos() {
    system("cls");
    cout << "TODOS LOS REGISTROS" << endl;
    for (int i = 0; i < c; i++) {
        cout << endl << endl;
        cout << "Alumno: " << p[i].nombre << " " << p[i].apellido << endl;
        cout << "Correo electr�nico: " << p[i].correo << endl;
        cout << "Tel�fono: " << p[i].tel << endl;
        cout << "Matr�cula: " << p[i].matricula << endl;
        cout << "Direcci�n: " << p[i].calle << " " << p[i].numcasa << " " << p[i].colonia << endl;
        cout << "Calificaciones: " << endl;
        cout << "Parcial 1: " << p[i].cal1 << endl;
        cout << "Parcial 2: " << p[i].cal2 << endl;
        cout << "Parcial 3: " << p[i].cal3 << endl;
    }

    system("pause > nul");
    menu();
}

void buscarmat() {
    system("cls");
    cout << "BUSCADOR" << endl << endl;
    int matricula;
    cout << "�Qu� matr�cula quiere ver? " << endl;
    cin >> matricula;

    bool encontrado = false;
    for (int i = 0; i < c; i++)
    {
        if (p[i].id == matricula) {
            cout << "Lo encontr�:" << endl;
            cout << "Alumno: " << p[i].nombre << " " << p[i].apellido << endl;
            cout << "Correo electr�nico: " << p[i].correo << endl;
            cout << "Tel�fono: " << p[i].tel << endl;
            cout << "Matr�cula: " << p[i].id << endl;
            cout << "Direcci�n: " << p[i].calle << " " << p[i].numcasa << " " << p[i].colonia << endl;
            cout << "Calificaciones: " << endl;
            cout << "Parcial 1: " << p[i].cal1 << endl;
            cout << "Parcial 2: " << p[i].cal2 << endl;
            cout << "Parcial 3: " << p[i].cal3 << endl;
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "No hab�a registros con esa matr�cula." << endl;
    }

    system("pause > nul");

    menu();
}

void buscar() {
    cin.ignore();
    system("cls");
    cout << "BUSCADOR" << endl << endl;
    cout << "�Qu� nombre buscas? " << endl;
    string n;
    getline(cin, n);

    bool encontrado = false;
    int i = 0;
    while (i<c)
    {


        if (strcmp(n.c_str(), p[i].nombre.c_str()) == 0) {
            cout << "Lo encontr�: " << endl;
            cout << "Alumno: " << p[i].nombre << " " << p[i].apellido << endl;
            cout << "Correo electr�nico: " << p[i].correo << endl;
            cout << "Tel�fono: " << p[i].tel << endl;
            cout << "Matr�cula: " << p[i].matricula << endl;
            cout << "Direcci�n: " << p[i].calle << " " << p[i].numcasa << " " << p[i].colonia << endl;
            cout << "Calificaciones: " << endl;
            cout << "Parcial 1: " << p[i].cal1 << endl;
            cout << "Parcial 2: " << p[i].cal2 << endl;
            cout << "Parcial 3: " << p[i].cal3 << endl;
            encontrado = true;
            break;
        }
        i++;
    }

    if (!encontrado) {
        cout << "No hab�a registros con esa matr�cula." << endl;

    }
    i++;
    system("pause > nul");

    menu();
}

void modificar() {
    cout << "MODIFICAR DATOS" << endl;
    cin.ignore();
    cout << "�Inserte una matricula? " << endl;
    cin >> o;

    int i = 0;
    while (i < c) {
        if (p[i].id == o) {
            cout << "Encontr� a: " << endl;
            cout << "Alumno: " << p[i].nombre << " " << p[i].apellido << endl;
            cout << "Correo electr�nico: " << p[i].correo << endl;
            cout << "Tel�fono: " << p[i].tel << endl;
            cout << "Matr�cula: " << p[i].matricula << endl;
            cout << "Direcci�n: " << p[i].calle << " " << p[i].numcasa << " " << p[i].colonia << endl;
            cout << "Calificaciones: " << endl;
            cout << "Parcial 1: " << p[i].cal1 << endl;
            cout << "Parcial 2: " << p[i].cal2 << endl;
            cout << "Parcial 3: " << p[i].cal3 << endl;

            cout << "�Qu� deseas modificar?" << endl;
            cout << "1. Matr�cula \n2. Nombre \n3. Apellido \n4. Correo electr�nico \n5. Tel�fono \n6. Calificaciones \n7.Direcci�n \0. Nada" << endl;
            cin >> o;

            switch (o)
            {
            case 1:
                cout << "Ingresa nueva m�tricula: ";
                cin >> p[i].matricula;
                break;
            case 2:
                cin.ignore();
                cout << "Ingresa nuevo nombre: ";
                getline(cin, p[i].nombre);
                break;
            case 3:
                cout << "Ingresa nuevo apellido: ";
                cin >> p[i].apellido;
                break;
            case 4:
                cout << "Ingresa nuevo correo electr�nico: ";
                cin >> p[i].correo;
                break;
            case 5:
                cout << "Ingresa nuevo tel�fono: ";
                cin >> p[i].tel;
                break;
            case 6:
                cout << "�Qu� calificaci�n quiere cambiar?";
                cout << "1. Parcial 1 \n2. Parcial 2 \n3. Parcial 3" << endl;
                int cambiarcal;
                cin >> cambiarcal;
                cout << "Ingrese nueva calificaci�n" << endl;
                if (cambiarcal == 1) {
                    cin >> p[i].cal1;
                }
                else if (cambiarcal == 2) {
                    cin >> p[i].cal2;
                }
                else if (cambiarcal == 3) {
                    cin >> p[i].cal3;
                }
                break;

            case 7:
                cout << "Ingrese nueva direcci�n" << endl;
                cout << "Calle: ";
                cin >> p[i].calle;
                cout << "N�mero: ";
                cin >> p[i].numcasa;
                cout << "Colonia: ";
                getline(cin, p[c].colonia);
                cout << endl;

            default:
                break;
            }

            if (o != 0) {
                system("cls");
                cout << "Datos modificados " << endl;
                cout << "Alumno: " << p[i].nombre << " " << p[i].apellido << endl;
                cout << "Correo electr�nico: " << p[i].correo << endl;
                cout << "Tel�fono: " << p[i].tel << endl;
                cout << "Matr�cula: " << p[i].matricula << endl;
                cout << "Direcci�n: " << p[i].calle << " " << p[i].numcasa << " " << p[i].colonia << endl;
                cout << "Calificaciones: " << endl;
                cout << "Parcial 1: " << p[i].cal1 << endl;
                cout << "Parcial 2: " << p[i].cal2 << endl;
                cout << "Parcial 3: " << p[i].cal3 << endl;

                cout << "�Qu� deseas modificar?" << endl;
                cout << "1. Matr�cula \n2. Nombre \n3. Apellido \n4. Correo electr�nico \n5. Tel�fono \n6. Calificaciones \0. Nada" << endl;
            }
            else {
                cout << "No modificaste nada." << endl;
            }

            break;
        }
        i++;
    }

    system("pause > nul");
    menu();
}

void eliminar() {
    cout << "�Qu� matr�cula desea eliminar?" << endl;
    cin >> o;
    int i = 0;
    while (i < c) {
        if (p[i].id == o) {
            cout << "1. Eliminar \n2. Cancelar" << endl;
            cin >> o;
            if (o == 1 && c != 0) {
                for (int j = i; j < c; j++) {
                    p[j] = p[j + 1];
                }
                c--;
            }
            break;
        }
        i++;
    }
    if (i == c)
        cout << "No se encontraron registros." << endl;
}

void archivito()    {
ofstream archivo;

archivo.open("Base de datos.txt", ios::binary);

archivo.write((char*)&p, sizeof(p));

archivo.close();

excel();
}

void excelo() {
    ofstream datos;

    datos.open("Alumnos.csv");

    datos << "Matriculas" << ",";
    datos << "Apellido(s)" << ",";
    datos << "Nombre(s)" << ",";
    datos << "Correo electr�nico" << ",";
    datos << "Tel�fono" << ",";
    datos << "N�mero de Casa" << ",";
    datos << "Calle" << ",";
    datos << "Colonia" << ",";
    datos << "Primer Parcial" << ",";
    datos << "Segundo Parcial" << ",";
    datos << "Tercer Parcial" << ",";
    datos << endl << endl;

    for (int i = 1; i < c; i++) {
        datos << (p[i].matricula) << ",";
        datos << (p[i].apellido) << ",";
        datos << (p[i].nombre) << ",";
        datos << (p[i].correo) << ",";
        datos << (p[i].tel) << ",";
        datos << (p[i].numcasa) << ",";
        datos << (p[i].calle) << ",";
        datos << (p[i].colonia) << ",";
        datos << (p[i].cal1) << ",";
        datos << (p[i].cal2) << ",";
        datos << (p[i].cal3) << ",";
        datos << endl;

    }

    datos.close();

}
