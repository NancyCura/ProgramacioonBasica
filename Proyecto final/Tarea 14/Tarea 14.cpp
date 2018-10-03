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
    cin >> p[c].id;

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
        cout << "Alumno: " << p[i].nombre << " " << p[i].apellido << endl;
        cout << "Correo electr�nico: " << p[i].correo << endl;
        cout << "Tel�fono: " << p[i].tel << endl;
        cout << "Matr�cula: " << p[i].id << endl;
        cout << "Calificaciones: " << p[i].cal1 << " - " << p[i].cal2 << " - " << p[i].cal3 << endl;
    }

    system("pause > nul");
    menu();
}

void buscar() {
    system("cls");
    cout << "BUSCADOR" << endl << endl;
    cout << "�Qu� matr�cula quiere ver? " << endl;
    cin >> o;

    bool encontrado = false;
    for (int i = 0; i < c; i++)
    {
        if (p[i].id == o) {
            cout << "Lo encontr�:" << endl;
            cout << "Alumno: " << p[i].nombre << " " << p[i].apellido << endl;
            cout << "Correo electr�nico: " << p[i].correo << endl;
            cout << "Tel�fono: " << p[i].tel << endl;
            cout << "Matr�cula: " << p[i].id << endl;
            cout << "Calificaciones: " << p[i].cal1 << " - " << p[i].cal2 << " - " << p[i].cal3 << endl;
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


        if (strcmp(n.c_str(), p[i].id.c_str()) == 0) { 
            cout << "Lo encontr�: " << endl;
            cout << "Alumno: " << p[i].nombre << " " << p[i].apellido << endl;
            cout << "Correo electr�nico: " << p[i].correo << endl;
            cout << "Tel�fono: " << p[i].tel << endl;
            cout << "Matr�cula: " << p[i].id << endl;
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
    cin.ignore();
    cout << "�Qu� matr�cula buscas? " << endl;
    cin >> o;

    int i = 0;
    while (i < c) {
        if (p[i].id == o) {
            cout << "Encontr� a: " << endl;
            cout << "Alumno: " << p[i].nombre << " " << p[i].apellido << endl;
            cout << "Correo electr�nico: " << p[i].correo << endl;
            cout << "Tel�fono: " << p[i].tel << endl;
            cout << "Matr�cula: " << p[i].id << endl;
            cout << "Calificaciones: " << p[i].cal1 << " - " << p[i].cal2 << " - " << p[i].cal3 << endl;

            cout << "�Qu� deseas modificar?" << endl;
            cout << "1. Matr�cula \n2. Nombre \n3. Apellido \n4. Correo electr�nico \n5. Tel�fono \n6. Calificaciones \0. Nada" << endl;
            cin >> o;

            switch (o)
            {
            case 1:
                cout << "Ingresa nueva m�tricula: ";
                cin >> p[i].id;
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
                cout << "Ingrese nueva calificaci�n"<<endl;
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
            default:
                break;
            }

            if (o != 0) {
                cout << "Registro modificado: " << endl;           
                cout << "Alumno: " << p[i].nombre << " " << p[i].apellido << endl;
                cout << "Correo electr�nico: " << p[i].correo << endl;
                cout << "Tel�fono: " << p[i].tel << endl;
                cout << "Matr�cula: " << p[i].id << endl;
                cout << "Calificaciones: " << p[i].cal1 << " - " << p[i].cal2 << " - " << p[i].cal3 << endl;

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



}