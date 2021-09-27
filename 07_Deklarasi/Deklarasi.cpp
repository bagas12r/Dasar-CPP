#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int a;

	a = 11;
	cout << a << endl;

	int b;
	cout << "Masukan Nilai Daffa : "  ;
	cin >> b;
	
	int c;

	cout << "Masukan Nilai Bagas : " ;
	cin >> c;
	
cout << "\n" ;

	cout << "Nilai Daffa Adalah : " ;
	cout << b << endl;

cout << "\n" ;

	cout << "Nilai Bagas Adalah : " ;
	cout << c << endl;

cout << "\n" ;	

	cout << "Jumlah Nilai Kalian Adalah : " ;
	cout << a + b + c << endl;


	cin.get();

	return 0;
}