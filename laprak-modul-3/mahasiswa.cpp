#include <iostream>
#include <string>
using namespace std;

// Definisi struktur data mahasiswa
struct Mahasiswa {
    string nama;
    string nim;
    float uts;
    float uas;
    float tugas;
    float nilaiAkhir;
};

// FUNGSI untuk menghitung nilai akhir
float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return (0.3 * uts) + (0.4 * uas) + (0.3 * tugas);
}

int main() {
    Mahasiswa mhs[10];
    int jumlah;
    
    cout << "Masukkan jumlah mahasiswa (max 10): ";
    cin >> jumlah;
    
    if(jumlah > 10) jumlah = 10;

    // Input data
    for(int i = 0; i < jumlah; i++) {
        cout << "\nData Mahasiswa ke-" << i+1 << endl;
        cout << "Nama  : "; cin.ignore(); getline(cin, mhs[i].nama);
        cout << "NIM   : "; cin >> mhs[i].nim;
        cout << "Nilai UTS   : "; cin >> mhs[i].uts;
        cout << "Nilai UAS   : "; cin >> mhs[i].uas;
        cout << "Nilai Tugas : "; cin >> mhs[i].tugas;
        
        // Memanggil fungsi hitung nilai akhir
        mhs[i].nilaiAkhir = hitungNilaiAkhir(mhs[i].uts, mhs[i].uas, mhs[i].tugas);
    }
    
    // Tampilkan data
    cout << "\n--- Rekap Nilai Mahasiswa ---\n";
    for(int i = 0; i < jumlah; i++) {
        cout << mhs[i].nama << " (" << mhs[i].nim << ") - Nilai Akhir: " << mhs[i].nilaiAkhir << endl;
    }

    return 0;
}