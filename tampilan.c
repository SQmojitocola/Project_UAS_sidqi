//untuk menampilkan tampilan utama program yaitu menampilkan daftar barang

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"


//Fungsi untuk membaca data produk dari file eksternal
void bacaDataBarang(Produk dataproduk[], int *jumlahproduk) {
    FILE *file;
    file = fopen("data_barang.txt", "r");
    if (file == NULL) {
        printf("File data_barang.txt tidak dapat dibuka.\n");
        exit(1);
    }

    *jumlahproduk = 0;
    while (fscanf(file, "%s %s %f %d", dataproduk[*jumlahproduk].kode, dataproduk[*jumlahproduk].nama, &dataproduk[*jumlahproduk].harga, &dataproduk[*jumlahproduk].stok) != EOF) {
        (*jumlahproduk)++;
    }

    fclose(file);
}

//Fungsi untuk menampilkan daftar produk
void tampilkanDaftarBarang(Produk dataproduk[], int jumlahproduk){
    printf("----------------------------------------------------------------\n");
    printf("\t\t\tDAFTAR PRODUK\t\t\t\t|\n");
    printf("----------------------------------------------------------------\n");
    printf("KODE PRODUK\t|NAMA PRODUK\t|HARGA PRODUK\t|STOK PRODUK\t|\n");
    printf("----------------------------------------------------------------\n");

    for (int i = 0; i < jumlahproduk; i++) {
        printf("%s\t\t|%s\t\t|%.2f\t|%d\t\t|\n", dataproduk[i].kode, dataproduk[i].nama, dataproduk[i].harga, dataproduk[i].stok);
    }
    printf("----------------------------------------------------------------\n");
}
