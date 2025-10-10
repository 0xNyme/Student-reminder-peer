#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <sstream>      
#include <iomanip>      

using namespace std;

// enumerasi dari priority
enum Priority {
    HIGH ,  
    MEDIUM,
    LOW
};

// enumerasi untuk status
enum Status {  
    COMPLETE,
    UNCOMPLETE
};

// struktur struct untuk Task
struct Task {
    int Task_id;    
    string Judul_tugas;
    Priority priority;    
    Status task_status;
    chrono::system_clock::time_point deadline;
};

string getPriorityString(Priority p) {
    // convert nilai konstan pada enum jadi tingkatan prioritas tugas
    switch(p) {
        case HIGH: return "HIGH";
        case MEDIUM: return "MEDIUM";
        case LOW: return "LOW";
        default: return "UNKNOWN";
    }
}

string getStatusString(Status s) {
    // convert nilai konstan pada enum jadi tingkatan prioritas tugas
    switch(s) {
        case COMPLETE: return "COMPLETE";
        case UNCOMPLETE: return "UNCOMPLETE";
        default: return "UNKNOWN";
    }
}

chrono::system_clock::time_point stringToTimePoint(const string& str) {
    tm tm = {};
    stringstream ss(str);
    // Format input: Tahun-Bulan-Tanggal Jam:Menit
    ss >> get_time(&tm, "%Y-%m-%d %H:%M");
    if (ss.fail()) {
        // kalo format ny-salah, kembalikan waktu sekarang sebagai default
        return chrono::system_clock::now();
    }
    return chrono::system_clock::from_time_t(mktime(&tm));
}

void tambahBeberapaTugas(vector<Task>& daftarTugas) {
        cout << "++++++++++++++++++++++++++++++++++++++++\n" << endl;
        cout << "+++++++++++++[Tambah Tugas]+++++++++++++\n" << endl;
        cout << "++++++++++++++++++++++++++++++++++++++++\n" << endl;
        // deklarasi variabel
        Task temp;
        char stat;
        char complete;
        string deadlineStr;
        // untuk id
        temp.Task_id = daftarTugas.size() + 1;
        // untuk judul
        cout << "Masukkan Judul Tugas: ";
        cin >> temp.Judul_tugas;
        // untuk tingkat prioritas tugas
        cout << "Masukkan Prioritas Tugas berupa HIGH , MEDIUM, dan LOW berupa format (H/M/L) : ";
        cin >> stat;
        switch (toupper(stat))
        {
        case 'H':
            temp.priority = HIGH;
            break;
        case 'M':
            temp.priority = MEDIUM;
            break;
        case 'L':
            temp.priority = LOW;
            break;
        default:
            temp.priority = MEDIUM;
            break;
        }
        // untuk status tugas
        cout << "Masukkan Prioritas Tugas  COMPLETE dan UNCOMPLETE berupa format (C/U) : ";
        cin >> complete;
        switch (toupper(complete))
        {
        case 'C':
            temp.task_status = COMPLETE;
            break;
        case 'U':
            temp.task_status = UNCOMPLETE;
            break;
        default:
            temp.task_status = UNCOMPLETE;
            break;
        }
        cout << "Masukkan Deadline (YYYY-MM-DD HH:MM): ";
        cin.ignore();
        getline(cin,deadlineStr);
        cout << endl;
        temp.deadline = stringToTimePoint(deadlineStr);
        daftarTugas.push_back(temp);
        cout << endl;
}

//untuk fitur edit reminder
void editTugas(vector<Task>& daftarTugas) {
    cout << "\n========== Edit Tugas ==========\n";
    
    if (daftarTugas.empty()) {
        cout << "Belum ada tugas!\n";
        return;
    }
    
    for (const auto& task : daftarTugas) {
        cout << "ID " << task.Task_id << ": " << task.Judul_tugas << endl;
    }
    
    int idEdit;
    cout << "\nID tugas: ";
    cin >> idEdit;
    cin.ignore();
    
    for (auto& task : daftarTugas) {
        if (task.Task_id == idEdit) {
            char prio, stat;
            string deadlineStr;
            
            cout << "Judul baru: ";
            getline(cin, task.Judul_tugas);
            
            cout << "Prioritas (H/M/L): ";
            cin >> prio;
            task.priority = (toupper(prio) == 'H') ? HIGH : (toupper(prio) == 'L') ? LOW : MEDIUM;
            
            cout << "Status (C/U): ";
            cin >> stat;
            task.task_status = (toupper(stat) == 'C') ? COMPLETE : UNCOMPLETE;
            
            cout << "Deadline (YYYY-MM-DD HH:MM): ";
            cin.ignore();
            getline(cin, deadlineStr);
            task.deadline = stringToTimePoint(deadlineStr);
            
            cout << "\nSemua data diubah!\n";
            return;
        }
    }
    cout << "ID tidak ditemukan!\n";
}

// panggil untuk pertama x dijalankan
void firstOpen() {
    cout << "\n+===============================================+" << endl;
    cout << "|               STUDENT REMINDER                |"<< endl;
    cout << "+-----------------------------------------------+"<< endl;
    cout << "|      Selamat Datang di Student Reminder!      |"<< endl;
    cout << "|  Buat, atur, dan pantau tugasmu dengan mudah  |"<< endl;
    cout << "+===============================================+"<< endl;
    cout << "Pilih menu berikut :" << endl;
    cout << " - Tambah tugas (T)" << endl;
    cout << " - Lihat tugas (L)" << endl;
    cout << " - Sortir tugas (R)" << endl;
    cout << " - Snooze/Tunda tugas (S)" << endl;
    cout << " - Edit Tugas (E)" << endl;
    cout << "Mau apa nih kamu ? :D" << endl;
    cout << "Pilih Menu (T/L/SR/ST/E)";
    cout << ": ";
}

int main() {
    
    vector<Task> Tugas;

    char pilihMenu;
    bool dontClosetheProgram = true;
    do
    {
        firstOpen();
        cin >> pilihMenu;
        switch (toupper(pilihMenu))
        {
        case 'T':
            tambahBeberapaTugas(Tugas);
            break;
        case 'L':
            // Case lihat Tugas
            
            break;
        case 'R':
            // Case Sortir Tugas
            
            break;
        case 'S':
            // Case Snooze / Tunda Tugas

            break;
        case 'E':
            editTugas(Tugas);
            
            break;
        default:
            break;
        }
    } while (dontClosetheProgram);
    
    return 0;
}
