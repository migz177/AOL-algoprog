#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// menggunakan struct agar setiap elemen dapat menjadi satu kesatuan di satu index temp
struct data {
    // angka yang di command menunjukkan parameter yang dipass ke function display pada search data.
    char location1[41]; // 1
    char city[31]; // 2
    char price[15]; // 3
    char room[6]; // 4 
    char bathroom[15]; // 5 
    char carpark[10]; // 6
    char type[15]; // 7
    char furnish[15]; // 8
}temp[5000]; 

int count = 0; // buat ngetrack ada berapa baris di file.csv
int displayDataCounter = 0; // buat ngetrack pada saat export data, menu apa yang paling terakhir di gunakan oleh user
int searchDataCounter = 0; // buat ngetrack pada saat export data, menu apa yang paling terakhir di gunakan oleh user
int sortDataCounter = 0; // buat ngetrack pada saat export data, menu apa yang paling terakhir di gunakan oleh user

// buat ngeread file 
void readFile(){
    FILE *fp = fopen("file.csv", "r"); // format open file
    if (!fp){
        printf ("File not found\n");
    }
    else {
        // fscanf untuk membaca input dalam file
        while (fscanf (fp, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s\n", temp[count].location1, temp[count].city, temp[count].price, temp[count].room, temp[count].bathroom, temp[count].carpark, temp[count].type, temp[count].furnish) == 8){ 
            count++; // buat mengetahui berapa baris dalam file
        }
    }
    fclose (fp);
}

// buat menu 1
void displayData (){
    int row;
    printf ("Number of rows: "); scanf ("%d", &row); getchar ();
    int i = 0;
    if (row >= 1){ // row >= 1 karena jika row = 0, berarti hanya header file yang muncul sendiri ketika user menginput row = 0
        printf ("%-28s %-15s %-10s %-8s %-10s %-10s %-10s %s\n", temp[i].location1, temp[i].city, temp[i].price, temp[i].room, temp[i].bathroom, temp[i].carpark, temp[i].type, temp[i].furnish);
    }
    for (i = 1; i <= row && i < count; i++){ // i < count karena count dimulai dari 0 bukan dari 1
        printf ("%-28s %-15s %-10s %-8s %-10s %-10s %-10s %s\n", temp[i].location1, temp[i].city, temp[i].price, temp[i].room, temp[i].bathroom, temp[i].carpark, temp[i].type, temp[i].furnish);
    }
    searchDataCounter = 0; 
    sortDataCounter = 0;
    displayDataCounter = 1; // displayDataCounter menjadi 1 menandakan menu 1 yang paling terakhir digunakan oleh user sebelum melakukan export data
}

// function buat menu ngeprint menu 2 dan exportData ketika menu 2 paling terakhir digunakan sebelum user ingin mengexport data
char search[20];
int num = 0; // untuk ngetrack function apa yang akan dipanggil ketika ingin exportData search
// numExport = 0 menandakan hanya pemanggilan menu search biasa
// numExport = 1 menandakan ingin mengexport data search 
void displaySearchData1 (int numExport, FILE *fp){
    if (numExport == 0){ 
        printf ("Data found. Detail of data:\n");
        printf ("%-28s %-15s %-10s %-8s %-10s %-10s %-10s %s\n", temp[0].location1, temp[0].city, temp[0].price, temp[0].room, temp[0].bathroom, temp[0].carpark, temp[0].type, temp[0].furnish);
    }
    if (numExport == 1){ 
        fprintf (fp, "%-28s %-15s %-10s %-8s %-10s %-10s %-10s %s\n", temp[0].location1, temp[0].city, temp[0].price, temp[0].room, temp[0].bathroom, temp[0].carpark, temp[0].type, temp[0].furnish);
    }
    for (int i = 1; i < count; i++){
        if (strcmp(temp[i].location1, search) == 0 && numExport == 0){
            printf ("%-28s %-15s %-10s %-8s %-10s %-10s %-10s %s\n", temp[i].location1, temp[i].city, temp[i].price, temp[i].room, temp[i].bathroom, temp[i].carpark, temp[i].type, temp[i].furnish);
        }
        else if (strcmp(temp[i].location1, search) == 0 && numExport == 1) {
            fprintf (fp, "%-28s %-15s %-10s %-8s %-10s %-10s %-10s %s\n", temp[i].location1, temp[i].city, temp[i].price, temp[i].room, temp[i].bathroom, temp[i].carpark, temp[i].type, temp[i].furnish);
        }
    }
}

void displaySearchData2 (int numExport, FILE *fp){
    if (numExport == 0){
        printf ("Data found. Detail of data:\n");
        printf ("%-28s %-15s %-10s %-8s %-10s %-10s %-10s %s\n", temp[0].location1, temp[0].city, temp[0].price, temp[0].room, temp[0].bathroom, temp[0].carpark, temp[0].type, temp[0].furnish);
    }
    if (numExport == 1){
        fprintf (fp, "%-28s %-15s %-10s %-8s %-10s %-10s %-10s %s\n", temp[0].location1, temp[0].city, temp[0].price, temp[0].room, temp[0].bathroom, temp[0].carpark, temp[0].type, temp[0].furnish);
    }
    for (int i = 1; i < count; i++){
        if (strcmp(temp[i].city, search) == 0 && numExport == 0){
            printf ("%-28s %-15s %-10s %-8s %-10s %-10s %-10s %s\n", temp[i].location1, temp[i].city, temp[i].price, temp[i].room, temp[i].bathroom, temp[i].carpark, temp[i].type, temp[i].furnish);
        }
        else if (strcmp(temp[i].city, search) == 0 && numExport == 1) {
            fprintf (fp, "%-28s %-15s %-10s %-8s %-10s %-10s %-10s %s\n", temp[i].location1, temp[i].city, temp[i].price, temp[i].room, temp[i].bathroom, temp[i].carpark, temp[i].type, temp[i].furnish);
        }
    }
}

void displaySearchData3 (int numExport, FILE *fp){
    if (numExport == 0){
        printf ("Data found. Detail of data:\n");
        printf ("%-28s %-15s %-10s %-8s %-10s %-10s %-10s %s\n", temp[0].location1, temp[0].city, temp[0].price, temp[0].room, temp[0].bathroom, temp[0].carpark, temp[0].type, temp[0].furnish);
    }
    if (numExport == 1){
        fprintf (fp, "%-28s %-15s %-10s %-8s %-10s %-10s %-10s %s\n", temp[0].location1, temp[0].city, temp[0].price, temp[0].room, temp[0].bathroom, temp[0].carpark, temp[0].type, temp[0].furnish);
    }
    for (int i = 1; i < count; i++){
        if (strcmp(temp[i].price, search) == 0 && numExport == 0){
            printf ("%-28s %-15s %-10s %-8s %-10s %-10s %-10s %s\n", temp[i].location1, temp[i].city, temp[i].price, temp[i].room, temp[i].bathroom, temp[i].carpark, temp[i].type, temp[i].furnish);
        }
        else if (strcmp(temp[i].price, search) == 0 && numExport == 1) {
            fprintf (fp, "%-28s %-15s %-10s %-8s %-10s %-10s %-10s %s\n", temp[i].location1, temp[i].city, temp[i].price, temp[i].room, temp[i].bathroom, temp[i].carpark, temp[i].type, temp[i].furnish);
        }
    }
}

void displaySearchData4 (int numExport, FILE *fp){
    if (numExport == 0){
        printf ("Data found. Detail of data:\n");
        printf ("%-28s %-15s %-10s %-8s %-10s %-10s %-10s %s\n", temp[0].location1, temp[0].city, temp[0].price, temp[0].room, temp[0].bathroom, temp[0].carpark, temp[0].type, temp[0].furnish);
    }
    if (numExport == 1){
        fprintf (fp, "%-28s %-15s %-10s %-8s %-10s %-10s %-10s %s\n", temp[0].location1, temp[0].city, temp[0].price, temp[0].room, temp[0].bathroom, temp[0].carpark, temp[0].type, temp[0].furnish);
    }
    for (int i = 1; i < count; i++){
        if (strcmp(temp[i].room, search) == 0 && numExport == 0){
            printf ("%-28s %-15s %-10s %-8s %-10s %-10s %-10s %s\n", temp[i].location1, temp[i].city, temp[i].price, temp[i].room, temp[i].bathroom, temp[i].carpark, temp[i].type, temp[i].furnish);
        }
        else if (strcmp(temp[i].room, search) == 0 && numExport == 1) {
            fprintf (fp, "%-28s %-15s %-10s %-8s %-10s %-10s %-10s %s\n", temp[i].location1, temp[i].city, temp[i].price, temp[i].room, temp[i].bathroom, temp[i].carpark, temp[i].type, temp[i].furnish);
        }
    }
}

void displaySearchData5 (int numExport, FILE *fp){
    if (numExport == 0){
        printf ("Data found. Detail of data:\n");
        printf ("%-28s %-15s %-10s %-8s %-10s %-10s %-10s %s\n", temp[0].location1, temp[0].city, temp[0].price, temp[0].room, temp[0].bathroom, temp[0].carpark, temp[0].type, temp[0].furnish);
    }
    if (numExport == 1){
        fprintf (fp, "%-28s %-15s %-10s %-8s %-10s %-10s %-10s %s\n", temp[0].location1, temp[0].city, temp[0].price, temp[0].room, temp[0].bathroom, temp[0].carpark, temp[0].type, temp[0].furnish);
    }
    for (int i = 1; i < count; i++){
        if (strcmp(temp[i].bathroom, search) == 0 && numExport == 0){
            printf ("%-28s %-15s %-10s %-8s %-10s %-10s %-10s %s\n", temp[i].location1, temp[i].city, temp[i].price, temp[i].room, temp[i].bathroom, temp[i].carpark, temp[i].type, temp[i].furnish);
        }
        else if (strcmp(temp[i].bathroom, search) == 0 && numExport == 1) {
            fprintf (fp, "%-28s %-15s %-10s %-8s %-10s %-10s %-10s %s\n", temp[i].location1, temp[i].city, temp[i].price, temp[i].room, temp[i].bathroom, temp[i].carpark, temp[i].type, temp[i].furnish);
        }
    }
}

void displaySearchData6 (int numExport, FILE *fp){
    if (numExport == 0){
        printf ("Data found. Detail of data:\n");
        printf ("%-28s %-15s %-10s %-8s %-10s %-10s %-10s %s\n", temp[0].location1, temp[0].city, temp[0].price, temp[0].room, temp[0].bathroom, temp[0].carpark, temp[0].type, temp[0].furnish);
    }
    if (numExport == 1){
        fprintf (fp, "%-28s %-15s %-10s %-8s %-10s %-10s %-10s %s\n", temp[0].location1, temp[0].city, temp[0].price, temp[0].room, temp[0].bathroom, temp[0].carpark, temp[0].type, temp[0].furnish);
    }
    for (int i = 1; i < count; i++){
        if (strcmp(temp[i].carpark, search) == 0 && numExport == 0){
            printf ("%-28s %-15s %-10s %-8s %-10s %-10s %-10s %s\n", temp[i].location1, temp[i].city, temp[i].price, temp[i].room, temp[i].bathroom, temp[i].carpark, temp[i].type, temp[i].furnish);
        }
        else if (strcmp(temp[i].carpark, search) == 0 && numExport == 1) {
            fprintf (fp, "%-28s %-15s %-10s %-8s %-10s %-10s %-10s %s\n", temp[i].location1, temp[i].city, temp[i].price, temp[i].room, temp[i].bathroom, temp[i].carpark, temp[i].type, temp[i].furnish);
        }
    }
}

void displaySearchData7 (int numExport, FILE *fp){
    if (numExport == 0){
        printf ("Data found. Detail of data:\n");
        printf ("%-28s %-15s %-10s %-8s %-10s %-10s %-10s %s\n", temp[0].location1, temp[0].city, temp[0].price, temp[0].room, temp[0].bathroom, temp[0].carpark, temp[0].type, temp[0].furnish);
    }
    if (numExport == 1){
        fprintf (fp, "%-28s %-15s %-10s %-8s %-10s %-10s %-10s %s\n", temp[0].location1, temp[0].city, temp[0].price, temp[0].room, temp[0].bathroom, temp[0].carpark, temp[0].type, temp[0].furnish);
    }
    for (int i = 1; i < count; i++){
        if (strcmp(temp[i].type, search) == 0 && numExport == 0){
            printf ("%-28s %-15s %-10s %-8s %-10s %-10s %-10s %s\n", temp[i].location1, temp[i].city, temp[i].price, temp[i].room, temp[i].bathroom, temp[i].carpark, temp[i].type, temp[i].furnish);
        }
        else if (strcmp(temp[i].type, search) == 0 && numExport == 1) {
            fprintf (fp, "%-28s %-15s %-10s %-8s %-10s %-10s %-10s %s\n", temp[i].location1, temp[i].city, temp[i].price, temp[i].room, temp[i].bathroom, temp[i].carpark, temp[i].type, temp[i].furnish);
        }
    }
}

void displaySearchData8 (int numExport, FILE *fp){
    if (numExport == 0){
        printf ("Data found. Detail of data:\n");
        printf ("%-28s %-15s %-10s %-8s %-10s %-10s %-10s %s\n", temp[0].location1, temp[0].city, temp[0].price, temp[0].room, temp[0].bathroom, temp[0].carpark, temp[0].type, temp[0].furnish);
    }
    if (numExport == 1){
        fprintf (fp, "%-28s %-15s %-10s %-8s %-10s %-10s %-10s %s\n", temp[0].location1, temp[0].city, temp[0].price, temp[0].room, temp[0].bathroom, temp[0].carpark, temp[0].type, temp[0].furnish);
    }
    for (int i = 1; i < count; i++){
        if (strcmp(temp[i].furnish, search) == 0 && numExport == 0){
            printf ("%-28s %-15s %-10s %-8s %-10s %-10s %-10s %s\n", temp[i].location1, temp[i].city, temp[i].price, temp[i].room, temp[i].bathroom, temp[i].carpark, temp[i].type, temp[i].furnish);
        }
        else if (strcmp(temp[i].furnish, search) == 0 && numExport == 1) {
            fprintf (fp, "%-28s %-15s %-10s %-8s %-10s %-10s %-10s %s\n", temp[i].location1, temp[i].city, temp[i].price, temp[i].room, temp[i].bathroom, temp[i].carpark, temp[i].type, temp[i].furnish);
        }
    }
}

// function utama dari menu 2
void searchData (){
    searchDataCounter = 1; // menandakan kalau searchData adalah menu terakhir yang digunakan user sebelum melakukan exportData
    sortDataCounter = 0;
    displayDataCounter = 0;
    int track = 0; // variable untuk memvalidasi data yang ingin di cari ada atau tidak
    char column[20];
    printf ("Choose column : "); scanf ("%[^\n]", column); getchar ();
    printf ("What data do you want to find? "); scanf ("%[^\n]", search); getchar ();
    if (strcmp(temp[0].location1, column) == 0){ // temp[0] karena index ke 0 mengandung line pertama dari file
        for (int i = 1; i < count; i++){
            if (strcmp(temp[i].location1, search) == 0){
                track = 1; 
                break; // karena hanya ingin mengecek data yang ingin dicari ada apa tidak
            }
        }
        if (track == 1){
            displaySearchData1(0, 0); // displaySearchData1 () untuk search Location, 0 menandakan bahwa dia hanya menyetak di console
            num = 1; // berguna di function exportData
        } 
        else {
            printf ("Data not found!\n");
            searchDataCounter = 0;
        }
    }
    else if (strcmp(temp[0].city, column) == 0){ // temp[0] karena index ke 0 mengandung line pertama dari file
        for (int i = 1; i < count; i++){
            if (strcmp(temp[i].city, search) == 0){
                track = 1;
                break; // karena hanya ingin mengecek data yang ingin dicari ada apa tidak
            }
        }
        if (track == 1){
            displaySearchData2(0, 0); // displaySearchData2 () untuk search Location, 0 menandakan bahwa dia hanya menyetak di console
            num = 2; // berguna di function exportData
        }
        else {
            printf ("Data not found!\n");
            searchDataCounter = 0;
        }
    }
    else if (strcmp(temp[0].price, column) == 0){ // temp[0] karena index ke 0 mengandung line pertama dari file
        for (int i = 1; i < count; i++){
            if (strcmp(temp[i].price, search) == 0){
                track = 1;
                break; // karena hanya ingin mengecek data yang ingin dicari ada apa tidak
            }
        }
        if (track == 1){
            displaySearchData3(0, 0); // displaySearchData3 () untuk search Location, 0 menandakan bahwa dia hanya menyetak di console
            num = 3; // berguna di function exportData
        }
        else {
            printf ("Data not found!\n");
            searchDataCounter = 0;
        }
    }
    else if (strcmp(temp[0].room, column) == 0){ // temp[0] karena index ke 0 mengandung line pertama dari file
        for (int i = 1; i < count; i++){
            if (strcmp(temp[i].room, search) == 0){
                track = 1;
                break; // karena hanya ingin mengecek data yang ingin dicari ada apa tidak
            }
        }
        if (track == 1){
            displaySearchData4(0, 0); // displaySearchData4 () untuk search Location, 0 menandakan bahwa dia hanya menyetak di console
            num = 4; // berguna di function exportData
        }
        else{
            printf ("Data not found!\n");
            searchDataCounter = 0;
        }
    }
    else if (strcmp(temp[0].bathroom, column) == 0){ // temp[0] karena index ke 0 mengandung line pertama dari file
        for (int i = 1; i < count; i++){
            if (strcmp(temp[i].bathroom, search) == 0){
                track = 1;
                break; // karena hanya ingin mengecek data yang ingin dicari ada apa tidak
            }
        }
        if (track == 1){
            displaySearchData5(0, 0); // displaySearchData5 () untuk search Location, 0 menandakan bahwa dia hanya menyetak di console
            num = 5; // berguna di function exportData
        }
        else  {
            printf ("Data not found!\n");
            searchDataCounter = 0;
        }
    }
    else if (strcmp(temp[0].carpark, column) == 0){ // temp[0] karena index ke 0 mengandung line pertama dari file
        for (int i = 1; i < count; i++){
            if (strcmp(temp[i].carpark, search) == 0){
                track = 1;
                break; // karena hanya ingin mengecek data yang ingin dicari ada apa tidak
            }
        }
        if (track == 1){
            displaySearchData6(0, 0); // displaySearchData6 () untuk search Location, 0 menandakan bahwa dia hanya menyetak di console
            num = 6; // berguna di function exportData
        }
        else {
            printf ("Data not found!\n");
            searchDataCounter = 0;
        }
    }
    else if (strcmp(temp[0].type, column) == 0){ // temp[0] karena index ke 0 mengandung line pertama dari file
        for (int i = 1; i < count; i++){
            if (strcmp(temp[i].type, search) == 0){
                track = 1;
                break; // karena hanya ingin mengecek data yang ingin dicari ada apa tidak
            }
        }
        if (track == 1){
            displaySearchData7(0, 0); // displaySearchData7 () untuk search Location, 0 menandakan bahwa dia hanya menyetak di console
            num = 7; // berguna di function exportData
        }
        else {
            printf ("Data not found!\n");
            searchDataCounter = 0;
        }
    }
    else if (strcmp(temp[0].furnish, column) == 0){ // temp[0] karena index ke 0 mengandung line pertama dari file
        for (int i = 1; i < count; i++){
            if (strcmp(temp[i].furnish, search) == 0){
                track = 1;
                break; // karena hanya ingin mengecek data yang ingin dicari ada apa tidak
            }
        }
        if (track == 1){
            displaySearchData8(0, 0); // displaySearchData8 () untuk search Location, 0 menandakan bahwa dia hanya menyetak di console
            num = 8; // berguna di function exportData
        }
        else  {
            printf ("Data not found!\n");
            searchDataCounter = 0;
        }
    }
    else {
        printf ("Data not found!\n");
        searchDataCounter = 0;
    }
}

// buat menu 3 
void sortData (){
    char columnSort[20], sorting[11];
    int size = count; 
    printf ("Choose column: "); scanf ("%[^\n]", columnSort); getchar ();
    printf ("Sort ascending or descending? "); scanf ("%[^\n]", sorting); getchar ();
    for (int i = size - 1; i > 1 ; i--){
        for (int j = 1; j < i; j++){
            int hasil = 0; // variable untuk mengetahui hasil dari strcmp itu > atau < dari 0 jika < berarti dsc, > berarti asc
            if (strcmp(temp[0].location1, columnSort) == 0) { 
                hasil = strcmp(temp[j].location1, temp[j + 1].location1);
            } else if (strcmp(temp[0].city, columnSort) == 0) {
                hasil = strcmp(temp[j].city, temp[j + 1].city);
            } else if (strcmp(temp[0].price, columnSort) == 0) {
                // menggunakan atoi untuk mengubah nilai string menjadi nilai integer
                int price1 = atoi(temp[j].price); 
                int price2 = atoi(temp[j + 1].price);
                hasil = price1 - price2;  
            } else if (strcmp(temp[0].room, columnSort) == 0) {
                hasil = strcmp(temp[j].room, temp[j + 1].room);
            } else if (strcmp(temp[0].bathroom, columnSort) == 0) {
                hasil = strcmp(temp[j].bathroom, temp[j + 1].bathroom);
            } else if (strcmp(temp[0].carpark, columnSort) == 0) {
                hasil = strcmp(temp[j].carpark, temp[j + 1].carpark);
            } else if (strcmp(temp[0].type, columnSort) == 0) {
                hasil = strcmp(temp[j].type, temp[j + 1].type);
            } else if (strcmp(temp[0].furnish, columnSort) == 0) {
                hasil = strcmp(temp[j].furnish, temp[j + 1].furnish);
            }
            if ((strcmp(sorting, "asc") == 0 && hasil > 0) || (strcmp(sorting, "ascending") == 0 && hasil > 0)|| (strcmp(sorting, "descending") == 0 && hasil < 0) ||(strcmp(sorting, "dsc") == 0 && hasil < 0)) {
                // melakukan swap 
                data temp1 = temp[j];
                temp[j]= temp[j+1];
                temp[j+1] = temp1;
            }
        }
    }
    // buat ngeprint header 
    printf ("%-28s %-15s %-10s %-8s %-10s %-10s %-10s %s\n", temp[0].location1, temp[0].city, temp[0].price, temp[0].room, temp[0].bathroom, temp[0].carpark, temp[0].type, temp[0].furnish);
    for (int i = 1; i <= 10; i++){
        printf ("%-28s %-15s %-10s %-8s %-10s %-10s %-10s %s\n", temp[i].location1, temp[i].city, temp[i].price, temp[i].room, temp[i].bathroom, temp[i].carpark, temp[i].type, temp[i].furnish);
    }
    searchDataCounter = 0;
    sortDataCounter = 1; // menandakan bahwa sortdata merupakan menu terakhir yang digunakan user sebelum ingin mengexport data
    displayDataCounter = 0;
}

// buat menu 4 
void exportData (){
    char fileNew[1001];
    printf ("File name: "); scanf ("%s", fileNew); getchar ();
    FILE *newFile = fopen (strcat(fileNew, ".csv"), "w"); // menggunakan strcat untuk menggabungkan 2 kata menjadi satu (variable FileNew.csv)
    if (displayDataCounter == 1 || (displayDataCounter == 0 && searchDataCounter == 0 && sortDataCounter == 0)){
        for(int i = 0; i < count ; i++) {
            fprintf(newFile, "%s,%s,%s,%s,%s,%s,%s,%s", temp[i].location1, temp[i].city, temp[i].price, temp[i].room, temp[i].bathroom, temp[i].carpark, temp[i].type, temp[i].furnish);
            if (i < count - 1) fprintf (newFile, "\n"); 
        }
    }
    else if (searchDataCounter == 1){
        if (num == 1) displaySearchData1(1, newFile);
        else if (num == 2) displaySearchData2(1, newFile);
        else if (num == 3) displaySearchData3(1, newFile);
        else if (num == 4) displaySearchData4(1, newFile);
        else if (num == 5) displaySearchData5(1, newFile);
        else if (num == 6) displaySearchData6(1, newFile);
        else if (num == 7) displaySearchData7(1, newFile);
        else if (num == 8) displaySearchData8(1, newFile);
    }
    else if (sortDataCounter == 1){
        char jawaban[5];
        printf ("Want to print all data that alr sorted? [YES/NO] \n"); 
        printf ("> "); scanf ("%s", jawaban); getchar ();
        if (strcmp(jawaban, "YES") == 0){
            for (int i = 0; i < count; i++){
                fprintf(newFile, "%s,%s,%s,%s,%s,%s,%s,%s", temp[i].location1, temp[i].city, temp[i].price, temp[i].room, temp[i].bathroom, temp[i].carpark, temp[i].type, temp[i].furnish);
                if (i < count - 1) fprintf (newFile, "\n"); 
            }
        }
        else {
            for (int i = 0; i <= 10; i++){
                fprintf(newFile, "%s,%s,%s,%s,%s,%s,%s,%s", temp[i].location1, temp[i].city, temp[i].price, temp[i].room, temp[i].bathroom, temp[i].carpark, temp[i].type, temp[i].furnish);
                if (i < count - 1) fprintf (newFile, "\n"); 
            } 
        }
    }
	printf("Data successfully written to file %s!\n", fileNew);
	
	fclose(newFile);
}

int main (){
    readFile ();
    int option;
    do {
        printf ("What do you want to do?\n");
        printf ("1. Display Data\n");
        printf ("2. Search Data\n");
        printf ("3. Sort Data\n");
        printf ("4. Export Data\n");
        printf ("5. Exit\n");
        printf ("Your Choice: "); 
        scanf ("%d", &option); getchar ();
        switch (option){
            case 1 : {
                displayData ();
                break;
            }
            case 2 : {
                searchData ();
                break;
            }
            case 3 : {
                sortData ();
                break;
            }
            case 4 : {
                exportData ();
            }
        }
    }while (option != 5);
return 0;
}