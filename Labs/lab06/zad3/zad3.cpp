#include <iostream>
using namespace std;

int main()
{
    char tab[10] = "Cisco";
    char *wsk = tab;

    while (*wsk != '\0')
    {
        cout << *wsk;
        wsk++;
    }

    cout << endl;
    return 0;
}
