#include <iostream>
#include <fstream>

using namespace std;

class BacaIris
{
private:
    ifstream ifile; // pointer to file stream
    string namafile; // nama file yang dibaca

public:
    BacaIris(string namafile) { this->namafile = namafile; } // constructor
    void bukaFile() { ifile.open(namafile); } // Fungsi untul membuka file
    void fileRead(); // Fungsi untuk membaca file
    ~BacaIris() { ifile.close(); } // Destructor untuk menutup file
};

void BacaIris::fileRead() 
{
    string baris; // variabel untuk menyimpan baris yang dibaca

    if (ifile.fail()) // jika file gagal dibuka
    {
        cerr << "Error: Gagal membuka file" << endl; //Tampilan pesan yang akan dikeluarkan jika file gagal dibuka.
    }

    while(getline( ifile, baris, ',')) // membaca data-data dari file yang dibatasi dengan delimiter koma (,) akan disimpan di variabel baris
    {
        cout << baris << endl; // tampilkan baris yang telah dibaca
    }
}

int main()  
{
    BacaIris iris("iris.data"); // Membuat objek iris dengan nama file iris.data

    iris.bukaFile();
    iris.fileRead();

    return 0;
}