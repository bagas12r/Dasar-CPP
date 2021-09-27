#include <iostream>
#include <fstream> // ada ofstream = out stream , ifstream = input stream, fstream = gabungan output input
using namespace std;

int main(){

	ofstream myFile;

	//	ios::out = default, operasi output;
	//	ios::app = menuliskan pada akhir baris , menambah kalimat dan tidak menimpa kalimat lama;
	//	ios::trunc = default, membuat file baru jika file tidak ditemukan

	myFile.open("data3.txt", ios::app); // append / menambah kalimat baru tanpa menindih kalimat lama
	myFile << "\nmenuliskan baris baru pada data3";
	myFile.close(); // di close agar tidak mempegaruhi file lain

	int a = 5352; // bisa juga menggunakan integer
	myFile.open("data1.txt", ios::out);
	myFile << "\nmenuliskan baris baru pada data1";
	myFile << a;
	myFile.close(); // jika tidak close akan mempengaruhi file lain

	myFile.open("data2.txt", ios::trunc);
	myFile << "\nmenuliskan baris baru pada data2";
	myFile.close();

	cin.get();
	return 0;
}
