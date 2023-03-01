/* MODUL LIST INTEGER DENGAN ELEMEN POSITIF */
/* Berisi definisi dan semua primitif pemrosesan list integer dengan elemen
   positif */
/* Penempatan elemen selalu rapat kiri */
/* Banyaknya elemen didefinisikan secara implisit, memori array statik */

#ifndef LISTPOINT_H
#define LISTPOINT_H

#include "boolean.h"
#include "Point.h"

/*  Kamus Umum */
#define CAPACITY 1000
/* Kapasitas penyimpanan */
#define IDX_UNDEF -1
/* Indeks tak terdefinisi*/
extern Point VAL_UNDEF;
/* Deklarasi nilai elemen tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef Point ElType; /* type elemen List */
typedef struct
{
    ElType contents[CAPACITY]; /* memori tempat penyimpan elemen (container) */
} ListPoint;
/* Indeks yang digunakan [0..CAPACITY-1] */
/* Jika l adalah ListPoint, cara deklarasi dan akses: */
/* Deklarasi : l : ListPoint */
/* Maka cara akses:
   ELMT(l,i) untuk mengakses elemen ke-i */
/* Definisi :
   List kosong: semua elemen bernilai VAL_UNDEF
   Definisi elemen pertama: ELMT(l,i) dengan i=0 */

/* ********** SELEKTOR ********** */
#define ELMT(l, i) (l).contents[(i)]

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListPoint(ListPoint *l);
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi semua elemen List l dengan VAL_UNDEF */
/* *** Konstruktor List Random *** */
void CreateListPointRandom(ListPoint *l, int size);
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l dengan ukuran sebesar size */
/* Setiap elemen list diinisialisasi secara acak */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int length(ListPoint l);
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmpty(ListPoint l);
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
/* *** Test List penuh *** */
boolean isFull(ListPoint l);
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */

/* ********** TULIS dengan INPUT/OUTPUT device ********** */
void displayList(ListPoint l);
/* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika List kosong : menulis [] */

/* ********** SORTING ********** */
void selectionSortX(ListPoint *l, int i, int j);
/* I.S. l boleh kosong */
/* F.S. l terurut membesar berdasarkan absis */
/* Proses : Mengurutkan l dengan salah satu algoritma selection sort berdasarkan absis */
void partisiX(ListPoint *l, int i, int j);
/* Mempartisi larik l[i..j] dengan cara mencari elemen minimum di dalam A[i..j] */
/* Menempatkan elemen terkecil sebagai elemen pertama larik */
/* Masukan: l[i..j] sudah terdefinisi elemen-elemennya */
/* Luaran: l[i..j] dengan l[i] adalah elemen minimum. */
void selectionSortY(ListPoint *l, int i, int j);
/* I.S. l boleh kosong */
/* F.S. l terurut membesar berdasarkan ordinat */
/* Proses : Mengurutkan l dengan salah satu algoritma selection sort berdasarkan absis */
void partisiY(ListPoint *l, int i, int j);
/* Mempartisi larik A[i..j] dengan cara mencari elemen minimum di dalam A[i..j] */
/* Menempatkan elemen terkecil sebagai elemen pertama larik */
/* Masukan: l[i..j] sudah terdefinisi elemen-elemennya */
/* Luaran: l[i..j] dengan l[i] adalah elemen minimum. */

/* ********** OPERASI LAIN ********** */
void copyList(ListPoint lIn, int firstIdxCopy, int lastIdxCopy, ListPoint *lOut);
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn
        Elemen yang disalin mulai dari indeks ke-firstIdx sampai lastIdx */
/* Proses : Menyalin isi lIn ke lOut */

/* ********** MENAMBAH ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLast(ListPoint *l, ElType val);
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */

/* ********** MENCARI PASANGAN TITIK TERDEKAT ********** */
/* *** Menggunakan algoritma brute force *** */
void FindClosestPairBF(ListPoint *l, Point *p1, Point *p2, float *min, int *count);
/* *** Menggunakan algoritma divide and conquer *** */
void FindClosestPairDC(ListPoint *l, int size, Point *p1, Point *p2, float *min, int *count);

#endif