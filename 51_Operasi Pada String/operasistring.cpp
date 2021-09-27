#include <iostream>
#include <string>
using namespace std;

int main(){

	string kata("cat");

	// menampilkan data string
	cout << kata << endl;

	// mengambil karakter berdasarkan index
	cout << "index ke 0 : " << kata[0] << endl;
	cout << "index ke 1 : " << kata[1] << endl;
	cout << "index ke 2 : " << kata[2] << endl;

	// merubah karakter pada index
	kata[1] = 'e'; // kalau mau merubah , menggunalan ' '
	cout << kata << endl;

	// menyambung / concatenation
	string kata2(kata + "ar");
	cout << kata2 << endl;

	string kata3("membahana");
	kata2.append(" " + kata3);
	cout << kata2 << endl;

	string kata4("ahay!!!!!");
	kata2 += " " + kata4;
	// kata2 = kata2 + " " + kata4;
	cout << kata2 << endl;

	string kata5, kata6, kata7;
	cout << "masukan kata : ";
	cin >> kata5; // tidak bisa lebih dari satu kata menggunakan spasi
	cout << "masukan kata : ";
	cin >> kata6; // tidak bisa lebih dari satu kata menggunakan spasi
	kata7 = kata5 + " " + kata6;
	cout << "kata anda adalah : ";
	cout << kata7 << endl; 
	

	cin.get();
	return 0;
}
