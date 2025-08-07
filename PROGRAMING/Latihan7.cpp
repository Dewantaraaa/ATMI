#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip> 
#include <fstream>

using namespace std;

struct Mahasiswa {
	string nama;
	string nim;
	string prodi;
	double tabungan;
	Mahasiswa(const string& n, const string& i, const string& p) : nama(n), nim(i), prodi(p), tabungan(0.0) {
	}
};

void sortMahasiswa(vector<Mahasiswa>& mahasiswa)
{
	sort(mahasiswa.begin(), mahasiswa.end(), [](const Mahasiswa& a, const Mahasiswa& b) {
		return a.nim < b.nim;
		});
	cout << "--------------------------------------------------------------\n";
	cout << "| NIM         | Nama Mahasiswa   | Program Studi  | Tabungan |\n";
	cout << "--------------------------------------------------------------\n";
	for (const auto& mhs : mahasiswa) {
		cout << "| " << setw(12) << left << mhs.nim
			<< "| " << setw(17) << left << mhs.nama
			<< "| " << setw(15) << left << mhs.prodi
			<< "| " << setw(8) << right << fixed << setprecision(2) << mhs.tabungan << " |\n";
	}
	cout << "--------------------------------------------------------------\n";
}


void addMahasiswa(vector<Mahasiswa>& mahasiswa)
{
	string nama, nim;
	cout << "Masukkan nama mahasiswa: ";
	cin.ignore();
	getline(cin, nama);
	cout << "Masukkan NIM mahasiswa: ";
	getline(cin, nim);

	string prodi;
	if (nim.length() >= 5) {
		char prodiCode = nim[4];
		if (prodiCode == '1') {
			prodi = "TMI";
		}
		else if (prodiCode == '2') {
			prodi = "TMK";
		}
		else if (prodiCode == '3') {
			prodi = "TPM";
		}
		else if (prodiCode == '4') {
			prodi = "RTM";
		}
		else if (prodiCode == '5') {
			prodi = "PM";
		}
		else if (prodiCode == '6') {
			prodi = "TRMK";
		}
		else {
			prodi = "Tidak Diketahui";
		}
	}
	else {
		prodi = "Tidak Diketahui";
	}
	mahasiswa.emplace_back(nama, nim, prodi);
}

void ubahDataMahasiswa(vector<Mahasiswa>& mahasiswa)
{
	string nim;
	cout << "Masukkan NIM mahasiswa yang ingin diubah: ";
	cin >> nim;
	auto it = find_if(mahasiswa.begin(), mahasiswa.end(), [&nim](const Mahasiswa& mhs) {
		return mhs.nim == nim;
	});
	if (it != mahasiswa.end()) {
		string namaBaru, prodiBaru;
		cout << "Masukkan nama baru: ";
		cin.ignore();
		getline(cin, namaBaru);
		cout << "Masukkan program studi baru: ";
		getline(cin, prodiBaru);
		it->nama = namaBaru;
		it->prodi = prodiBaru;
		cout << "Data mahasiswa berhasil diubah." << endl;
	}
	else {
		cout << "Mahasiswa dengan NIM " << nim << " tidak ditemukan." << endl;
		system("pause");
	}
}

void tambahTabunganMahasiswa(vector<Mahasiswa>& mahasiswa)
{
	string nim;
	cout << "Masukkan NIM mahasiswa yang ingin ditambah tabungannya: ";
	cin >> nim;
	auto it = find_if(mahasiswa.begin(), mahasiswa.end(), [&nim](const Mahasiswa& mhs) {
		return mhs.nim == nim;
	});
	if (it != mahasiswa.end()) {
		double jumlahTabungan;
		cout << "Masukkan jumlah tabungan yang ingin ditambahkan: ";
		cin >> jumlahTabungan;
		it->tabungan += jumlahTabungan;
		cout << "Tabungan berhasil ditambahkan. Total tabungan sekarang: " << fixed << setprecision(2) << it->tabungan << endl;
	}
	else {
		cout << "Mahasiswa dengan NIM " << nim << " tidak ditemukan." << endl;
		system("pause");
	}
}

void exportDataMahasiswa(const vector<Mahasiswa>& mahasiswa)
{
	ofstream file("data_mahasiswa.txt");
	if (!file) {
		cerr << "Error membuka file untuk penulisan." << endl;
		system("pause");
	}
	for (const auto& mhs : mahasiswa) {
		file << mhs.nim << "\t" << mhs.nama << "\t" << mhs.prodi << "\t" << fixed << setprecision(2) << mhs.tabungan << "\n";
	}
	file.close();
}

void removeMahasiswa(vector<Mahasiswa>& mahasiswa, const string& nim)
{
	auto it = remove_if(mahasiswa.begin(), mahasiswa.end(), [&nim](const Mahasiswa& mhs) {
		return mhs.nim == nim;
	});
	if (it != mahasiswa.end()) {
		mahasiswa.erase(it, mahasiswa.end());
	}
	else {
		cout << "Mahasiswa dengan NIM " << nim << " tidak ditemukan." << endl;
		system("pause");
	}
}

int main()
{
	vector<Mahasiswa> mahasiswa;

awal:
	system("cls");


	sortMahasiswa(mahasiswa);

	cout << "Tambah mahasiswa (A)   |   Ubah Data   (B)" << endl;
	cout << "Tambah Tabungan  (C)   |   Export Data (D)" << endl;
	cout << "Hapus Mahasiswa  (E)" << endl << endl;
	char opsi;
	cin >> opsi;
	if (opsi == 'A' || opsi == 'a') {
		addMahasiswa(mahasiswa);
		goto awal;
	}
	if (opsi == 'B' || opsi == 'b') {
		ubahDataMahasiswa(mahasiswa);
		goto awal;
	}
	if (opsi == 'C' || opsi == 'c') {
		tambahTabunganMahasiswa(mahasiswa);
		goto awal;
	}
	if (opsi == 'D' || opsi == 'd') {
		exportDataMahasiswa(mahasiswa);
		goto awal;
	}
	if (opsi == 'E' || opsi == 'e') {
		string nim;
		cout << "Masukkan NIM mahasiswa yang ingin dihapus: ";
		cin >> nim;
		removeMahasiswa(mahasiswa, nim);
		goto awal;
	}
	else {
		goto awal;
	}
}
