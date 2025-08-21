#include "project.h"
#include <fstream>
#include <limits>

void Project::mainHeader() {
    system("cls");
    cout << "==========================================================" << endl;
    cout << ">>>>>>>>>>>>>>>>>>>>REKAP PLUS MINUS<<<<<<<<<<<<<<<<<<<<<<" << endl;
    cout << "==========================================================" << endl;
}

void Project::mainMenu() {
    cout << "1. Tambah Mahasiswa" << "\t\t" << "4. Hapus Mahasiswa" << endl;
    cout << "2. Lihat Mahasiswa" << "\t\t" << "5. Export Data" << endl;
    cout << "3. Rekap Jam" << "\t\t\t" << "6. Exit" << endl;
    cout << "Pilih menu: ";
}

string Project::getProdiFromNIM(const string& nim) {
    if (nim.length() >= 5) {
        char prodiCode = nim[4];
        switch (prodiCode) {
        case '1': return "TMI";
        case '2': return "TMK";
        case '3': return "TPM";
        case '4': return "RTM";
        case '5': return "PM";
        case '6': return "TRMK";
        }
    }
    return "Unknown Prodi";
}

void Project::addMahasiswa(vector<Mahasiswa>& mahasiswa) {
    system("cls");
    cout << "==========================================================" << endl;
    cout << ">>>>>>>>>>>>>>>>>>>>TAMBAH MAHASISWA<<<<<<<<<<<<<<<<<<<<<<" << endl;
    cout << "==========================================================" << endl;

    char lanjut;
    do {
        Mahasiswa mhs;
        cout << "Nama Mahasiswa: ";
        cin.ignore();
        getline(cin, mhs.nama);
        cout << "NIM Mahasiswa: ";
        cin >> mhs.nim;

        mhs.prodi = getProdiFromNIM(mhs.nim);
        if (mhs.prodi == "Unknown Prodi") {
            cout << "Data Tidak Valid!" << endl;
        }
        else {
            mahasiswa.emplace_back(mhs);
            cout << "Mahasiswa berhasil ditambahkan!" << endl;
        }

        cout << "Tambah Mahasiswa (y/n)? ";
        cin >> lanjut;
    } while (lanjut == 'y' || lanjut == 'Y');
}

void Project::deleteMahasiswa(vector<Mahasiswa>& mahasiswa)
{
    system("cls");
    cout << "==========================================================" << endl;
    cout << ">>>>>>>>>>>>>>>>>>>>HAPUS MAHASISWA<<<<<<<<<<<<<<<<<<<<<<<" << endl;
    cout << "==========================================================" << endl;
    if (mahasiswa.empty()) {
        cout << "Belum Ada Mahasiswa untuk dihapus!" << endl;
        return;
    }
    string nim;
    cout << "Masukkan NIM Mahasiswa yang ingin dihapus: ";
    cin.ignore();
    getline(cin, nim);
    auto it = remove_if(mahasiswa.begin(), mahasiswa.end(), [&](const Mahasiswa& mhs) {
        return mhs.nim == nim;
        });
    if (it != mahasiswa.end()) {
        mahasiswa.erase(it, mahasiswa.end());
        cout << "Mahasiswa dengan NIM " << nim << " berhasil dihapus!" << endl;
    }
    else {
        cout << "Mahasiswa dengan NIM " << nim << " tidak ditemukan!" << endl;
    }
}

void Project::displayMahasiswa(const vector<Mahasiswa>& mahasiswa) {
    system("cls");
    if (mahasiswa.empty()) {
        cout << "\nBelum Ada Mahasiswa!\n";
        return;
    }

    cout << "==========================================================" << endl;
    cout << ">>>>>>>>>>>>>>>>>>>>DAFTAR MAHASISWA<<<<<<<<<<<<<<<<<<<<<<" << endl;
    cout << "==========================================================" << endl;

    for (const auto& mhs : mahasiswa) {
        cout << "Nama: " << mhs.nama << endl;
        cout << "NIM: " << mhs.nim << endl;
        cout << "Prodi: " << mhs.prodi << endl;
        cout << "\nSaldo Jam: ";
        for (int j : mhs.saldoJam) cout << j << " ";
        cout << "\nTotal Saldo Jam: " << mhs.saldoJamTotal << endl;
        cout << "-----------------------------" << endl;
    }
}

void Project::inputJam(vector<Mahasiswa>& mahasiswa) {
    system("cls");
    cout << "==========================================================" << endl;
    cout << ">>>>>>>>>>>>>>>>>>>>INPUT REKAP JAM<<<<<<<<<<<<<<<<<<<<<<<" << endl;
    cout << "==========================================================" << endl;

    if (mahasiswa.empty()) {
        cout << "Belum Ada Mahasiswa!\n";
        return;
    }

    string nim;
    cout << "Masukkan NIM Mahasiswa: ";
    cin.ignore();
    getline(cin, nim);

    bool found = false;
    for (auto& mhs : mahasiswa) {
        if (mhs.nim == nim) {
            found = true;
            cout << "Rekap Jam untuk " << mhs.nama << endl;
            mhs.saldoJamTotal = 0;

            for (int i = 0; i < 7; ++i) {
                int jam;
                cout << mhs.hari[i] << ": ";
                cin >> jam;
                mhs.inputJam[i] = jam;              
                mhs.saldoJam[i] = jam;             
                mhs.saldoJamTotal += jam;          
            }

            cout << "Jam berhasil diinput!" << endl;
            break;
        }
    }

    if (!found) {
        cout << "Mahasiswa dengan NIM " << nim << " tidak ditemukan!" << endl;
    }
}

void Project::exportData(const vector<Mahasiswa>& mahasiswa) {
    system("cls");
    cout << "==========================================================" << endl;
    cout << ">>>>>>>>>>>>>>>>>>>>>>>EXPORT DATA<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
    cout << "==========================================================" << endl;

    if (mahasiswa.empty()) {
        cout << "Belum Ada Mahasiswa untuk diekspor!" << endl;
        return;
    }

    string filename;
    cout << "Masukkan nama file (tanpa ekstensi): ";
    cin.ignore();
    getline(cin, filename);
    filename += ".txt";

    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Gagal membuka file!" << endl;
        return;
    }

    for (const auto& mhs : mahasiswa) {
        outFile << "Nama: " << mhs.nama << "\n";
        outFile << "NIM: " << mhs.nim << "\n";
        outFile << "Prodi: " << mhs.prodi << "\n";
        outFile << "Saldo Jam: ";
        for (int j : mhs.inputJam) outFile << j << " ";
        outFile << "\Total Jam: " << mhs.saldoJamTotal << "\n";
        outFile << "-----------------------------\n";
    }

    outFile.close();
    cout << "Data berhasil diekspor ke: " << filename << endl;
}

void Project::landspace()
{
    vector<Mahasiswa> mahasiswa;
    int pilihan;

    do {
        mainHeader();
        mainMenu();
        cin >> pilihan;

        switch (pilihan) {
        case 1: addMahasiswa(mahasiswa); break;
        case 2: displayMahasiswa(mahasiswa); break;
        case 3: inputJam(mahasiswa); break;
        case 4: deleteMahasiswa(mahasiswa); break;
        case 5: exportData(mahasiswa); break;
        case 6: cout << "Keluar dari program.\n"; break;
        default: cout << "Pilihan tidak valid!\n"; break;
        }

        if (pilihan != 6) system("pause");

    } while (pilihan != 6);

    return;
}