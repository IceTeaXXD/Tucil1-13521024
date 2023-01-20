#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>
#include <chrono>

#include "operations.hpp"
#include "cards.hpp"
#include "result.hpp"

using namespace std;

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
            auto start = chrono::steady_clock::now(); // start timer
            perm(nilai_kartu, 0, 4, &hasil); // Memanggil fungsi permutasi untuk mendapatkan semua kemungkinan kombinasi kartu
            auto end = chrono::steady_clock::now(); // hitung runtime dalam milisecond
            double runtime = chrono::duration_cast<chrono::microseconds>(end - start).count() * 0.001; // hitung runtime dalam milisecond
            
            /* OUTPUT AKHIR */
            if (hasil.size() == 0){
                cout << "============================" << endl;
                cout << "|Tidak ada solusi          |" << endl;
                cout << "============================" << endl;
                printruntime(runtime);
            }
            else{
                cout << "============================" << endl;
                cout << "| Jumlah solusi : " << hasil.size() << "       |" << endl;
                cout << "============================" << endl;
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
            auto start = chrono::steady_clock::now(); // start timer
            perm(nilai_kartu, 0, 4, &hasil); // Memanggil fungsi permutasi untuk mendapatkan semua kemungkinan kombinasi kartu
            auto end = chrono::steady_clock::now(); // hitung runtime dalam milisecond
            double runtime = chrono::duration_cast<chrono::microseconds>(end - start).count() * 0.001; // hitung runtime dalam milisecond

            /* OUTPUT AKHIR */
            if (hasil.size() == 0){
                cout << "============================" << endl;
                cout << "Tidak ada solusi" << endl;
                cout << "============================" << endl;
                printruntime(runtime);
            }
            else{
                cout << "============================" << endl;
                cout << "| Jumlah solusi : " << hasil.size() << "       |" << endl;
                cout << "============================" << endl;
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
            cout << "Press enter to exit...";
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