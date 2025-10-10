#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <sstream>      
#include <iomanip>      
#include <algorithm>

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

void sortTugas(vector<Task>& daftarTugas) {
    cout << "\n========== Sortir Tugas ==========\n";
    if (daftarTugas.empty()) {
        cout << "Belum ada tugas!\n";
        return;
    }

    cout <<   "Pilih metode pengurutan:\n";
    cout << "1.Berdasarkan Deadline (terdekat dulu)\n";
    cout << "2.Berdasarkan Prioritas (HIGH > MEDIUM > LOW)\n";
    cout << "3.Berdasarkan Judul (A-Z)\n";
    cout << "4.Berdasarkan Judul (Z-A)\n";
    cout << "Pilih (1/2/3/4): ";
    
    int pilihan;
    cin >> pilihan;

    switch (pilihan) {
        case 1: // Sortir berdasarkan Deadline
            sort(daftarTugas.begin(), daftarTugas.end(), 
                [](const Task& a, const Task& b) {
                    return a.deadline < b.deadline; // Deadline terdekat di atas
                });
            cout << "Tugas diurutkan berdasarkan Deadline!\n";
            break;

        case 2: // Sortir berdasarkan Prioritas
            sort(daftarTugas.begin(), daftarTugas.end(), 
                [](const Task& a, const Task& b) {
                    return a.priority < b.priority; // HIGH(0) < MEDIUM(1) < LOW(2)
                });
            cout << "Tugas diurutkan berdasarkan Prioritas!\n";
            break;

        case 3: // Sortir berdasarkan Judul (A-Z)
            sort(daftarTugas.begin(), daftarTugas.end(), 
                [](const Task& a, const Task& b) {
                    return a.Judul_tugas < b.Judul_tugas; // A-Z
                });
            cout << "Tugas diurutkan berdasarkan Judul (A-Z)!\n";
            break;

        case 4: // Sortir berdasarkan Judul (Z-A)
            sort(daftarTugas.begin(), daftarTugas.end(), 
                [](const Task& a, const Task& b) {
                    return a.Judul_tugas > b.Judul_tugas; // Z-A
                });
            cout << "Tugas diurutkan berdasarkan Judul (Z-A)!\n";
            break;

        default:
            cout << "Pilihan tidak valid!\n";
            return;
    }

    // Tampilkan daftar tugas yang sudah diurutkan (menggunakan kode dari case 'L')
    cout << "\n========== DAFTAR TUGAS ==========\n" << endl;
    for (const auto& task : daftarTugas) {
        cout << "Tugas " << task.Task_id << endl;
        cout << "Judul: " << task.Judul_tugas << endl;
        
        time_t tt = chrono::system_clock::to_time_t(task.deadline);
        tm* tm = localtime(&tt);
        cout << "Deadline: " << put_time(tm, "%Y-%m-%d %H:%M") << endl;
        
        cout << "Prioritas: " << getPriorityString(task.priority) << endl;
        cout << "Status: " << getStatusString(task.task_status) << endl;
        cout << "----------------------------" << endl;
    }
}

void hapusTugas(vector<Task>& daftarTugas) {
    cout << "\n========== Hapus Tugas ==========\n";
    if (daftarTugas.empty()) {
        cout << "Belum ada tugas!\n";
        return;
    }
    for (const auto& task : daftarTugas) {
        cout << "ID " << task.Task_id << ": " << task.Judul_tugas << endl;
    }
    int idHapus;
    cout << "ID tugas yang ingin dihapus: " << endl;
    cin >> idHapus;

    auto it = std::remove_if(daftarTugas.begin(), daftarTugas.end(),[idHapus](const Task& t) { return t.Task_id == idHapus; });
    if (it != daftarTugas.end()) {
        daftarTugas.erase(it, daftarTugas.end());
        for (int i = 0; i < daftarTugas.size(); i++) {
            daftarTugas[i].Task_id = i + 1;
        }
        cout << "Tugas berhasil dihapus!\n";
    } else {
        cout << "ID tidak ditemukan!\n";
    }
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
    cout << " - Hapus Tugas (H)" << endl;
    cout << "Mau apa nih kamu ? :D" << endl;
    cout << "Pilih Menu (T/L/SR/ST/E/H)";
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
            // case lihat tugas
                cout << "\n========== DAFTAR TUGAS ==========\n" << endl;
                //kalau belum ada tugas sama sekali
                if (Tugas.size() == 0) {
                    cout << "Belum ada tugas!" << endl;
                } else {
                    // Kalau ada tugas, tampilkan satu per satu
                    for (int i = 0; i < Tugas.size(); i++) {
                        
                        cout << "Tugas " << Tugas[i].Task_id << endl;
                        cout << "Judul: " << Tugas[i].Judul_tugas << endl;
                        
                        time_t tt = chrono::system_clock::to_time_t(Tugas[i].deadline);
                        tm* tm = localtime(&tt);
                        cout << "Deadline: " << put_time(tm, "%Y-%m-%d") << endl;
                        
                        if (Tugas[i].priority == HIGH) {
                            cout << "Prioritas: HIGH" << endl;
                        } else if (Tugas[i].priority == MEDIUM) {
                            cout << "Prioritas: MEDIUM" << endl;
                        } else {
                            cout << "Prioritas: LOW" << endl;
                        }
                        
                        if (Tugas[i].task_status == COMPLETE) {
                            cout << "Status: COMPLETE" << endl;
                        } else {
                            cout << "Status: UNCOMPLETE" << endl;
                        }
                        
                        cout << "----------------------------" << endl;
                    }
                }
                cout << endl;
            
            break;
        case 'R':
            // Case Sortir Tugas
            sortTugas(Tugas);
            break;
        case 'H':
            // Case Hapus Tugas
            hapusTugas(Tugas);
            break;
        case 'S':
            // Case Snooze / Tunda Tugas
            cout << "\n========== Tunda Tugas ==========\n";
            if(Tugas.size() == 0){
                cout << "Belum ada tugas!" << endl;
            }else{
                int id;
                cout << "ID Tugas Mana yang ingin kamu tunda? "<<endl;
                for (int i = 0; i < Tugas.size(); i++) {
                    cout << "Id " << Tugas[i].Task_id << endl;
                }
                cout << "Masukkan ID yang ingin kamu tunda : ";
                cin >> id;
                for (int i = 0; i < Tugas.size(); i++) {
                    if(Tugas[i].Task_id == id){
                        string tunda;
                        time_t tt = chrono::system_clock::to_time_t(Tugas[i].deadline);
                        tm* tm = localtime(&tt);
                        cout << "Waktu yang ingin kamu tunda " << put_time(tm, "%Y-%m-%d") << endl;
                        cout << "Masukkan Deadline Baru (YYYY-MM-DD HH:MM): ";
                        cin.ignore();
                        getline(cin,tunda);
                        cout << endl;
                        Tugas[i].deadline = stringToTimePoint(tunda);
                        cout << "Berhasil !" << endl;
                    }
                }
            }
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
