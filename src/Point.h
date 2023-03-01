/* File: Point.h */
/* *** Definisi ABSTRACT DATA TYPE Point *** */

#ifndef POINT_H
#define POINT_H

#include "boolean.h"

typedef struct
{
    float X; /* absis   */
    float Y; /* ordinat */
    float Z; /* aplikat */
} Point;

/* *** Notasi Akses: Selektor Point *** */
#define Absis(P) (P).X
#define Ordinat(P) (P).Y
#define Aplikat(P) (P).Z

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk Point *** */
Point MakePoint(float X, float Y, float Z);
/* Membentuk sebuah Point dari komponen-komponennya */
/* *** Konstruktor membentuk Point dengan komponen yang dibangkitkan secara acak *** */
Point MakeRandomPoint(void);

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */
void PrintPoint(Point P);
/* Nilai P ditulis ke layar dengan format "(X,Y)"
   tanpa spasi, enter, atau karakter lain di depan, belakang,
   atau di antaranya
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */
float Distance(Point P1, Point P2);
/* Menghitung jarak antara dua titik dengan rumus Euclidean */

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean Equal(Point P1, Point P2);
/* Mengirimkan true jika P1 = P2 : absis, ordinat, aplikatnya sama */

/* *** Operasi tambahan *** */
float ABS(float a, float b);
/* Mengembalikan nilai mutlak dari selisih dua bilangan real */

#endif