#include <stdio.h>
#include <string.h>

//==== DEKLARASI ARRAY STRUCT ====//
typedef struct {
    char jenis[50];
    float berat;
    float ukuran;
    char lokasi[50];
} Tangkapan;

//==== DEKLARASI STRUCT DIDALAM ====//
Tangkapan tangkapanData[100];
int jumlahTangkapan = 0;


//==== VOID TAMPILAN MENU UTAMA ====//
void tampilkanMenu() {
    printf("                                    _                 \n");
    printf("                   _               | |      _         \n");
    printf(" ____   ____ ____ | |_ _   _     _ | | ____| |_  ____ \n");
    printf("|  _ \\ / _  )  _ \\|  _) | | |   / || |/ _  |  _)/ _  |\n");
    printf("| | | ( (/ /| | | | |_| |_| |  ( (_| ( ( | | |_( ( | |\n");
    printf("|_| |_|\\____) ||_/ \\___)____|   \\____|\\_||_|\\___)_||_|\n");
    printf("            |_|                                       \n");
    
    printf("\n======================== MANAJEMEN DATA HASIL TANGKAPAN PERIKANAN ========================\n");
    printf("1. Input Data Tangkapan\n");
    printf("2. Lihat Statistik Tangkapan\n");
    printf("3. Simpan Data ke File\n");
    //printf("4. Hapus Data dari File\n");
    printf("4. Muat Data dari File\n");
    printf("5. Cari Tangkapan\n");
    printf("6. Urutkan Data\n");
    printf("7. Keluar\n");
    printf("===========================================================================================\n");
    printf("Pilih opsi: ");
}


//==== VOID TAMPILAN SAMBUTAN ====//
void tampilkanSambutan(){
    printf("\n");
    printf("===================================== SELAMAT DATANG ======================================\n");
    printf("||                                 DI PROGRAM NEPTU Data!                                ||\n");
    printf("||                                                                                       ||\n");
    printf("||                            Semoga Anda memiliki pengalaman                            ||\n");
    printf("||                           yang menyenangkan bersama ikan anda!                        ||\n");
    printf("||                                                                                       ||\n");
    printf("===========================================================================================\n");
}


//==== FUNGSI FLOAT UNTUK MENCARI RATA-RATA ====//
float hitungRataRataBerat() {
    float totalBerat = 0;
    for (int i = 0; i < jumlahTangkapan; i++) {
        totalBerat += tangkapanData[i].berat;
    }
    return totalBerat / jumlahTangkapan;
}


//==== FUNGSI MENCARI IKAN TERBANYAK ====//
char* cariIkanTerbanyak() {
    int frekuensi[100] = {0};

    for (int i = 0; i < jumlahTangkapan; i++) {
        for (int j = i + 1; j < jumlahTangkapan; j++) {
            if (strcmp(tangkapanData[i].jenis, tangkapanData[j].jenis) == 0) {
                frekuensi[i]++;
            }
        }
    }

    int indeksTerbanyak = 0;
    for (int i = 1; i < jumlahTangkapan; i++) {
        if (frekuensi[i] > frekuensi[indeksTerbanyak]) {
            indeksTerbanyak = i;
        }
    }
    return tangkapanData[indeksTerbanyak].jenis;
}


// ==== VOID INPUTAN DATA USER ====//
void inputData() {
    printf("\n================================= INPUT DATA TANGKAPAN =================================\n");
    printf("Jenis Ikan       : ");
    scanf("%s", tangkapanData[jumlahTangkapan].jenis);
    printf("Berat (kg)       : ");
    scanf("%f", &tangkapanData[jumlahTangkapan].berat);
    printf("Ukuran (cm)      : ");
    scanf("%f", &tangkapanData[jumlahTangkapan].ukuran);
    printf("Lokasi Penangkapan: ");
    scanf("%s", tangkapanData[jumlahTangkapan].lokasi);
    jumlahTangkapan++;
    printf("\nData berhasil disimpan!\n");
}


//==== VOID MENAMPILKAN STATISTIK ====//
void tampilkanStatistik() {
    printf("\n================================ STATISTIK TANGKAPAN ==================================\n");
    printf("Jumlah Total Tangkapan        : %d\n", jumlahTangkapan);
    printf("Rata-rata Berat Tangkapan     : %.2f kg\n", hitungRataRataBerat());
    printf("Ikan Terbanyak Ditangkap      : %s\n", cariIkanTerbanyak());
    printf("=========================================================================================\n");
}


//==== VOID MENYIMPAN FILE KE CSV ====//
void simpanKeFile() {
    FILE *file = fopen("C:\\Users\\asus\\OneDrive\\Desktop\\Test\\tangkapan.csv", "w");
    if (file != NULL) {
        for (int i = 0; i < jumlahTangkapan; i++) {
            fprintf(file, "%s %.2f %.2f %s\n", tangkapanData[i].jenis, tangkapanData[i].berat, tangkapanData[i].ukuran, tangkapanData[i].lokasi);
        }
        fclose(file);
        printf("Data berhasil disimpan ke dalam file.\n");
    } else {
        printf("Gagal menyimpan data ke dalam file.\n");
    }
}


//==== VOID MEMUAT ATAU MEMBACA FILE CSV ====//
void muatDariFile() {
    FILE *file = fopen("C:\\Users\\asus\\OneDrive\\Desktop\\Test\\tangkapan.csv", "r");
    if (file != NULL) {
        while (fscanf(file, "%s %f %f %s", tangkapanData[jumlahTangkapan].jenis, &tangkapanData[jumlahTangkapan].berat, &tangkapanData[jumlahTangkapan].ukuran, tangkapanData[jumlahTangkapan].lokasi) != EOF) {
            jumlahTangkapan++;
        }
        fclose(file);
        printf("Data berhasil dimuat dari file.\n");
    } else {
        printf("Gagal memuat data dari file.\n");
    }
}


//==== VOID MENGHAPUS FILE ====//
/*void hapusFile() {
     FILE *file = fopen("C:\\Users\\asus\\OneDrive\\Desktop\\Test\\tangkapan.csv", "w");
    if (file != NULL) {
        fclose(file);
        printf("Semua data berhasil dihapus dari file.\n");
    } else {
        printf("Gagal menghapus data dari file.\n");
    }
}*/


//==== VOID SORTING BERDASARKAN PILIHAN USERS ====//
void sortingBerdasarkan() {
    int pilihan;
    printf("\n===== PILIH KRITERIA PENGGURUTAN =====\n");
    printf("1. Jenis Ikan (A-Z)\n");
    printf("2. Berat (Descending)\n");
    printf("3. Ukuran (Descending)\n");
    printf("4. Lokasi (A-Z)\n");
    printf("Pilih opsi: ");
    scanf("%d", &pilihan);

    Tangkapan temp;
    for (int i = 0; i < jumlahTangkapan - 1; i++) {
        for (int j = 0; j < jumlahTangkapan - i - 1; j++) {
            switch (pilihan) {
                case 1: // Urutkan berdasarkan jenis ikan
                    if (strcmp(tangkapanData[j].jenis, tangkapanData[j + 1].jenis) > 0) {
                        temp = tangkapanData[j];
                        tangkapanData[j] = tangkapanData[j + 1];
                        tangkapanData[j + 1] = temp;
                    }
                    break;
                case 2: // Urutkan berdasarkan berat (terbesar ke terkecil)
                    if (tangkapanData[j].berat < tangkapanData[j + 1].berat) {
                        temp = tangkapanData[j];
                        tangkapanData[j] = tangkapanData[j + 1];
                        tangkapanData[j + 1] = temp;
                    }
                    break;
                case 3: // Urutkan berdasarkan ukuran (terbesar ke terkecil)
                    if (tangkapanData[j].ukuran < tangkapanData[j + 1].ukuran) {
                        temp = tangkapanData[j];
                        tangkapanData[j] = tangkapanData[j + 1];
                        tangkapanData[j + 1] = temp;
                    }
                    break;
                case 4: // Urutkan berdasarkan lokasi
                    if (strcmp(tangkapanData[j].lokasi, tangkapanData[j + 1].lokasi) > 0) {
                        temp = tangkapanData[j];
                        tangkapanData[j] = tangkapanData[j + 1];
                        tangkapanData[j + 1] = temp;
                    }
                    break;
                default:
                    printf("Opsi pengurutan tidak valid.\n");
                    return;
            }
        }
    }

    // Menampilkan data yang telah diurutkan
    printf("\n===== DATA TANGKAPAN YANG TELAH DIURUTKAN =====\n");
    printf("Jenis Ikan\tBerat (kg)\tUkuran (cm)\tLokasi\n");
    printf("-------------------------------------------------------\n");
    for (int i = 0; i < jumlahTangkapan; i++) {
        printf("%s\t\t%.2f\t\t%.2f\t\t%s\n", tangkapanData[i].jenis, tangkapanData[i].berat, tangkapanData[i].ukuran, tangkapanData[i].lokasi);
    }
}


//==== VOID MENCARI TANGKAPAN BERDASARKAN APA ====//
void cariTangkapan() {
    int pilihan;
    char kriteria[20];

    printf("\n");
    printf("=====================================\n");
    printf("|    PILIH KRITERIA PENCARIAN       |\n");
    printf("=====================================\n");
    printf("| 1. Jenis Ikan                     |\n");
    printf("| 2. Lokasi Penangkapan             |\n");
    printf("| 3. Berat                          |\n");
    printf("| 4. Ukuran                         |\n");
    printf("=====================================\n");
    printf("Pilih kriteria pencarian: ");
    scanf("%d", &pilihan);

    switch(pilihan) {
        case 1:
            strcpy(kriteria, "Jenis Ikan");
            break;
        case 2:
            strcpy(kriteria, "Lokasi Penangkapan");
            break;
        case 3:
            strcpy(kriteria, "Berat");
            break;
        case 4:
            strcpy(kriteria, "Ukuran");
            break;
        default:
            printf("Pilihan tidak valid.\n");
            printf("PILIH DARI 1-4");
            return;
    }

    printf("\nMasukkan %s yang ingin dicari: ", kriteria);
    char nilaiCari[50];
    scanf("%s", nilaiCari);

    printf("\n===== HASIL PENCARIAN BERDASARKAN %s =====\n", kriteria);
    printf("Jenis Ikan\tBerat (kg)\tUkuran (cm)\tLokasi\n");
    printf("-------------------------------------------------------\n");

    int ditemukan = 0;
    for (int i = 0; i < jumlahTangkapan; i++) {
        if (strcmp(kriteria, "Jenis Ikan") == 0 && strcmp(tangkapanData[i].jenis, nilaiCari) == 0) {
            printf("%s\t\t%.2f\t\t%.2f\t\t%s\n", tangkapanData[i].jenis, tangkapanData[i].berat, tangkapanData[i].ukuran, tangkapanData[i].lokasi);
            ditemukan = 1;
        } else if (strcmp(kriteria, "Lokasi Penangkapan") == 0 && strcmp(tangkapanData[i].lokasi, nilaiCari) == 0) {
            printf("%s\t\t%.2f\t\t%.2f\t\t%s\n", tangkapanData[i].jenis, tangkapanData[i].berat, tangkapanData[i].ukuran, tangkapanData[i].lokasi);
            ditemukan = 1;
        } else if (strcmp(kriteria, "Berat") == 0 && tangkapanData[i].berat == atof(nilaiCari)) {
            printf("%s\t\t%.2f\t\t%.2f\t\t%s\n", tangkapanData[i].jenis, tangkapanData[i].berat, tangkapanData[i].ukuran, tangkapanData[i].lokasi);
            ditemukan = 1;
        } else if (strcmp(kriteria, "Ukuran") == 0 && tangkapanData[i].ukuran == atof(nilaiCari)) {
            printf("%s\t\t%.2f\t\t%.2f\t\t%s\n", tangkapanData[i].jenis, tangkapanData[i].berat, tangkapanData[i].ukuran, tangkapanData[i].lokasi);
            ditemukan = 1;
        }
    }
    if (!ditemukan) {
        printf("Data tidak ditemukan berdasarkan %s.\n", kriteria);
    }
}


//==== FUNGSI UTAMA PROGRAM ====//
int main() {
    int pilihanMulai;

    // Menampilkan sambutan
    tampilkanSambutan();

    // Menampilkan pilihan untuk memulai atau keluar
    printf("+-------------------------------------+\n");
    printf("|                                     |\n");
    printf("| 1. Mulai Program                    |\n");
    printf("| 2. Keluar                           |\n");
    printf("|                                     |\n");
    printf("+-------------------------------------+\n");
    printf("Pilih opsi: ");
    scanf("%d", &pilihanMulai);

    if (pilihanMulai == 1) {
        int pilihan;
        do {

            tampilkanMenu();
            scanf("%d", &pilihan);
            switch (pilihan) {
                case 1:
                    inputData();
                    break;
                case 2:
                    tampilkanStatistik();
                    break;
                case 3:
                    simpanKeFile();
                    break;
                /*case 4:
                    hapusFile();
                    break;*/
                case 4:
                    muatDariFile();
                    break;
                case 5:
                    cariTangkapan();
                    break;
                case 6:
                    sortingBerdasarkan();
                    break;
                case 7:
                    printf("Terima kasih telah menggunakan program ini.\n");
                    break;
                default:
                    printf("Opsi tidak valid.\n");
                    break;
            }
        } while (pilihan != 7);
    } else if (pilihanMulai == 2) {
        printf("Terima kasih telah mengunjungi program ini. Sampai jumpa!\n");
    } else {
        printf("Pilihan tidak valid. Harap coba lagi.\n");
    }
    return 0;
}

//==== PROGRAM SELESAI ====//
