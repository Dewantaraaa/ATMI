#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip> 

using namespace std;

struct Mahasiswa {
	string nama;
	string nim;
	string prodi;
	Mahasiswa(const string& n, const string& i, const string& p) : nama(n), nim(i), prodi(p) {}
};


void sortMahasiswa(vector<Mahasiswa>& mahasiswa) 
{
	sort(mahasiswa.begin(), mahasiswa.end(), [](const Mahasiswa& a, const Mahasiswa& b) {
		return a.nim < b.nim;
	});
	
	cout << "---------------------------------------------------\n";
	cout << "| NIM         | Nama Mahasiswa   | Program Studi  |\n";
	cout << "---------------------------------------------------\n";
	for (const auto& mhs : mahasiswa) {
		cout << "| " << setw(12) << left << mhs.nim
			<< "| " << setw(17) << left << mhs.nama
			<< "| " << setw(15) << left << mhs.prodi << "|\n";
	}
	cout << "---------------------------------------------------\n";
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
		} else if (prodiCode == '2') {
			prodi = "TMK"; 
		} else if (prodiCode == '3') {
			prodi = "TPM";
		} else if (prodiCode == '4') {
			prodi = "RTM";
		} else if (prodiCode == '5') {
			prodi = "PM";
		} else if (prodiCode == '6') {
			prodi = "TRMK";
		}
		else {
			prodi = "Tidak Diketahui"; 
		}
	} else {
		prodi = "Tidak Diketahui"; 
	}
	mahasiswa.emplace_back(nama, nim, prodi);
}

int main() 
{
	vector<Mahasiswa> mahasiswa;

awal:
	system("cls");


	sortMahasiswa(mahasiswa);

	cout << "Tambah mahasiswa (A)   |   Keluar (B)" << endl << endl;
	char opsi;
	cin >> opsi;
	if (opsi == 'A' || opsi == 'a') {
		addMahasiswa(mahasiswa);
		goto awal;
	} 
	if (opsi == 'B' || opsi == 'b') {
		cout << "Terima kasih telah menggunakan program ini!" << endl;
		return 0;
	} 
	else {
		goto awal;
	}
}
