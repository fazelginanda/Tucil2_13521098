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

    CreateListPointRandom(&l3, 1000);
    displayList(l3);
    printf("\n");
    selectionSortX(&l3, 0, length(l3) - 1);
    displayList(l3);
    printf("\n");
    // CreateListPoint(&l1);
    // copyList(l3, 2, 4, &l1);
    // displayList(l1);
    // printf("\n");

    // Point VAL_UNDEF = {.X = -9999,
    //                    .Y = -9999,
    //                    .Z = -9999};
    // PrintPoint(VAL_UNDEF);

    // p1 = MakePoint(1, 2, 3);
    // p2 = MakePoint(1, 2, 3);
    // if (Equal(p1, p2))
    // {
    //     printf("p1 dan p2 sama\n");
    // }

    countE1 = 0;
    FindClosestPairBF(&l3, &p6, &p7, &minBF, &countE1);
    printf("Pasangan titik terdekat BF:");
    PrintPoint(p6);
    printf("\n");
    PrintPoint(p7);
    printf("\n");
    printf("Min = %f\n", minBF);
    printf("countEuclid1 = %d\n", countE1);

    countE2 = 0;
    int n = length(l3);
    FindClosestPairDC(&l3, n, &p8, &p9, &minDC, &countE2);
    printf("Pasangan titik terdekat DC:");
    PrintPoint(p8);
    printf("\n");
    PrintPoint(p9);
    printf("\n");
    printf("Min = %f\n", minDC);
    printf("countEuclid2 = %d\n", countE2);
    // dealocate(&l3);

    // printf("%f\n", ABS(2, 5));
    // printf("%f\n", ABS(5, 2));

    // CreateListPointRandom(&l1, 6);
    // displayList(l1);
    // printf("\n");
    // copyList(l1, 2, 4, &l2);
    // displayList(l2);
    // printf("\n");
    // int size = 10;
    // int size1 = size / 2;
    // CreateListPointRandom(&l1, size);
    // CreateListPoint(&l2, size1);
    // copyList(l1, 0, size1 - 1, &l2);
    // displayList(l2);
    // dealocate(&l1);
    // dealocate(&l2);
}