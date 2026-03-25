#include <iostream>
#include <string>
using namespace std;

struct Hewan {
    int id;
    string nama;
    string jenis;
    int harga;
};

const int MAX = 100;
int jumlah = 0;

// ================== SWAP POINTER ==================
void swapHewan(Hewan *a, Hewan *b) {
    Hewan temp = *a;
    *a = *b;
    *b = temp;
}

// ================== TAMBAH DATA ==================
void tambahData(Hewan *arr, int &n) { // pakai referensi pointer (&)
    cout << "\nTambah Data Hewan\n";
    cout << "ID: "; cin >> (arr + n)->id;
    cout << "Nama: "; cin >> (arr + n)->nama;
    cout << "Jenis: "; cin >> (arr + n)->jenis;
    cout << "Harga: "; cin >> (arr + n)->harga;
    n++;
}

// ================== TAMPIL DATA ==================
void tampilData(Hewan *arr, int n) {
    cout << "\nData Hewan:\n";
    for (int i = 0; i < n; i++) {
        cout << "ID: " << (arr + i)->id << endl;
        cout << "Nama: " << (arr + i)->nama << endl;
        cout << "Jenis: " << (arr + i)->jenis << endl;
        cout << "Harga: " << (arr + i)->harga << endl;
        cout << "------------------\n";
    }
}

// ================== LINEAR SEARCH ==================
void linearSearch(Hewan *arr, int n, string cari) {
    bool found = false;

    for (int i = 0; i < n; i++) {
        if ((arr + i)->nama == cari) {
            cout << "\nData ditemukan:\n";
            cout << "ID: " << (arr + i)->id << endl;
            cout << "Nama: " << (arr + i)->nama << endl;
            cout << "Jenis: " << (arr + i)->jenis << endl;
            cout << "Harga: " << (arr + i)->harga << endl;
            found = true;
            break;
        }
    }

    if (!found) cout << "Data tidak ditemukan!\n";
}

// ================== FIBONACCI SEARCH ==================
void fibonacciSearch(Hewan *arr, int n, int key) {
    int fibMMm2 = 0;
    int fibMMm1 = 1;
    int fibM = fibMMm2 + fibMMm1;

    while (fibM < n) {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }

    int offset = -1;

    cout << "\nProses Fibonacci Search:\n";

    while (fibM > 1) {
        int i = min(offset + fibMMm2, n - 1);

        cout << "Cek index ke-" << i << " (ID: " << (arr + i)->id << ")\n";

        if ((arr + i)->id < key) {
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        } else if ((arr + i)->id > key) {
            fibM = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        } else {
            cout << "Data ditemukan!\n";
            cout << "Nama: " << (arr + i)->nama << endl;
            return;
        }
    }

    if (fibMMm1 && (arr + offset + 1)->id == key) {
        cout << "Data ditemukan!\n";
        cout << "Nama: " << (arr + offset + 1)->nama << endl;
        return;
    }

    cout << "Data tidak ditemukan!\n";
}

// ================== BUBBLE SORT (NAMA) ==================
void bubbleSort(Hewan *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if ((arr + j)->nama > (arr + j + 1)->nama) {
                swapHewan((arr + j), (arr + j + 1));
            }
        }
    }
    cout << "Data berhasil diurutkan (Nama A-Z)\n";
}

// ================== SELECTION SORT (HARGA) ==================
void selectionSort(Hewan *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if ((arr + j)->harga < (arr + minIndex)->harga) {
                minIndex = j;
            }
        }
        swapHewan((arr + i), (arr + minIndex));
    }
    cout << "Data berhasil diurutkan (Harga termurah)\n";
}

// ================== MAIN ==================
int main() {
    Hewan data[MAX];
    int pilihan;

    do {
        cout << "\n=== Pawcare Petshop ===\n";
        cout << "1. Tambah Data\n";
        cout << "2. Tampil Data\n";
        cout << "3. Cari Nama (Linear)\n";
        cout << "4. Cari ID (Fibonacci)\n";
        cout << "5. Sort Nama (Bubble)\n";
        cout << "6. Sort Harga (Selection)\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahData(data, jumlah);
                break;
            case 2:
                tampilData(data, jumlah);
                break;
            case 3: {
                string nama;
                cout << "Masukkan nama: ";
                cin >> nama;
                linearSearch(data, jumlah, nama);
                break;
            }
            case 4: {
                int id;
                cout << "Masukkan ID: ";
                cin >> id;
                fibonacciSearch(data, jumlah, id);
                break;
            }
            case 5:
                bubbleSort(data, jumlah);
                break;
            case 6:
                selectionSort(data, jumlah);
                break;
        }

    } while (pilihan != 0);

    return 0;
}