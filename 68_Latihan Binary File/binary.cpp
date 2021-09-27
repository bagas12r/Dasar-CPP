#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Mahasiswa{
	int NIM;
	string nama;
	string jurusan;
};

int main(){

	fstream myFile;
	myFile.open("data.bin", ios::trunc | ios::out | ios::in | ios::binary);// ios::trunc = membuat file jike belum ada

	Mahasiswa mahasiswa1, mahasiswa2, mahasiswa3;

	mahasiswa1.NIM = 123;
	mahasiswa1.nama = "ucup";
	mahasiswa1.jurusan = "memasak";

	mahasiswa2.NIM = 124;
	mahasiswa2.nama = "otong";
	mahasiswa2.jurusan = "menjahit";

	mahasiswa3.NIM = 125;
	mahasiswa3.nama = "sandra";
	mahasiswa3.jurusan = "mesin";

	myFile.write(reinterpret_cast<char*>(&mahasiswa1), sizeof(Mahasiswa));
	myFile.write(reinterpret_cast<char*>(&mahasiswa2), sizeof(Mahasiswa));
	myFile.write(reinterpret_cast<char*>(&mahasiswa3), sizeof(Mahasiswa));

	myFile.close();

	cin.get();
	return 0;
}

