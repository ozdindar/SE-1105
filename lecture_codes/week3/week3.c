#include "stdio.h"
#include "stdbool.h"

void func()
{
    printf("func is called!");
}

// Write a function that takes 3 integers as parameters and returns the sum of them.
int sum( int a, int b, int c)
{
    return a+b+c;
}

// Write a function that prints «Hello» to the screen
void printHello()
{
    printf("Hello\n");
}




void main_old() {
    int x;  // 1. Variable definition statement
    x = 3;  // 2. Assignment statement
    func(); // 3. Function call statement
}

// Write a function that prints 3 times “Hello” to the screen
void print3Hello()
{   printHello();
    printHello();
    printHello();
}

void main_old2()
{
    int m = 3 , n = 5, o = 7, p = 4;



    printf("Sum of %d and %d and %d : %d\n", m,n,o, sum(m,n,o));

    printf("%d\n", sum( 2 , 5 , sum (5,10,11)));
}

void main_int_demo()
{
    int x = 300000;
    int y = 400000;

    printf("x:%d  y:%d x*y=%d", x,y,x*y);
}



void main_swap_question()
{
    int x = 1;
    int y = 8;

    printf("x:%d y:%d\n",x,y);

    x = x+y;
    y = x-y;
    x = x-y;

    printf("x:%d y:%d\n",x,y);

}


void main_if()
{
    int x = 4;
    int y = 3;

    int z = x + (7*y-4*(3*x+2));

    if ( z < 0 ) {
        printf("z is negative\n");
        z =  z*-1;
    }
    else
        if (z >0)
            printf("z is positive");
        else
            printf("z is 0");




    if (x<0)
    {
        if (x %2 ==0)
            printf("x is negative even number");
        else printf("x is negative odd number");
    }

}

// Write a function that takes an integer as parameter and returns its absolute value
int  absolute(int a)
{
    if ( a <0 )
        return -1*a;
    else return a;
}

// Write a function that takes 3 integers as parameters and returns the minimum
int minimumOfThree(int k, int d, int b)
{
    // 1st way
    if (  k <d)
    {
        if (k<b)
            return k;
        else return b;
    }
    else
    {
        if (d<b)
            return d;
        else return b;
    }

    // 2nd way
    if ( k <= d && k<=b  )
        return k;
    else if ( b<=k && b<=d)
        return b;
    else return d;
}

// Write a function that takes 5 integers as parameters and returns the minimum
int minOfFive(int k1, int k2, int k3, int k4, int k5 )
{
    return minimumOfThree(k1,k2, minimumOfThree(k3,k4,k5));
}

void main()
{
    printf("The minimum %d", minOfFive(5,4,3,2,1));
}



























