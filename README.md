# 🐟 NEPTU Data - Manajemen Data Hasil Tangkapan Perikanan 🐟

<p align="center">
  <img src="https://i.imgur.com/your-image-url.png" alt="Neptu Data Banner" width="600"/>
</p>

<p align="center">
  <strong>Sebuah program CLI sederhana namun powerful untuk mencatat, mengelola, dan menganalisis data hasil tangkapan ikan.</strong>
  <br>
  <br>
  <em>Proyek ini dibuat untuk memenuhi Tugas Besar mata kuliah Algoritma Pemrograman di Telkom University Surabaya.</em>
</p>

---

## 🌟 Tentang Program

**NEPTU Data** adalah solusi berbasis C untuk para nelayan modern atau penghobi mancing yang ingin mendata setiap hasil tangkapannya secara digital. Lupakan pencatatan manual yang merepotkan! Dengan program ini, Anda dapat dengan mudah memasukkan data, melihat statistik penting, mencari data spesifik, mengurutkannya, hingga menyimpan semua informasi ke dalam sebuah file untuk dokumentasi jangka panjang.

Program ini didesain dengan antarmuka yang ramah pengguna dan fungsionalitas yang relevan untuk manajemen data perikanan skala kecil hingga menengah.

---

## ✨ Fitur Utama

Program ini dilengkapi dengan berbagai fitur untuk memudahkan manajemen data Anda:

* **📝 Input Data Dinamis:** Masukkan data tangkapan baru kapan saja, mencakup jenis ikan, berat (kg), ukuran (cm), dan lokasi penemuan.
* **📊 Statistik Cerdas:** Dapatkan insight berharga secara instan!
    * Total jumlah tangkapan yang sudah dicatat.
    * Rata-rata berat dari semua tangkapan.
    * Jenis ikan yang paling sering ditangkap.
* **💾 Simpan & Muat Data:** Jangan khawatir kehilangan data.
    * **Simpan ke File:** Ekspor semua data ke dalam format `.csv` yang mudah dibaca.
    * **Muat dari File:** Impor kembali data dari file untuk melanjutkan pekerjaan Anda.
* **🔍 Pencarian Lanjutan:** Cari data spesifik dengan cepat berdasarkan:
    * Jenis Ikan
    * Lokasi Penangkapan
    * Berat
    * Ukuran
* **SORT Urutkan Data:** Atur tampilan data Anda agar lebih mudah dianalisis. Urutkan berdasarkan:
    * Jenis Ikan (A-Z)
    * Berat (Terbesar ke Terkecil)
    * Ukuran (Terbesar ke Terkecil)
    * Lokasi (A-Z)
* **🎨 Antarmuka Teks yang Menarik:** Tampilan menu yang tertata rapi dengan sentuhan *ASCII art* untuk pengalaman yang lebih menyenangkan.

---

## 🚀 Cara Menggunakan

Untuk menjalankan program ini di komputermu, ikuti langkah-langkah berikut:

1.  **Clone atau Unduh Repositori**
    ```bash
    # Jika menggunakan git
    git clone [https://github.com/your-username/your-repo-name.git](https://github.com/your-username/your-repo-name.git)
    cd your-repo-name
    ```
    Atau cukup unduh file `main.c` dari repositori ini.

2.  **Kompilasi Kode**
    Anda memerlukan sebuah C compiler (seperti GCC) untuk membuat file executable. Buka terminal atau command prompt, navigasi ke direktori tempat file disimpan, dan jalankan perintah:
    ```bash
    gcc nama_file_anda.c -o NeptuData
    ```
    *Ganti `nama_file_anda.c` dengan nama file kode sumber Anda.*

3.  **Jalankan Program**
    Setelah kompilasi berhasil, jalankan program dengan perintah:
    ```bash
    # Untuk Windows
    .\NeptuData.exe

    # Untuk MacOS/Linux
    ./NeptuData
    ```

4.  **Ikuti Menu**
    Program akan menampilkan menu utama. Pilih opsi yang Anda inginkan dengan mengetikkan nomor yang sesuai dan tekan Enter. Selamat mendata!


---

## 🛠️ Teknologi yang Digunakan

* **Bahasa Pemrograman:** C
* **Compiler:** GCC (disarankan)
* **Library Standar:**
    * `stdio.h`
    * `string.h`

---
