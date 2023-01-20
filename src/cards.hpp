#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include "operations.hpp"

using namespace std;

#ifndef CARDS_H
#define CARDS_H

void inputkartu (vector<string> *kartu_input);
    /*
    I.S. Menerima sebuah vector string
    F.S. Mengisi vector string dengan 4 kartu yang diinput
    */

bool isduplicate(vector<string> *hasil, string str);
    /*
    I.S. Menerima sebuah vector string dan sebuah string
    F.S. Mengembalikan true jika string tersebut sudah ada di dalam vector string
    */

void perm(double *nums, int start, int end, vector<string> *hasil);
    /*
    I.S. Menerima sebuah array of double, sebuah integer start, sebuah integer end, dan sebuah vector string
    F.S. Mengisi vector string dengan semua kemungkinan operasi yang menghasilkan 24 dari angka-angka yang terdapat pada array of double
    */

#endif