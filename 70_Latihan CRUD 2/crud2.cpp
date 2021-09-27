#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Mahasiswa {
	int pk;
	string NIM; // menggunakan string karena jika menggunakan int saat angka awal 0 tidak bisa dibaca dengan int
	string nama;
	string jurusan;	
};
// prototype =============================
int get0ption();
void checkDatabase(fstream &data);
void writeData(fstream &data, int posisi, Mahasiswa &inputMahasiswa);
int getDataSize(fstream &data);
Mahasiswa readData(fstream &data, int posisi);
void addDataMahasiswa(fstream &data);
void displayDataMahasiswa(fstream &data);
// ========================================

int main(){

	fstream data;

	checkDatabase(data); // menampilkan fungsi cek data

	int pilihan =  get0ption();
	char is_continue;

	enum option{CREATE = 1, READ, UPDATE, DELETE, FINISH}; // kata pengganti untuk angka 1 sampai 5, agar memudahkan orang lain membaca program kita

	while(pilihan != FINISH){ // karena finish = 5
		
		switch(pilihan){
			case CREATE: // CREATE adalah kata ganti angka 1
			cout << "Menambah data mahasiswa" << endl;
			addDataMahasiswa(data); // menggunakan fungsi add data
			break;
			case READ: // READ adalah kata ganti angka 2
			cout << "Menambah data mahasiswa" << endl;
			displayDataMahasiswa(data); // menggunakan fungsi display data
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

void checkDatabase(fstream &data){ // membuat fungsi cek file data
	data.open("data.bin", ios::out | ios::in | ios::binary); // membaca dan menguba dalam bentuk binary

	// check file ada atau tidak
	if (data.is_open()){ // jika data ditemukan dan terbuka,maka data itu ada
		cout << "database ditemukan" << endl;
	} else {
		cout << "database tidak ditemukan, buat database baru" << endl;
		data.close();
		data.open("data.bin", ios::trunc | ios::out | ios::in | ios::binary); // trunc berfungsi ketika file ada maupun tidak ada, akan dibuatkan file kosong baru dan menimpa file sebelumnya
	}
}

// fungsi=====================================================================================================================

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
	//cin.ignore(numeric_limits<streamsize>::max(),'\n');
	return input;
}

void writeData(fstream &data, int posisi, Mahasiswa &inputMahasiswa){
	data.seekp((posisi -1) * sizeof(Mahasiswa), ios::beg); // mencari posisi mahasiswa dari size nya mulai data awal
	data.write(reinterpret_cast<char*>(&inputMahasiswa), sizeof(Mahasiswa));
}

int getDataSize(fstream &data){
	int start, end;
	data.seekg(0, ios::beg); // mencari data paling awal
	start = data.tellg();
	data.seekg(0, ios::end);
	end = data.tellg();
	return (end-start)/sizeof(Mahasiswa);
}

Mahasiswa readData(fstream &data, int posisi){ // membaca data mahasiswa dari binary
	Mahasiswa readMahasiswa; // membuat variabel readMahasiswa dari fungsi Mahasiswa
	data.seekg((posisi -1) * sizeof(Mahasiswa), ios::beg);
	data.read(reinterpret_cast<char*>(&readMahasiswa),sizeof(Mahasiswa));
	return readMahasiswa;
}

void addDataMahasiswa(fstream &data){

	Mahasiswa inputMahasiswa, lastMahasiswa; // menambah variabel inputMahasiswa dengan fungsi struct Mahasiswa

	int size = getDataSize(data);

	cout << "ukuran data : " << size << endl; // readData(data,size);

	if(size == 0){
		inputMahasiswa.pk = 1;
	} else {
		lastMahasiswa = readData(data, size);
		cout << "pk = " << lastMahasiswa.pk << endl;
		inputMahasiswa.pk = lastMahasiswa.pk + 1;
	}

	cout << "nama: ";
	getline(cin, inputMahasiswa.nama); // membaca satu baris dari input nama
	cout << "Jurusan: ";
	getline(cin, inputMahasiswa.jurusan); // membaca satu baris dari input jurusan
	cout << "NIM: ";
	getline(cin, inputMahasiswa.NIM); // membaca satu baris dari input nama

	writeData(data, size+1 , inputMahasiswa);
}

void displayDataMahasiswa(fstream &data){ // fungsi menampilkan data mahasiswa
	int size = getDataSize(data); // yang ditampilkan adalah seluruh data mahasiswa
	Mahasiswa showMahasiswa; // membuat variabel showMahasiswa dari fungsi Mahsiswa
	cout << "no.\tpk.\tNIM.\tNama.\tJurusan." << endl; // menampilkan sub menu mahasiswa
	for(int i = 1; i <= size; i++){ // membaca keseluruhan data // mulai dari 1 karena seekg ber rumus -1
		showMahasiswa = readData(data, i);
		cout << i << "\t";
		cout << showMahasiswa.pk << "\t"; // menampilkan pk
		cout << showMahasiswa.NIM << "\t"; // menampilkan NIM
		cout << showMahasiswa.nama << "\t"; // menampilkan nama
		cout << showMahasiswa.jurusan << "\t"; // menampilkan jurusan
	}
}

// ===========================================================================================================