#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

using namespace std;

void saveMatrixToFile(const string &filename, const vector<vector<int>> &matrix)
{
    ofstream out(filename, ios::binary);
    if (!out)
    {
        cerr << "Blad zapisu do pliku!" << endl;
        return;
    }

    int rows = matrix.size();
    int cols = matrix[0].size();
    out.write((char *)&rows, sizeof(rows));
    out.write((char *)&cols, sizeof(cols));

    for (const auto &row : matrix)
        out.write((char *)row.data(), cols * sizeof(int));

    out.close();
}

void displayMatrix(const vector<vector<int>> &matrix)
{
    for (const auto &row : matrix)
    {
        for (int val : row)
        {
            cout << val << '\t';
        }
        cout << endl;
    }
}

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        cout << "Uzycie: " << argv[0] << " <plik> <wiersze> <kolumny>\n";
        return 1;
    }

    string filename = argv[1];
    int rows = atoi(argv[2]);
    int cols = atoi(argv[3]);

    if (rows <= 0 || cols <= 0)
    {
        cerr << "Niepoprawne wymiary macierzy.\n";
        return 2;
    }

    vector<vector<int>> matrix(rows, vector<int>(cols));
    int counter = 1;

    // Wypelnianie
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            matrix[i][j] = counter++;

    // Wyswietlenie
    cout << "Zawartosc macierzy:\n";
    displayMatrix(matrix);

    saveMatrixToFile(filename, matrix);

    return 0;
}
