#include <iostream>
#include <algorithm>
#include <array>
using namespace std;

const size_t arraySize = 10;

void printArray(array <int, arraySize> &angka){
	cout << "Array: ";
	for(int &a : angka){
		cout << a << " ";
	}
	cout << endl;
}

int main(){

	array <int, arraySize> angka = {9,4,6,7,8,1,3,2,5,0};
	printArray(angka);

	int angkaCari;
	bool ketemu;

	// 1. Sort dulu
	// 2. Search -> Binary_search

	cout << "mencari angka dalam array diatas: ";
	cin >> angkaCari;
	sort(angka.begin(), angka.end());
	ketemu = binary_search(angka.begin(), angka.end(), angkaCari); // (angka awal, angka akhir, angka yang dicari)

	if (ketemu){
		cout << "ketemu" << endl;
	}else {
		cout << "tidak ketemu" << endl;
	}

	cin.get();
	return 0;
}
