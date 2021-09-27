#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){

	fstream myFile;
	int number = 12345;
	myFile.open("data.bin", ios::out | ios::binary); // out = menulis, binary = dalam bentuk biner
	
	myFile.write(reinterpret_cast<char*>(&number), sizeof(number));

	myFile.close();	

	cin.get();
	return 0;
}

