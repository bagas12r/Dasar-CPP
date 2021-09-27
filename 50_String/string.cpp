#include <iostream>
using namespace std;

int main(){

	// char kata[5] = {'m','o','b','i','l'};
	// array char tidakbisa kita tambah, fix karena array

	//string namavariabel( "kata");
	string kata("cat");
	cout << kata << endl;

	// memakai tipe data string
	string data;
	cout << "masukan kata: ";
	cin >> data;
	cout << "data yang dimasukan adalah: ";
	cout << data << endl;

	// tidak bisa menggunakan spasi
	// kalau mau menggunakan spasi harus tambah library lain


	cin.get();
	return 0;
}
