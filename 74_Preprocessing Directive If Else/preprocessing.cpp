#include <iostream>

#define ID 1

#if ID == 1 // memulai fungsi IF
	#define LANG "Indonesia"
#else
	#define LANG "English"
#endif
 		// endif = akhir dari IF

 using namespace std;

 int main(){

 	cout << "Bahasa dipilih: " << LANG << endl;

 	cin.get();
 	return 0;
 }
 
