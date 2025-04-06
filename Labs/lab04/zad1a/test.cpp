#include <iostream>
#include <bitset>

using namespace std;

// void d2b(unsigned char);

int main()
{

    // int x = 2, y = 3, z;

    // z = (x, x++, y = ++x + y++);
    // // z = (x, y++);
    // printf("%d %d %d\n", x, y, z);

    // bool tt = 1, ff = 0, fint = 23;
    // cout << "fint = " << fint << endl;
    // cout << "tt && ff = " << (tt && ff) << endl;
    // cout << "tt || ff = " << (tt || ff) << endl;

    int s0 = 0x0, s1 = 0x1, s4 = 0x3;

    cout << "s0 = " << s0 << " s1 = " << s1 << " s4 = " << s4 << endl;
    cout << "(s0 & s1)  " << (s0 & s1) << "  " << bitset<3>(s0 & s1) << endl;
    cout << "(s0 | s1)  " << (s0 | s1) << "  " << bitset<3>(s0 | s1) << endl;
    cout << "(!s0 & !s1)  " << (!s0 & !s1) << "  " << bitset<3>(!s0 & !s1) << endl;
    cout << "(!s0 ^ !s1)  " << (!s0 ^ !s1) << "  " << bitset<3>(!s0 ^ !s1) << endl;
    cout << !s4 << " " << (255 << 1) << endl;
    cout << (255 & -8) << " " << bitset<8>(255 & -8) << endl;
    return 0;
}