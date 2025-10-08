# Dokumentasi Teknis

## Deskripsi Aplikasi
Studer adalah aplikasi pengingat tugas yang dirancang untuk membantu pengguna mengelola jadwal dan kewajiban mereka secara efisien. Sebelum menggunakan aplikasi, pengguna harus melakukan registrasi dengan memasukkan nama, email, dan kata sandi.

### 1. ⁠Tambah reminder
pengguna dapat menambahkan tugas beserta deadline adapun format input sebagai berikut :

Task[] (`Struct`)
- ID tugas (`int`)
- Judul tugas (`String`)
- Deskripsi tugas (`String`)
- Skala Prioritas (`Enum( High, Medium, Low )`)
- Status Complete (`Enum( Complete, Uncomplete )`)
- Deadline (`string`)

### 2. ⁠Lihat daftar reminder
pengguna dapat melihat semua pengingat yang sudah dibuat dalam bentuk daftar terorganisir di terminal, jadi kita bisa tau apa saja tugas, ujian, atau kegiatan yang harus dikerjakan dalam waktu dekat.

Menampilkan semua reminder 
- Daftar Judul  
- Tanggal
- Jam 
Menampilkan status reminder
- Complete atau Uncomplete
### 3. ⁠Edit reminder
untuk mengubah detail pengingat yang sudah dibuat sebelumnya, misalnya deadline tugas di majukan, ganti jam ujian, atau kita salah input waktu.

- Ubah Judul 
- Ubah Tanggal & Jam 
- Ubah Prioritas 
- Ubah Status
### 4. ⁠Hapus reminder
untuk menghapus pengingat yang sudah dijadwalkan.

Konsep fitur hapus reminder:
* lihat daftar reminder, lalu pilih reminder yang ingin dihapus
* Selanjutnya, reminder setelahnya akan menggeser / mengisi bagian dari reminder yg dihapus
* jumlah reminder berkurang 1

### 5. ⁠Snooze/tunda
untuk menunda pengingat yang telah dijadwalkan. Misalnya ingin menunda +- 1 jam, atau +- 1 hari

Konsep fitur snooze reminder:
* pilih reminder yg akan di tunda, lalu tentukan berapa lama waktu penundaannya (tambah keterangan kaya "snoozed +1 hour")
* reminder tidak dihapus tapi hanya diubah waktunya jadi lebih lambat
### 7. ⁠Sorting reminder
untuk mengurutkan daftar pengingat (reminder) agar lebih mudah dibaca, dikelola, dan diprioritaskan.
Sehingga bisa meningkatkan keteraturan ~semua pengingat tersusun rapi sesuai prioritas

konsep kerja sorting reminder
1. Berdasarkan waktu (Deadline/Date Sorting)
Reminder dengan waktu terdekat muncul paling atas.
2. Berdasarkan prioritas (Priority Sorting)
Reminder dikategorikan (misalnya: High, Medium, Low).
3. Berdasarkan alfabet (Alphabetical Sorting)
Judul reminder diurutkan dari A–Z atau Z–A.

Contoh sederhana konsep kerjanya (alur):
1. Kamu punya 5 reminder acak.
2. Kamu pilih opsi "Sort by Date"
3. Sistem akan membaca semua field tanggal dari reminder.
4. Sistem mengurutkan dari tanggal paling dekat → paling jauh.
5. Hasilnya tampil dalam daftar rapi sesuai pilihan sorting.
## Library dan Technical case
