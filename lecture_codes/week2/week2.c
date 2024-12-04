#include "stdbool.h"
#include "stdio.h"


void func2()
{
    printf("Function 2 is called!\n");
}
void func1()
{
    printf("Function 1 is called!\n");
    func2();
}

void demoVariables()
{
    int x;
    int y;
    int armut;
    int a,b,c,d,e;
}

void main()
{
    // Examples of variable definition
    int x;
    int y;
    int armut;
    int a=1,b= 2,c= 6,d= -2,e= 5;

    // Examples of assignment
    armut= 5;
    x = armut;
    armut = 6;
    x =3;
    x = armut;

    int t = x;

    a = x = armut=2;


    x = 3 + 5;

    x = x + 6;
    y = 0;

    x = (x + (y - (t * 4) +5 * x /4) );


    printf("Hello x:%d World \n Apple",x);

    printf(" Bir Sayı: %d", x+y*7);

    bool g = false;

    g = true;

    g = g && true;

    g = g || (!true);

    g = (x + 5) == 2;
    g = 4 >= 7;

}
