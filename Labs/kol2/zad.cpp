#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

struct Employee
{
    string pesel;
    string name;
    string surname;
    string address;
    Employee *next;
};

Employee *head = nullptr;

bool peselExists(const string &pesel)
{
    for (Employee *p = head; p != nullptr; p = p->next)
        if (p->pesel == pesel)
            return true;
    return false;
}

void addToEnd(const Employee &data)
{
    Employee *newNode = new (nothrow) Employee(data);
    if (!newNode)
    {
        cerr << "Blad: brak pamieci!\n";
        return;
    }
    newNode->next = nullptr;

    if (!head)
    {
        head = newNode;
    }
    else
    {
        Employee *p = head;
        while (p->next)
            p = p->next;
        p->next = newNode;
    }
}

void insertBeforePesel(const string &targetPesel, const Employee &data)
{
    if (peselExists(data.pesel))
    {
        cerr << "PESEL juz istnieje!\n";
        return;
    }

    Employee *newNode = new (nothrow) Employee(data);
    if (!newNode)
    {
        cerr << "Brak pamieci!\n";
        return;
    }

    if (!head)
    {
        cerr << "Lista jest pusta!\n";
        delete newNode;
        return;
    }

    if (head->pesel == targetPesel)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    Employee *p = head;
    while (p->next && p->next->pesel != targetPesel)
    {
        p = p->next;
    }

    if (!p->next)
    {
        cerr << "Nie znaleziono PESEL!\n";
        delete newNode;
        return;
    }

    newNode->next = p->next;
    p->next = newNode;
}

void modifyByPesel(const string &pesel)
{
    Employee *p = head;
    while (p)
    {
        if (p->pesel == pesel)
        {
            cout << "Nowe imie: ";
            cin >> p->name;
            cout << "Nowe nazwisko: ";
            cin >> p->surname;
            cout << "Nowy adres: ";
            cin.ignore();
            getline(cin, p->address);
            return;
        }
        p = p->next;
    }
    cerr << "Nie znaleziono PESEL!\n";
}

void displayForward()
{
    for (Employee *p = head; p; p = p->next)
        cout << p->pesel << " | " << p->name << " " << p->surname << " | " << p->address << endl;
}

void displayBackward(Employee *p)
{
    if (!p)
        return;
    displayBackward(p->next);
    cout << p->pesel << " | " << p->name << " " << p->surname << " | " << p->address << endl;
}

void saveToFile(const string &filename)
{
    ofstream f(filename, ios::binary);
    if (!f)
    {
        cerr << "Blad otwarcia pliku!\n";
        return;
    }

    for (Employee *p = head; p; p = p->next)
    {
        size_t len;

        len = p->pesel.size();
        f.write((char *)&len, sizeof(len));
        f.write(p->pesel.c_str(), len);
        len = p->name.size();
        f.write((char *)&len, sizeof(len));
        f.write(p->name.c_str(), len);
        len = p->surname.size();
        f.write((char *)&len, sizeof(len));
        f.write(p->surname.c_str(), len);
        len = p->address.size();
        f.write((char *)&len, sizeof(len));
        f.write(p->address.c_str(), len);
    }

    f.close();
    cout << "Zapisano do pliku.\n";
}

void loadFromFile(const string &filename)
{
    ifstream f(filename, ios::binary);
    if (!f)
    {
        cerr << "Blad otwarcia pliku!\n";
        return;
    }

    head = nullptr;
    while (f.peek() != EOF)
    {
        Employee emp;
        size_t len;
        char *buf;

        f.read((char *)&len, sizeof(len));
        buf = new char[len + 1];
        f.read(buf, len);
        buf[len] = 0;
        emp.pesel = buf;
        delete[] buf;
        f.read((char *)&len, sizeof(len));
        buf = new char[len + 1];
        f.read(buf, len);
        buf[len] = 0;
        emp.name = buf;
        delete[] buf;
        f.read((char *)&len, sizeof(len));
        buf = new char[len + 1];
        f.read(buf, len);
        buf[len] = 0;
        emp.surname = buf;
        delete[] buf;
        f.read((char *)&len, sizeof(len));
        buf = new char[len + 1];
        f.read(buf, len);
        buf[len] = 0;
        emp.address = buf;
        delete[] buf;

        addToEnd(emp);
    }

    f.close();
    cout << "Wczytano z pliku.\n";
}

void freeList()
{
    while (head)
    {
        Employee *tmp = head;
        head = head->next;
        delete tmp;
    }
}

int main()
{
    int choice;
    string pesel;

    do
    {
        cout << "\n1. Dodaj na koniec\n2. Modyfikuj po PESEL\n3. Wstaw przed PESEL\n4. Pokaz przod\n5. Pokaz tyl\n6. Zapisz\n7. Wczytaj\n0. Wyjscie\n";
        cout << "Wybor: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            Employee e;
            cout << "PESEL: ";
            cin >> e.pesel;
            if (peselExists(e.pesel))
            {
                cerr << "PESEL juz istnieje!\n";
                break;
            }
            cout << "Imie: ";
            cin >> e.name;
            cout << "Nazwisko: ";
            cin >> e.surname;
            cout << "Adres: ";
            cin.ignore();
            getline(cin, e.address);
            addToEnd(e);
            break;
        }
        case 2:
            cout << "PESEL do modyfikacji: ";
            cin >> pesel;
            modifyByPesel(pesel);
            break;
        case 3:
        {
            Employee e;
            cout << "PESEL nowego: ";
            cin >> e.pesel;
            cout << "Imie: ";
            cin >> e.name;
            cout << "Nazwisko: ";
            cin >> e.surname;
            cout << "Adres: ";
            cin.ignore();
            getline(cin, e.address);
            cout << "Wstaw przed PESEL: ";
            string before;
            cin >> before;
            insertBeforePesel(before, e);
            break;
        }
        case 4:
            displayForward();
            break;
        case 5:
            displayBackward(head);
            break;
        case 6:
            saveToFile("pracownicy.dat");
            break;
        case 7:
            loadFromFile("pracownicy.dat");
            break;
        case 0:
            freeList();
            cout << "Zakonczono.\n";
            break;
        default:
            cout << "Nieznana opcja.\n";
        }
    } while (choice != 0);

    return 0;
}
