#include <iostream>
using namespace std;
int main()
{
	float a,b,hasil;
	char aritmatika;

	cout << "\n---Selamat Datang Di Calculator--- \n \n";

	// masukan input dari user
	cout << "Masukan Nilai Pertama: ";
	cin >> a;
	cout << "Pilih Operator +,-,/,* :";
	cin >> aritmatika;
	cout << "Masukan Nilai Kedua: ";
	cin >> b;

	cout << "\nHasil Perhitungan: ";
	cout << a << aritmatika << b;

	if (aritmatika == '+') {
		hasil = a + b;
	}	else if (aritmatika == '-') {
		hasil = a - b;
	}	else if (aritmatika == '/') {
		hasil = a / b;
	}	else if (aritmatika == '*') {
		hasil = a * b;
	}	else {
		cout << "\nOperator Anda Salah" << endl;
	}

		cout << " = " << hasil << endl;
		cout << "\n---Terimakasih---" << endl;
		
	cin.get();
	return 0;
}
