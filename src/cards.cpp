#include "cards.hpp"

double strtocard(string c){
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

void perm(double *nums,vector<string> *hasil){
    /*
    I.S. Menerima sebuah array of double, dan sebuah vector string
    F.S. Mengisi vector string dengan semua kemungkinan operasi yang menghasilkan 24 dari angka-angka yang terdapat pada array of double
    */
    double nums_perm[4];
    for (int i = 0 ; i < 4 ; i++){
        for (int j = 0 ; j < 4 ; j++){
            for (int k = 0 ; k < 4 ; k++){
                for (int l = 0 ; l < 4 ; l++){
                    if (i != j && i != k && i != l && j != k && j != l && k != l){
                        nums_perm[0] = nums[i];
                        nums_perm[1] = nums[j];
                        nums_perm[2] = nums[k];
                        nums_perm[3] = nums[l];
                        validator24(nums_perm, hasil);
                    }
                }
            }
        }
    }
}