#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Mahasiswa{
	int NIM;
	string nama;
	string jurusan;
};

Mahasiswa ambilData(int &posisi, fstream &myFile){ // mengambil posisi data keberapa dan membaca dari myFile
	Mahasiswa bufferData;

	myFile.seekp((posisi-1)*sizeof(Mahasiswa)); // mengambil data keberapa, data bisa diambil sesaui kelipadan size Mahasiswa, data pertama dimulai dari 0 maka dari itu menjadi (posisi-1)
	myFile.read(reinterpret_cast<char*>(&bufferData),sizeof(Mahasiswa)); // membaca address dan ditaruh ke variabel buffer dengan ukuran data Mahasiswa

	return bufferData; // semua perintah sebelumnya dikembalikan / dimasukan ke vaariabel buffer
}
	fstream myFile;
	Mahasiswa dataBaca;
	myFile.open("data.bin", ios::in | ios::binary); // mencari dan membaca file dalam bentuk binary
	int posisi = 1; // mengambil posisi ke n
	dataBaca = ambilData(posisi, myFile); // membaca posisi dari file

	cout << dataBaca.NIM << endl;
	cout << dataBaca.nama << endl;
	cout << dataBaca.jurusan << endl;

	myFile.close();

	cin.get();
	return 0;

