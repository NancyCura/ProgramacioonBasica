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

void buscarmat();

void modificar();

int main() {
    locale::global(locale("spanish"));
    c = 0; 

    menu();
}

void menu() {
    system("cls");
    cout << "Menú principal" << endl << endl;
    cout << "Qué quieres hacer" << endl;
    cout << "1. Registrar \n2. Mostrar todos \n3. Buscar \n4. Buscar matricula" << endl;
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
        buscarmat();

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

    cout << "Correo electrónico: ";
    cin >> p[c].correo;

    cout << "Teléfono: ";
    cin >> p[c].tel;

    cout << "Matrícula: ";
    cin >> p[c].mat;


    c++;
    menu();
}

void mostrarTodos() {
    system("cls");
    cout << "TODOS LOS REGISTROS" << endl;
    for (int i = 0; i < c; i++) {
        cout << "Nombre y apellido: " << p[i].nombre << " " << p[i].apellido << endl;
        cout << "Correo electrónico: " << p[i].correo << endl;
        cout << "Teléfono: " << p[i].tel << endl;
        cout << "Matrícula: " << p[i].mat << endl;
    }

    system("pause > nul");
    menu();
}

void buscar() {
    system("cls");
    cout << "BUSCADOR" << endl << endl;
    cout << "¿Qué id quiere ver? " << endl;
    cin >> o;

    bool encontrado = false;
    for (int i = 0; i < c; i++)
    {
        if (p[i].id == o) {
            cout << "Lo encontré:" << endl;
            cout << "Nombre y apellido: " << p[i].nombre << " " << p[i].apellido << endl;
            cout << "Correo electrónico: " << p[i].correo << endl;
            cout << "Teléfono: " << p[i].tel << endl;
            cout << "Matrícula: " << p[i].mat << endl;
            encontrado = true;
            break; 
        }
    }

    if (!encontrado) {
        cout << "No había registros con ese id." << endl;
    }

    system("pause > nul");

    menu();
}

void buscarmat() {
    cin.ignore();
    system("cls");
    cout << "BUSCADOR" << endl << endl;
    cout << "¿Qué matrícula buscas? " << endl;
    string n;
    getline(cin, n);

    bool encontrado = false;
    i = 0;
    while (i<c)
    {


        if (strcmp(n.c_str(), p[i].mat.c_str()) == 0) { 
            cout << "Lo encontré: " << endl;
            cout << "Nombre y apellido: " << p[i].nombre << " " << p[i].apellido << endl;
            cout << "Correo electrónico: " << p[i].correo << endl;
            cout << "Teléfono: " << p[i].tel << endl;
            cout << "Matrícula: " << p[i].mat << endl;
            encontrado = true;
            break; 
        }
    }

    if (!encontrado) {
        cout << "No había registros con esa matrícula." << endl;

    }
    i++;
    }

    system("pause > nul");

    menu();
}