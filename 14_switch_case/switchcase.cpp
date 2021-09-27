#include <iostream>
using namespace std;

int main()
{
	int a;

	cout << "masukan nilai = ";
	cin >> a;

	switch(a){
		 case 1:
		 	cout << "benar itu adalah 1" << endl;
		 	break;
		 case 2:
		 	cout << "benar itu adalah 2" << endl;
		 case 3:
		 	cout << "benar itu adalah 3" << endl;
		 case 4:
		 	cout << "benar itu adalah 4" << endl;
		 case 5:
		 	cout << "benar itu adalah 5" << endl;
		 default:
		 	cout << "angka tidak ditemukan" << endl;
	}

	cout << "akhir dari program" << endl;
	
	return 0;
}