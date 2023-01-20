#include "operations.h"

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