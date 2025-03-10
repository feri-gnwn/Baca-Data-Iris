#include <iostream>
#include <fstream>

using namespace std;

class BacaIris
{
private:
    ifstream ifile;
    string namafile;

public:
    BacaIris(string namafile) { this->namafile = namafile; }
    void bukaFile() { ifile.open(namafile); }
    void fileRead();
    ~BacaIris() { ifile.close(); }
};

void BacaIris::fileRead()
{
    string baris;

    if (ifile.fail())
    {
        cerr << "Error: Gagal membuka file" << endl;
    }

    while(getline( ifile, baris, ','))
    {
        cout << baris << endl;
    }
}

int main()
{
    BacaIris iris("iris.data");

    iris.bukaFile();
    iris.fileRead();

    return 0;
}