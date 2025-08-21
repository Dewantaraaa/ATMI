#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    string prodi;
    vector<string> hari = { "Senin", "Selasa", "Rabu", "Kamis", "Jumat", "Sabtu", "Minggu" };
    vector<int> inputJam = vector<int>(7, 0);
    vector<int> saldoJam = vector<int>(7, 0);
    int saldoJamTotal = 0;
};

class Project {
public:
    void entertocontinue();
    void mainHeader();
    void mainMenu();
    void addMahasiswa(vector<Mahasiswa>& mahasiswa);
    void deleteMahasiswa(vector<Mahasiswa>& mahasiswa);
    void displayMahasiswa(const vector<Mahasiswa>& mahasiswa);
    void inputJam(vector<Mahasiswa>& mahasiswa);
    void exportData(const vector<Mahasiswa>& mahasiswa);
    string getProdiFromNIM(const string& nim);
    void landspace();
};