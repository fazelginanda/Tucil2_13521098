/* File: Point.c */
/* Implementasi dari Point.h */

#include "Point.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Implementasi konstruktor membentuk Point */
Point MakePoint(float X, float Y, float Z)
{
    /* KAMUS */
    Point p;

    /* ALGORITMA */
    Absis(p) = X;
    Ordinat(p) = Y;
    Aplikat(p) = Z;
    return p;
}

Point MakeRandomPoint()
{
    /* KAMUS */
    Point p;

    /* ALGORITMA */
    Absis(p) = rand() % 10;
    Ordinat(p) = rand() % 10;
    Aplikat(p) = rand() % 10;
    return p;
}

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */
void PrintPoint(Point P)
{
    /*KAMUS*/
    /* ALGORITMA */
    printf("(%.3f,%.3f,%.3f)", Absis(P), Ordinat(P), Aplikat(P));
}

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */
float Distance(Point P1, Point P2)
{
    /*KAMUS*/
    /*ALGORITMA*/
    return (sqrtf(powf(Absis(P2) - Absis(P1), 2) + powf(Ordinat(P2) - Ordinat(P1), 2) + powf(Aplikat(P2) - Aplikat(P1), 2)));
}