#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){

	fstream myFile;
	int hasil;
	myFile.open("data.bin", ios::in | ios::binary);

	myFile.read(reinterpret_cast<char*>(&hasil), sizeof(hasil)); // membaca my file kemudian dimasukan ke variabel hasil melalui pointer char

	cout << "besar integer = " << sizeof(hasil) << endl;
	cout << hasil << endl;

	cin.get();
	return 0;
}

