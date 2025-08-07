#include <iostream>
#include <cmath>
#include "LatOOP.h"

using namespace std;

int main()
{
	LatOOP obj;
	char opsi;

awal:
	cout << "\nSelamat datang di penghitung jarak & ketinggian max peluru \n ingin mencari apa nih? \n Hmax (A) \n Xmax (B) \n";
	cin >> opsi;

	if (opsi == 'A' || opsi == 'a')
	{
		double kecepatan, elevasi;

		cout << "================================================\n";
		cout << "================[Penghitung Hmax]===============\n";
		cout << "================================================\n";

		cout << "Masukkan Kecepatan (m/s):";
		cin >> kecepatan;
		cout << "Masukkan Sudut Elevasi (o):";
		cin >> elevasi;

		cout << "Hasil dari penghitungan :" << obj.hmax(kecepatan, elevasi);

		goto awal;

		return 0;
	}
	if (opsi == 'B' || opsi == 'b')
	{
		double kecepatan, elevasi;

		cout << "================================================\n";
		cout << "================[Penghitung Xmax]===============\n";
		cout << "================================================\n";

		cout << "Masukkan Kecepatan (m/s):";
		cin >> kecepatan;
		cout << "Masukkan Sudut Elevasi (o):";
		cin >> elevasi;

		cout << "Hasil dari penghitungan :" << obj.xmax(kecepatan,elevasi);

		goto awal;

		return 0;
	}
	else
	{
		goto awal;
	}

	return 0;

}