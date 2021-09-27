#include <iostream>
#include "bersama.h"
#include "foo.h"
#include "bar.h"

/*
#define FOO "foo lama"

// ifdef
#ifdef FOO // untuk memastikan FOO ada atau tidak
	#define TEST_FOO "foo ada" // jika foo terdeksi maka foo ada
#else
	#define TEST_FOO "foo tidak ada" // jika foo tidak terdeteksi maka foo tidak ada
#endif

// ifndef
#ifndef FOO // jika foo tidak ada (if not define foo)
	#define FOO "membuat foo baru" // maka akan membuat foo
#endif
// pragma once
*/

using namespace std;

int main(){

	/*
	cout << TEST_FOO << endl;
	cout << FOO << endl;
	*/

	Mahasiswa mahasiswa;
	mahasiswa.NIM = 10;
	cout << mahasiswa.NIM << endl;
	cin.get();
	return 0;
}
