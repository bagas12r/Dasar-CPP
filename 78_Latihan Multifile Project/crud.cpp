#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include "crud.h"

void crud::writeData(std::fstream &data, int posisi, Mahasiswa &inputMahasiswa){
		data.seekp((posisi -1) * sizeof(Mahasiswa), std::ios::beg); // mencari posisi mahasiswa dari size nya mulai data awal
		data.write(reinterpret_cast<char*>(&inputMahasiswa), sizeof(Mahasiswa));
	}

crud::Mahasiswa crud::readData(std::fstream &data, int posisi){ // membaca data mahasiswa dari binary
		Mahasiswa readMahasiswa; // membuat variabel readMahasiswa dari fungsi Mahasiswa
		data.seekg((posisi -1) * sizeof(Mahasiswa), std::ios::beg);
		data.read(reinterpret_cast<char*>(&readMahasiswa),sizeof(Mahasiswa));
		return readMahasiswa;
	}

int crud::getDataSize(std::fstream &data){
		int start, end;
		data.seekg(0, std::ios::beg); // mencari data paling awal
		start = data.tellg();
		data.seekg(0, std::ios::end);
		end = data.tellg();
		return (end-start)/sizeof(Mahasiswa);
	}

void crud::displayDataMahasiswa(std::fstream &data){ // fungsi menampilkan data mahasiswa
		int size = crud::getDataSize(data); // yang ditampilkan adalah seluruh data mahasiswa
		Mahasiswa showMahasiswa; // membuat variabel showMahasiswa dari fungsi Mahsiswa
		std::cout << "no.\tpk.\tNIM.\tNama.\tJurusan." << std::endl; // menampilkan sub menu mahasiswa
		for(int i = 1; i <= size; i++){ // membaca keseluruhan data // mulai dari 1 karena seekg ber rumus -1
			showMahasiswa = readData(data, i);
			std::cout << i << "\t";
			std::cout << showMahasiswa.pk << "\t"; // menampilkan pk
			std::cout << showMahasiswa.NIM << "\t"; // menampilkan NIM
			std::cout << showMahasiswa.nama << "\t"; // menampilkan nama
			std::cout << showMahasiswa.jurusan << std::endl; // menampilkan jurusan
		}
	}

void crud::checkDatabase(std::fstream &data){ // membuat fungsi cek file data
		data.open("data.bin", std::ios::out | std::ios::in | std::ios::binary); // membaca dan menguba dalam bentuk binary

		// check file ada atau tidak
		if (data.is_open()){ // jika data ditemukan dan terbuka,maka data itu ada
			std::cout << "database ditemukan" << std::endl;
		} else {
			std::cout << "database tidak ditemukan, buat database baru" << std::endl;
			data.close();
			data.open("data.bin", std::ios::trunc | std::ios::out | std::ios::in | std::ios::binary); // trunc berfungsi ketika file ada maupun tidak ada, akan dibuatkan file kosong baru dan menimpa file sebelumnya
		}
	}

	int crud::get0ption(){
		int input;
		system("cls"); // agar console otomatis menghapus tampilan agar bersih mulai awal
		std::cout << "\nProgram CRUD data mahasiswa" << std::endl;
		std::cout << "=============================" << std::endl;
		std::cout << "1. Tambah data mahasiswa" << std::endl;
		std::cout << "2. Tampilkan data mahasiswa" << std::endl;
		std::cout << "3. Ubah data mahasiswa" << std::endl;
		std::cout << "4. Hapus data mahasiswa" << std::endl;
		std::cout << "5. Selesai" << std::endl;
		std::cout << "=============================" << std::endl;
		std::cout << "Pilih [1-5]? : ";
		std::cin >> input;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
		return input;
	}

	void crud::addDataMahasiswa(std::fstream &data){

		Mahasiswa inputMahasiswa, lastMahasiswa; // menambah variabel inputMahasiswa dengan fungsi struct Mahasiswa

		int size = crud::getDataSize(data);

		std::cout << "ukuran data : " << size << std::endl; // readData(data,size);

		if(size == 0){
			inputMahasiswa.pk = 1;
		} else {
			lastMahasiswa = crud::readData(data, size);
			std::cout << "pk = " << lastMahasiswa.pk << std::endl;
			inputMahasiswa.pk = lastMahasiswa.pk + 1;
		}

		std::cout << "nama: ";
		std::getline(std::cin, inputMahasiswa.nama); // membaca satu baris dari input nama
		std::cout << "Jurusan: ";
		std::getline(std::cin, inputMahasiswa.jurusan); // membaca satu baris dari input jurusan
		std::cout << "NIM: ";
		std::getline(std::cin, inputMahasiswa.NIM); // membaca satu baris dari input nama

		crud::writeData(data, size+1 , inputMahasiswa);
	}

	

	void crud::updateRecord(std::fstream &data){ // fungsi untuk update
		int nomor;
		Mahasiswa updateMahasiswa; // membuat variabel updateMahasiswa dengan fungsi Mahasiswa
		std::cout << "pilih no: ";
		std::cin >> nomor;

		updateMahasiswa = crud::readData(data, nomor); // membaca data berdasarkan kolom nomor

		std::cout << "\n\n pilihan data: " << std::endl; // menampilkan data sebelum diubah
		std::cout << "NIM : " << updateMahasiswa.NIM << std::endl;
		std::cout << "nama : " << updateMahasiswa.nama << std::endl;
		std::cout << "jurusan : " << updateMahasiswa.jurusan << std::endl;

		std::cout << "\nMerubah data: " << std::endl; // merubah data
		std::cout << "NIM: ";
		std::getline(std::cin, updateMahasiswa.NIM); // memasukan data NIM untuk megupdate variabel NIM
		std::cout << "nama: ";
		std::getline(std::cin, updateMahasiswa.nama); // memasukan data nama untuk megupdate variabel nama
		std::cout << "jurusan: ";
		std::getline(std::cin, updateMahasiswa.jurusan); // memasukan data jurusan untuk megupdate variabel jurusan

		crud::writeData(data, nomor, updateMahasiswa); // menulis dan mengupdate data ke variabel update Mahasiswa berdasarkan kolom nomor
	}
	void crud::deleteRecord(std::fstream &data){
		int nomor, size, offset;
		Mahasiswa blankMahasiswa, tempMahasiswa; // blank untuk file kosong, temp untuk file sementara
		std::fstream dataSementara;

		size = crud::getDataSize(data);
		// 1.Pilih nomor
		std::cout << "Hapus nomor: ";
		std::cin >> nomor;
		// 2.Di posisi ini diisi dengan data kosong
		crud::writeData(data,nomor,blankMahasiswa);
		// 3.Kita cek data yang ada dari file data.bin, kalau ada data kita pindahkan ke file sementara
		dataSementara.open("temp.dat", std::ios::trunc | std::ios::out | std::ios::in | std::ios::binary); // membuat data sementara

		offset = 0;

		for (int i = 1; i <= size; i++){
			tempMahasiswa = crud::readData(data,i);

			if (!tempMahasiswa.nama.empty()){ // jika file temp kosong
				crud::writeData(dataSementara, i - offset, tempMahasiswa);
			} else {
				offset++;
				std::cout << "deleted item" << std::endl;
			}
		}	
		// 4.Kita pindahkan data dari file sementara ke data.bin
		size = crud::getDataSize(dataSementara);
		data.close();
		data.open("data.bin", std::ios::trunc | std::ios::out | std::ios::binary); // menimba ke data bin
		data.close();
		data.open("data.bin", std::ios::out | std::ios::in | std::ios::binary);

		for (int i = 1; i <= size; i++){
			tempMahasiswa = crud::readData(dataSementara, i);
			crud::writeData(data,i,tempMahasiswa);
		}
	}


// ===========================================================================================================