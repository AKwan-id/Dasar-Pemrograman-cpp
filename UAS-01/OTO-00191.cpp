#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

struct Sparepart {
    string nama;
    string satuan;
    int jumlah;
    long long harga;

    long long totalHarga() const {
        return harga * jumlah;
    }
};

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int inputInt(const string& prompt, int minVal = 0) {
    int x;
    while (true) {
        cout << prompt;
        if (cin >> x && x >= minVal) {
            clearInput();
            return x;
        }
        cout << "Input tidak valid.\n";
        clearInput();
    }
}

long long inputLL(const string& prompt, long long minVal = 0) {
    long long x;
    while (true) {
        cout << prompt;
        if (cin >> x && x >= minVal) {
            clearInput();
            return x;
        }
        cout << "Input tidak valid.\n";
        clearInput();
    }
}

string inputString(const string& prompt) {
    string s;
    do {
        cout << prompt;
        getline(cin, s);
    } while (s.empty());
    return s;
}

void tampilkanData(const vector<Sparepart>& data) {
    if (data.empty()) {
        cout << "Data kosong.\n";
        return;
    }

    cout << "\nDAFTAR SPAREPART\n";
    cout << left << setw(5) << "No"
         << setw(20) << "Nama"
         << setw(10) << "Satuan"
         << right << setw(10) << "Jumlah"
         << setw(15) << "Harga"
         << setw(15) << "Total\n";

    cout << string(75, '-') << "\n";

    long long totalStok = 0;
    int totalBarang = 0;

    for (size_t i = 0; i < data.size(); i++) {
        cout << left << setw(5) << i + 1
             << setw(20) << data[i].nama
             << setw(10) << data[i].satuan
             << right << setw(10) << data[i].jumlah
             << setw(15) << data[i].harga
             << setw(15) << data[i].totalHarga() << "\n";

        totalStok += data[i].totalHarga();
        totalBarang += data[i].jumlah;
    }

    cout << "Total Barang : " << totalBarang << "\n";
    cout << "Nilai Semua Stok : " << totalStok << "\n";
}

void tambahData(vector<Sparepart>& data) {
    int n = inputInt("Masukkan jumlah data (minimal 3): ", 3);

    for (int i = 0; i < n; i++) {
        Sparepart sp;
        cout << "\nData ke-" << i + 1 << "\n";
        sp.nama = inputString("Nama Barang : ");
        sp.satuan = inputString("Satuan      : ");
        sp.jumlah = inputInt("Jumlah      : ", 0);
        sp.harga = inputLL("Harga       : ", 0);
        data.push_back(sp);
    }
}

void editData(vector<Sparepart>& data) {
    if (data.empty()) return;
    int idx = inputInt("Pilih nomor data yang diedit: ", 1) - 1;
    if (idx < 0 || idx >= (int)data.size()) return;

    data[idx].nama = inputString("Nama baru   : ");
    data[idx].satuan = inputString("Satuan baru : ");
    data[idx].jumlah = inputInt("Jumlah baru : ", 0);
    data[idx].harga = inputLL("Harga baru  : ", 0);
}

void hapusData(vector<Sparepart>& data) {
    if (data.empty()) return;
    int idx = inputInt("Pilih nomor data yang dihapus: ", 1) - 1;
    if (idx < 0 || idx >= (int)data.size()) return;
    data.erase(data.begin() + idx);
}

void programSparepart() {
    vector<Sparepart> data;
    int pilih;

    do {
        cout << "\nPROGRAM 1 - PENDATAAN SPAREPART\n";
        cout << "1. Input Data\n";
        cout << "2. Tampilkan Data\n";
        cout << "3. Edit Data\n";
        cout << "4. Hapus Data\n";
        cout << "0. Kembali\n";
        cout << "Pilih: ";
        cin >> pilih;
        clearInput();

        if (pilih == 1) tambahData(data);
        else if (pilih == 2) tampilkanData(data);
        else if (pilih == 3) editData(data);
        else if (pilih == 4) hapusData(data);

    } while (pilih != 0);
}

void hitungGanjilGenap(int i, int n, int& ganjil, int& genap) {
    if (i > n) return;
    if (i % 2 == 0) genap++;
    else ganjil++;
    hitungGanjilGenap(i + 1, n, ganjil, genap);
}

int jumlahRekursif(int A, int B) {
    if (B == 0) return A;
    return jumlahRekursif(A + 1, B - 1);
}

void programRekursif() {
    int pilih;
    do {
        cout << "\nPROGRAM 2 - REKURSIF\n";
        cout << "1. Hitung Ganjil & Genap\n";
        cout << "2. Penjumlahan Rekursif\n";
        cout << "0. Kembali\n";
        cout << "Pilih: ";
        cin >> pilih;
        clearInput();

        if (pilih == 1) {
            int n = inputInt("Masukkan jumlah urutan data: ", 1);
            int ganjil = 0, genap = 0;
            hitungGanjilGenap(1, n, ganjil, genap);
            cout << "Jumlah Bilangan Ganjil : " << ganjil << "\n";
            cout << "Jumlah Bilangan Genap  : " << genap << "\n";
        }
        else if (pilih == 2) {
            int A = inputInt("Masukkan A: ", 0);
            int B = inputInt("Masukkan B: ", 0);
            cout << "Jumlah bilangan: " << jumlahRekursif(A, B) << "\n";
        }

    } while (pilih != 0);
}

int main() {
    int pilih;
    do {
        cout << "\nMENU UTAMA\n";
        cout << "1. Program Sparepart\n";
        cout << "2. Program Rekursif\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;
        clearInput();

        if (pilih == 1) programSparepart();
        else if (pilih == 2) programRekursif();

    } while (pilih != 0);

    return 0;
}
