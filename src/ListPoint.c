/* File: ListPoint.c*/
/* Deskripsi: Implementasi ListPoint.h */

#include <stdio.h>
#include "ListPoint.h"

/* Kamus Global */
Point VAL_UNDEF = {.X = -9999,
                   .Y = -9999,
                   .Z = -9999};

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListPoint(ListPoint *l)
{
    /* KAMUS LOKAL */
    int i;
    /* ALGORITMA */
    for (i = 0; i <= CAPACITY - 1; i++)
    {
        ELMT(*l, i) = VAL_UNDEF;
    }
}
/* Konstruktor : create list random  */
void CreateListPointRandom(ListPoint *l, int size)
{
    /* KAMUS LOKAL */
    int i;
    Point p;
    /* ALGORITMA */
    for (i = 0; i < size; i++)
    {
        p = MakeRandomPoint();
        ELMT(*l, i) = p;
    }
    for (i = size; i <= CAPACITY - 1; i++)
    {
        ELMT(*l, i) = VAL_UNDEF;
    }
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int length(ListPoint l)
{
    /* KAMUS LOKAL */
    int i;
    /* ALGORITMA */
    i = 0;
    while ((!Equal(ELMT(l, i), VAL_UNDEF)) && i < CAPACITY)
    {
        i += 1;
    }
    return i;
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmpty(ListPoint l)
{
    /* KAMUS LOKAL */
    /* ALGORITMA */
    return (length(l) == 0);
}
/* *** Test List penuh *** */
boolean isFull(ListPoint l)
{
    /* KAMUS LOKAL */
    /* ALGORITMA */
    return (length(l) == 1000);
}

/* ********** SORTING ********** */
void selectionSortX(ListPoint *l, int i, int j)
{
    /* KAMUS LOKAL */
    int k;
    /* ALGORITMA */
    if (i < j)
    {
        partisiX(l, i, j);
        selectionSortX(l, i + 1, j);
    }
}
void partisiX(ListPoint *l, int i, int j)
{
    /* KAMUS LOKAL */
    int k, idxmin;
    Point temp;
    /* ALGORITMA */
    idxmin = i;
    for (k = i + 1; k <= j; k++)
    {
        if (Absis(ELMT(*l, k)) < Absis(ELMT(*l, idxmin)))
        {
            idxmin = k;
        }
    }
    temp = ELMT(*l, i);
    ELMT(*l, i) = ELMT(*l, idxmin);
    ELMT(*l, idxmin) = temp;
}
void selectionSortY(ListPoint *l, int i, int j)
{
    /* KAMUS LOKAL */
    int k;
    /* ALGORITMA */
    if (i < j)
    {
        partisiY(l, i, j);
        selectionSortY(l, i + 1, j);
    }
}
void partisiY(ListPoint *l, int i, int j)
{
    /* KAMUS LOKAL */
    int k, idxmin;
    Point temp;
    /* ALGORITMA */
    idxmin = i;
    for (k = i + 1; k <= j; k++)
    {
        if (Ordinat(ELMT(*l, k)) < Ordinat(ELMT(*l, idxmin)))
        {
            idxmin = k;
        }
    }
    temp = ELMT(*l, i);
    ELMT(*l, i) = ELMT(*l, idxmin);
    ELMT(*l, idxmin) = temp;
}

/* ********** OPERASI LAIN ********** */
void copyList(ListPoint lIn, int firstIdxCopy, int lastIdxCopy, ListPoint *lOut)
{
    /* KAMUS LOKAL */
    int i, size, offset;
    /* ALGORITMA */
    size = lastIdxCopy - firstIdxCopy + 1;
    for (i = 0; i < size; i++)
    {
        offset = i + firstIdxCopy;
        ELMT(*lOut, i) = ELMT(lIn, offset);
    }
}

/* ********** MENAMBAH ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLast(ListPoint *l, ElType val)
{
    /* KAMUS LOKAL */
    /* ALGORITMA */
    ELMT(*l, length(*l)) = val;
}

/* ********** MENCARI PASANGAN TITIK TERDEKAT ********** */
/* *** Menggunakan algoritma brute force *** */
void FindClosestPairBF(ListPoint *l, Point *p1, Point *p2, float *min, int *count)
{
    /* KAMUS LOKAL */
    float d;
    /* ALGORITMA */
    *min = 999999999;
    *p1 = ELMT(*l, 0);
    *p2 = ELMT(*l, 1);
    for (int i = 0; i < length(*l); i++)
    {
        for (int j = i + 1; j < length(*l); j++)
        {
            d = Distance(ELMT(*l, i), ELMT(*l, j));
            *count = *count + 1;
            if (d < *min)
            {
                *min = d;
                *p1 = ELMT(*l, i);
                *p2 = ELMT(*l, j);
            }
        }
    }
}

/* *** Menggunakan algoritma divide and conquer *** */
void FindClosestPairDC(ListPoint *l, int size, Point *p1, Point *p2, float *min, int *count)
{
    /* KAMUS LOKAL */
    float minLeft, minRight;
    ListPoint S1, S2, Sstrip;
    int size1, size2, sizeStrip;
    int Xmid;
    int i, j;
    Point left1, left2, right1, right2;
    int countLeft, countRight;
    float distance01, distance02, distance12;
    float dStrip;
    /* ALGORITMA */
    /* Basis 1: Banyak elemen genap */
    if (size == 2)
    {
        *min = Distance(ELMT(*l, 0), ELMT(*l, 1));
        *p1 = ELMT(*l, 0);
        *p2 = ELMT(*l, 1);
        *count = *count + 1;
    }
    /* Basis 2: Banyak elemen ganjil */
    else if (size == 3)
    {
        /* Hitung jarak setiap pasangan titik */
        distance01 = Distance(ELMT(*l, 0), ELMT(*l, 1));
        *count = *count + 1;
        distance02 = Distance(ELMT(*l, 0), ELMT(*l, 2));
        *count = *count + 1;
        distance12 = Distance(ELMT(*l, 1), ELMT(*l, 2));
        *count = *count + 1;

        /* Mencari pasangan titik terdekat */
        if (distance01 < distance02)
        {
            if (distance01 < distance12) // 01 < 02 && 01 < 12
            {
                *min = distance01;
                *p1 = ELMT(*l, 0);
                *p2 = ELMT(*l, 1);
            }
            else // 12 < 01 < 02
            {
                *min = distance12;
                *p1 = ELMT(*l, 1);
                *p2 = ELMT(*l, 2);
            }
        }
        else
        {
            if (distance02 < distance12) // 02 < 01 && 02 < 12
            {
                *min = distance02;
                *p1 = ELMT(*l, 0);
                *p2 = ELMT(*l, 2);
            }
            else // 12 < 02 < 01
            {
                *min = distance12;
                *p1 = ELMT(*l, 1);
                *p2 = ELMT(*l, 2);
            }
        }
    }
    else
    {
        /* Hitung banyak elemen S1 dan S2 */
        size1 = size / 2;
        size2 = size - size1;
        /* Inisialisasi S1 */
        CreateListPoint(&S1);
        copyList(*l, 0, size1 - 1, &S1);
        /* Inisialisasi S2 */
        CreateListPoint(&S2);
        copyList(*l, size1, size - 1, &S2);
        /* Mencari sepasang titik terdekat di S1 dan S2 */
        FindClosestPairDC(&S1, size1, &left1, &left2, &minLeft, &countLeft);
        FindClosestPairDC(&S2, size2, &right1, &right2, &minRight, &countRight);
        /* Menentukan pasangan titik terdekat dari S1 dan S2*/
        if (minLeft < minRight)
        {
            *min = minLeft;
            *p1 = left1;
            *p2 = left2;
        }
        else
        {
            *min = minRight;
            *p1 = right1;
            *p2 = right2;
        }
        *count = countLeft + countRight;

        /* ***Mencari pasangan titik terdekat di Sstrip*** */
        CreateListPoint(&Sstrip);
        /* Mencari absis garis L: Xn/2 */
        Xmid = size / 2;
        /* Mencari semua titik di S1 yang berada di dalam strip */
        for (i = 0; i < length(S1); i++)
        {
            if ((Xmid - Absis(ELMT(S1, i))) <= *min)
            {
                insertLast(&Sstrip, ELMT(S1, i));
            }
        }
        /* Mencari semua titik di S2 yang berada di dalam strip */
        for (i = 0; i < length(S2); i++)
        {
            if ((Absis(ELMT(S2, i)) - Xmid) <= *min)
            {
                insertLast(&Sstrip, ELMT(S2, i));
            }
        }
        /* Mengurutkan titik di Sstrip berdasarkan ordinat menaik */
        selectionSortY(&Sstrip, 0, length(Sstrip) - 1);
        /* Menghitung jarak setiap pasangan titik di Sstrip */
        /* Dibandingkan dengan jarak terdekat sebelumnya  */
        for (i = 0; i < length(Sstrip) - 1; i++)
        {
            for (j = i + 1; j < length(Sstrip) - 1; j++)
            {
                if ((ABS(Absis(ELMT(Sstrip, i)), Absis(ELMT(Sstrip, j))) > *min) || (ABS(Ordinat(ELMT(Sstrip, i)), Ordinat(ELMT(Sstrip, j))) > *min))
                {
                    /* Tidak diproses */
                }
                else
                {
                    dStrip = Distance(ELMT(Sstrip, i), ELMT(Sstrip, j));
                    *count = *count + 1;
                    if (dStrip < *min)
                    {
                        *min = dStrip;
                    }
                }
            }
        }
    }
}