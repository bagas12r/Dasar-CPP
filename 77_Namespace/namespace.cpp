#include <iostream>
#include "otong.h"


void fungsi2(){
	std::cout << "ini adalah fungsi biasa" << std::endl;
}

using namespace otong; // sama seperti std jadi kita tidak perlu menambahkan otong::   sebelum memulai syntax

int main(){

	fungsi2();
	std::cout << otong::b << std::endl;
	otong::fungsi(); // mesikipun tidak memakai otong:: tetap bisa karena sudah using namespace otong
	otong::cout(100);

	std::cin.get();
	return 0;
}
