#include <iostream>
#include "pelajaran.h"
using namespace std;

pelajaran create_pelajaran(string namapel, string kodepel)
{
    pelajaran p;
    p.namaMapel = namapel;
    p.kodeMapel = kodepel;
    return p;
}

void tampil_pelajaran(pelajaran pel)
{
    cout << "nama pelajaran : " << pel.namaMapel << endl;
    // Berdasarkan gambar contoh output, kode mapel dicetak dengan label "nilai :"
    cout << "nilai : " << pel.kodeMapel << endl;
}