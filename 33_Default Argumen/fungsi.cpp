#include <iostream>
using namespace std;

// fungsi prototipe
double volume_kubus(double p = 1, double l = 1, double t = 1); // diisi dengan "=" agar dapat menambahkan default atau standart angka jika tidak dimasukan angka yang kita inginkan

int main(){
	
	cout << " volume kubus : " << volume_kubus(3,4,5) << endl;
	cout << " volume kubus : " << volume_kubus(3,4) << endl;
	cout << " volume kubus : " << volume_kubus(3) << endl;
	cout << " volume kubus : " << volume_kubus() << endl;


	cin.get();
	return 0;
}

// default argumen atau nilai standar nya jika tidak diisi angka apapun
double volume_kubus(double p, double l, double t){
	return p * l * t;
}
