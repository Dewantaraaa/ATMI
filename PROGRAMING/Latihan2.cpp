#include <iostream>
#include <cmath>

using namespace std;

double lkeliling(double a, double b)
{
	double hasilkeliling = (a * 2) + (b * 2);
	return hasilkeliling;
}
double lluas(double D1, double D2)
{
	double hasilluas = 0.5 * D1 * D2;
	return hasilluas;
}

double volume(double jari, double tinggi)
{
	double hasilvolume = 3.14 * jari * jari * tinggi;
	return hasilvolume;
}

int main()
{
	char opsi;

awal:
	cout << "\n================================================\n";
	cout << "================[MESIN PINTARRRR]===============\n";
	cout << "================================================\n";
	cout << "Hitung luas & keliling layang (A)\n";
	cout << "Hitung Volume Tabung (B)\n";
	cout << "Keluar (C)\n\n";
	cin >> opsi;

	if (opsi == 'A' || opsi == 'a')
	{
		double a, b, D1, D2;

		cout << "\n================================================\n";
		cout << "================[Penghitung Luas]===============\n";
		cout << "================================================\n";

		cout << "Masukkan A:";
		cin >> a;
		cout << "Masukkan B:";
		cin >> b;

		cout << "Masukkan D1:";
		cin >> D1;
		cout << "Masukkan D2:";
		cin >> D2;

		cout << "\nHasil dari penghitungan Keliling :" << lkeliling(a, b) << "cm" << endl;
		cout << "Hasil dari penghitungan luas :" << lluas(D1, D2) << "cm2" << endl;

		goto awal;

		return 0;
	}
	if (opsi == 'B' || opsi == 'b')
	{
		double jari, tinggi;

		cout << "\n================================================\n";
		cout << "============[Penghitung Volume Tabung]============\n";
		cout << "==================================================\n";

		cout << "Masukkan jari jari : ";
		cin >> jari;
		cout << "Masukkan tinggi:";
		cin >> tinggi;

		cout << "\nHasil dari penghitungan :" << volume(jari, tinggi) << "cm3";
		goto awal;

		return 0;
	}
	if (opsi == 'C' || opsi == 'c')
	{
		return 0;
	}
	else
	{
		goto awal;
	}

}
