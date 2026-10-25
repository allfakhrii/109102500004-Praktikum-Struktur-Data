#include <iostream>
using namespace std;

// Fungsi menampilkan isi array integer 2D
void tampilArray(int arr[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

// Fungsi menukarkan isi dari 2 array integer 2D pada posisi tertentu (baris, kolom)
void tukarIsiArray(int arr1[3][3], int arr2[3][3], int baris, int kolom)
{
    int temp = arr1[baris][kolom];
    arr1[baris][kolom] = arr2[baris][kolom];
    arr2[baris][kolom] = temp;
}

// Fungsi menukarkan isi variabel yang ditunjuk oleh 2 buah pointer
void tukarIsiPointer(int *ptr1, int *ptr2)
{
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

int main()
{
    // 2 buah array 2D integer berukuran 3x3
    int arrayA[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int arrayB[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};

    // 2 buah pointer integer
    int var1 = 100, var2 = 999;
    int *p1 = &var1;
    int *p2 = &var2;

    cout << "=== Test Fungsi Array ===" << endl;
    cout << "Array A awal:\n";
    tampilArray(arrayA);
    cout << "\nArray B awal:\n";
    tampilArray(arrayB);

    cout << "\nMenukar posisi [1][1] (tengah)..." << endl;
    tukarIsiArray(arrayA, arrayB, 1, 1);

    cout << "\nArray A sesudah ditukar:\n";
    tampilArray(arrayA);
    cout << "\nArray B sesudah ditukar:\n";
    tampilArray(arrayB);

    cout << "\n=== Test Fungsi Pointer ===" << endl;
    cout << "Isi p1 awal: " << *p1 << ", p2 awal: " << *p2 << endl;
    tukarIsiPointer(p1, p2);
    cout << "Isi p1 akhir: " << *p1 << ", p2 akhir: " << *p2 << endl;

    return 0;
}