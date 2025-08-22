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
    PresensiHari presensi[7]; 
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

class Project {
public:
    void tampilkanDaftarMahasiswa();
    void tampilkanTabelPresensi(const Mahasiswa* mhs);
    void cetakTabelPresensiKeFile(const Mahasiswa* mhs);
    void adminMenu();
    void presensiMenu();
	void landspace();
};
