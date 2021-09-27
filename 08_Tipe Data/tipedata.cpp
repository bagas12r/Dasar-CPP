#include <iostream>

using namespace std;

int main()
{

	//bilangan bulat
	unsigned int h = 4; //32-bit
	int a = 1;
	long b = 5;
	short c = 7;

	//bilangan decimal
	float d = 1.0;
	double e = 2.5;

	//character
	char f = 's'; //character 1-bit

	//boolean
	bool g = true; // true/false


	cout << c << endl;
	cout << sizeof(c) << " byte" << endl;
	cout << numeric_limits<short>::max() << endl;
	cout << numeric_limits<short>::min() << endl;
	
	cin.get();
	
	return 0;
}

