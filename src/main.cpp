#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>

using namespace std;

void inputkartu (vector<string> *kartu_input){
    /*
    I.S. Menerima sebuah vector string
    F.S. Mengisi vector string dengan 4 kartu yang diinput
    */

    string temp;
    cout << "Masukkan 4 kartu (A,2,3,4,5,6,7,8,9,10,J,Q,K) : ";
    for (int i = 0 ; i < 4 ; i++){
        cin >> temp;
        kartu_input->push_back(temp);
    }
}

string inttostr(int num){
    /*
    I.S. Menerima sebuah integer
    F.S. Mengembalikan nilai integer tersebut dalam bentuk string
    */

    string str = "";
    while (num > 0){
        str = (char)(num % 10 + 48) + str;
        num /= 10;
    }
    return str;
}

double strtodouble(string c){
    /*
    I.S. Menerima sebuah string
    F.S. Mengembalikan nilai kartu tersebut dalam bentuk integer
    */

    if (c == "A"){
        return 1.0;
    }
    else if (c == "J"){
        return 11.0;
    }
    else if (c == "Q"){
        return 12.0;
    }
    else if (c == "K"){
        return 13.0;
    }
    else if (c == "2"){
        return 2.0;
    }
    else if (c == "3"){
        return 3.0;
    }
    else if (c == "4"){
        return 4.0;
    }
    else if (c == "5"){
        return 5.0;
    }
    else if (c == "6"){
        return 6.0;
    }
    else if (c == "7"){
        return 7.0;
    }
    else if (c == "8"){
        return 8.0;
    }
    else if (c == "9"){
        return 9.0;
    }
    else if (c == "10"){
        return 10.0;
    }
    else{ // Jika input salah
        return 999.0;
    }
}

string inttoop(int op){
    /*
    I.S. Menerima sebuah integer
    F.S. Mengembalikan nilai operator tersebut dalam bentuk string
    */

    if (op == 0){
        return "+";
    }
    else if (op == 1){
        return "-";
    }
    else if (op == 2){
        return "*";
    }
    else if (op == 3){
        return "/";
    }
}

double operasi (double a, double b, int op){
    /*
    I.S. Menerima dua buah bilangan dan sebuah operator
    F.S. Mengembalikan hasil operasi antara dua buah bilangan tersebut
    */

    if (op == 0){
        return a+b;
    }
    else if (op == 1){
        return a-b;
    }
    else if (op == 2){
        return a*b;
    }
    else if (op == 3){
        return a/b;
    }
}

bool isduplicate(vector<string> *hasil, string str){
    /*
    I.S. Menerima sebuah vector string dan sebuah string
    F.S. Mengembalikan true jika string tersebut sudah ada di dalam vector string
    */

    for (int i = 0 ; i < hasil->size() ; i++){
        if (hasil->at(i) == str){
            return true;
        }
    }
    return false;
}

void validator24 (double nums[4], vector<string> *hasil){
    /*
    I.S. Menerima sebuah array of double dan sebuah vector string
    F.S. Mengisi vector string dengan semua kemungkinan operasi yang menghasilkan 24
    */

    double a = nums[0];
    double b = nums[1];
    double c = nums[2];
    double d = nums[3];
    string temp = "";
    for (int i = 0 ; i < 4 ; i++){
        for (int j = 0 ; j < 4 ; j++){
            for (int k = 0 ; k < 4 ; k++){
                // KEMUNGKINAN OPERASI
                // X adalah operator * / + -
                    // i or j or k = 0 -> +
                    // i or j or k = 1 -> -
                    // i or j or k = 2 -> *
                    // i or j or k = 3 -> /

                // (a X b) X (c X d)
                if (operasi(operasi(a,b,i),operasi(c,d,k),j) == 24.0){
                    temp = "(" + inttostr(a) + " " + inttoop(i) + " " + inttostr(b) + ") " + inttoop(j) + " (" + inttostr(c) + " " + inttoop(k) + " " + inttostr(d) + ")";
                    if (!isduplicate(hasil,temp)){
                        hasil->push_back(temp);
                    }
                }

                // a X (b X (c X d))
                if (operasi(a,operasi(b,operasi(c,d,k),j),i) == 24.0){
                    temp = inttostr(a) + " " + inttoop(i) + " (" + inttostr(b) + " " + inttoop(j) + " (" + inttostr(c) + " " + inttoop(k) + " " + inttostr(d) + "))";
                    if (!isduplicate(hasil,temp)){
                        hasil->push_back(temp);
                    }
                }

                // a X ((b X c) X d)
                if (operasi(a,operasi(operasi(b,c,j),d,k),i) == 24.0){
                    temp = inttostr(a) + " " + inttoop(i) + " ((" + inttostr(b) + " " + inttoop(j) + " " + inttostr(c) + ") " + inttoop(k) + " " + inttostr(d) + ")";
                    if (!isduplicate(hasil,temp)){
                        hasil->push_back(temp);
                    }
                }

                // (a X (b X c)) X d
                if (operasi(operasi(a,operasi(b,c,j),i),d,k) == 24.0){
                    temp = "(" + inttostr(a) + " " + inttoop(i) + " (" + inttostr(b) + " " + inttoop(j) + " " + inttostr(c) + ")) " + inttoop(k) + " " + inttostr(d);
                    if (!isduplicate(hasil,temp)){
                        hasil->push_back(temp);
                    }
                }

                // ((a X b) X c) X d
                if (operasi(operasi(operasi(a,b,i),c,j),d,k) == 24.0){
                    temp = "((" + inttostr(a) + " " + inttoop(i) + " " + inttostr(b) + ") " + inttoop(j) + " " + inttostr(c) + ") " + inttoop(k) + " " + inttostr(d);
                    if (!isduplicate(hasil,temp)){
                        hasil->push_back(temp);
                    }
                }
            }
        }
    }
}

void perm(double *nums, int start, int end, vector<string> *hasil){
    /*
    I.S. Menerima sebuah array of double, sebuah integer start, sebuah integer end, dan sebuah vector string
    F.S. Mengisi vector string dengan semua kemungkinan operasi yang menghasilkan 24 dari angka-angka yang terdapat pada array of double
    */
   
    if (start == end){
        validator24(nums, hasil);
    }
    else{
        for (int i = start; i < end; i++){
            swap(nums[start], nums[i]);
            perm(nums, start + 1, end, hasil);
            swap(nums[start], nums[i]);
        }
    }
}

void writefile(vector<string> kartu, vector<string> *hasil, double runtime){ 
    /*
    I.S. Menerima sebuah vector string kartu, sebuah vector string hasil, dan sebuah double
    F.S. Menulis hasil ke file
    */
   
   /* INISIASI VARIABEL */
    bool save = false;
    string yesno;
    string filename;
    string path;

    /* SAVE LOOP */
    while (!save){
        cout << "Simpan hasil ke file? (Y/N) : ";
        cin >> yesno;

        /* SAVE FILE */
        if (yesno == "Y" || yesno == "y"){
            /* INPUT NAMA FILE */
            cout << "Masukkan nama file : ";
            cin >> filename;
            path = "test\\" + filename + ".txt";
            const char * filename_char = path.c_str(); // Mengubah string menjadi bentuk constan char

            /* MEMBUAT FILE */
            ofstream file;
            file.open(filename_char);

            /* MENULISKAN HASIL SOLUSI KE DALAM FILE */
            file << "Kartu : " << kartu[0] << " " << kartu[1] << " " << kartu[2] << " " << kartu[3] << endl;
            file << "Jumlah Solusi : " << hasil->size() << endl;
            file << "Solusi : " << endl;
            for (int i = 0 ; i < hasil->size() ; i++){
                file << hasil->at(i) << endl;
            }
            file << "Waktu Eksekusi : " << runtime << " ms" << endl;
            file.close();
            cout << "Solusi telah disimpan di file " << filename << endl;
                save = true;
        }

        /* DONT SAVE FILE */
        else if (yesno == "N" || yesno == "n"){
            save = true;
        }

        /* INPUT SALAH */
        else{
            cout << "Input tidak valid!" << endl;
        }
    }
}

void splashscreen(){
    system("cls");  
    cout << "========================================================================================" << endl;                                                
    cout << "  ___    _  _            _______.  ______    __      ____    ____  _______ .______      " << endl;
    cout << " |__ \\  | || |          /       | /  __  \\  |  |     \\   \\  /   / |   ____||   _  \\     " << endl;
    cout << "    ) | | || |_        |   (----`|  |  |  | |  |      \\   \\/   /  |  |__   |  |_)  |    " << endl;
    cout << "   / /  |__   _|        \\   \\    |  |  |  | |  |       \\      /   |   __|  |      /     " << endl;
    cout << "  / /_     | |      .----)   |   |  `--'  | |  `----.   \\    /    |  |____ |  |\\  \\----." << endl;
    cout << " |____|    |_|      |_______/     \\______/  |_______|    \\__/     |_______|| _| `._____|" << endl;
    cout << "                               BY 13521024 - AHMAD NADIL                                         " << endl;
    cout << "========================================================================================" << endl;
    cout << " " << endl;
}

void printruntime(double runtime){
    cout << "============================" << endl;
    cout << "| Waktu Eksekusi : " << runtime << " ms    |" << endl;
    cout << "============================" << endl;
}

int main(){
    /* INISIASI VARIABEL */
    splashscreen();
    bool run = true;
    bool valid;
    int pilihan;
    vector<string> kartu_input;
    vector<string> hasil;
    string temp_kartu;
    string arr_kartu[] = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
    double nilai_kartu[4];    
    double runtime;
    time_t start,end;

    /* MAIN PROGRAM LOOP */
    while (run){
        cout << "===== MENU UTAMA =====" << endl;
        cout << "1. Input Kartu" << endl;
        cout << "2. Random Kartu" << endl;
        cout << "3. Exit" << endl;

        /* PILIHAN MENU */
        cout << "Pilihan (1/2/3) : ";
        cin >> pilihan;

        /* MENU INPUT KARTU (1) */
        if (pilihan == 1){
            /* INPUT KARTU DAN VALIDASI */
            valid= false;
            while (!valid){
                inputkartu(&kartu_input);
                /* VALIDASI */
                for (int i = 0 ; i < 4 ; i++){
                    /* MERUBAH INPUT KARTU MENJADI INTEGER */
                    nilai_kartu[i] = strtodouble(kartu_input[i]);
                    if (nilai_kartu[i] == 999){
                        cout << "Kartu tidak valid" << endl;
                        kartu_input.clear();
                        break;
                    }
                    /* Jika semua kartu berhasil divalidasi */
                    if (i == 3){
                        valid = true;
                    }
                }
            }

            /* MAIN PROGRAM UNTUK MENCARI SOLUSI */
            clock_t start = clock(); // start timer
            perm(nilai_kartu, 0, 4, &hasil); // Memanggil fungsi permutasi untuk mendapatkan semua kemungkinan kombinasi kartu
            clock_t end = clock();  // end timer
            double runtime = double(end - start)/CLOCKS_PER_SEC * 1000; // hitung runtime dalam milisecond
            
            /* OUTPUT AKHIR */
            if (hasil.size() == 0){
                cout << "Tidak ada solusi" << endl;
                printruntime(runtime);
            }
            else{
                cout <<  "Jumlah solusi : " << hasil.size() << endl;
                for (int i = 0; i < hasil.size(); i++){
                    cout << hasil[i] << endl;
                }
                printruntime(runtime);
            }
            
            /* MENULISKAN SOLUSI KE FILE */
            writefile(kartu_input, &hasil, runtime);
            
            /* RESET VARIABEL*/
            kartu_input.clear();
            hasil.clear();

            cout << "Press enter to continue...";
            cin.ignore();
            cin.get();
        }

        /* MENU RANDOM KARTU */
        else if (pilihan == 2){
            srand(time(0)); // seed random menggunakan waktu

            /* LOOP RANDOM KARTU */
            for (int i = 0; i < 4; i++) {
                int rand_num = rand() % 13; // random number dari 0-12 (sesuai jumlah kartu)
                kartu_input.push_back(arr_kartu[rand_num]); // memasukkan kartu ke vector, dari array kartu dengan index random
                nilai_kartu[i] = strtodouble(arr_kartu[rand_num]); // Merubah kartu menjadi integer
                cout << arr_kartu[rand_num] << " "; // menampilkan kartu
            }
            cout << endl;

            /* MAIN PROGRAM UNTUK MENCARI SOLUSI */
            clock_t start = clock(); // start timer
            perm(nilai_kartu, 0, 4, &hasil); // Memanggil fungsi permutasi untuk mendapatkan semua kemungkinan kombinasi kartu
            clock_t end = clock();  // end timer
            double runtime = double(end - start)/CLOCKS_PER_SEC * 1000; // hitung runtime dalam milisecond

            /* OUTPUT AKHIR */
            if (hasil.size() == 0){
                cout << "Tidak ada solusi" << endl;
                printruntime(runtime);
            }
            else{
                cout <<  "Jumlah solusi : " << hasil.size() << endl;
                for (int i = 0; i < hasil.size(); i++){
                    cout << hasil[i] << endl;
                }
                printruntime(runtime);
            }

            /* MENULISKAN SOLUSI KE FILE */
            writefile(kartu_input, &hasil, runtime);
            
            /* RESET VARIABEL*/
            kartu_input.clear();
            hasil.clear();

            cout << "Press enter to continue...";
            cin.ignore();
            cin.get();
        }

        /* MENU EXIT */
        else if (pilihan == 3){
            run = false;
            cout << "Thank you for using this program!" << endl;
            cout << "Have a nice day!" << endl;
            cout << "Press enter to continue...";
            cin.ignore();
            cin.get();
        }
        
        /* JIKA PILIHAN TIDAK VALID */
        else{
            cout << "Pilihan salah, ulangi input!" << endl;
            cout << "Press enter to continue...";
            cin.ignore();
            cin.get();
        }
        splashscreen();
    }
    return 0;
}