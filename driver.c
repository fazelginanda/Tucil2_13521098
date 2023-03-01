#include "Point.h"
#include "ListPoint.h"
#include <stdio.h>

int main()
{
    Point p1, p2, p3;
    Point p4, p5;
    Point p6, p7;
    Point p8, p9;
    ListPoint l1, l2, l3;
    float minBF;
    float minDC;
    int countE1;
    int countE2;
    // CreateListPoint(&l1, 10);
    // CreateListPoint(&l2, 10);
    // p1 = MakePoint(3.0, 2.0, 9.0);
    // p2 = MakePoint(4.0, 2.0, 16.0);
    // p3 = MakePoint(5.0, 2.0, 25.0);
    // insertLast(&l1, p1);
    // insertLast(&l1, p2);
    // insertLast(&l2, p3);
    // displayList(l1);
    // printf("\n");
    // displayList(l2);
    // printf("\n");
    // FindClosestPairBF(&l1, &p4, &p5);
    // PrintPoint(p4);
    // printf("\n");
    // PrintPoint(p5);
    // printf("\n");

    CreateListPointRandom(&l3, 10);
    selectionSortX(&l3, 0, NEFF(l3) - 1);
    displayList(l3);
    printf("\n");

    FindClosestPairBF(&l3, &p6, &p7, &minBF, &countE1);
    printf("Pasangan titik terdekat BF:");
    PrintPoint(p6);
    printf("\n");
    PrintPoint(p7);
    printf("\n");
    printf("Min = %f\n", minBF);
    printf("countEuclid1 = %d\n", countE1);

    FindClosestPairDC(&l3, length(l3) - 1, &p8, &p9, &minDC, &countE2);
    printf("Pasangan titik terdekat DC:");
    PrintPoint(p8);
    printf("\n");
    PrintPoint(p9);
    printf("\n");
    printf("Min = %f\n", minDC);
    printf("countEuclid2 = %d\n", countE1);
}