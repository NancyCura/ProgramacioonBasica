#include "stdafx.h"
#include <iostream>
using namespace std;
// Permite escribir con acentos;
int main()
{
    locale::global(locale("spanish"));
    cout << "Nombre: " <<endl;
    char n[20];
    cin >> n;

    cout << "Edad: " <<endl;
    int e;
    cin >> e;

    cout << "Yo" <<"\t" << n <<endl;
    cout << "Tengo" << "\t"<< e <<"\t"<< "años";
    cout << "\n";

    system("pause");
    return 0;
}
