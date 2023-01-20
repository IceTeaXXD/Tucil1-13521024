#include "result.h"

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

void printruntime(double runtime){
    cout << "============================" << endl;
    cout << "| Waktu Eksekusi : " << runtime << " ms    |" << endl;
    cout << "============================" << endl;
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