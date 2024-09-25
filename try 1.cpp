#include <iostream>
#include <string>
using namespace std;

void enkripsi() {
    string plainteks, cipherteks;
    int i, k;
    char c;

    cout << "Ketikkan pesan: ";
    cin.ignore(); // Bersihkan buffer
    getline(cin, plainteks); // Ambil seluruh input plainteks
    cout << "Masukkan jumlah pergeseran (0-25): ";
    cin >> k;

    for (i = 0; i < plainteks.length(); i++) {
        c = plainteks[i];
        if (isalpha(c)) {
            c = toupper(c); // Ubah menjadi huruf kapital
            c = c - 'A';
            c = (c + k) % 26; // Enkripsi dengan pergeseran
            c = c + 'A';
        }
        cipherteks = cipherteks + c;
    }
    cout << "Cipherteks: " << cipherteks << endl;
}

void dekripsi() {
    string plainteks, cipherteks;
    int i, k;
    char c;

    cout << "Ketikkan cipherteks: ";
    cin.ignore(); // Bersihkan buffer input sebelum membaca
    getline(cin, cipherteks); // Ambil seluruh input cipherteks

    cout << "Masukkan jumlah pergeseran (0-25): ";
    cin >> k;

    for (i = 0; i < cipherteks.length(); i++) {
        c = cipherteks[i];
        if (isalpha(c)) {
            c = toupper(c); // Ubah menjadi huruf kapital
            c = c - 'A';
            c = (c - k + 26) % 26; // Dekripsi dengan pergeseran, pastikan tidak negatif
            c = c + 'A';
            c = tolower(c); // Ubah kembali ke huruf kecil
        }
        plainteks = plainteks + c;
    }
    cout << "Plainteks: " << plainteks << endl;
}

int main() {
    int pil;
    bool stop = false;
    while (!stop) {
        cout << "Menu" << endl;
        cout << "1. Enkripsi" << endl;
        cout << "2. Dekripsi" << endl;
        cout << "3. Exit" << endl;
        cout << "Pilih menu: "; 
        cin >> pil;
        
        switch (pil) {
            case 1: enkripsi(); break;
            case 2: dekripsi(); break;
            case 3: stop = true; break;
            default: cout << "Pilihan tidak valid!" << endl; break;
        }
    }
}

