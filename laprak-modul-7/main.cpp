#include "stack.h"

int main()
{
    cout << "=== BAGIAN 1: STACK DASAR ===" << endl;
    cout << "Hello world!" << endl;
    Stack S1;
    createStack(S1);
    push(S1, 3);
    push(S1, 4);
    push(S1, 8);
    pop(S1);
    push(S1, 2);
    push(S1, 3);
    pop(S1);
    push(S1, 9);

    printInfo(S1);
    cout << "balik stack" << endl;
    balikStack(S1);
    printInfo(S1);
    cout << endl;

    // ==========================================
    // BAGIAN 2: Main Push Ascending (Gambar 7-14)
    // ==========================================
    cout << "=== BAGIAN 2: PUSH ASCENDING ===" << endl;
    cout << "Hello world!" << endl;
    Stack S2;
    createStack(S2);
    pushAscending(S2, 3);
    pushAscending(S2, 4);
    pushAscending(S2, 8);
    pushAscending(S2, 2);
    pushAscending(S2, 3);
    pushAscending(S2, 9);

    printInfo(S2);
    cout << "balik stack" << endl;
    balikStack(S2);
    printInfo(S2);
    cout << endl;

    // ==========================================
    // BAGIAN 3: Main Input Stream (Gambar 7-16)
    // ==========================================
    cout << "=== BAGIAN 3: INPUT STREAM ===" << endl;
    cout << "Hello world!" << endl;
    Stack S3;
    createStack(S3);

    cout << "Masukkan angka berderet lalu tekan Enter (Contoh: 4729601): ";
    getInputStream(S3);

    printInfo(S3);
    cout << "balik stack" << endl;
    balikStack(S3);
    printInfo(S3);

    return 0;
}