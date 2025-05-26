#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <fcntl.h>
#include <cstring>

using namespace std;

void wypiszBezBialych(const string &filename)
{
    ifstream file(filename);
    if (!file)
    {
        cerr << "Nie mozna otworzyc pliku.\n";
        return;
    }
    char c;
    while (file.get(c))
    {
        if (!isspace(c))
            cout << c;
    }
    cout << endl;
}

bool porownajPliki(const string &f1, const string &f2)
{
    ifstream file1(f1, ios::binary), file2(f2, ios::binary);
    if (!file1 || !file2)
    {
        cerr << "Blad otwarcia plikow.\n";
        return false;
    }

    char c1, c2;
    while (file1.get(c1) && file2.get(c2))
    {
        if (c1 != c2)
            return false;
    }
    return file1.eof() && file2.eof();
}

int otworzDoDopisaniaNaKoniec(const string &filename)
{
    int fd = open(filename.c_str(), O_WRONLY | O_APPEND | O_CREAT, 0644);
    if (fd == -1)
        perror("Blad otwarcia do dopisania");
    return fd;
}

int otworzDoDopisaniaNaPoczatek(const string &filename)
{
    string bufor;
    ifstream in(filename);
    if (in)
        bufor.assign((istreambuf_iterator<char>(in)), istreambuf_iterator<char>());
    in.close();

    ofstream out(filename);
    if (!out)
    {
        cerr << "Nie mozna otworzyc pliku do nadpisania.\n";
        return -1;
    }

    return open(filename.c_str(), O_WRONLY);
}

void wpiszTekstDoPliku(int fd)
{
    if (fd == -1)
        return;
    string tekst;
    cout << "Podaj tekst do zapisania: ";
    cin.ignore();
    getline(cin, tekst);
    write(fd, tekst.c_str(), tekst.size());
    close(fd);
}

int main()
{
    cout << "Zadanie 7\n";

    string f1 = "plik1.txt", f2 = "plik2.txt";

    wypiszBezBialych(f1);

    cout << "Pliki sa " << (porownajPliki(f1, f2) ? "identyczne\n" : "rozne\n");

    int fd1 = otworzDoDopisaniaNaKoniec(f1);
    wpiszTekstDoPliku(fd1);

    int fd2 = otworzDoDopisaniaNaPoczatek(f2);
    wpiszTekstDoPliku(fd2);

    return 0;
}
