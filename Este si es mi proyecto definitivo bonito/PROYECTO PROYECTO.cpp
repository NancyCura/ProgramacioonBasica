#include <iostream>
#include <string>
#include <fstream>
#include<stdio.h>
#include <sstream>
#include <iostream>
using namespace std;

int contador = 0;
int opcion = 0;

void menu();
void registro();
void mostrartodos();
void buscarNombre();
void modificar();
void eliminar();
void guardar();
void guardarCSV();


struct alumno {
    int numlista;
    string nombre;
    string correo;
    char telefono[12];
    char matricula[7];
    float cal1 = 0.00;
    float cal2 = 0.00;
    float cal3 = 0.00;
    string calle;
    char numcasa[4];
    string colonia;
    float prom;
};

alumno al[100];

void main() {
    locale::global(locale("spanish"));
    contador = 0;
    opcion = 0;
    system("color FD");

    ifstream archivo;

    archivo.open("Proyecto.txt", ios::binary);
    if (archivo.is_open()) {

        while (!archivo.eof()) {
            lectura.read((char*)&al, sizeof(al));
        }
    }
    else {
        cout << "Lectura de Archivo:" << endl;
        cout << endl;

        cout << "El archivo no existente o hay problemas para abrirlo." << endl;
        cout << endl;

        cout << "Presione cualquier tecla para entrar a Menu." << endl;
        system("pause>nul");
    }

    archivo.close();

    for (int i = 0; i < 100; i++)
    {
        if (al[i].numlista != 0) {
            contador++;
        }
    }

    menu();

}

void menu() {
    system("cls");
    cout << "MENÚ PRINCIPAL" << endl << endl;
    cout << "¿Qué quieres hacer?" << endl;
    cout << "1. Registrar \n2. Mostrar todos \n3. Buscar nombre \n4. Modificar \n5. Eliminar \n6. Guardar \n7. Salir" << endl;

    cin >> opcion;

    switch (opcion) {

    case 1:
        registro();
        break;

    case 2:
        mostrartodos();
        break;

    case 3:
        buscarNombre();
        break;

    case 4:
        modificar();
        break;

    case 5:
        eliminar();
        break;

    case 6:
        guardarCSV();
        break;


    case 7:
        guardar();
        system("cls");
        cout << "Aiooooos";
        system("pause>nul");
        break;

    default:
        cout << "Escribe una opción válida." << endl;
        system("pause > nul");
        menu();
        break;

    }
}

void registro() {
    system("cls");
    bool conf = false;
    al[contador].numlista = contador + 1;

    //nombre

    cin.ignore();
    do
    {
        cout << "Nombre completo: " << endl;
        getline(cin, al[contador].nombre);
        int c = al[contador].nombre.size();
        int validar = 0;


        for (int i = 0; i < c; i++) {
            if (isalpha(al[contador].nombre[i])) {
                validar++;
            }
            else if (al[contador].nombre[i] == ' ')
            {

                validar++;
            }
        }
        if (validar == c) {
            conf = true;
        }

        if (contador != 0) {
            for (int j = 0; j < contador; j++) {
                if (al[contador].nombre == al[j].nombre) {
                    conf = false;
                    break;
                }
            }

        }

        if (conf == false) {
            cout << "Inserte un nombre válido. " << endl;
            system("pause > nul");
            system("cls");

        }
        else
        {
            cout << "Nombre confirmado: " << al[contador].nombre << endl;
            system("pause > nul ");
            system("cls");
        }
    } while (conf == false);

    //matricula

    bool confmat = false;
    do
    {
        cin.ignore();
        cout << "Matrícula: " << endl;
        cin >> al[contador].matricula;

        int mat = 0;
        int noval = 0;

        for (int i = 0; i <= 7; i++) {
            if (isdigit(al[contador].matricula[i])) {
                mat++;
            }
        }

        if (mat == 7) {
            confmat = true;
        }

        if (contador != 0) {
            for (int j = 0; j < contador; j++) {
                if (al[contador].matricula == al[j].matricula) {
                    confmat = false;
                    break;
                }
            }

        }



        if (confmat == false) {
            cout << "Inserte una matricula válida. " << endl;
            system("pause > nul");
            system("cls");

        }
        else
        {
            cout << "Matricula confirmada: " << al[contador].matricula << endl;
            system("pause > nul ");
            system("cls");

        }


    } while (confmat == false);

    //correo
    bool confcorreo = false;
    do
    {
        cout << "Correo electrónico: " << endl;
        cin >> al[contador].correo;
        int arroba = 0;
        int c = al[contador].correo.size();
        for (int i = 0; i < c; i++) {
            if (al[contador].correo[i] == '@') {
                arroba++;
            }
        }
        if (arroba == 1) {
            confcorreo = true;
        }
        for (int i = 0; i < c; i++) {
            if (c - i == 4) {
                if (al[contador].correo[i] != '.') {
                    confcorreo = false;
                }
                if (al[contador].correo[i + 1] != 'c') {
                    confcorreo = false;
                }
                if (al[contador].correo[i + 2] != 'o') {
                    confcorreo = false;
                }
                if (al[contador].correo[i + 3] != 'm') {
                    confcorreo = false;
                }
            }


        }

        if (contador != 0) {
            for (int j = 0; j < contador; j++) {
                if (al[contador].correo == al[j].correo) {
                    confcorreo = false;
                    break;
                }
            }
        }

        if (confcorreo == false) {
            cout << "Inserte un correo válido." << endl;
            system("pause > nul");
            system("cls");
        }
        else
        {

            cout << "correo confirmado: " << al[contador].correo << endl;
            system("pause > nul");
            system("cls");
        }

    } while (confcorreo == false);

    //telefono
    bool conftel = false;
    bool conftel2 = false;
    bool confftel = false;
    do
    {
        cout << "Teléfono: " << endl;
        cin >> al[contador].telefono;

        int val = 0;

        int l = strlen(al[contador].telefono);

        for (int i = 0; i <= 12; i++) {
            if (isdigit(al[contador].telefono[i])) {
                val++;
            }

            else
            {
                conftel = false;
                break;
            }

        }

        if (l == val) {
            conftel = true;
        }


        if (l > 7 && l < 13) {
            conftel2 = true;
        }

        if (conftel2 == true && conftel == true) {
            confftel = true;
        }

        else
        {
            confftel = false;
        }


        if (contador != 0) {
            for (int j = 0; j < contador; j++) {
                if (al[contador].telefono == al[j].telefono) {
                    confftel = false;
                    break;
                }
            }

        }

        if (confftel == false) {
            cout << "Inserte un teléfono válido. " << endl;
            system("pause > nul");
            system("cls");

        }
        else
        {
            cout << "Teléfono confirmado: " << al[contador].telefono << endl;
            system("pause > nul ");
            system("cls");

        }


    } while (confftel == false);

    //direccion
    bool confdirec = false;
    cout << "Direccion" << endl;
    do
    {
        cout << "Calle: ";
        cin >> al[contador].calle;
        int c = al[contador].calle.size();
        int validar = 0;


        for (int i = 0; i < c; i++) {
            if (isalpha(al[contador].calle[i])) {
                validar++;
            }
            else if (al[contador].calle[i] == ' ')
            {

                validar++;
            }
        }
        if (validar == c) {
            confdirec = true;
        }

        if (confdirec == false) {
            cout << "Inserte una calle válida. " << endl;
            system("pause > nul");
            system("cls");

        }
        else
        {
            cout << "Calle confirmada: " << al[contador].calle << endl;
            system("pause > nul ");
            system("cls");
        }
    } while (confdirec == false);

    confdirec = true;
    do
    {
        cout << "Número: ";
        cin >> al[contador].numcasa;

        int l = strlen(al[contador].numcasa);

        for (int i = 0; i < l; i++) {

            if (isdigit(al[contador].numcasa[i])) {
                confdirec = true;
            }
            else
            {
                confdirec = false;
                break;
            }

        }


        if (confdirec == false) {
            cout << "Inserte un numero válido. " << endl;
            system("pause > nul");
            system("cls");

        }
        else
        {
            cout << "Número confirmado: " << al[contador].numcasa << endl;
            system("pause > nul ");
            system("cls");
        }
    } while (confdirec == false);

    confdirec = true;
    do
    {
        cout << "Colonia: ";
        cin.ignore();
        getline(cin, al[contador].colonia);
        cout << endl;

        int c = al[contador].colonia.size();
        int validar = 0;


        for (int i = 0; i < c; i++) {
            if (isalpha(al[contador].colonia[i])) {
                validar++;
            }
            else if (al[contador].colonia[i] == ' ')
            {

                validar++;
            }
        }
        if (validar == c) {
            confdirec = true;
        }

        if (confdirec == false) {
            cout << "Inserte una colonia válido. " << endl;
            system("pause > nul");
            system("cls");

        }
        else
        {
            cout << "Colonia confirmada: " << al[contador].colonia << endl;
            system("pause > nul ");
            system("cls");
        }
    } while (confdirec == false);


    cout << "Direccion: " << al[contador].calle << " " << al[contador].numcasa << " " << al[contador].colonia << endl;
    system("pause > nul");
    system("cls");

    bool confparcial = false;

    //calificaciones
    cout << "Calificaciones" << endl;

    do
    {
        cout << "Parcial 1: " << endl;
        cin >> al[contador].cal1;

        if (al[contador].cal1 > -1 && al[contador].cal1 < 101) {
            confparcial = true;
        }

        if (confparcial == false) {
            cout << "Inserte una calificación válida. " << endl;
            system("pause > nul");
            system("cls");

        }
        else
        {
            cout << "Calificación confirmada: " << al[contador].cal1 << endl;
            system("pause > nul ");
            system("cls");

        }

    } while (confparcial == false);

    confparcial = false;
    do
    {
        cout << "Parcial 2: " << endl;
        cin >> al[contador].cal2;

        if (al[contador].cal2 > -1 && al[contador].cal2 < 101) {
            confparcial = true;
        }

        if (confparcial == false) {
            cout << "Inserte una calificación válida. " << endl;
            system("pause > nul");
            system("cls");

        }
        else
        {
            cout << "Calificación confirmada: " << al[contador].cal2 << endl;
            system("pause > nul ");
            system("cls");

        }

    } while (confparcial == false);


    confparcial = false;
    do
    {
        cout << "Parcial 3: " << endl;
        cin >> al[contador].cal3;

        if (al[contador].cal3 > -1 && al[contador].cal3 < 101) {
            confparcial = true;
        }

        if (confparcial == false) {
            cout << "Inserte una calificación válida. " << endl;
            system("pause > nul");
            system("cls");

        }
        else
        {
            cout << "Calificación confirmada: " << al[contador].cal3 << endl;
            system("pause > nul ");
            system("cls");

        }

    } while (confparcial == false);



    al[contador].prom = (((al[contador].cal1 * 30) / 100) + ((al[contador].cal2 * 45) / 100) + ((al[contador].cal3 * 25) / 100));

    contador++;
    guardar();
    menu();

}

void mostrartodos() {
    system("cls");
    cout << "Todos los registros" << endl;
    for (int i = 0; i < contador; i++) {
        cout << al[i].numlista << "." << endl;
        cout << "Matrícula: " << al[i].matricula << endl;
        cout << "Nombre completo: " << al[i].nombre << endl;
        cout << "Correo electrónico: " << al[i].correo << endl;
        cout << "Teléfono: " << al[i].telefono << endl;
        cout << "Dirección: " << al[i].calle << " " << al[i].numcasa << " " << al[i].colonia << endl;
        cout << "Calificaciones " << endl;
        cout << "Parcial 1: " << al[i].cal1 << endl;
        cout << "Parcial 2; " << al[i].cal2 << endl;
        cout << "Parcial 3: " << al[i].cal3 << endl;
        cout << "Promedio final: " << al[i].prom << endl;
        cout << "----------------------------------------------------------------" << endl;
    }

    system("pause");
    menu();
}

void buscarNombre() {
    cin.ignore();
    system("cls");
    cout << "Buscador" << endl << endl;
    cout << "¿Qué nombre busca? " << endl;
    string n;
    getline(cin, n);

    bool encontrado = false;

    int i = 0;
    while (i < contador)
    {
        if (strcmp(n.c_str(), al[i].nombre.c_str()) == 0) {
            cout << "Alumno encontrado:" << endl;
            cout << "Matrícula: " << al[i].matricula << endl;
            cout << "Nombre completo: " << al[i].nombre << endl;
            cout << "Correo electrónico: " << al[i].correo << endl;
            cout << "Teléfono: " << al[i].telefono << endl;
            cout << "Dirección: " << al[i].calle << " " << al[i].numcasa << " " << al[i].colonia << endl;
            cout << "Calificaciones " << endl;
            cout << "Parcial 1: " << al[i].cal1 << endl;
            cout << "Parcial 2; " << al[i].cal2 << endl;
            cout << "Parcial 3: " << al[i].cal3 << endl;
            cout << "Promedio final: " << al[i].prom << endl;
            encontrado = true;
            break;
        }
        i++;
    }

    if (!encontrado) {
        cout << "No se encontraron registros con ese nombre." << endl;
    }

    system("pause > nul");

    menu();
}

void modificar() {
    cin.ignore();
    system("cls");
    cout << "¿Qué alumno quiere modificar? " << endl;
    cout << "Nombre:" << endl;
    string n;
    getline(cin, n);

    bool encontrado = false;
    int i = 0;
    while (i < contador) {
        if (strcmp(n.c_str(), al[i].nombre.c_str()) == 0) {
            cout << "Encontré a: " << endl;
            cout << "Matrícula: " << al[i].matricula << endl;
            cout << "Nombre completo: " << al[i].nombre << endl;
            cout << "Correo electrónico: " << al[i].correo << endl;
            cout << "Teléfono: " << al[i].telefono << endl;
            cout << "Dirección: " << al[i].calle << " " << al[i].numcasa << " " << al[i].colonia << endl;
            cout << "Calificaciones " << endl;
            cout << "Parcial 1: " << al[i].cal1 << endl;
            cout << "Parcial 2; " << al[i].cal2 << endl;
            cout << "Parcial 3: " << al[i].cal3 << endl;
            cout << "Promedio final: " << al[i].prom << endl;
            encontrado = true;

            cout << "¿Qué deseas modificar?" << endl;
            cout << "1. Matrícula \n2. Nombre \n3. Correo electrónico \n4. Teléfono \n5. Dirección \n6. Calificaciones \n7.Nada " << endl;
            cin >> opcion;
            bool confdirec = false;
            bool confmat = false;
            bool conf = false;
            bool confcorreo = false;
            bool conftel = false;
            bool confparcial = true;
            confdirec = false;
            conftel = false;
            bool conftel2 = false;
            bool confftel = false;

            switch (opcion)
            {
            case 1:

                do
                {
                    cin.ignore();
                    cout << "Nueva matrícula: " << endl;
                    cin >> al[i].matricula;

                    int mat = 0;
                    int noval = 0;

                    for (int j = 0; j <= 7; j++) {
                        if (isdigit(al[i].matricula[j])) {
                            mat++;
                        }
                    }

                    if (mat == 7) {
                        confmat = true;
                    }

                    if (i != 0) {
                        for (int j = 0; j < contador; j++) {
                            if (al[i].matricula == al[j].matricula) {
                                confmat = false;
                                break;
                            }
                        }

                    }



                    if (confmat == false) {
                        cout << "Inserte una matricula válida. " << endl;
                        system("pause > nul");
                        system("cls");

                    }
                    else
                    {
                        cout << "Nueva matricula confirmada: " << al[i].matricula << endl;
                        system("pause > nul ");
                        system("cls");

                    }


                } while (confmat == false);
                break;

            case 2:

                do
                {
                    cin.ignore();
                    cout << "Nombre completo: " << endl;
                    getline(cin, al[i].nombre);
                    int c = al[i].nombre.size();
                    int validar = 0;


                    for (int j = 0; j < c; j++) {
                        if (isalpha(al[i].nombre[j])) {
                            validar++;
                        }
                        else if (al[i].nombre[j] == ' ')
                        {

                            validar++;
                        }
                    }
                    if (validar == c) {
                        conf = true;
                    }

                    if (conf == false) {
                        cout << "Inserte un nombre válido. " << endl;
                        system("pause > nul");
                        system("cls");

                    }
                    else
                    {
                        cout << "Nombre confirmado: " << al[i].nombre << endl;
                        system("pause > nul ");
                        system("cls");
                    }
                } while (conf == false);


                break;

            case 3:


                do
                {
                    cout << "Correo electrónico: " << endl;
                    cin >> al[i].correo;
                    int arroba = 0;
                    int c = al[i].correo.size();
                    for (int j = 0; j < c; j++) {
                        if (al[i].correo[j] == '@') {
                            arroba++;
                        }
                    }
                    if (arroba == 1) {
                        confcorreo = true;
                    }
                    for (int j = 0; j < c; j++) {
                        if (c - j == 4) {
                            if (al[i].correo[j] != '.') {
                                confcorreo = false;
                            }
                            if (al[i].correo[j + 1] != 'c') {
                                confcorreo = false;
                            }
                            if (al[i].correo[j + 2] != 'o') {
                                confcorreo = false;
                            }
                            if (al[i].correo[j + 3] != 'm') {
                                confcorreo = false;
                            }
                        }


                    }

                    if (i != 0) {
                        for (int k = 0; k < contador; k++) {
                            if (al[i].correo == al[k].correo) {
                                confcorreo = false;
                                break;
                            }
                        }
                    }

                    if (confcorreo == false) {
                        cout << "Inserte un correo válido." << endl;
                        system("pause > nul");
                        system("cls");
                    }
                    else
                    {

                        cout << "correo confirmado: " << al[i].correo << endl;
                        system("pause > nul");
                        system("cls");
                    }

                } while (confcorreo == false);

                break;
            case 4:

                do
                {
                    cout << "Teléfono: " << endl;
                    cin >> al[i].telefono;

                    int val = 0;

                    int l = strlen(al[i].telefono);

                    for (int j = 0; j <= 12; j++) {
                        if (isdigit(al[i].telefono[j])) {
                            val++;
                        }

                        else
                        {
                            conftel = false;
                            break;
                        }

                    }

                    if (l == val) {
                        conftel = true;
                    }


                    if (l > 7 && l < 13) {
                        conftel2 = true;
                    }

                    if (conftel2 == true && conftel == true) {
                        confftel = true;
                    }

                    else
                    {
                        confftel = false;
                    }


                    if (i != 0) {
                        for (int j = 0; j < i; j++) {
                            if (al[i].telefono == al[j].telefono) {
                                confftel = false;
                                break;
                            }
                        }

                    }

                    if (confftel == false) {
                        cout << "Inserte un teléfono válido. " << endl;
                        system("pause > nul");
                        system("cls");

                    }
                    else
                    {
                        cout << "Teléfono confirmado: " << al[i].telefono << endl;
                        system("pause > nul ");
                        system("cls");

                    }


                } while (confftel == false);
                break;

            case 5:

                cout << "Nueva direccion" << endl;
                do
                {
                    cout << "Calle: ";
                    cin >> al[i].calle;
                    int c = al[i].calle.size();
                    int validar = 0;


                    for (int j = 0; j < c; j++) {
                        if (isalpha(al[i].calle[j])) {
                            validar++;
                        }
                        else if (al[i].calle[j] == ' ')
                        {

                            validar++;
                        }
                    }
                    if (validar == c) {
                        confdirec = true;
                    }

                    if (confdirec == false) {
                        cout << "Inserte una calle válida. " << endl;
                        system("pause > nul");
                        system("cls");

                    }
                    else
                    {
                        cout << "Calle confirmada: " << al[i].calle << endl;
                        system("pause > nul ");
                        system("cls");
                    }
                } while (confdirec == false);

                confdirec = true;
                do
                {
                    cout << "Número: ";
                    cin >> al[i].numcasa;

                    int l = strlen(al[i].numcasa);

                    for (int j = 0; j < l; j++) {

                        if (isdigit(al[i].numcasa[j])) {
                            confdirec = true;
                        }
                        else
                        {
                            confdirec = false;
                            break;
                        }

                    }


                    if (confdirec == false) {
                        cout << "Inserte un numero válido. " << endl;
                        system("pause > nul");
                        system("cls");

                    }
                    else
                    {
                        cout << "Número confirmado: " << al[i].numcasa << endl;
                        system("pause > nul ");
                        system("cls");
                    }
                } while (confdirec == false);

                confdirec = true;
                do
                {
                    cout << "Colonia: ";
                    cin.ignore();
                    getline(cin, al[i].colonia);
                    cout << endl;

                    int c = al[i].colonia.size();
                    int validar = 0;


                    for (int j = 0; j < c; j++) {
                        if (isalpha(al[i].colonia[j])) {
                            validar++;
                        }
                        else if (al[i].colonia[j] == ' ')
                        {

                            validar++;
                        }
                    }
                    if (validar == c) {
                        confdirec = true;
                    }

                    if (confdirec == false) {
                        cout << "Inserte una colonia válido. " << endl;
                        system("pause > nul");
                        system("cls");

                    }
                    else
                    {
                        cout << "Colonia confirmada: " << al[i].colonia << endl;
                        system("pause > nul ");
                        system("cls");
                    }
                } while (confdirec == false);

                break;


            case 6:

                cout << "¿Qué calificación quiere cambiar?";
                cout << "1. Parcial 1 \n2. Parcial 2 \n3. Parcial 3" << endl;
                int cambiarcal;
                cin >> cambiarcal;
                cout << "Ingrese nueva calificación" << endl;

                if (cambiarcal == 1) {
                    do
                    {
                        cout << "Parcial 1: " << endl;
                        cin >> al[i].cal1;

                        if (al[i].cal1 > -1 && al[i].cal1 < 101) {
                            confparcial = true;
                        }

                        if (confparcial == false) {
                            cout << "Inserte una calificación válida. " << endl;
                            system("pause > nul");
                            system("cls");

                        }
                        else
                        {
                            cout << "Calificación confirmada: " << al[i].cal1 << endl;
                            system("pause > nul ");
                            system("cls");

                        }

                    } while (confparcial == false);
                }
                else if (cambiarcal == 2) {
                    do
                    {
                        cout << "Parcial 2: " << endl;
                        cin >> al[i].cal1;

                        if (al[i].cal2 > -1 && al[i].cal2 < 101) {
                            confparcial = true;
                        }

                        if (confparcial == false) {
                            cout << "Inserte una calificación válida. " << endl;
                            system("pause > nul");
                            system("cls");

                        }
                        else
                        {
                            cout << "Calificación confirmada: " << al[i].cal2 << endl;
                            system("pause > nul ");
                            system("cls");

                        }

                    } while (confparcial == false);
                }
                else if (cambiarcal == 3) {
                    do
                    {
                        cout << "Parcial 3: " << endl;
                        cin >> al[i].cal3;

                        if (al[i].cal3 > -1 && al[i].cal3 < 101) {
                            confparcial = true;
                        }

                        if (confparcial == false) {
                            cout << "Inserte una calificación válida. " << endl;
                            system("pause > nul");
                            system("cls");

                        }
                        else
                        {
                            cout << "Calificación confirmada: " << al[i].cal3 << endl;
                            system("pause > nul ");
                            system("cls");

                        }

                    } while (confparcial == false);
                }

                break;

            default:
                break;

            }

            if (opcion != 0) {
                cout << "Datos modificado: " << endl;
                cout << "Matrícula: " << al[i].matricula << endl;
                cout << "Nombre completo: " << al[i].nombre << endl;
                cout << "Correo electrónico: " << al[i].correo << endl;
                cout << "Teléfono: " << al[i].telefono << endl;
                cout << "Dirección: " << al[i].calle << " " << al[i].numcasa << " " << al[i].colonia << endl;
                cout << "Calificaciones " << endl;
                cout << "Parcial 1: " << al[i].cal1 << endl;
                cout << "Parcial 2; " << al[i].cal2 << endl;
                cout << "Parcial 3: " << al[i].cal3 << endl;
                cout << "Promedio final: " << al[i].prom << endl;
                cout << "¿Qué deseas modificar?" << endl;

                cout << "1. Matrícula \n2. Nombre \n3. Correo electrónico \n4. Teléfono \n5. Dirección \n6. Calificaciones \n7.Nada " << endl;
            }
            else {
                cout << "No modificaste nada." << endl;
            }

            break;
        }
        i++;

    }
    if (!encontrado) {
        cout << "No se encontraron registros con ese nombre." << endl;
    }

    system("pause > nul");
    menu();
}

void eliminar() {
    cin.ignore();
    system("cls");
    cout << "¿Qué alumno quiere eliminar? " << endl;
    string n;
    getline(cin, n);

    int i = 0;
    while (i < contador) {
        if (strcmp(n.c_str(), al[i].nombre.c_str()) == 0) {
            cout << "Matrícula: " << al[i].matricula << endl;
            cout << "Nombre completo: " << al[i].nombre << endl;
            cout << "Correo electrónico: " << al[i].correo << endl;
            cout << "Teléfono: " << al[i].telefono << endl;
            cout << "Dirección: " << al[i].calle << " " << al[i].numcasa << " " << al[i].colonia << endl;
            cout << "Calificaciones " << endl;
            cout << "Parcial 1: " << al[i].cal1 << endl;
            cout << "Parcial 2; " << al[i].cal2 << endl;
            cout << "Parcial 3: " << al[i].cal3 << endl;
            cout << "Promedio final: " << al[i].prom << endl;

            cout << "1. Eliminar \n2. Cancelar" << endl;
            cin >> opcion;
            if (opcion == 1 && contador != 0) {
                for (int j = i; j < contador; j++) {
                    al[j] = al[j + 1];
                }
                contador--;
            }
            break;
        }
        i++;
    }
    if (i == contador) {
        cout << "No se encontraron registros." << endl;

    }
    i++;

    system("pause<nul");
    system("cls");
    menu();
}

void guardar() {
    cout << "¿Deseas guardar permanentemente?" << endl;
    cout << "1.- Sí \n2.- No." << endl;

    cin >> opcion;

    if (opcion == 1)
    {

        ofstream archivo;


        archivo.open("proyecto.data", ios::binary);

        archivo.write((char*)&al, sizeof(al));

        archivo.close();
    }
}

void guardarCSV() {

    ofstream archivo;

    archivo.open("proyecto.csv");

    for (int i = 0; i < contador; i++) {
        archivo << al[contador].matricula << ",";
        archivo << al[i].nombre << ",";
        archivo << al[i].correo << ",";
        archivo << al[i].telefono << ",";
        archivo << "Dirección: " << al[i].calle << " " << al[i].numcasa << " " << al[i].colonia << ",";
        archivo << "Calificaciones " << ",";
        archivo << al[i].cal1 << ",";
        archivo << al[i].cal2 << ",";
        archivo << al[i].cal3 << ",";
        archivo << al[i].prom << ",";

    }

    archivo.close();

    menu();
}