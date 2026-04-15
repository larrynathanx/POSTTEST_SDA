#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;
#define MAX 50

struct Kereta{
    int NomorKereta;
    string NamaKereta;
    string asal;
    string tujuan;
    string jadwal;
    int HargaTiket;
};

struct Transaksi{
    string NamaPenumpang;
    string NamaKereta;
    string asal;
    string tujuan;
    Transaksi *next;
};

int JumlahData = 0;

void swap(Kereta *a, Kereta *b){
    Kereta simpan = *a;
    *a = *b;
    *b = simpan;
}

void Enqueue(Transaksi *&front, Transaksi *&rear){
    Transaksi *baru = new Transaksi;

    cin.ignore();
    cout << "Nama Penumpang: ";
    getline(cin, baru->NamaPenumpang);
    cout << "Nama Kereta: ";
    getline(cin, baru->NamaKereta);
    cout << "Asal: ";
    getline(cin, baru->asal);
    cout << "Tujuan: ";
    getline(cin, baru->tujuan);

    baru->next = NULL;

    if (rear == NULL){
        front = rear = baru;
    } else {
        rear->next = baru;
        rear = baru;
    }

    cout << "Penumpang masuk antrian\n";
}

void Dequeue(Transaksi *&front, Transaksi *&rear, Transaksi *&top){
    if (front == NULL){
        cout << "Antrian kosong (Underflow)\n";
        return;
    }

    Transaksi *hapus = front;

    cout << "\nMemproses tiket:\n";
    cout << hapus->NamaPenumpang << " | "  << hapus->asal << " -> " << hapus->tujuan << endl;

    Transaksi *baru = new Transaksi;
    *baru = *hapus;
    baru->next = top;
    top = baru;

    front = front->next;
    if (front == NULL) rear = NULL;

    delete hapus;
}

void PopRiwayat(Transaksi *&top){
    if (top == NULL){
        cout << "Riwayat kosong (Underflow)\n";
        return;
    }

    Transaksi *hapus = top;
    cout << "Hapus: " << top->NamaPenumpang << endl;

    top = top->next;
    delete hapus;
}

void PeekQueue(Transaksi *front){
    if (front == NULL){
        cout << "Antrian kosong (Underflow)\n";
        return;
    }

    cout << "\nTerdepan: " << front->NamaPenumpang << endl;
}

void PeekStack(Transaksi *top){
    if (top == NULL){
        cout << "Riwayat kosong (Underflow)\n";
        return;
    }

    cout << "Terakhir: " << top->NamaPenumpang << endl;
}

void TampilkanAntrian(Transaksi *front){
    if (front == NULL){
        cout << "Antrian kosong\n";
        return;
    }

    cout << "\nDAFTAR ANTRIAN:\n";
    Transaksi *p = front;
    while (p != NULL){
        cout << "- " << p->NamaPenumpang << " | " << p->asal << " -> " << p->tujuan << endl;
        p = p->next;
    }
}

void TampilkanRiwayat(Transaksi *top){
    if (top == NULL){
        cout << "Riwayat kosong\n";
        return;
    }

    cout << "\nRIWAYAT:\n";
    Transaksi *p = top;
    while (p != NULL){
        cout << "- " << p->NamaPenumpang << " | " << p->asal << " -> " << p->tujuan << endl;
        p = p->next;
    }
}

void TampilkanRute(Kereta *arr, int k){
    if (k == 0){
    cout << "Data kereta belum ada";
    return;
    }
    cout << "\nDATA KERETA\n";
    for(int i = 0; i < k; i++){
        cout << i+1 << ". " << (arr + i)->NamaKereta << " | " << (arr+i)->asal << " -> " << (arr+i)->tujuan << " | Rp" << (arr+i)->HargaTiket << endl;
    }
}

void TambahRute(Kereta *arr){
    if (JumlahData == MAX){
        cout << "Data kereta penuh";
        return;
    }
    cout << "\nNomor Kereta: "; cin >> arr[JumlahData].NomorKereta;
    cin.ignore();
    cout << "Nama Kereta: "; getline(cin, arr[JumlahData].NamaKereta);
    cout << "Asal: "; getline(cin, arr[JumlahData].asal);
    cout << "Tujuan: "; getline(cin, arr[JumlahData].tujuan);
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
    Kereta L[MAX], R[MAX];

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
    if (n == 0){
        cout << "Data kosong\n";
        return -1;
    }
    int step = sqrt(n);
    int prev = 0;
    cout << "\nPencarian:\n";

    while (step < n && arr[min(step, n) - 1].NomorKereta < key){
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
    Transaksi *front = NULL;
    Transaksi *rear = NULL;
    Transaksi *top = NULL;
    Kereta data[MAX];
    int Menu;

    do{
        cout << "\n==== SISTEM MANAJEMEN KEBERANGKATAN KERETA API ====\n";
        cout << "1. Tambah Rute\n";
        cout << "2. Tampilkan Rute\n";
        cout << "3. Cari Rute\n";
        cout << "4. Cari Nomor Kereta\n";
        cout << "5. Urutkan Nama Kereta\n";
        cout << "6. Urutkan Harga Tiket\n";
        cout << "7. Ambil Antrian (Enqueue)\n";
        cout << "8. Proses Tiket (Dequeue)\n";
        cout << "9. Tampilkan Antrian\n";
        cout << "10. Tampilkan Riwayat\n";
        cout << "11. Peek Antrian & Riwayat\n";
        cout << "12. Hapus Riwayat Terakhir (Pop)\n";
        cout << "0. Keluar\n";
        cout << "===================================================\n";
        cout << "Pilih: "; cin >> Menu;

        switch(Menu){
            case 1:
            TambahRute(data);
            break;

            case 2:
            TampilkanRute(data, JumlahData);
            break;

            case 3:
            CariRute(data, JumlahData);
            break;

            case 4:{
                int key;
                cout << "Masukkan nomor kereta: "; cin >> key;

                int hasil = JumpSearch(data, JumlahData, key);

                if (hasil!= -1)
                cout << "Nomor kereta ditemukan: " << data[hasil].NamaKereta << endl;
                else
                cout << "Tidak ditemukan!\n";
            }
            break;

            case 5: 
            if (JumlahData == 0){
                cout << "Data kosong\n";
                break;
            }
            MergeSort(data, 0, JumlahData - 1);
            cout << "Data sudah diurutkan berdasarkan nama, silakan pilih 'Tampilkan Rute' pada menu\n";
            break;

            case 6:
            if (JumlahData == 0){
                cout << "Data kosong\n";
                break;
            }
            SortHargaTiket(data, JumlahData);
            break;

            case 7:
            Enqueue(front, rear);
            break;

            case 8:
            Dequeue(front, rear, top);
            break;

            case 9:
            TampilkanAntrian(front);
            break;

            case 10:
            TampilkanRiwayat(top);
            break;

            case 11:
            PeekQueue(front);
            PeekStack(top);
            break;

            case 12:
            PopRiwayat(top);
            break;
        }
    } while(Menu != 0);
    return 0;
}