#include <iostream>
using namespace std;

void tukarBilangan(int* a, int*b){
    int simpan = *a;
    *a = *b;
    *b = simpan;
}

int main(){
    int bilangan1, bilangan2;
    cout << "Masukkan bilangan pertama (a): "; cin >> bilangan1;
    cout << "Masukkan bilangan kedua (b): "; cin >> bilangan2;
    cout << "Sebelum ditukar: ";
    cout << "a = " << bilangan1 << ", b = " << bilangan2 << endl;

    tukarBilangan(&bilangan1, &bilangan2);
    cout << "Setelah ditukar: ";
    cout << "a = " << bilangan1 << ", b = " << bilangan2 << endl;
    return 0;
}