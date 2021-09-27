#include <iostream>
#include <string>
using namespace std;

int main(){

	string kalimat_1("aku suka kamu suka, siapa? dia!");
	string kalimat_2("wakanda forevah!!!");

	cout << "1: " << kalimat_1 << endl;
	cout << "2: " << kalimat_2 << endl << endl;

	// swap string / menukar kalimat string
	kalimat_1.swap(kalimat_2);
	cout << "swap string 1 ke string 2: " << endl;
	cout << "1: " << kalimat_1 << endl;
	cout << "2: " << kalimat_2 << endl << endl;

	// replace, mengganti string
	kalimat_2.replace(27,3,"otong"); // (huruf ke :, panjang huruf, huruf pengganti)
	// replace menggunakan find huruf	
	int posisi = kalimat_1.find("ah");
	kalimat_1.replace(posisi,2,"er");

	cout << "replace string" << endl;
	cout << "1: " << kalimat_1 << endl;
	cout << "2: " << kalimat_2 << endl << endl;

	// insert string / memasukatan kata
	kalimat_1.insert(8, "dan hatiku ");
	cout << "insert string" << endl;
	cout << "1: " << kalimat_1 << endl;
	cout << "2: " << kalimat_2 << endl << endl;

	// replace dengan memasukan kata sendiri
	string kata;
	int posisi1 = kalimat_1.find("forever");
	cout << "replace string dengan kata sendiri" << endl;
	cout << "masukan kalimat pengganti forever : ";
	cin >> kata;
	kalimat_1.replace(posisi1,7,kata);
	cout << kalimat_1 << endl;


	cin.get();
	return 0;
}
