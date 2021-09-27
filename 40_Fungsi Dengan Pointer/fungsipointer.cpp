#include <iostream>
using namespace std;
// prototype
void fungsi(int *);
void kuadrat(int *);

int main(){
	int a = 5;
	cout << "address a : " << &a << endl;
	cout << "nilai a : " << a << endl;

	fungsi (&a);

	// fungsi (&a); // fungsi dengan input pointer
	kuadrat (&a);
	cout << "nilai kuadrat dari a : " << a << endl;

	fungsi (&a);

	cin.get();
	return 0;
}

void fungsi(int *b){
	cout << "address b : " << b << endl;
	cout << "nilai b : " << *b << endl; // deferencing
}

void kuadrat(int *valPtr){    //valPtr untuk menggantikan variabel
	*valPtr = (*valPtr) * (*valPtr);
}
