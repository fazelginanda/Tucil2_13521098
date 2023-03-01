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

Point MakeRandomPoint(void)
{
    /* KAMUS */
    Point p;

    /* ALGORITMA */
    Absis(p) = rand();
    Ordinat(p) = rand();
    Aplikat(p) = rand();
    return p;
}

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */
float Distance(Point P1, Point P2)
{
    /*KAMUS*/
    /*ALGORITMA*/
    return (sqrtf(powf(Absis(P2) - Absis(P1), 2) + powf(Ordinat(P2) - Ordinat(P1), 2) + powf(Aplikat(P2) - Aplikat(P1), 2)));
}

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean Equal(Point P1, Point P2)
{
    /*KAMUS*/
    /* ALGORITMA */
    return ((Absis(P1) == Absis(P2)) && (Ordinat(P1) == Ordinat(P2)) && (Aplikat(P1) == Aplikat(P2)));
}

/* Operasi tambahan */
float ABS(float a, float b)
{
    if (a > b)
    {
        return a - b;
    }
    else
    {
        return b - a;
    }
}