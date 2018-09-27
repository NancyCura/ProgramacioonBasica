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
    int cal1;
    int cal2;
    int cal3;
};

persona p[5]; 

void menu();
void manual();
void registrar();

void mostrarTodos();

void buscar();

void buscarmat();

void modificar();

int main() {
    locale::global(locale("spanish"));
    c = 0; 
    cout << "Bienvenido al men� principal" << endl;
    menu();
}

void menu() {
    system("cls");
    cout << "MEN� PRINCIPAL" << endl << endl;
    cout << "�Qu� quieres hacer?" << endl;
    cout << "1.Manual de usuario \n2. Registrar \n3. Mostrar todos \n4. Buscar \n5. Buscar matricula \n6. Modificar" << endl;
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
    default:
        break;
    }
}


void manual() {


 cout << "Bienvenido al manual de usuario, aqui te ayudaremos a identificar las opciones" << endl;

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
    cin >> p[c].mat;

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
        cout << "Nombre y apellido: " << p[i].nombre << " " << p[i].apellido << endl;
        cout << "Correo electr�nico: " << p[i].correo << endl;
        cout << "Tel�fono: " << p[i].tel << endl;
        cout << "Matr�cula: " << p[i].mat << endl;
        cout << "Calificaciones: " << p[i].cal1 << " - " << p[i].cal2 << " - " << p[i].cal3 << endl;
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
            cout << "Calificaciones: " << p[i].cal1 << " - " << p[i].cal2 << " - " << p[i].cal3 << endl;
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

void buscarmat() {
    cin.ignore();
    system("cls");
    cout << "BUSCADOR" << endl << endl;
    cout << "�Qu� matr�cula buscas? " << endl;
    string n;
    getline(cin, n);

    bool encontrado = false;
    i = 0;
    while (i<c)
    {


        if (strcmp(n.c_str(), p[i].mat.c_str()) == 0) { 
            cout << "Lo encontr�: " << endl;
            cout << "Nombre y apellido: " << p[i].nombre << " " << p[i].apellido << endl;
            cout << "Correo electr�nico: " << p[i].correo << endl;
            cout << "Tel�fono: " << p[i].tel << endl;
            cout << "Matr�cula: " << p[i].mat << endl;
            cout << "Calificaciones: " << p[i].cal1 << " - " << p[i].cal2 << " - " << p[i].cal3 << endl;
            encontrado = true;
            break; 
        }
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













}


}