#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>
#include <vector>
using namespace std;

int strtoint(string c){
    /*
    I.S. Menerima sebuah string
    F.S. Mengembalikan nilai kartu tersebut dalam bentuk integer
    */

    if (c == "A"){
        return 1;
    }
    else if (c == "J"){
        return 11;
    }
    else if (c == "Q"){
        return 12;
    }
    else if (c == "K"){
        return 13;
    }
    else if (c == "2"){
        return 2;
    }
    else if (c == "3"){
        return 3;
    }
    else if (c == "4"){
        return 4;
    }
    else if (c == "5"){
        return 5;
    }
    else if (c == "6"){
        return 6;
    }
    else if (c == "7"){
        return 7;
    }
    else if (c == "8"){
        return 8;
    }
    else if (c == "9"){
        return 9;
    }
    else if (c == "10"){
        return 10;
    }
    else{ // Jika input salah
        return 999;
    }
}

void check24 (int nums[4], vector<string> *hasil, int *count){
    // Fungsi untuk mengecek apakah ada 4 angka yang dapat menghasilkan 24
    int a = nums[0];
    int b = nums[1];
    int c = nums[2];
    int d = nums[3];

    // Operasi komutatif
    if (a+b+c+d == 24){
        hasil->push_back(to_string(a) + " + " + to_string(b) + " + " + to_string(c) + " + " + to_string(d));
        *count += 1;
    }
    if (a*b*c*d == 24){
        hasil->push_back(to_string(a) + " * " + to_string(b) + " * " + to_string(c) + " * " + to_string(d));
        *count += 1;
    }

    // 2 '+' dan 1 '-'
    if (a+b+c-d == 24){
        hasil->push_back(to_string(a) + " + " + to_string(b) + " + " + to_string(c) + " - " + to_string(d));
        *count += 1;
    }

    // 2 '+' dan 1 '*'
    if (a*b+c+d == 24){
        hasil->push_back(to_string(a) + " * " + to_string(b) + " + " + to_string(c) + " + " + to_string(d));
        *count += 1;
    }
    if (a*(b+c)+d == 24){
        hasil->push_back(to_string(a) + " * (" + to_string(b) + " + " + to_string(c) + ") + " + to_string(d));
    }
    if (a*(b+c+d) == 24){
        hasil->push_back(to_string(a) + " * (" + to_string(b) + " + " + to_string(c) + " + " + to_string(d) + ")");
        *count += 1;
    }

    // 1 '+' dan 2 '*'
    if ((a*b*c)+d == 24){
        hasil->push_back("(" + to_string(a) + " * " + to_string(b) + " * " + to_string(c) + ") + " + to_string(d));
        *count += 1;
    }
    if(a*b*(c+d) == 24){
        hasil->push_back(to_string(a) + " * " + to_string(b) + " * (" + to_string(c) + " + " + to_string(d) + ")");
        *count += 1;
    }
    if((a*b)+(c*d)){
        hasil->push_back("(" + to_string(a) + " * " + to_string(b) + ") + (" + to_string(c) + " * " + to_string(d) + ")");
        *count += 1;
    }

    // 1 '-' dan 2 '*'
    if((a*b*c)-d == 24){
        hasil->push_back("(" + to_string(a) + " * " + to_string(b) + " * " + to_string(c) + ") - " + to_string(d));
        *count += 1;
    }
    if(a*b*(c-d) == 24){
        hasil->push_back(to_string(a) + " * " + to_string(b) + " * (" + to_string(c) + " - " + to_string(d) + ")");
        *count += 1;
    }
    if((a*b)-(c*d) == 24){
        hasil->push_back("(" + to_string(a) + " * " + to_string(b) + ") - (" + to_string(c) + " * " + to_string(d) + ")");
        *count += 1;
    }

    // 1 '+' dan 1 '-' dan 1 '*'
    if(a*b+c-d == 24){
        hasil->push_back(to_string(a) + " * " + to_string(b) + " + " + to_string(c) + " - " + to_string(d));
        *count += 1;
    }
    if(a*(b+c)-d == 24){
        hasil->push_back(to_string(a) + " * (" + to_string(b) + " + " + to_string(c) + ") - " + to_string(d));
        *count += 1;
    }
    if(a*(b-c)+d == 24){
        hasil->push_back(to_string(a) + " * (" + to_string(b) + " - " + to_string(c) + ") + " + to_string(d));
        *count += 1;
    }
    if(a*(b+c-d) == 24){
        hasil->push_back(to_string(a) + " * (" + to_string(b) + " + " + to_string(c) + " - " + to_string(d) + ")");
        *count += 1;
    }
    if(a*b-(c+d) == 24){
        hasil->push_back(to_string(a) + " * " + to_string(b) + " - (" + to_string(c) + " + " + to_string(d) + ")");
        *count += 1;
    }

    // 1 '*' dan 1 '/' dan 1 '+'
    if (a*b == (24-d) * c){ // (a*b/c)+d
        hasil->push_back("(" + to_string(a) + " * " + to_string(b) + " / " + to_string(c) + ") + " + to_string(d));
        *count += 1;
    }
    if(((a*b)+c) == 24*d){ // ((a*b)+c)/d
        hasil->push_back("((" + to_string(a) + " * " + to_string(b) + ") + " + to_string(c) + ") / " + to_string(d));
        *count += 1;
    }
    if((a+b)*c == 24*d){ // ((a+b)*c)/d
        hasil->push_back("((" + to_string(a) + " + " + to_string(b) + ") * " + to_string(c) + ") / " + to_string(d));
        *count += 1;
    }
    if(a*b == 24*(c+d)){ // (a*b)/(c+d)
        hasil->push_back("(" + to_string(a) + " * " + to_string(b) + ") / (" + to_string(c) + " + " + to_string(d) + ")");
        *count += 1;
    }

    // 1 '*' dan 1 '/' dan 1 '-'
    if(a*b == (24 + d)*c){ // (a*b/c)-d
        hasil->push_back("(" + to_string(a) + " * " + to_string(b) + " / " + to_string(c) + ") - " + to_string(d));
        *count += 1;
    }
    if(((a*b)-c) == 24*d){ // ((a*b)-c)/d
        hasil->push_back("((" + to_string(a) + " * " + to_string(b) + ") - " + to_string(c) + ") / " + to_string(d));
        *count += 1;
    }
    if((a-b)*c == 24*d){ // ((a-b)*c)/d
        hasil->push_back("((" + to_string(a) + " - " + to_string(b) + ") * " + to_string(c) + ") / " + to_string(d));
        *count += 1;
    }
    if(a*b == 24*(c-d)){ // (a*b)/(c-d)
        hasil->push_back("(" + to_string(a) + " * " + to_string(b) + ") / (" + to_string(c) + " - " + to_string(d) + ")");
        *count += 1;
    }

    // 2 '*' dan 1 '/'
    if(a*b*c == 24*d){ // a*b*c/d
        hasil->push_back(to_string(a) + " * " + to_string(b) + " * " + to_string(c) + " / " + to_string(d));
        *count += 1;
    }
    if(a*b == 24*c*d){ //a*b/(c*d)
        hasil->push_back(to_string(a) + " * " + to_string(b) + " / (" + to_string(c) + " * " + to_string(d) + ")");
        *count += 1;
    }
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
    int nilai_kartu[4];    
    string arr_kartu[] = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};

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
                cin >> kartu[0] >> kartu[1] >> kartu[2] >> kartu[3];

                /* VALIDASI */
                for (int i = 0; i < length_kartu; i++){

                    /* MERUBAH INPUT KARTU MENJADI INTEGER */
                    nilai_kartu[i] = strtoint(kartu[i]);

                    if (nilai_kartu[i] == 999){
                        cout << "Input salah, ulangi input!" << endl;
                        break;
                    }
                    else if (i == length_kartu - 1){
                        valid = true;
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
                nilai_kartu[i] = strtoint(arr_kartu[rand_num]);
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