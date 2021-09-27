#include <iostream>
using namespace std;

int main()

		// flow v.1
{
	for(int i = 0; i <= 10; i++){
		if(i == 5){
			continue;
			//break;
		}
		cout << i << endl;
	}	 

	// flow v.2

	/* int i = 0;
	while(i <= 10){
		i++;
		if(i == 5){
			continue;
			//break;
		}
		cout << i << endl;
	*/	
	}


	cout << "akhirnya" << endl;

	cin.get();
	return 0;
}
