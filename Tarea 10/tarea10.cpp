#include <iostream>
#include <time.h>
#include <windows.h>
using namespace std;

int p = 0;

int main() {
    int a[100] = {}; 
    int pos = 49;

    for (int i = 0; i < 100; i++)
    {
        system("cls");
        srand(time(NULL));
        int r = 1 - rand() % 2 * 2;
        pos += r;


        pos = pos < 0 ? 99 : pos;
        pos = pos > 99 ? 0 : pos;


        for (int j = 0; j < 100; j++)
        {
            if (j == pos) {
                cout << "@";
            }
            else if (j == 49) {
                cout << "0";
            }
            else {
                cout << "*";
            }

        }


        if (pos == 49) {
            p++;
        }

        Sleep(30);
    }

    system("cls");
    cout << "Las veces que paso por el inicio fue: " << p << endl;
    system("pause");


}