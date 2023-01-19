#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>

using namespace std;

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

int strtodouble(string c){
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
    for (int i = 0 ; i < hasil->size() ; i++){
        if (hasil->at(i) == str){
            return true;
        }
    }
    return false;
}

void validator24 (double nums[4], vector<string> *hasil){
    double a = nums[0];
    double b = nums[1];
    double c = nums[2];
    double d = nums[3];
    string temp = "";
    for (int i = 0 ; i < 4 ; i++){
        for (int j = 0 ; j < 4 ; j++){
            for (int k = 0 ; k < 4 ; k++){
                for (int l = 0 ; l < 4 ; l++){
                    // KEMUNGKINAN OPERASI
                    // X adalah operator * / + -
                        // i or j or k or l = 0 -> +
                        // i or j or k or l = 1 -> -
                        // i or j or k or l = 2 -> *
                        // i or j or k or l = 3 -> /

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
}

void perm(double *nums, int start, int end, vector<string> *hasil){
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

void writefile(string kartu[4], vector<string> *hasil){ 
    time_t t = time(0);
    struct tm * now = localtime(&t);

    const char * dir = "test\\";
    const char * ext = ".txt";
    char filename[100];
    sprintf(filename, "%s%d-%d-%d-%d-%d%s", dir, (now->tm_year + 1900), now->tm_mday, now->tm_hour, now->tm_min, now->tm_sec, ext);

    ofstream file;
    file.open(filename);

    file << "Kartu : " << kartu[0] << " " << kartu[1] << " " << kartu[2] << " " << kartu[3] << endl;
    file << "Jumlah Solusi : " << hasil->size() << endl;
    file << "Solusi : " << endl;
    for (int i = 0 ; i < hasil->size() ; i++){
        file << hasil->at(i) << endl;
    }
    file.close();
    cout << "Solusi telah disimpan di file " << filename << endl;
}

int main(){
    /* SPLASH SCREEN */
    system("cls");  
    cout << "========================================================================================" << endl;                                                
    cout << "  ___    _  _            _______.  ______    __      ____    ____  _______ .______      " << endl;
    cout << " |__ \\  | || |          /       | /  __  \\  |  |     \\   \\  /   / |   ____||   _  \\     " << endl;
    cout << "    ) | | || |_        |   (----`|  |  |  | |  |      \\   \\/   /  |  |__   |  |_)  |    " << endl;
    cout << "   / /  |__   _|        \\   \\    |  |  |  | |  |       \\      /   |   __|  |      /     " << endl;
    cout << "  / /_     | |      .----)   |   |  `--'  | |  `----.   \\    /    |  |____ |  |\\  \\----." << endl;
    cout << " |____|    |_|      |_______/     \\______/  |_______|    \\__/     |_______|| _| `._____|" << endl;
    cout << "                                   BY 13521024 - AHMAD NADIL                                         " << endl;
    cout << "========================================================================================" << endl;
    cout << " " << endl;

    /* MAIN MENU */
    bool run = true;
    int pilihan;
    string kartu[4];
    int length_kartu = 4;
    double nilai_kartu[4];    
    string arr_kartu[] = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
    vector<string> hasil;

    while (run){
        cout << "===== MENU UTAMA =====" << endl;
        cout << "1. Input Kartu" << endl;
        cout << "2. Random Kartu" << endl;
        cout << "3. Exit" << endl;
        cout << "Pilihan : ";
        cin >> pilihan;
        if (pilihan == 1){

            /* INPUT KARTU DAN VALIDASI */
            bool valid= false;
            while (!valid){
                /* INPUT KARTU */
                cout << "Masukkan 4 kartu (A,2,3,4,5,6,7,8,9,10,J,Q,K) : ";
                cin >> kartu[0] >> kartu[1] >> kartu[2] >> kartu[3];

                /* VALIDASI */
                for (int i = 0; i < 3; i++){

                    /* MERUBAH INPUT KARTU MENJADI INTEGER */
                    nilai_kartu[i] = strtodouble(kartu[i]);

                    if (nilai_kartu[i] == 999){
                        cout << "Input salah, ulangi input!" << endl;
                        break;
                    }
                    else if (i == 2){
                        valid = true;
                    }
                }
                if (valid){
                    // cek nilai 24
                    perm(nilai_kartu, 0, 4, &hasil);

                    // print hasil
                    if (hasil.size() == 0){
                        cout << "Tidak ada solusi" << endl;
                    }
                    else{
                        cout <<  "Jumlah solusi : " << hasil.size() << endl;
                        for (int i = 0; i < hasil.size(); i++){
                            cout << hasil[i] << endl;
                        }
                        writefile(kartu, &hasil);
                    }
                }
            }

            cout << "Press enter to continue...";
            cin.ignore();
            cin.get();
        }

        else if (pilihan == 2){
            srand(time(0));

            for (int i = 0; i < length_kartu; i++) {
                int rand_num = rand() % 13;
                nilai_kartu[i] = strtodouble(arr_kartu[rand_num]);
                cout << arr_kartu[rand_num] << " ";
            }

            cout << endl;

            cout << "Press enter to continue...";
            cin.ignore();
            cin.get();
        }

        else if (pilihan == 3){
            run = false;
            cout << "Thank you for using this program!" << endl;
            cout << "Have a nice day!" << endl;
            cout << "Press enter to continue...";
            cin.ignore();
            cin.get();
        }
        
        else{
            cout << "Pilihan salah, ulangi input!" << endl;
            cout << "Press enter to continue...";
            cin.ignore();
            cin.get();
        }
        system("cls");
    }
    return 0;
}