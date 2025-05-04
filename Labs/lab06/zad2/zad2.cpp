#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char *wskchar = new char[10];
    int *wskint = new int[3];

    strcpy(wskchar, "Microsoft");

    cout << "Napis (wskchar): " << wskchar << endl;

    wskint[0] = 10;
    wskint[1] = 20;
    wskint[2] = 30;

    cout << "Zawartosc wskint: "
         << wskint[0] << " "
         << wskint[1] << " "
         << wskint[2] << endl;

    delete[] wskchar;
    delete[] wskint;

    return 0;
}
