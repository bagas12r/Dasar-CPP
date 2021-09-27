#include <iostream>
#include <string>
using namespace std;

int main(){

	// perbandingan string
	string input;
	string nama_rahasia("ucup");

	while(true){
		cout << "tebak nama : ";
		cin >> input;
		if(input == nama_rahasia){
			cout << "tebakan anda benar!!!!!" << endl;
			cout << "program selesai" << endl;
			break;
		}else{
			cout << "tebakan anda salah" << endl;
		}
	}

	/*
	 bisa juga menggunakan :
		while(true){
		cout << "tebak nama : ";
		cin >> input;
		if(input == nama_rahasia){
			cout << "tebakan anda benar!!!!!" << endl;
			break;
		}
			cout << "tebakan anda salah" << endl;
		}
	}
			cout << "program selesai" << endl;
	*/

	cin.get();
	return 0;
}
