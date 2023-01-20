#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

#ifndef OPERATIONS_H
#define OPERATIONS_H

string inttostr(int num);
    /*
    I.S. Menerima sebuah integer
    F.S. Mengembalikan nilai integer tersebut dalam bentuk string
    */

string inttoop(int op);
    /*
    I.S. Menerima sebuah integer
    F.S. Mengembalikan nilai operator tersebut dalam bentuk string
    */

double operasi (double a, double b, int op);
    /*
    I.S. Menerima dua buah bilangan dan sebuah operator
    F.S. Mengembalikan hasil operasi antara dua buah bilangan tersebut
    */
   
#endif