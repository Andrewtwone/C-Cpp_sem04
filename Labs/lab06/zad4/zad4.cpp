#include <iostream>
using namespace std;

int main()
{
    char m[6] = {'C', 'i', 's', 'c', 'o', '\0'};
    char n[10] = "Microsoft";
    char *wsk = n;

    cout << "Napis: " << wsk << endl;
    // cout << "Length: " << sizeof(n) / sizeof((n[0])) << endl;

    return 0;
}
