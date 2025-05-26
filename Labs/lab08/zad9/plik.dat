#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>
#include <sys/stat.h>

using namespace std;

void copyBinary(int src_fd, int dst_fd, const string &mode)
{
    const int BUF_SIZE = 1024;
    char buffer[BUF_SIZE];
    ssize_t bytesRead, bytesWritten, totalRead = 0;

    struct stat st;
    fstat(src_fd, &st);
    off_t fileSize = st.st_size;

    while ((bytesRead = read(src_fd, buffer, BUF_SIZE)) > 0)
    {
        bytesWritten = write(dst_fd, buffer, bytesRead);
        if (bytesWritten != bytesRead)
        {
            cerr << "Blad zapisu danych.\n";
            break;
        }

        totalRead += bytesWritten;

        if (mode == "-p")
        {
            int percent = (int)((double)totalRead / fileSize * 100);
            cout << "\rPostep: " << percent << "%" << flush;
        }
        else if (mode == "-b")
        {
            cout << "\rSkopiowano: " << totalRead << " / " << fileSize << " bajtow" << flush;
        }
    }

    cout << "\nKopiowanie zakonczone.\n";
}

int main(int argc, char *argv[])
{
    if (argc < 3 || argc > 4)
    {
        cerr << "Uzycie: ./prog plik_zrodlowy plik_docelowy [-p|-b]\n";
        return 1;
    }

    string src = argv[1];
    string dst = argv[2];
    string mode = (argc == 4) ? argv[3] : "";

    int in_fd = open(src.c_str(), O_RDONLY);
    if (in_fd < 0)
    {
        perror("Blad otwarcia pliku zrodlowego");
        return 1;
    }

    int out_fd = open(dst.c_str(), O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (out_fd < 0)
    {
        perror("Blad otwarcia pliku docelowego");
        close(in_fd);
        return 1;
    }

    copyBinary(in_fd, out_fd, mode);

    close(in_fd);
    close(out_fd);
    return 0;
}
