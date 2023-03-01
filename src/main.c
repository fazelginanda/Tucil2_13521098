#include "Point.h"
#include "ListPoint.h"
#include <stdio.h>
#include <time.h>

int main()
{
    int n;
    printf("PROGRAM PENCARIAN PASANGAN TITIK TERDEKAT\n");
    printf("Masukkan banyak titik (n): ");
    do
    {
        scanf("%d", &n);
        if (n < 2)
        {
            printf("Masukan salah. Titik minimal sebanyak 2. Ulangi!\n");
            printf("Masukkan banyak titik (n): ");
        }
    } while (n < 2);

    ListPoint l;
    CreateListPointRandom(&l, n);

    /* MENCARI DENGAN ALGORITMA BRUTE FORCE */
    Point p1BF, p2BF;
    float minBF;
    int countBF;
    clock_t startBF, endBF;
    double timeBF;

    startBF = clock();
    FindClosestPairBF(&l, &p1BF, &p2BF, &minBF, &countBF);
    endBF = clock();
    timeBF = ((double)(endBF - startBF)) / CLOCKS_PER_SEC;

    printf("\n");
    printf("Hasil pencarian pasangan titik terdekat berdasarkan algoritma brute force:\n");
    printf("1. Pasangan titik\n");
    printf("   ");
    printf("Titik pertama: ");
    PrintPoint(p1BF);
    printf("\n");
    printf("   ");
    printf("Titik kedua: ");
    PrintPoint(p2BF);
    printf("\n");
    printf("   ");
    printf("Jarak pasangan titik terdekat: %f\n", minBF);
    printf("2. Banyak perhitungan rumus Euclidean: %d\n", countBF);
    printf("3. Waktu riil: %f\n", timeBF);

    /* MENCARI DENGAN ALGORITMA DIVIDE AND CONQUER */
    Point p1DC, p2DC;
    float minDC;
    int countDC;
    clock_t startDC, endDC;
    float timeDC;

    startDC = clock();
    selectionSortX(&l, 0, n - 1);
    FindClosestPairDC(&l, n, &p1DC, &p2DC, &minDC, &countDC);
    endDC = clock();
    timeDC = ((double)(endDC - startDC)) / CLOCKS_PER_SEC;

    printf("\n");
    printf("Hasil pencarian pasangan titik terdekat berdasarkan algoritma divide and conquer:\n");
    printf("1. Pasangan titik terdekat dan jaraknya\n");
    printf("   ");
    printf("Titik pertama: ");
    PrintPoint(p1DC);
    printf("\n");
    printf("   ");
    printf("Titik kedua: ");
    PrintPoint(p2DC);
    printf("\n");
    printf("   ");
    printf("Jarak pasangan titik terdekat: %f\n", minDC);
    printf("2. Banyak perhitungan rumus Euclidean: %d\n", countDC);
    printf("3. Waktu riil: %f\n", timeDC);
}