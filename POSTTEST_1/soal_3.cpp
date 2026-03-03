#include <iostream>
using namespace std;

/*soal 2*/

void reverseArray(int* arr, int n) {
    int* start = arr;
    int* end = arr + n - 1;

    while(start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}

int main() {
    int prima[7] = {2, 3, 5, 7, 11, 13, 17};

    cout << "Array sebelum dibalik:\n";
    for(int i = 0; i < 7; i++) {
        cout << prima[i] << " ";
    }

    cout << "\n\nAlamat memori setiap elemen:\n";
    int* ptr = prima;
    for(int i = 0; i < 7; i++) {
        cout << "Nilai: " << *ptr 
             << " | Alamat: " << ptr << endl;
        ptr++;
    }

    reverseArray(prima, 7);

    cout << "\nArray setelah dibalik:\n";
    for(int i = 0; i < 7; i++) {
        cout << prima[i] << " ";
    }

    return 0;
}