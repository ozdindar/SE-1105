#include <stdio.h>
#include "stdlib.h"
#include "stdbool.h"
#include "time.h"
#include "geometryCircle.h"


void main_while_dowhile() {
    for (int i = 0; i<10;i++)
    {
        printf("Hello\n");
    }

    int j = 0;

    while (j<10)
    {
        printf("Hello\n");
        j++;
    }

    int x;
    do{
        printf("Enter a positive value of x:\n");
        scanf_s("%d",&x);
    } while (x<=0);
}


// Write a function that returns a random positive number smaller than n
int randBelow(int n)
{
    return rand()%n;
}


// Write a function that returns a random number between m and n
int randomBetween(int n, int m)
{
    int x = randBelow(m-n);

    return n+x;



}

// Write a function that returns true with the given probability p
bool flipCoin(double p)
{
    int x = randomBetween(0,10000);

    if (x<p*10000)
        return true;
    else return false;

}

void main_rand()
{

    srand(time(0));

    for (int i = 0; i < 10; ++i) {
        int x = randomBetween(20000,20002);
        printf("%d\n",x);
    }
}



void main_macro()
{
    double circ= circumferenceOfCircle(3.0);
    printf("Circumference: %f\n", circ );

}

int func2(int a,int b)
{
    printf("%d %d\n",a+4,b-5);
    a = a+b;
    b = b-1;
    return a+b;
}
int func1(int a[], int b)
{
    printf("%d %d %d\n",a[b], b, a[a[0]]);
    b=b+1;
    a[1]= func2(a[b],b);
    printf("%d %d %d\n",a[b], b, a[a[0]]);
    return a[1]+b;
}
int main() {
    int a[]= {1,2,3,4,5};
    a[3]=func1(a,0);
    for(int i=1; i<5;i+=2)
        printf("%d-",a[i]);
    return 0;
}