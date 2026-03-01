#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa{
    string nama;
    string nim;
    float ipk;
};

int main(){
    int n = 5;
    Mahasiswa mhs[n];

    for (int i = 0; i < n; i++){
        cout << "Mahasiswa ke-" << i + 1 << endl;
        cout << "Nama Mahasiswa: ";
        getline(cin, mhs[i].nama);
        cout << "NIM: ";
        getline(cin, mhs[i].nim);
        cout << "IPK: ";
        cin >> mhs[i].ipk;
        cin.ignore();
        cout << endl;
    }
    int Max = 0;
    for (int i = 1; i < n; i++){
        if (mhs[i].ipk > mhs[Max].ipk){
            Max = i;
        }
    }
    cout << "\nMahasiswa dengan IPK tertinggi" << endl;
    cout << "Nama Mahasiswa: " << mhs[Max].nama << endl;
    cout << "NIM: " << mhs[Max].nim << endl;
    cout << "IPK: " << mhs[Max].ipk << endl;
    return 0;
}