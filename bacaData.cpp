#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class BacaIris
{
private:
    ifstream ifile;
    string namafile;

public:
    BacaIris(string namafile) { this->namafile = namafile; }
    ~BacaIris() { ifile.close(); }
    void bukaFile() { ifile.open(namafile); }
    void fileRead();
};

void BacaIris::fileRead()
{
    string line;

    while (getline(ifile, line))
    {
        stringstream ss(line);
        string word;

        while (getline(ss, word, ','))
        {
            cout << word << endl;
        }
    }

    ifile.close();
}

int main()
{
    BacaIris iris("iris.data");

    iris.bukaFile();
    iris.fileRead();

    return 0;
}