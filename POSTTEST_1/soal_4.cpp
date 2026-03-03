#include <iostream>
using namespace std;

/*Last soal*/

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x, y;

    // Validasi input x
    cout << "Masukkan nilai x (Cuma boleh Angka): ";
    while (!(cin >> x)) {
        cout << "Angka Woi!: ";
        cin.clear();              // reset error flag
        cin.ignore(1000, '\n');   // buang input salah
    }

    // Validasi input y
    cout << "Masukkan nilai y (Cuma boleh Angka): ";
    while (!(cin >> y)) {
        cout << "Angka doang bos, Haram Huruf ";
        cin.clear();
        cin.ignore(1000, '\n');
    }

    cout << "\nSebelum swap:\n";
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    swap(&x, &y);

    cout << "\nSetelah swap:\n";
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    return 0;
}
