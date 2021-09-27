#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){

	ifstream myFile;
	string output;
	string buffer;
	string nama;
	int no;
	bool isData = false;

	// ios::in = membaca file
	// ios::ate = mulai dari akhir file
	// ios::binary = membaca file binary / angka koma

	myFile.open("data.txt"); // membuka file txt di folder yang sama , sebenarnya bisa pakai myFile.open("data.txt, ios::in");

	while(!isData){
		getline(myFile,buffer); // membaca baris pertama dan dimasukan ke variabel buffer
		output.append("\n" + buffer); // buffer digabungkan ke variabel output
		if (buffer == "data"){ 
		isData = true; // jika sudah menemukan kalimat "data" maka loops akan berhenti
		}
	}
	cout << output << endl; // menampilkan kalimat sampai menemukan kalimat "data"

	getline(myFile,buffer); // membaca baris selanjutnya dari txt dan dimasukan ke variabel bufer
	cout << buffer << endl;
	int jumlah_data = 0;	
	while(!myFile.eof()){ // eof = end of file, yang berarti membaca txt sampai akhir kalimat
		myFile >> no;
		myFile >> nama;

		cout << no << "\t" << nama << endl;
		jumlah_data++; // menghitung jumlah nomor
	}	
	cout << "jumlah data = " << jumlah_data << endl; // menampilkan jumlah data dari nomor


	cin.get();
	return 0;
}
