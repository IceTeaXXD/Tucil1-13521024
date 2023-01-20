#include "operations.hpp"

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
    else{
        return "error";
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
    else{
        return 999.0;
    }
}