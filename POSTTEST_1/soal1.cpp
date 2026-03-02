#include <iostream>
using namespace std;

/*ANALISIS PSEUDOCODE + COST
Pseudocode:
1  min ← A[0]
2  for i ← 1 to n-1 do
3      if A[i] < min then
4          min ← A[i]
5      end if
6  end for
7  return min
8 end procedure

PSEUDOCODE          | COST | Tmin | Tmax |
procedure FindMin   |  C1  |  1   |  1   |
min <- A[0]         |  C2  |  1   |  1   |
for i <- 1 to n-1   |  C3  |  n   |  n   |
if A[i] < min       |  C4  |  n-1 |  n-1 |
min <- A[i]         |  C5  |  0   |  n-1 |
end if              |  C6  |  n-1 |  n-1 |
end for             |  C7  |  n   |  n   |
return min          |  C8  |  1   |  1   |
end procedure       |  C9  |  1   |  1   |

Tmin : If tidak pernah benar karena data sudah terurut naik, tidak pernah update min, baris 5 tidak dijalankan
Tmax : If hampir selalu benar karena data terurut turun, min selalu di update

BEST CASE:
Dalam array Fibonnaci {1, 1, 2, 3, 5, 8, 13, 21} akan selalu mengecek dan membandingkan setiap nilai.
Dalam indeks 0 di array adalah angka 1. Program mengasumsikan nilai minimum ada di indeks 0.
Program membandingkan angka 1 di indeks 0 dengan yang lain apakah lebih kecil dari angka 1 di indeks 0
Jika If tidak memenuhi, maka program mengembalikan nilai minimum dan indeks minimum

WORST CASE:
Array Fibonnaci dibalik menjadi {21, 13, 8, 5, 3, 2, 1, 1}. Program mengasumsikan bahwa nilai minimum ada di indeks 0, yaitu 23.
Indeks 0 di array itu adalah 23 dan akan dibandingkan dengan semua angka yang ada dalam array.
If hampir selalu memenuhi dan nilai minimum serta indeks minimum akan selalu update, kecuali yang
terakhir karena 1 < 1 adalah false sehingga mengembalikan nilai minimum, yaitu 1 di indeks 6.

Tmin (BEST CASE) = 1 + 1 + n + (n-1) + 0 + (n-1) + n + 1 + 1 = 4n + 2
Tmax (WORST CASE) = 1 + 1 + n + (n-1) + (n-1) + (n-1) + n + 1 + 1 = 5n + 1

Big O-Case
Karena linear, maka kompleksitasnya O(n) 
Tmin -> O(n)
Tmax -> O(n)

*/

int FindMin(int Angka[], int n, int &indexMin){
    int min = Angka[0];
    indexMin = 0;

    for (int i = 1; i < n; i++){
        if (Angka[i] < min){
            min = Angka[i];
            indexMin = i;
        }
    }
    return min;
}

int main(){
    int AngkaFibonacci[8] = {21, 13, 8, 5, 3, 2, 1, 1};
    int n = 8;
    int indexMin;

    int minimum = FindMin(AngkaFibonacci, n, indexMin);
    cout << "Array: ";
    for (int i = 0; i < n; i++){
        cout << AngkaFibonacci[i] << " ";
    }
    cout << endl;
    cout << "Nilai minimum: " << minimum << endl;
    cout << "Indeks minimum: " << indexMin << endl;
    return 0;
}
