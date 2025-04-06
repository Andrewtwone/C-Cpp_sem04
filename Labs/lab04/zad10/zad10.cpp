#include <iostream>
#include <bitset>
using namespace std;

int main()
{
    cout << "=== Przesuwanie bitow dla CHAR ===\n";
    for (char c = 0; c < 127; ++c)
    {
        cout << "W lewo:  " << (int)c << " -> " << bitset<8>(c) << " -> " << bitset<8>(c << 1) << endl;
        cout << "W prawo: " << (int)c << " -> " << bitset<8>(c) << " -> " << bitset<8>(c >> 1) << endl;
    }

    cout << "\n=== Przesuwanie bitow dla UNSIGNED CHAR ===\n";
    for (unsigned char uc = 0; uc < 255; ++uc)
    {
        cout << "W lewo:  " << (int)uc << " -> " << bitset<8>(uc) << " -> " << bitset<8>(uc << 1) << endl;
        cout << "W prawo: " << (int)uc << " -> " << bitset<8>(uc) << " -> " << bitset<8>(uc >> 1) << endl;
    }

    cout << "\n=== Przesuwanie bitow dla INT (zakres 0..255 i 255..0) ===\n";
    for (int i = 0; i <= 255; ++i)
    {
        cout << "W lewo:  " << i << " -> " << bitset<8>(i) << " -> " << bitset<8>(i << 1) << endl;
        cout << "W prawo: " << i << " -> " << bitset<8>(i) << " -> " << bitset<8>(i >> 1) << endl;
    }
    cout << "\n--- Odwrotnie (255 do 0) ---\n";
    for (int i = 255; i >= 0; --i)
    {
        cout << "W lewo:  " << i << " -> " << bitset<8>(i) << " -> " << bitset<8>(i << 1) << endl;
        cout << "W prawo: " << i << " -> " << bitset<8>(i) << " -> " << bitset<8>(i >> 1) << endl;
    }

    return 0;
}
