#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int nilai;

int address()
{
	int* n = &nilai;
	cout << "address = " << n << endl;
	return *n;	
}

int kuadrat()
{
	int hasilk = nilai * nilai;
	cout << "hasilnya " << nilai << "x" << nilai << " = " << hasilk << endl;
	return hasilk;
}

int akar()
{
	double hasila = sqrt(nilai);
	cout << "Akar " << nilai << " = " << hasila << endl;
	return hasila;
}

int main()
{
awal:
	system("cls");
	cout << "----------------------------------------------------\n";
	cout << "\t\t\tPointer" << endl;
	cout << "----------------------------------------------------\n";
	cout << "";

	char opsi;
	cout << "Ketik A untuk menghitung" << endl << "Ketik B untuk keluar" << endl << endl;
	cin >> opsi;

	if (opsi == 'A' || opsi == 'a') {
		cout << "Masukkan nilai = ";
		cin >> nilai;
		address();
		kuadrat();
		akar();
		system("pause");
		goto awal;
	}else if (opsi == 'B' || opsi == 'b') {
		cout << "Terima kasih telah menggunakan program ini!" << endl;
		system("pause");
		return 0;
	}
	else
	{
		goto awal;
	}
}
