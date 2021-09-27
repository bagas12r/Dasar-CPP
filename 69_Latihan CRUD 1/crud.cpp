#include <iostream>
#include <string>
using namespace std;

int get0ption(); // prototype

int main(){

	int pilihan =  get0ption();
	char is_continue;

	enum option{CREATE = 1, READ, UPDATE, DELETE, FINISH}; // kata pengganti untuk angka 1 sampai 5, agar memudahkan orang lain membaca program kita

	while(pilihan != FINISH){ // karena finish = 5
		
		switch(pilihan){
			case CREATE: // CREATE adalah kata ganti angka 1
			cout << "Menambah data mahasiswa" << endl;
			break;
			case READ: // READ adalah kata ganti angka 2
			cout << "Menambah data mahasiswa" << endl;
			break;
			case UPDATE: // UPDATE adalah kata ganti angka 3
			cout << "Menambah data mahasiswa" << endl;
			break;
			case DELETE: // DELETE adalah kata ganti angka 4
			cout << "Hapus data mahasiswa" << endl;
			break;
			default:
			cout << "Pilihan tidak ditemukan" << endl;
			break;

		}
			label_continue: // menandai agar program dimulai lagi dari baris ini jika diperintahkan
		
		cout << "Lanjutkan?(y/n) : ";
		cin >> is_continue;
		if ( (is_continue == 'y') | (is_continue == 'Y')){ // jika menekan y / Y maka program lanjut
			pilihan = get0ption();
		} else if ((is_continue == 'n') | (is_continue == 'N')){
			break; // jika menekan n / N maka program akan berhenti
		} else {
			goto label_continue; // menuju ke baris program yang ditandai sebelumnya yaitu label_continue
		}
	}

	cout << "akhir dari program" << endl;


	cin.get();
	return 0;
}

int get0ption(){
	int input;
	system("cls"); // agar console otomatis menghapus tampilan agar bersih mulai awal
	cout << "\nProgram CRUD data mahasiswa" << endl;
	cout << "=============================" << endl;
	cout << "1. Tambah data mahasiswa" << endl;
	cout << "2. Tampilkan data mahasiswa" << endl;
	cout << "3. Ubah data mahasiswa" << endl;
	cout << "4. Hapus data mahasiswa" << endl;
	cout << "5. Selesai" << endl;
	cout << "=============================" << endl;
	cout << "Pilih [1-5]? : ";
	cin >> input;
	return input;
}