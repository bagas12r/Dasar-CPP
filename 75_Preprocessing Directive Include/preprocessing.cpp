#include <iostream>
#include "library.h" // untuk mengcopy seluruh isi dari file atau library tersebut
#include <string>

#define PI 3.1459265359

using namespace std;

int main(){

	cout << "berhasil" << endl;

	cout << "PI : " << PI << endl;
	cout << "LUADRAT : " << KUADRAT(5) << endl; // fungsi diambil dari library.h
	cout << "MAX : " << MAX(10,2) << endl;
	cout << "data string : " << data << endl;

	cin.get();
	return 0;
}
