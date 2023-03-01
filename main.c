#include "Point.h"
#include "ListPoint.h"
#include <stdio.h>

int main()
{
    int n;
    printf("PROGRAM PENCARIAN PASANGAN TITIK TERDEKAT\n");
    printf("Masukkan banyak titik (n): ");
    scanf("%d", &n);
    Point p1, p2;
    ListPoint l;

    CreateListPointRandom(&l, n);
    displayList(l);
    printf("\n");

    FindClosestPairBF(&l, &p1, &p2);
    PrintPoint(p1);
    printf("\n");
    PrintPoint(p2);
    printf("\n");
}