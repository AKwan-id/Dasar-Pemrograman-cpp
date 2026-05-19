#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

struct Buku {
    string kode, judul, penulis;
    int tahun, jumlah, harga;
};

int cariBuku(const vector<Buku>& data, const string& kode) {
    for (int i = 0; i < data.size(); i++) {
        if (data[i].kode == kode) return i;
    }
    return -1;
}

int main() {
    vector<Buku> data;
    int pilih;

    while (true) {
        cout << endl;
        cout << "1. Input Buku" << endl;
        cout << "2. Edit Buku" << endl;
        cout << "3. Hapus Buku" << endl;
        cout << "4. Laporan Buku" << endl;
        cout << "5. Keluar Program" << endl;
        cout << "Pilih [1..5] : ";
        cin >> pilih;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (pilih == 5) {
            cout << "Keluar..." << endl;
            break;
        }

        // INPUT BUKU
        if (pilih == 1) {
            Buku b;

            while (true) {
                cout << "Kode   : ";
                getline(cin, b.kode);
                if (b.kode == "") {
                    cout << "Kode Masih Kosong!" << endl;
                } else if (cariBuku(data, b.kode) != -1) {
                    cout << "Kode buku sudah ada!" << endl;
                } else break;
            }

            while (true) {
                cout << "Judul  : ";
                getline(cin, b.judul);
                if (b.judul == "") {
                    cout << "Kode Masih Kosong!" << endl;
                } else break;
            }

            cout << "Penulis: ";
            getline(cin, b.penulis);
            cout << "Tahun  : ";
            cin >> b.tahun;
            cout << "Jumlah : ";
            cin >> b.jumlah;
            cout << "Harga  : ";
            cin >> b.harga;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            data.push_back(b);
            cout << "Data buku berhasil ditambahkan." << endl;
        }

        // EDIT BUKU
        else if (pilih == 2) {
            string kode;
            cout << "Kode buku: ";
            getline(cin, kode);

            int idx = cariBuku(data, kode);
            if (idx == -1) {
                cout << "Kode Buku tidak ditemukan!" << endl;
            } else {
                cout << "Judul baru   : ";
                getline(cin, data[idx].judul);
                if (data[idx].judul == "") {
                    cout << "Kode Masih Kosong!" << endl;
                    continue;
                }
                cout << "Penulis baru : ";
                getline(cin, data[idx].penulis);
                cout << "Tahun baru   : ";
                cin >> data[idx].tahun;
                cout << "Jumlah baru  : ";
                cin >> data[idx].jumlah;
                cout << "Harga baru   : ";
                cin >> data[idx].harga;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "Data buku berhasil diedit." << endl;
            }
        }

        // HAPUS BUKU
        else if (pilih == 3) {
            string kode;
            cout << "Kode buku: ";
            getline(cin, kode);

            int idx = cariBuku(data, kode);
            if (idx == -1) {
                cout << "Kode Buku tidak ditemukan!" << endl;
            } else {
                data.erase(data.begin() + idx);
                cout << "Data buku berhasil dihapus." << endl;
            }
        }

        // LAPORAN BUKU
        else if (pilih == 4) {
            if (data.empty()) {
                cout << "Data masih kosong." << endl;
            } else {
                cout << endl << "=== LAPORAN BUKU ===" << endl;
                cout << left
                     << setw(8)  << "Kode"
                     << setw(15) << "Judul"
                     << setw(12) << "Penulis"
                     << setw(8)  << "Tahun"
                     << right
                     << setw(8)  << "Jumlah"
                     << setw(10) << "Harga"
                     << setw(10) << "Total" << endl;

                for (int i = 0; i < data.size(); i++) {
                    cout << left
                         << setw(8)  << data[i].kode
                         << setw(15) << data[i].judul
                         << setw(12) << data[i].penulis
                         << setw(8)  << data[i].tahun
                         << right
                         << setw(8)  << data[i].jumlah
                         << setw(10) << data[i].harga
                         << setw(10) << data[i].jumlah * data[i].harga
                         << endl;
                }
            }
        }
    }

    return 0;
}
