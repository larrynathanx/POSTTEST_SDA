#include <iostream>
using namespace std;

void ReverseArray(int* arr, int n){
    int *awal = arr;
    int *akhir = arr + n - 1;

    while (awal < akhir){
        int simpanan = *awal;
        *awal = *akhir;
        *akhir = simpanan;
        awal++;
        akhir--;
    }
}

void TampilArray(int* arr, int n){
    int *ptr = arr;
    n = 7;
    for (int i = 0; i < n; i++){
        cout << "Nilai: " << *ptr << " |" << " Alamat: " << ptr << endl;
        ptr++;
    }
}

int main(){
    int Angka[7] = {2, 3, 5, 7, 11, 13, 17};
    int n = 7;
    cout << "Nilai dan Alamat sebelum dibalik: " << endl;
    TampilArray(Angka, n);
    ReverseArray(Angka, n);
    cout << "\nNilai dan Alamat setelah dibalik: " << endl;
    TampilArray(Angka, n);
    return 0;
}