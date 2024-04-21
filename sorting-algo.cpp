#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>

using namespace std;

struct Mahasiswa{
	int nbi;
    string nama;
    int umur;
};

//set Mahasiswa
const int MAX_MAHASISWA = 100;
Mahasiswa mahasiswas[MAX_MAHASISWA];
int mahasiswaCount = 3;

//data dummy mahasiswa
void mahasiswaDummy(){
	mahasiswas[0].nbi = 3;
	mahasiswas[0].nama = "Rimba";
	mahasiswas[0].umur = 21;
	
	mahasiswas[1].nbi = 1;
	mahasiswas[1].nama = "Jun";
	mahasiswas[1].umur = 20;
	
	mahasiswas[2].nbi = 6;
	mahasiswas[2].nama = "Salim";
	mahasiswas[2].umur = 18;
}

void tambahMahasiswa(){
	int nbi, umur;
	string nama;
	
	cout << "Tambah Data Mahasiswa:\n";
	cout << "Masukkan NBI: ";
	cin >> nbi;
	cout << "Masukkan Nama: ";
	cin >> nama;
	cout << "Masukkan Umur: ";
	cin >> umur;
	
	if (mahasiswaCount < MAX_MAHASISWA) {
			mahasiswas[mahasiswaCount].nbi = nbi;
            mahasiswas[mahasiswaCount].nama = nama;
            mahasiswas[mahasiswaCount].umur = umur;
			mahasiswaCount++;
			cout << "Pengguna berhasil ditambahkan!\n" << endl;
		}
        else {
			cout << "Pengguna mencapai limit. Tidak dapat menambahkan pengguna lagi.\n" << endl;
		}
}

void deleteAllMahasiswa(){
	mahasiswaCount = 0;
    cout << "Semua data mahasiswa telah dihapus.\n\n";
}

void showAllMahasiswa(){
	cout << "Data Mahasiswa ALL:\n";
	if(mahasiswaCount == 0){
		cout << "Data Kosong\n";
	}
    for (int i = 0; i < mahasiswaCount; ++i) {
        cout << i + 1 << ". "
            << " NBI : " << setw(12) << left << mahasiswas[i].nbi
            << " Nama: " << setw(12) << left << mahasiswas[i].nama
            << " Umur: " << mahasiswas[i].umur << "\n";
    }
    cout << "\n";
}

//Metode Bubble Sort
void bubbleSort(){
	int plh;
	cout << "=== Metode Bubble Sort ===\n";
	cout << "1.Ascending\n";
	cout << "2.Descending\n";
	cout << "Urutkan Secara(Masukkan angka):";
	cin >> plh;
	if(plh == 1){
		//1,3,6
		cout << "Ascending: \n";
		for (int i = 0; i < mahasiswaCount - 1; ++i) {
        	for (int j = 0; j < mahasiswaCount - i - 1; ++j) {
            	if (mahasiswas[j].nbi > mahasiswas[j + 1].nbi) {
            	    // Tukar posisi
            	    Mahasiswa temp = mahasiswas[j];
            	    mahasiswas[j] = mahasiswas[j + 1];
            	    mahasiswas[j + 1] = temp;
            	}
        	}
    	}
	}else{
		//6,3,1
		cout << "Descending: \n";
		for (int a = 0; a < mahasiswaCount - 1; ++a) {
        	for (int b = 0; b < mahasiswaCount - a - 1; ++b) {
            	if (mahasiswas[b].nbi < mahasiswas[b + 1].nbi) { 
            	    // Tukar posisi
            	    Mahasiswa temp = mahasiswas[b];
            	    mahasiswas[b] = mahasiswas[b + 1];
            	    mahasiswas[b + 1] = temp;
            	}
        	}
    	}	
	}
    showAllMahasiswa();
}

//Metode Shell Sort
void shellSort(){
	int plh;
	cout << "=== Metode Shell Sort ===\n";
	cout << "1.Ascending\n";
	cout << "2.Descending\n";
	cout << "Urutkan Secara(Masukkan angka):";
	cin >> plh;
	
	if(plh == 1){
		for (int gap = mahasiswaCount / 2; gap > 0; gap /= 2) {
        	for (int i = gap; i < mahasiswaCount; i++) {
            	Mahasiswa temp = mahasiswas[i];
            	int j;
            	for (j = i; j >= gap && mahasiswas[j - gap].nbi > temp.nbi; j -= gap) {
            	    mahasiswas[j] = mahasiswas[j - gap];
            	}
            	mahasiswas[j] = temp;
        	}
    	}
	}else{
		for (int gap = mahasiswaCount / 2; gap > 0; gap /= 2) {
        	for (int i = gap; i < mahasiswaCount; i++) {
            	Mahasiswa temp = mahasiswas[i];
            	int j;
            	for (j = i; j >= gap && mahasiswas[j - gap].nbi < temp.nbi; j -= gap) {
            	    mahasiswas[j] = mahasiswas[j - gap];
            	}
            	mahasiswas[j] = temp;
        	}
    	}
	}
	showAllMahasiswa();
}

//Metode Selection Sort
void selectionSort(){
	int plh;
	cout << "=== Metode Selection Sort ===\n";
	cout << "1.Ascending\n";
	cout << "2.Descending\n";
	cout << "Urutkan Secara(Masukkan angka):";
	cin >> plh;
	
	if(plh == 1){
		cout << "Ascending: \n";
    	for (int i = 0; i < mahasiswaCount - 1; ++i) {
    	    int minIndex = i;
    	    for (int j = i + 1; j < mahasiswaCount; ++j) {
    	        if (mahasiswas[j].nbi < mahasiswas[minIndex].nbi) {
    	            minIndex = j;
    	        }
    	    }
    	    if (minIndex != i) {
    	        Mahasiswa temp = mahasiswas[i];
    	        mahasiswas[i] = mahasiswas[minIndex];
    	        mahasiswas[minIndex] = temp;
    	    }
    	}
	}else{
		cout << "Descending: \n";
    	for (int i = 0; i < mahasiswaCount - 1; ++i) {
        	int maxIndex = i;
        	for (int j = i + 1; j < mahasiswaCount; ++j) {
        	    if (mahasiswas[j].nbi > mahasiswas[maxIndex].nbi) {
        	        maxIndex = j;
        	    }
        	}
        	if (maxIndex != i) {
        	    // Tukar posisi
        	    Mahasiswa temp = mahasiswas[i];
        	    mahasiswas[i] = mahasiswas[maxIndex];
        	    mahasiswas[maxIndex] = temp;
        	}
    	}
	}
	showAllMahasiswa();
}

//Metode Quick Short
int partitionAsc(Mahasiswa mahasiswas[], int start, int end)
{
 
    Mahasiswa pivot = mahasiswas[start];
 
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (mahasiswas[i].nbi <= pivot.nbi)
            count++;
    }
 
    // Giving pivot element its correct position
    int pivotIndex = start + count;
    swap(mahasiswas[pivotIndex], mahasiswas[start]);
 
    // Sorting left and right parts of the pivot element
    int i = start, j = end;
 
    while (i < pivotIndex && j > pivotIndex) {
 
        while (mahasiswas[i].nbi <= pivot.nbi) {
            i++;
        }
 
        while (mahasiswas[j].nbi > pivot.nbi) {
            j--;
        }
 
        if (i < pivotIndex && j > pivotIndex) {
            swap(mahasiswas[i++], mahasiswas[j--]);
        }
    }
 
    return pivotIndex;
}
 
void quickSortAsc(Mahasiswa mahasiswas[], int start, int end)
{
 
    // base case
    if (start >= end)
        return;
 
    // partitioning the array
    int p = partitionAsc(mahasiswas, start, end);
 
    // Sorting the left part
    quickSortAsc(mahasiswas, start, p - 1);
 
    // Sorting the right part
    quickSortAsc(mahasiswas, p + 1, end);
}

int partitionDesc(Mahasiswa mahasiswas[], int start, int end)
{
    Mahasiswa pivot = mahasiswas[start];
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (mahasiswas[i].nbi >= pivot.nbi) // Change <= to >= for descending order
            count++;
    }

    int pivotIndex = start + count;
    swap(mahasiswas[pivotIndex], mahasiswas[start]);

    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex) {
        while (mahasiswas[i].nbi >= pivot.nbi) { // Change <= to >=
            i++;
        }

        while (mahasiswas[j].nbi < pivot.nbi) { // Change > to <
            j--;
        }

        if (i < pivotIndex && j > pivotIndex) {
            swap(mahasiswas[i++], mahasiswas[j--]);
        }
    }

    return pivotIndex;
}

void quickSortDesc(Mahasiswa mahasiswas[], int start, int end)
{
    if (start >= end)
        return;

    int p = partitionDesc(mahasiswas, start, end);

    quickSortDesc(mahasiswas, p + 1, end); // Sort the right part first
    quickSortDesc(mahasiswas, start, p - 1); // Then sort the left part
}

void quickSort(Mahasiswa mahasiswas[], int start, int end){
	int plh;
	cout << "=== Metode Quick Short ===\n";
	cout << "1.Ascending\n";
	cout << "2.Descending\n";
	cout << "Urutkan Secara(Masukkan angka):";
	cin >> plh;
	
	if(plh == 1){
		cout << "Ascending: \n";
    	quickSortAsc(mahasiswas, 0, mahasiswaCount-1);
	}else{
		cout << "Descending: \n";
		quickSortDesc(mahasiswas, 0, mahasiswaCount-1);
    	
	}
	showAllMahasiswa();
}

//Metode insertion Sort
void insertionSort(){
	int plh;
    Mahasiswa temp;
	cout << "=== Metode Insertion Sort ===\n";
	cout << "1.Ascending\n";
	cout << "2.Descending\n";
	cout << "Urutkan Secara(Masukkan angka):";
	cin >> plh;
	
	if(plh == 1){
		cout << "Ascending: \n";
    	int i, j;
    	Mahasiswa key;
    	for (i = 1; i < mahasiswaCount; i++) {
        	key = mahasiswas[i];
        	j = i - 1;

        	while (j >= 0 && mahasiswas[j].nbi > key.nbi) {
        	    mahasiswas[j + 1] = mahasiswas[j];
        	    j = j - 1;
        	}
        	mahasiswas[j + 1] = key;
    	}
	}else{
		cout << "Descending: \n";
		int k, l;
		Mahasiswa key;
    	for (k = 1; k < mahasiswaCount; k++) {
        	key = mahasiswas[k];
        	l = k - 1;

        	while (l >= 0 && mahasiswas[l].nbi < key.nbi) {
        	    mahasiswas[l + 1] = mahasiswas[l];
        	    l = l - 1;
        	}
        	mahasiswas[l + 1] = key;
    	}
    	
	}
	showAllMahasiswa();
}

int main() {
	int pilih, start;
	
	mahasiswaDummy();
	do{
		cout << "=== Tambah Data ===\n";
		cout << "1.Tambah Mahasiswa\n";
		cout << "2.Delete All Mahasiswa\n";
		cout << "3.Show All Mahasiswa\n\n";
	
		cout << "=== Metode Sorting(berdasarkan NBI) ===\n";
		cout << "4. Buble Sort\n";
		cout << "5. Shell Sort\n";
		cout << "6. Selection Sort\n";
		cout << "7. Quick Sort\n";
		cout << "8. Insertion Sort\n";
		cout << "9. Program Berhenti\n";
		cout << "Pilih Opsi: ";
		cin >> pilih;
		
		switch(pilih){
			case 1:
				system("CLS");
				tambahMahasiswa();
				break;
			case 2:
				system("CLS");
				deleteAllMahasiswa();
				break;
			case 3:
				system("CLS");
				showAllMahasiswa();
				break;
			case 4:
				system("CLS");
				bubbleSort();
				break;
			case 5:
				system("CLS");
				shellSort();
				break;
			case 6:
				system("CLS");
				selectionSort();
				break;
			case 7:
				system("CLS");
				quickSort(mahasiswas, 0, mahasiswaCount - 1);
				break;
			case 8:
				system("CLS");
				insertionSort();
				break;
			case 9:
				cout << "Program Berhenti";
				return 0;
			default:
				cout << "Pilihan tidak valid. Silakan coba lagi.\n" << endl;
            	break;
		}	
	}while(pilih != 9);
}