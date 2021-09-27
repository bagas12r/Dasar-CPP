#include <iostream>
using namespace std;
int main()
{
	float a,b,hasil;
	char aritmatika;

	cout << "\nselamat datang di calculator\n\n";

	// input
	cout << "masukan nilai pertama: ";
	cin >> a;
	cout << "pilih operator +,-,/,*: ";
	cin >> aritmatika;
	cout << "masukan nilai kedua: ";
	cin >> b;

	switch (aritmatika){
		case '+':
			hasil = (a + b);
			cout << "hasil perhitungan: ";
			cout << a << aritmatika << b;
			cout << " = " << hasil << endl;
			break;
		case '-':
			hasil = (a - b);
			cout << "hasil perhitungan: ";
			cout << a << aritmatika << b;
			cout << " = " << hasil << endl;
			break;
		case '*':
			hasil = (a * b);
			cout << "hasil perhitungan: ";
			cout << a << aritmatika << b;
			cout << " = " << hasil << endl;
			break;
		case '/':
			hasil = (a / b);
			cout << "hasil perhitungan: ";
			cout << a << aritmatika << b;
			cout << " = " << hasil << endl;
			break;
		default:
		cout << "\nmaaf operator salah" << endl;	

	}

	cin.get();
	cin.get();
	return 0;
}
