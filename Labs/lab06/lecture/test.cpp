#include <iostream>

using namespace std;

int main()
{
    //    char tab[] = {"WSTI"};

    // cout << tab << endl;
    int tab[] = {11, 38, 33, 3, 67, 89, 0, 22, 23};
    int *wsk;

    wsk = &tab[1];

    cout << *(wsk) + 4 << endl; // LINIA 10
    cout << *(wsk + 2) << endl; // LINIA 11
    cout << *(wsk++) << endl;   // LINIA 12
    cout << *(wsk--) << endl;   // LINIA 13

    return 0;
}