#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <limits>
#include <fstream>

using namespace std;

struct PresensiHari {
    int jamMasuk = -1;
    int jamKeluar = -1;
};

struct Mahasiswa {
    string nama;
    string nim;
    int jamPlusMinus = 0;
    PresensiHari presensi[7]; // 0: Senin, 1: Selasa, ..., 6: Minggu
};

struct Jadwal {
    int jamMasuk = 7;
    int jamKeluar = 12;
};

vector<Mahasiswa> daftarMahasiswa;
Jadwal jadwal;

Mahasiswa* cariMahasiswa(const string& nim) {
    for (auto& mhs : daftarMahasiswa) {
        if (mhs.nim == nim) return &mhs;
    }
    return nullptr;
}

const char* namaHari[7] = {
    "Senin", "Selasa", "Rabu", "Kamis", "Jumat", "Sabtu", "Minggu"
};

void tampilkanDaftarMahasiswa() {
    cout << left << setw(25) << "Nama"
         << setw(15) << "NIM"
         << setw(15) << "Jam Plus/Minus" << endl;
    cout << string(55, '-') << endl;
    for (const auto& mhs : daftarMahasiswa) {
        cout << left << setw(25) << mhs.nama
             << setw(15) << mhs.nim
             << setw(15) << mhs.jamPlusMinus << endl;
    }
    cout << endl;
}

void tampilkanTabelPresensi(const Mahasiswa* mhs) {
    int totalPlus = 0;
    int totalMinus = 0;
    cout << left << setw(10) << "Hari"
        << setw(15) << "Jam Masuk"
        << setw(15) << "Jam Keluar"
        << setw(20) << "Status Masuk"
        << setw(20) << "Status Keluar" << endl;
    cout << string(80, '-') << endl;
    for (int i = 0; i < 7; ++i) {
        cout << left << setw(10) << namaHari[i];
        // Jam Masuk
        if (mhs->presensi[i].jamMasuk == -1)
            cout << setw(15) << "-";
        else
            cout << setw(15) << mhs->presensi[i].jamMasuk;
        // Jam Keluar
        if (mhs->presensi[i].jamKeluar == -1)
            cout << setw(15) << "-";
        else
            cout << setw(15) << mhs->presensi[i].jamKeluar;

        // Status Masuk
        if (mhs->presensi[i].jamMasuk == -1) {
            cout << setw(20) << "-";
        }
        else if (mhs->presensi[i].jamMasuk < jadwal.jamMasuk) {
            int plus = jadwal.jamMasuk - mhs->presensi[i].jamMasuk;
            totalPlus += plus;
            cout << setw(20) << ("plus(+" + to_string(plus) + ")");
        }
        else if (mhs->presensi[i].jamMasuk > jadwal.jamMasuk) {
            int minus = mhs->presensi[i].jamMasuk - jadwal.jamMasuk;
            totalMinus += minus;
            cout << setw(20) << ("terlambat(-" + to_string(minus) + ")");
        }
        else {
            cout << setw(20) << "Aman";
        }

        // Status Keluar
        if (mhs->presensi[i].jamKeluar == -1) {
            cout << setw(20) << "-";
        }
        else if (mhs->presensi[i].jamKeluar < jadwal.jamKeluar) {
            int minus = jadwal.jamKeluar - mhs->presensi[i].jamKeluar;
            totalMinus += minus;
            cout << setw(20) << ("minus(-" + to_string(minus) + ")");
        }
        else if (mhs->presensi[i].jamKeluar > jadwal.jamKeluar) {
            int plus = mhs->presensi[i].jamKeluar - jadwal.jamKeluar;
            totalPlus += plus;
            cout << setw(20) << ("plus(+" + to_string(plus) + ")");
        }
        else {
            cout << setw(20) << "Aman";
        }
        cout << endl;
    }
    cout << endl;
    cout << "Total Jam Plus   : " << totalPlus << endl;
    cout << "Total Jam Minus  : " << totalMinus << endl;
    cout << "Total Jam Saat Ini: ";
    int total = totalPlus - totalMinus;
    if (total > 0)
        cout << "plus(+" << total << ")" << endl;
    else if (total < 0)
        cout << "minus(" << total << ")" << endl;
    else
        cout << "0" << endl;
    cout << endl;
}

void cetakTabelPresensiKeFile(const Mahasiswa* mhs) {
    int totalPlus = 0;
    int totalMinus = 0;
    std::string filename = mhs->nim + ".txt";
    std::ofstream out(filename);
    if (!out) {
        cout << "Gagal membuat file " << filename << endl;
        return;
    }
    out << "Data Presensi Mahasiswa\n";
    out << "Nama: " << mhs->nama << endl;
    out << "NIM : " << mhs->nim << endl;
    out << left << setw(10) << "Hari"
        << setw(15) << "Jam Masuk"
        << setw(15) << "Jam Keluar"
        << setw(20) << "Status Masuk"
        << setw(20) << "Status Keluar" << endl;
    out << string(80, '-') << endl;
    for (int i = 0; i < 7; ++i) {
        out << left << setw(10) << namaHari[i];
        // Jam Masuk
        if (mhs->presensi[i].jamMasuk == -1)
            out << setw(15) << "-";
        else
            out << setw(15) << mhs->presensi[i].jamMasuk;
        // Jam Keluar
        if (mhs->presensi[i].jamKeluar == -1)
            out << setw(15) << "-";
        else
            out << setw(15) << mhs->presensi[i].jamKeluar;

        // Status Masuk
        if (mhs->presensi[i].jamMasuk == -1) {
            out << setw(20) << "-";
        } else if (mhs->presensi[i].jamMasuk < jadwal.jamMasuk) {
            int plus = jadwal.jamMasuk - mhs->presensi[i].jamMasuk;
            totalPlus += plus;
            out << setw(20) << ("plus(+" + to_string(plus) + ")");
        } else if (mhs->presensi[i].jamMasuk > jadwal.jamMasuk) {
            int minus = mhs->presensi[i].jamMasuk - jadwal.jamMasuk;
            totalMinus += minus;
            out << setw(20) << ("terlambat(-" + to_string(minus) + ")");
        } else {
            out << setw(20) << "Aman";
        }

        // Status Keluar
        if (mhs->presensi[i].jamKeluar == -1) {
            out << setw(20) << "-";
        } else if (mhs->presensi[i].jamKeluar < jadwal.jamKeluar) {
            int minus = jadwal.jamKeluar - mhs->presensi[i].jamKeluar;
            totalMinus += minus;
            out << setw(20) << ("minus(-" + to_string(minus) + ")");
        } else if (mhs->presensi[i].jamKeluar > jadwal.jamKeluar) {
            int plus = mhs->presensi[i].jamKeluar - jadwal.jamKeluar;
            totalPlus += plus;
            out << setw(20) << ("plus(+" + to_string(plus) + ")");
        } else {
            out << setw(20) << "Aman";
        }
        out << endl;
    }
    out << endl;
    out << "Total Jam Plus   : " << totalPlus << endl;
    out << "Total Jam Minus  : " << totalMinus << endl;
    out << "Total Jam Saat Ini: ";
    int total = totalPlus - totalMinus;
    if (total > 0)
        out << "plus(+" << total << ")" << endl;
    else if (total < 0)
        out << "minus(" << total << ")" << endl;
    else
        out << "0" << endl;
    out << endl;
    out.close();
    cout << "Data presensi berhasil dicetak ke file " << filename << endl;
}

void adminMenu() {
    int pilihan;
    do {
        system("cls");
        cout << "Daftar Mahasiswa:\n";
        tampilkanDaftarMahasiswa();

        cout << "-------------------------------------------------------\n";
        cout << "1. Tambah Mahasiswa\n";
        cout << "2. Edit Mahasiswa\n";
        cout << "3. Hapus Mahasiswa\n";
        cout << "4. Lihat Tabel Mahasiswa\n";
        cout << "5. Atur Jadwal Jam Masuk/Keluar\n";
        cout << "6. Cetak Data Presensi Mahasiswa\n";
        cout << "0. Logout\n";
        cout << "Pilih: ";
        cin >> pilihan;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (pilihan == 1) {
            system("cls");
            Mahasiswa mhs;
            cout << "Tambah Mahasiswa\n";
            cout << "Nama: "; getline(cin, mhs.nama);
            cout << "NIM: "; getline(cin, mhs.nim);
            daftarMahasiswa.push_back(mhs);
            cout << "Mahasiswa ditambahkan.\n";
            cin.get();
        } else if (pilihan == 2) {
            system("cls");
            string nim;
            cout << "Edit Mahasiswa\n";
            cout << "Masukkan NIM yang akan diedit: "; getline(cin, nim);
            Mahasiswa* mhs = cariMahasiswa(nim);
            if (mhs) {
                cout << "Nama baru: "; getline(cin, mhs->nama);
                cout << "NIM baru: "; getline(cin, mhs->nim);
                cout << "Data mahasiswa diupdate.\n";
            } else {
                cout << "Mahasiswa tidak ditemukan.\n";
            }
            cin.get();
        } else if (pilihan == 3) {
            system("cls");
            string nim;
            cout << "Hapus Mahasiswa\n";
            cout << "Masukkan NIM yang akan dihapus: "; getline(cin, nim);
            auto it = daftarMahasiswa.begin();
            while (it != daftarMahasiswa.end()) {
                if (it->nim == nim) {
                    it = daftarMahasiswa.erase(it);
                    cout << "Mahasiswa dihapus.\n";
                    break;
                } else {
                    ++it;
                }
            }
            if (it == daftarMahasiswa.end()) {
                cout << "Mahasiswa tidak ditemukan.\n";
            }
            cin.get();
        } else if (pilihan == 4) {
            system("cls");
            string nim;
            cout << "Lihat Tabel Mahasiswa\n";
            cout << "Masukkan NIM mahasiswa yang ingin dilihat: ";
            getline(cin, nim);
            Mahasiswa* mhs = cariMahasiswa(nim);
            if (mhs) {
                cout << "Tabel Presensi Mahasiswa: " << mhs->nama << " (" << mhs->nim << ")\n";
                tampilkanTabelPresensi(mhs);
            } else {
                cout << "Mahasiswa tidak ditemukan.\n";
            }
            cout << "Tekan ENTER untuk kembali...";
            cin.get();
        } else if (pilihan == 5) {
            system("cls");
            cout << "Atur Jadwal Jam Masuk/Keluar\n";
            cout << "Jam Masuk (1-24): "; cin >> jadwal.jamMasuk;
            cout << "Jam Keluar (1-24): "; cin >> jadwal.jamKeluar;
            cout << "Jadwal diupdate.\n";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
        } else if (pilihan == 6) {
            system("cls");
            string nim;
            cout << "Cetak Data Presensi Mahasiswa\n";
            cout << "Masukkan NIM mahasiswa yang ingin dicetak: ";
            getline(cin, nim);
            Mahasiswa* mhs = cariMahasiswa(nim);
            if (mhs) {
                cetakTabelPresensiKeFile(mhs);
            } else {
                cout << "Mahasiswa tidak ditemukan.\n";
            }
            cout << "Tekan ENTER untuk kembali...";
            cin.get();
        }
    } while (pilihan != 0);
}



void presensiMenu() {
    string nim;
    cout << "Masukkan NIM: ";
    cin.ignore();
    getline(cin, nim);
    Mahasiswa* mhs = cariMahasiswa(nim);
    if (!mhs) {
        cout << "Mahasiswa tidak ditemukan.\n";
        return;
    }
    while (true) {
        system("cls");
        cout << "Nama: " << mhs->nama << endl;
        cout << "NIM: " << mhs->nim << endl;
        cout << "Total Jam Plus/Minus: " << mhs->jamPlusMinus << endl;
        cout << "\n1. Presensi\n2. Lihat Tabel Presensi\n0. Kembali\nPilih: ";
        int pilihan;
        cin >> pilihan;
        if (pilihan == 0) break;
        if (pilihan == 1) {
            int hari;
            cout << "\nPilih Hari:\n";
            for (int i = 0; i < 7; ++i) {
                cout << (i+1) << ". " << namaHari[i] << endl;
            }
            cout << "Pilih hari (1-7): ";
            cin >> hari;
            if (hari < 1 || hari > 7) {
                cout << "Hari tidak valid.\n";
                cin.get(); cin.get();
                continue;
            }
            int idxHari = hari - 1;
            PresensiHari& presensi = mhs->presensi[idxHari];
            if (presensi.jamMasuk == -1) {
                cout << "Jadwal Masuk: " << jadwal.jamMasuk << endl;
                cout << "Jadwal Keluar: " << jadwal.jamKeluar << endl;
                cout << "Masukkan jam presensi masuk (1-24): ";
                int jamMasuk;
                cin >> jamMasuk;
                presensi.jamMasuk = jamMasuk;
                if (jamMasuk < jadwal.jamMasuk) {
                    mhs->jamPlusMinus += jadwal.jamMasuk - jamMasuk;
                    cout << "Anda mendapat jam plus: +" << jadwal.jamMasuk - jamMasuk << endl;
                } else if (jamMasuk > jadwal.jamMasuk) {
                    mhs->jamPlusMinus -= jamMasuk - jadwal.jamMasuk;
                    cout << "Anda mendapat jam minus: -" << jamMasuk - jadwal.jamMasuk << endl;
                } else {
                    cout << "Tepat waktu, tidak ada plus/minus.\n";
                }
                cout << "Presensi masuk hari " << namaHari[idxHari] << " dicatat.\n";
            } else if (presensi.jamKeluar == -1) {
                cout << "Jadwal Masuk: " << jadwal.jamMasuk << endl;
                cout << "Jadwal Keluar: " << jadwal.jamKeluar << endl;
                cout << "Masukkan jam presensi keluar (1-24): ";
                int jamKeluar;
                cin >> jamKeluar;
                presensi.jamKeluar = jamKeluar;
                if (jamKeluar < jadwal.jamKeluar) {
                    mhs->jamPlusMinus -= jadwal.jamKeluar - jamKeluar;
                    cout << "Anda mendapat jam minus: -" << jadwal.jamKeluar - jamKeluar << endl;
                } else if (jamKeluar > jadwal.jamKeluar) {
                    mhs->jamPlusMinus += jamKeluar - jadwal.jamKeluar;
                    cout << "Anda mendapat jam plus: +" << jamKeluar - jadwal.jamKeluar << endl;
                } else {
                    cout << "Tepat waktu, tidak ada plus/minus.\n";
                }
                cout << "Presensi keluar hari " << namaHari[idxHari] << " dicatat.\n";
            } else {
                cout << "Presensi hari " << namaHari[idxHari] << " sudah lengkap.\n";
            }
            cout << "Tekan ENTER untuk melanjutkan...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
        } else if (pilihan == 2) {
            system("cls");
            cout << "Tabel Presensi Mahasiswa: " << mhs->nama << " (" << mhs->nim << ")\n";
            tampilkanTabelPresensi(mhs);
            cout << "Tekan ENTER untuk kembali...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
        }
    }
}

void landspace()
{
    int pilihan;
    do {
		system("cls");
        cout << "==================================================\n";
        cout << "                   TUGAS 8 MBAK!!\n";
        cout << "==================================================\n";
        cout << "1. Login Admin\n";
        cout << "2. Presensi Mahasiswa\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        if (pilihan == 1) {
            string pass;
            cout << "Masukkan password admin: ";
            cin >> pass;
            if (pass == "123") {
                adminMenu();
            }
            else {
                cout << "Password salah.\n";
            }
        }
        else if (pilihan == 2) {
            presensiMenu();
        }
    } while (pilihan != 0);

    cout << "Program selesai.\n";
    return;
}

int main() 
{
	landspace();   
}

