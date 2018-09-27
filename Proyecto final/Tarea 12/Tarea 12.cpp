#include <iostream>
#include <string>
using namespace std;

int o; 
int c; 

struct persona { 
    int id;
    string nombre;
    char apellido[100];
    string correo;
    char tel[15];
    char mat[8];
};

persona p[5]; 

void menu();

void registrar();

void mostrarTodos();

void buscar();

void buscarNombre();

void modificar();

int main() {
    locale::global(locale("spanish"));
    c = 0; 

    menu();
}

void menu() {
    system("cls");
    cout << "Men� principal" << endl << endl;
    cout << "Qu� quieres hacer" << endl;
    cout << "1. Registrar \n2. Mostrar todos \n3. Buscar \n4. Buscar nombre" << endl;
    cin >> o;

    switch (o)
    {
    case 1:
        registrar();
        break;

    case 2:
        mostrarTodos();
        break;

    case 3:
        buscar();
        break;
    case 4:
        buscarNombre();

        break;
    default:
        break;
    }
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
    cin >> p[c].mat;


    c++;
    menu();
}

void mostrarTodos() {
    system("cls");
    cout << "TODOS LOS REGISTROS" << endl;
    for (int i = 0; i < c; i++) {
        cout << "Nombre y apellido: " << p[i].nombre << " " << p[i].apellido << endl;
        cout << "Correo electr�nico: " << p[i].correo << endl;
        cout << "Tel�fono: " << p[i].tel << endl;
        cout << "Matr�cula: " << p[i].mat << endl;
    }

    system("pause > nul");
    menu();
}

void buscar() {
    system("cls");
    cout << "BUSCADOR" << endl << endl;
    cout << "�Qu� id quiere ver? " << endl;
    cin >> o;

    bool encontrado = false;
    for (int i = 0; i < c; i++)
    {
        if (p[i].id == o) {
            cout << "Lo encontr�:" << endl;
            cout << "Nombre y apellido: " << p[i].nombre << " " << p[i].apellido << endl;
            cout << "Correo electr�nico: " << p[i].correo << endl;
            cout << "Tel�fono: " << p[i].tel << endl;
            cout << "Matr�cula: " << p[i].mat << endl;
            encontrado = true;
            break; 
        }
    }

    if (!encontrado) {
        cout << "No hab�a registros con ese id." << endl;
    }

    system("pause > nul");

    menu();
}

void buscarNombre() {
    cin.ignore();
    system("cls");
    cout << "BUSCADOR" << endl << endl;
    cout << "�Qu� nombre buscas? " << endl;
    string n;
    getline(cin, n);

    bool encontrado = false;
    for (int i = 0; i < c; i++)
    {


        if (strcmp(n.c_str(), p[i].nombre.c_str()) == 0) { 
            cout << "Lo encontr�: " << endl;
            cout << "Nombre y apellido: " << p[i].nombre << " " << p[i].apellido << endl;
            cout << "Correo electr�nico: " << p[i].correo << endl;
            cout << "Tel�fono: " << p[i].tel << endl;
            cout << "Matr�cula: " << p[i].mat << endl;
            encontrado = true;
            break; 
        }
    }

    if (!encontrado) {
        cout << "No hab�a registros con ese nombre" << endl;
    }

    system("pause > nul");

    menu();
}