#include "project.h"

void project::sortMahasiswa(vector<Mahasiswa>& mahasiswa)
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
	cout << "Tambah mahasiswa (A)   |   Ubah Data   (B)" << endl;
	cout << "Tambah Tabungan  (C)   |   Export Data (D)" << endl;
	cout << "Hapus Mahasiswa  (E)   |   Keluar      (F)" << endl << endl;
}

void project::addMahasiswa(vector<Mahasiswa>& mahasiswa)
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

void project::tambahTabunganMahasiswa(Mahasiswa& mhs)
{
	for (int i = 0; i < 6; ++i) {
		double jumlahTabungan;
		cout << "Masukkan jumlah tabungan untuk bulan " << mhs.bulan[i] << ": ";
		cin >> jumlahTabungan;
		mhs.tabungan += jumlahTabungan;
	}
	cout << "Total tabungan sekarang: " << fixed << setprecision(2) << mhs.tabungan << endl;
}

void project::ubahDataMahasiswa(vector<Mahasiswa>& mahasiswa)
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
		cout << "Ubah tabungan? (Y/N)";
		char ubahTabungan;
		cin >> ubahTabungan;
		if (ubahTabungan == 'Y' || ubahTabungan == 'y') {
			it->tabungan = 0.0;
			for (int i = 0; i < 6; ++i) {
				double jumlahTabungan;
				cout << "Masukkan jumlah tabungan untuk bulan " << it->bulan[i] << ": ";
				cin >> jumlahTabungan;
				it->tabungan += jumlahTabungan;
			}
		}
		else if (ubahTabungan != 'N' && ubahTabungan != 'n') {
			cout << "Pilihan tidak valid, tabungan tidak diubah." << endl;
		}
		it->nama = namaBaru;
		it->prodi = prodiBaru;
		cout << "Data mahasiswa berhasil diubah." << endl;
	}
	else {
		cout << "Mahasiswa dengan NIM " << nim << " tidak ditemukan." << endl;
		system("pause");
	}
}

void project::exportDataMahasiswa(const vector<Mahasiswa>& mahasiswa)
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

void project::removeMahasiswa(vector<Mahasiswa>& mahasiswa, const string& nim)
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

void project::landspace(vector<Mahasiswa> mahasiswa)
{
awal:
	system("cls");

	sortMahasiswa(mahasiswa);

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
		string nim;
		cout << "Masukkan NIM mahasiswa yang ingin ditambah tabungan: ";
		cin >> nim;
		auto it = find_if(mahasiswa.begin(), mahasiswa.end(), [&nim](Mahasiswa& mhs) {
			return mhs.nim == nim;
			});
		if (it != mahasiswa.end()) {
			tambahTabunganMahasiswa(*it);
		}
		else {
			cout << "Mahasiswa dengan NIM " << nim << " tidak ditemukan." << endl;
			system("pause");
		}
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
	if (opsi == 'F' || opsi == 'f') {
		cout << "Terima kasih telah menggunakan program ini." << endl;
		system("pause");
	}
	else {
		goto awal;
	}
}
