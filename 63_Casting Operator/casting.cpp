#include <iostream>
using namespace std;

int main(){

	int a = 5;
	float b = 6.67f;
	char c = 'd';

	cout << b << endl;
	cout << (int)b << endl;
	cout << a + (int)b << endl; // (int) merubah dari float ke int


	cout << a << endl;
	cout << c << endl;
	cout << (int)c << endl;
	cout << (int)(a + c) << endl;
	cout << (char)(c + a) << endl; // (char) merubah c dan a menjadi char


	cin.get();
	return 0;
}
