// Program ini dibuat oleh :
// Dio Farrel Putra Rachmawan (19081010144)
// Mahasiswa program studi Informatika UPN "Veteran" Jawa Timur.
// dibuat sebagai final project mata kuliah Pemrograman Lanjut

#include <iostream>
#include <conio.h>
#include <string.h>
#include <fstream>	//operasi file untuk bisa menulis dan membaca file
#define maks 100	//mendefinisikan nilai maks

using namespace std;

//inisialisasi struct
struct pegawai{
	char no[25];
	char nama[50];
	char jabatan[20];
	char jk[15];
	char no_telp[15];
	char alamat[75];
};

int main(){
	
	ifstream fi;	//perintah untuk membaca data dari file
	ofstream fo;	//perintah untuk menulis data ke dalam file
	pegawai pgw;	//pendefinisian variabel dari struct
	char search[maks],loop,del[maks];
	int n,i,pilihan,pil;
	
	do{	//looping untuk menampilkan input menu utama
		cout<<"===================================================================="<<endl;
		cout<<"\t\tPROGRAM PENDATAAN PEGAWAI PERUSAHAAN"<<endl;
		cout<<"===================================================================="<<endl;
		cout<<"[1] Tambah Data Pegawai"<<endl;
		cout<<"[2] Lihat Data Pegawai"<<endl;
		cout<<"[3] Cari Data Pegawai"<<endl;
		cout<<"[4] Hapus Data Pegawai"<<endl;
		cout<<"[0] Keluar"<<endl;
		cout<<"===================================================================="<<endl;
		cout<<"Masukkan pilihan anda : ";
		cin>>pilihan;
		
		//sekuensial untuk mengecek menu pilihan user
		if(pilihan==1){
			//bagian ini untuk menginputkan data pegawai ke dalam file oleh user
			system ("cls");
			cout<<"===================================================================="<<endl;
			cout<<"\t\tINPUT DATA PEGAWAI PERUSAHAAN"<<endl;
			cout<<"===================================================================="<<endl;
			cout<<"Berapa jumlah pegawai? ";
			cin>>i;
			cout<<"===================================================================="<<endl;
			
			//membuka file agar bisa ditulis
			fo.open("pgw.dat", ios::binary | ios::app);
			
			for(n=0; n<i; n++){
				cout<<"\nPegawai ke- "<<n+1;
				cout<<"\n";
				cout<<"Nomor Pegawai\t: ";
				cin>>pgw.no;
				cout<<"Nama Lengkap\t: ";
				fflush(stdin); gets(pgw.nama);
				cout<<"Jenis Kelamin\t: ";
				cin>>pgw.jk;
				cout<<"Jabatan\t\t: ";
				cin>>pgw.jabatan;
				cout<<"Alamat\t\t: ";
				fflush(stdin); gets(pgw.alamat);
				cout<<"Nomor Telepon\t: ";
				cin>>pgw.no_telp;
				fo.write((char *) &pgw, sizeof(pgw));	//menuliskan seluruh data dari isi alamat pgw ke dalam file
			}
			fo.close();	//menutup file
			cout<<"\nData berhasil ditambahkan!";
			
		}else if(pilihan==2){
			//bagian ini untuk menampilkan seluruh data yang telah diinputkan user
			system("cls");
			cout<<"===================================================================="<<endl;
			cout<<"\t\t\tDATA PEGAWAI PERUSAHAAN"<<endl;
			cout<<"===================================================================="<<endl;
			
			//membuka file agar bisa dibaca
			fi.open("pgw.dat", ios::binary);
			int j=1;
			
			//membaca seluruh isi data dari file
			while(fi.read((char *) &pgw, sizeof(pgw))){
				cout<<"\nPegawai ke- "<<j++;
				cout<<"\nNomor Pegawai\t: "<<pgw.no;
				cout<<"\nNama Lengkap\t: "<<pgw.nama;
				cout<<"\nJenis Kelamin\t: "<<pgw.jk;
				cout<<"\nJabatan\t\t: "<<pgw.jabatan;
				cout<<"\nAlamat\t\t: "<<pgw.alamat;
				cout<<"\nNomor Telepon\t: "<<pgw.no_telp;
				cout<<"\n";
			}
			fi.close();	//menutup file
		}else if(pilihan==3){
			//bagian ini untuk mencari data tertentu berdasarkan kata kunci
			system("cls");
			cout<<"===================================================================="<<endl;
			cout<<"\t\tCARI DATA PEGAWAI PERUSAHAAN"<<endl;
			cout<<"===================================================================="<<endl;
			cout<<"[1] Cari dari Nomor Pegawai"<<endl;
			cout<<"[2] Cari dari Nama Pegawai"<<endl;
			cout<<"[3] Cari dari Jabatan Pegawai"<<endl;
			cout<<"[0] Cancel"<<endl;
			cout<<"===================================================================="<<endl;
			cout<<"Masukkan pilihan anda : ";
			cin>>pil;
			
			if(pil==1){
				//bagian ini akan dijalankan jika user ingin mencari data berdasarkan nomor pegawai
				system("cls");
				cout<<"===================================================================="<<endl;
				cout<<"\t\tCARI DATA PEGAWAI PERUSAHAAN"<<endl;
				cout<<"===================================================================="<<endl;
				cout<<"Masukkan Nomor Pegawai : ";
    			cin>>search;
    			cout<<"===================================================================="<<endl;
    			
				//membuka file agar bisa dibaca
    			fi.open("pgw.dat", ios::binary);
    			
    			//membaca setiap isi data pada file
				while(fi.read((char *) &pgw, sizeof(pgw))){
					//pengecekan apakah ada data yang sesuai dengan kata kunci atau tidak, jika ada maka akan ditampilkan
        			if(strcmp(pgw.no, search) == 0){
            			cout<<"\nData Berhasil Ditemukan!\t\t";
            			cout<<"\nNomor Pegawai\t: "<<pgw.no;
						cout<<"\nNama Lengkap\t: "<<pgw.nama;
						cout<<"\nJenis Kelamin\t: "<<pgw.jk;
						cout<<"\nJabatan\t\t: "<<pgw.jabatan;
						cout<<"\nAlamat\t\t: "<<pgw.alamat;
						cout<<"\nNomor Telepon\t: "<<pgw.no_telp;
						cout<<"\n";
        			}
    			}
    			fi.close();	//menutup file
			}else if(pil==2){
				//bagian ini akan dijalankan jika user ingin mencari data berdasarkan nama pegawai
				system("cls");
				cout<<"===================================================================="<<endl;
				cout<<"\t\tCARI DATA PEGAWAI PERUSAHAAN"<<endl;
				cout<<"===================================================================="<<endl;
				cout<<"Masukkan Nama Pegawai : ";
    			fflush(stdin); gets(search);
    			cout<<"===================================================================="<<endl;
    			
				//membuka file agar bisa dibaca
    			fi.open("pgw.dat", ios::binary);
    			
    			//membaca setiap isi data pada file
				while(fi.read((char *) &pgw, sizeof(pgw))){
    				//pengecekan apakah ada data yang sesuai dengan kata kunci atau tidak, jika ada maka akan ditampilkan
        			if(strcmp(pgw.nama, search) == 0){
            			cout<<"\nData Berhasil Ditemukan!\t\t";
	            		cout<<"\nNomor Pegawai\t: "<<pgw.no;
						cout<<"\nNama Lengkap\t: "<<pgw.nama;
						cout<<"\nJenis Kelamin\t: "<<pgw.jk;
						cout<<"\nJabatan\t\t: "<<pgw.jabatan;
						cout<<"\nAlamat\t\t: "<<pgw.alamat;
						cout<<"\nNomor Telepon\t: "<<pgw.no_telp;
						cout<<"\n";
	        		}
    			}
    			fi.close();	//menutup file
			}else if(pil==3){
				//bagian ini akan dijalankan jika user ingin mencari data dari jabatan pegawai
				system("cls");
				cout<<"===================================================================="<<endl;
				cout<<"\t\tCARI DATA PEGAWAI PERUSAHAAN"<<endl;
				cout<<"===================================================================="<<endl;
				cout<<"Masukkan Jabatan Pegawai : ";
    			fflush(stdin); gets(search);
    			cout<<"===================================================================="<<endl;
    			
				//membuka file agar bisa dibaca
    			fi.open("pgw.dat", ios::binary);
    			
    			//membaca setiap isi data pada file
				while(fi.read((char *) &pgw, sizeof(pgw))){
    				//pengecekan apakah ada data yang sesuai dengan kata kunci atau tidak, jika ada maka akan ditampilkan
        			if(strcmp(pgw.jabatan, search) == 0){
            			cout<<"\nData Berhasil Ditemukan!\t\t";
	            		cout<<"\nNomor Pegawai\t: "<<pgw.no;
						cout<<"\nNama Lengkap\t: "<<pgw.nama;
						cout<<"\nJenis Kelamin\t: "<<pgw.jk;
						cout<<"\nJabatan\t\t: "<<pgw.jabatan;
						cout<<"\nAlamat\t\t: "<<pgw.alamat;
						cout<<"\nNomor Telepon\t: "<<pgw.no_telp;
						cout<<"\n";
	        		}
    			}
    			fi.close();	//menutup file
			}else if(pil==0){
				//bagian ini dijalankan jika user membatalkan untuk mencari data
				system("cls");
				cout<<"===================================================================="<<endl;
				cout<<"\t\t\t\tCANCEL"<<endl;
				cout<<"===================================================================="<<endl;
			}else{
				//bagian ini akan dijalankan jika user salah memasukkan input pada menu pencarian data
				system("cls");
				cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!  OMG ERROR  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
			}
		}else if(pilihan==4){
			//bagian ini untuk menginputkan data pegawai ke dalam file oleh user
			system ("cls");
			cout<<"===================================================================="<<endl;
			cout<<"\t\tHAPUS DATA PEGAWAI PERUSAHAAN"<<endl;
			cout<<"===================================================================="<<endl;
			cout<<"Masukkan nomor pegawai yang ingin dihapus : ";
			cin>>del;
			cout<<"===================================================================="<<endl;
			
			int c=sizeof(pgw);
			int x=0,y,z;
			pegawai tmp[c];
			
			//membuka file untuk dibaca
			fi.open("pgw.dat", ios::binary);
			
			//memindahkan setiap data dari file ke dalam array of struct
			while(fi.read((char *) &pgw, sizeof(pgw))){
				strcpy(tmp[x].no, pgw.no);
				strcpy(tmp[x].nama, pgw.nama);
				strcpy(tmp[x].jk, pgw.jk);
				strcpy(tmp[x].jabatan, pgw.jabatan);
				strcpy(tmp[x].alamat, pgw.alamat);
				strcpy(tmp[x].no_telp, pgw.no_telp);
				x++;
			}
			fi.close();	//menutup data
			
			//mencari data untuk dihapus
			for(int a=0;a<x;a++){
				if(strcmp(tmp[a].no, del)==0){
					x--;
					for(int b=a; b<x; b++){
						strcpy(tmp[b].no, tmp[b+1].no);
						strcpy(tmp[b].nama, tmp[b+1].nama);
						strcpy(tmp[b].jk, tmp[b+1].jk);
						strcpy(tmp[b].jabatan, tmp[b+1].jabatan);
						strcpy(tmp[b].alamat, tmp[b+1].alamat);
						strcpy(tmp[b].no_telp, tmp[b+1].no_telp);
					}
					cout<<"\nData dengan nomor pegawai ["<<del<<"] berhasil terhapus!"<<endl;
				}
			}
			
			//memasukkan seluruh data baru dari array of struct ke dalam file baru
			fo.open("temp.dat", ios::binary | ios::app);
			for(n=0; n<x; n++){
				strcpy(pgw.no, tmp[n].no);
				strcpy(pgw.nama, tmp[n].nama);
				strcpy(pgw.jk, tmp[n].jk);
				strcpy(pgw.jabatan, tmp[n].jabatan);
				strcpy(pgw.alamat, tmp[n].alamat);
				strcpy(pgw.no_telp, tmp[n].no_telp);
				fo.write((char *) &pgw, sizeof(pgw));	//menuliskan seluruh data ke dalam file
			}
			fo.close();	//menutup file
			
			remove("pgw.dat");	//menghapus file lama
			rename("temp.dat","pgw.dat");	//mengubah nama file baru seperti file lama
			
		}else if(pilihan==0){
			//bagian ini akan dijalankan jika user memilih untuk keluar dari program
			system("cls");
			cout<<"===================================================================="<<endl;
			cout<<"\t\tANDA TELAH KELUAR DARI PROGRAM"<<endl;
			cout<<"===================================================================="<<endl;
		}else{
			//bagian ini akan dijalankan jika user memasukkan input yang salah pada menu utama
			system("cls");
			cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!  OMG ERROR  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
		}
		//looping untuk menawarkan user kembali ke menu utama
		cout<<"\nKembali ke Menu Utama [y/n]? ";
		cin>>loop;
		system("cls");
	}while(loop=='y' || loop=='Y');	//pengecekan apakah user ingin kembali ke menu utama atau tidak
	
	cout<<"===================================================================="<<endl;
	cout<<"\t\tPROGRAM BERHASIL TERTUTUP"<<endl;
	cout<<"===================================================================="<<endl;
	return 0;
}
