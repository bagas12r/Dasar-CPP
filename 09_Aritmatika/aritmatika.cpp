#include <iostream>

using namespace std;

int main(){

	float a = 6;
	int b = 4;
	float hasil;

	// operatornya : +, -, *, /, %

	// penjumlahan

	hasil = a + b;
	cout << a + b << endl;
	cout << a << " + " << b << " = " << hasil << endl;  

	// pengurangan

	hasil = a - b;
	cout << a << " - " << b << " = " << hasil << endl; 

	// perkalian

	hasil = a * b;
	cout << a << " x " << b << " = " << hasil << endl; 	

	// pembagian

	hasil = a / b;
	cout << a << " : " << b << " = " << hasil << endl; 
	
	// modulus
	/*
	hasil = a % b;
	cout << a << " % " << b << " = " << hasil << endl; 
	*/

	// kurung

	hasil = ( a + b ) * b;
	cout << "( " << a << " + " << b << " ) " << "x " << b << " = " ; 
	cout << hasil << endl;


	cin.get();
	return 0;
}
