
/* File: ListPoint.h */
/* Definisi ADT ListPoint */

#ifndef LISTPOINT_H
#define LISTPOINT_H

#include "boolean.h"
#include "Point.h"

/*  Kamus Umum */
#define IDX_UNDEF -1
/* Indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef Point ElType; /* type elemen list */
typedef int IdxType;
typedef struct
{
   ElType *buffer; /* memori tempat penyimpan elemen (container) */
   int nEff;       /* >=0, banyaknya elemen efektif */
   int capacity;   /* ukuran elemen */
} ListPoint;
/* Indeks yang digunakan [0..capacity-1] */
/* Jika l adalah : ListPoint, cara deklarasi dan akses: */
/* Deklarasi : l : ListPoint */
/* Maka cara akses:
   l.nEff      untuk mengetahui banyaknya elemen
   l.buffer    untuk mengakses seluruh nilai elemen list
   l.buffer[i] untuk mengakses elemen ke-i */
/* Definisi :
  list kosong: l.nEff = 0
  Definisi elemen pertama : l.buffer[i] dengan i=0
  Definisi elemen terakhir yang terdefinisi: l.buffer[i] dengan i=l.nEff */

/* ********** SELEKTOR ********** */
#define NEFF(l) (l).nEff
#define BUFFER(l) (l).buffer
#define ELMT(l, i) (l).buffer[i]
#define CAPACITY(l) (l).capacity

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListPoint(ListPoint *l, int capacity);
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */
/* Konstruktor : create list random  */
void CreateListPointRandom(ListPoint *l, int size);
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l dengan ukuran sebesar size */
/* Setiap elemen list diinisialisasi secara acak */

void dealocate(ListPoint *l);
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int length(ListPoint l);
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmpty(ListPoint l);
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
/* *** Test list penuh *** */
boolean isFull(ListPoint l);
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
void displayList(ListPoint l);
/* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */

/* ********** NILAI EKSTREM ********** */
void extremesAbsis(ListPoint l, ElType *max, ElType *min);
/* I.S. List l tidak kosong */
/* F.S. max berisi nilai maksimum absis l;
        min berisi nilai minimum absis l */

/* ********** SORTING ********** */
void selectionSortX(ListPoint *l, int i, int j);
/* I.S. l boleh kosong */
/* F.S. l terurut membesar berdasarkan absis */
/* Proses : Mengurutkan l dengan salah satu algoritma selection sort berdasarkan absis */
void partisiX(ListPoint *l, int i, int j);
/* Mempartisi larik A[i..j] dengan cara mencari elemen minimum di dalam A[i..j] */
/* Menempatkan elemen terkecil sebagai elemen pertama larik */
/* Masukan: A[i..j] sudah terdefinisi elemen-elemennya */
/* Luaran: A[i..j] dengan A[i] adalah elemen minimum. */
void selectionSortY(ListPoint *l, int i, int j);
/* I.S. l boleh kosong */
/* F.S. l terurut membesar berdasarkan ordinat */
/* Proses : Mengurutkan l dengan salah satu algoritma selection sort berdasarkan absis */
void partisiY(ListPoint *l, int i, int j);
/* Mempartisi larik A[i..j] dengan cara mencari elemen minimum di dalam A[i..j] */
/* Menempatkan elemen terkecil sebagai elemen pertama larik */
/* Masukan: A[i..j] sudah terdefinisi elemen-elemennya */
/* Luaran: A[i..j] dengan A[i] adalah elemen minimum. */

/* ********** OPERASI LAIN ********** */
void copyList(ListPoint lIn, ListPoint *lOut);
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */

float ABS(float a, float b);
/* Mengembalikan nilai mutlak dari selisih dua bilagan real */

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLast(ListPoint *l, ElType val);
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLast(ListPoint *l, ElType *val);
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */

/* ********** MENCARI PASANGAN TITIK TERDEKAT ********** */
/* *** Menggunakan algoritma brute force *** */
void FindClosestPairBF(ListPoint *l, Point *p1, Point *p2, float *min, int *count);
/* *** Menggunakan algoritma divide and conquer *** */
void FindClosestPairDC(ListPoint *l, int size, Point *p1, Point *p2, float *min, int *count);

#endif