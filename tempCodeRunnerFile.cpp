#include <iostream>
#include <vector>
using namespace std;

void lihatreminder(vector<string>judul, vector<string>deadline, vector<string>kategori, vector<string>status){
    
    if (judul.size() == 0) {
        cout << "\nBelum Ada Reminder!\n";
        return;
    }
    
    cout << "\n===== DAFTAR REMINDER =====\n\n";
    
    for (int i = 0; i < judul.size(); i++){
        cout << (i + 1) << ". " << judul[i] << endl;
        cout << "  Deadline: " << deadline[i] << endl;
        cout << "  Kategori: " << kategori[i] << endl;
        cout << endl;
    }
    cout << "Total: " << judul.size() << " reminder\n";
}
