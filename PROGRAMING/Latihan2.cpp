#include <iostream>
#include <cmath>
using namespace std;

const double pi = 3.14;
char input, yt;
double a, b, d1, d2, radius, tinggi;

void headerUtama() {
        cout << "-------------------------------" << endl;
        cout << "\tMARI MENGHITUNG" << endl;
        cout << "-------------------------------" << endl;
        cout << endl << endl;
}

void menuUtama() {
        cout << "Apa yang ingin anda hitung?" << endl;
        cout << "A. Luas dan Keliling Layang-layang" << endl;
        cout << "B. Volume Tabung" << endl;
        cout << "C. Keluar" << endl;
        cout << "\n> ";
        cin >> input;
        cout << endl;
}

double luas(double d1, double d2);
double keliling(double a, double b);
double volume(double radius, double tinggi);

double luas(double d1, double d2)
{
        return(0.5 * d1 * d2);
}

double keliling(double a, double b)
{
        return(2 * (a + b));
}

double volume(double radius, double tinggi)
{
        return(pi * (radius * radius) * tinggi);
}

void inputA() {
        cout << "Menghitung Luas dan Keliling Layang-layang" << endl;
        cout << "------------------------------------------" << endl;
        cout << "Input sisi miring 1(a)\t: ";
        cin >> a;
        cout << "Input sisi miring 2(b)\t: ";
        cin >> b;
        cout << "Input diagonal 1(d1)\t: ";

        cin >> d1;
        cout << "Input diagonal 2(d2)\t: ";
        cin >> d2;
        cout << endl;
        cout << "------------------------------------------" << endl;
        cout << "Luas Layang-layang Adalah\t: " << luas(d1, d2) << "cm2" << endl;
        cout << "Keliling Layang-layang Adalah\t: " << keliling(a, b) << "cm" << endl;
}

void inputB() {
        cout << "\tMenghitung Volume Tabung" << endl;
        cout << "-------------------------------------" << endl;
        cout << "Input Jari-jari Tabung\t: ";
        cin >> radius;
        cout << "Input Tinggi Tabung\t: ";
        cin >> tinggi;
        cout << endl;
        cout << "-------------------------------------" << endl;
        cout << "Volume Tabung Adalah\t: " << volume(radius, tinggi) << "cm3" << endl;
}

int main() {

awal:
        headerUtama();
        menuUtama();


        if (input == 'A' || input == 'a') {

                inputA();

        }
        else if (input == 'B' || input == 'b') {

                inputB();

        }
        else if (input == 'C' || input == 'c') {
                goto akhir;
        }
        else {

                goto akhir;

        }
        cout << endl;
        cout << "Masukkan Data Lagi? (Y/T)" << endl;
        cout << "> ";
        cin >> yt;
        cout << endl;

        if (yt == 'Y' || yt == 'y') {
                goto awal;
        }
        else {
                goto akhir;
        }

akhir:
        return 0;

}
