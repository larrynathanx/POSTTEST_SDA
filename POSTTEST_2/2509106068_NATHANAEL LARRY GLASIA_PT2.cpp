#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

struct Kereta{
    int NomorKereta;
    string NamaKereta;
    string asal;
    string tujuan;
    string jadwal;
    int HargaTiket;
};

int JumlahData = 0;

void swap(Kereta *a, Kereta *b){
    Kereta simpan = *a;
    *a = *b;
    *b = simpan;
}

void TampilkanData(Kereta *arr, int k){
    if (JumlahData == 0){
    cout << "Data kereta belum ada";
    return;
    }
    cout << "\nDATA KERETA\n";
    cout << "============================================================================================================\n";

    cout << left << setw(5) << "No";
    cout << setw(15) << "Nomor Kereta";
    cout << setw(25) << "Nama Kereta";
    cout << setw(20) << "Asal";
    cout << setw(20) << "Tujuan";
    cout << setw(15) << "Jadwal";
    cout << setw(15) << "Harga" << endl;

    cout << "============================================================================================================\n";

    for (int i = 0; i < k; i++){
        cout << left << setw(5) << i + 1;
        cout << setw(15) << (arr + i)->NomorKereta;
        cout << setw(25) << (arr + i)->NamaKereta;
        cout << setw(20) << (arr + i)->asal;
        cout << setw(20) << (arr + i)->tujuan;
        cout << setw(15) << (arr + i)-> jadwal;
        cout << "Rp" << (arr + i)->HargaTiket << endl;
    }

    cout << "============================================================================================================\n";
}

void TambahData(Kereta* &arr){
    if (JumlahData == 50){
        cout << "Data kereta penuh";
        return;
    }
    cout << "\nNomor Kereta: "; cin >> arr[JumlahData].NomorKereta;
    cin.ignore();
    cout << "Nama Kereta: "; getline(cin, arr[JumlahData].NamaKereta);
    cout << "Asal: "; cin >> arr[JumlahData].asal;
    cout << "Tujuan: "; cin >> arr[JumlahData].tujuan;
    cout << "Jadwal (Contoh 07:30): "; cin >> arr[JumlahData].jadwal;
    cout << "Harga Tiket: "; cin >> arr[JumlahData].HargaTiket;
    JumlahData++;
}

void CariRute(Kereta *arr, int n){
    string asal, tujuan;
    bool ditemukan = false;

    cout << "\nAsal: "; cin >> asal;
    cout << "Tujuan: "; cin >> tujuan;

    for (int i = 0; i < n; i++){
        if ((arr + i) -> asal == asal && (arr + i) -> tujuan == tujuan){
            cout << "\nKereta ditemukan\n";
            cout << "Nomor Kereta: " << (arr + i) -> NomorKereta << endl;
            cout << "Nama Kereta: " << (arr + i) -> NamaKereta << endl;
            cout << "Asal: " << (arr + i) -> asal << endl;
            cout << "Tujuan: " << (arr + i) -> tujuan << endl;
            cout << "Jadwal: " << (arr + i) -> jadwal << endl;
            cout << "Harga tiket: Rp" << (arr + i) -> HargaTiket << endl;
            ditemukan = true;
        }
    }
    if (!ditemukan)
    cout << "Data tidak tersedia!\n";
}

void SortHargaTiket(Kereta *arr, int n){
    for (int i = 0; i < n - 1; i++){
        int TiketMurah = i;
        for (int m = i + 1; m < n; m++){
            if ((arr + m) -> HargaTiket < (arr + TiketMurah) -> HargaTiket)
            TiketMurah = m;
        }
        swap(arr + i, arr + TiketMurah);
    }
    cout << "\nHarga Tiket sudah diurutkan dari harga termurah, silakan pilih 'Tampilkan Rute' pada menu\n";
}

void merge (Kereta *arr, int a, int b, int c){
    int a1 = b - a + 1;
    int a2 = c - b;
    Kereta L[50], R[50];

    for (int i = 0; i < a1; i++)
    L[i] = arr[a + i];

    for (int j = 0; j < a2; j++)
    R[j] = arr[b + 1 + j];
    int i = 0, j = 0, k = a;

    while (i < a1 && j < a2){
        if (L[i].NamaKereta <= R[j].NamaKereta){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < a1){
        arr[k] = L[i];
        i++;
        k++;
    }   

    while (j < a2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

void MergeSort(Kereta *arr, int m, int n){
    if(m < n){
        int l = (m + n)/ 2;
        MergeSort(arr, m, l);
        MergeSort(arr, l + 1, n);
        merge(arr, m, l, n);
    }
}

int JumpSearch(Kereta *arr, int n, int key){
    int step = sqrt(n);
    int prev = 0;
    cout << "\nPencarian:\n";

    while (arr[min(step, n) - 1].NomorKereta < key){
        cout << "Loncat ke index " << step << endl;
        prev = step;
        step += sqrt(n);

        if (prev >= n)
        return -1;
    }
    for (int i = prev; i < min(step, n); i++){
        cout << "Cek index " << i << endl;

        if (arr[i].NomorKereta == key)
        return i;
    }
    return -1;
}

int main(){
    Kereta data[50];
    Kereta *p = data;
    int Menu;

    do{
        cout << "\n==== SISTEM MANAJEMEN KEBERANGKATAN KERETA API ====\n";
        cout << "1. Tambah Data\n";
        cout << "2. Tampilkan Rute\n";
        cout << "3. Cari Rute\n";
        cout << "4. Cari Nomor Kereta\n";
        cout << "5. Urutkan Nama Kereta\n";
        cout << "6. Urutkan Harga Tiket\n";
        cout << "0. Keluar\n";
        cout << "Pilih: "; cin >> Menu;

        switch(Menu){
            case 1:
            TambahData(p);
            break;

            case 2:
            TampilkanData(p, JumlahData);
            break;

            case 3:
            CariRute(p, JumlahData);
            break;

            case 4:{
                int key;
                cout << "Masukkan nomor kereta: "; cin >> key;

                int hasil = JumpSearch(p, JumlahData, key);

                if (hasil!= -1)
                cout << "Nomor kereta ditemukan: " << data[hasil].NamaKereta << endl;
                else
                cout << "Tidak ditemukan!\n";
            }
            break;

            case 5: 
            MergeSort(p, 0, JumlahData - 1);
            cout << "Data sudah diurutkan berdasarkan nama, silakan pilih 'Tampilkan Rute' pada menu\n";
            break;

            case 6:
            SortHargaTiket(p, JumlahData);
            break;
        }
    } while(Menu != 0);
    return 0;
}