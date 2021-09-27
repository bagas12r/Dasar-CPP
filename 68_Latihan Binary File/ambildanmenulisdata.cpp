#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Mahasiswa{
	int NIM;
	string nama;
	string jurusan;
};


Mahasiswa ambilData(int posisi, fstream &myFile){ // mengambil posisi data keberapa dan membaca dari myFile
	Mahasiswa bufferData;

	myFile.seekp((posisi-1)*sizeof(Mahasiswa)); // mengambil data keberapa, data bisa diambil sesaui kelipadan size Mahasiswa, data pertama dimulai dari 0 maka dari itu menjadi (posisi-1)
	myFile.read(reinterpret_cast<char*>(&bufferData),sizeof(Mahasiswa)); // membaca address dan ditaruh ke variabel buffer dengan ukuran data Mahasiswa

	return bufferData; // semua perintah sebelumnya dikembalikan / dimasukan ke vaariabel buffer
}

void menulisData(Mahasiswa &data, fstream &myFile){
	myFile.write(reinterpret_cast<char*>(&data), sizeof(Mahasiswa));
}

// merubah data, bisa merubah nama, jurusan dan lainya sesuai kehendak
void menulisDataByPosisi(int posisi,Mahasiswa &bufferData, fstream &myFile){ // mengambil posisi data keberapa dan membaca dari myFile
	myFile.seekg((posisi-1)*sizeof(Mahasiswa)); // mengambil data keberapa, data bisa diambil sesaui kelipadan size Mahasiswa, data pertama dimulai dari 0 maka dari itu menjadi (posisi-1)
	myFile.write(reinterpret_cast<char*>(&bufferData),sizeof(Mahasiswa)); // menulis dan menerjemahkan dari address binary dan ditaruh ke variabel buffer dengan ukuran data Mahasiswa
}

int main(){

	fstream myFile;
	myFile.open("data.bin", ios::trunc | ios::out | ios::in | ios::binary);// ios::trunc = membuat file jike belum ada

	Mahasiswa mahasiswa1, mahasiswa2, mahasiswa3, output;

	mahasiswa1.NIM = 123;
	mahasiswa1.nama = "ucup";
	mahasiswa1.jurusan = "memasak";

	mahasiswa2.NIM = 124;
	mahasiswa2.nama = "otong";
	mahasiswa2.jurusan = "menjahit";

	mahasiswa3.NIM = 125;
	mahasiswa3.nama = "sandra";
	mahasiswa3.jurusan = "mesin";

	menulisData(mahasiswa1, myFile);
	menulisData(mahasiswa2, myFile);
	menulisData(mahasiswa3, myFile);

	// mengganti nama mahasiswa
	mahasiswa2.nama = "mario";
	menulisDataByPosisi(2, mahasiswa2, myFile); // menulis di data ke 2, di variabel mahasiswa 2, di myfile
	//
	
	output = ambilData(2, myFile);

	cout << output.NIM << endl;
	cout << output.nama << endl;
	cout << output.jurusan << endl;

	myFile.close();

	cin.get();
	return 0;
}

