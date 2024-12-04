#include <stdio.h>

#define X 0
#define Y 1

enum CoinFace { Head, Tail};
typedef  enum CoinFace CoinFace;

typedef double Point2D[2];

CoinFace flip(  CoinFace current, int count)
{
    return (current + count) %2;
}

void main() {


    Point2D  p1 = { 1.35, 5.232};
    printf("p.x = %lf  p.y = %lf ", p1[X],p1[Y] );


    char s = 'a';

    s = 'b';

    printf("%c\n", s);

    int arr[4];
    double dArr[3];

    char cArr[] = { 'd', '?'};

    int x = s;
}
