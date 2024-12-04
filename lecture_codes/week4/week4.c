#include <stdio.h>


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
}

// Write a function that takes 5 integers as parameters and returns the minimum
int minOfFive(int k1, int k2, int k3, int k4, int k5 )
{
    return minimumOfThree(k1,k2, minimumOfThree(k3,k4,k5));
}


// Write a function that takes an integer as parameter and prints out if it is even or not
void printIfEven(int n)
{
    if (n%2 == 0) // n is even
        printf("%d is an even number\n", n);
    else printf("%d is an odd number\n", n);
}



// Write a program that reads 3 integers from user and prints out if the minimum is even or not
void function()
{
    int a,b,c;

    printf("Enter 3 integers:\n");
    scanf_s("%d %d %d",&a,&b,&c);
    printf(" %d %d %d\n",a,b,c);

    printIfEven(minimumOfThree(a,b,c));
}

// Write a function that prints a line of length n with “*”s.
void drawLine(int n)
{
    int c;
    for ( c =0 ; c < n ;  c++ ) {
        printf("*");
    }

    printf("\n");
}

// Write a function that prints a square of edge-size n with “*”s
void drawSquare(int m)
{
    for (int a = 0; a < m ; a++) {
        drawLine(m);
    }
}

// TODO: Write a function that prints an empty square of edge-size n with “*”s



// Write a function that prints even integers from 1 to n (inclusive).
void printEvens(int n)
{
    for( int b = 2;  b <=n ; b= b+2)
    {
       printf("%d\n",b);
    }
}

// Write a function that returns the sum of all odd integers from 1 to n
int sumOfOdds(int n)
{
    int sum = 0;
    for (int v = 1; v <= n ; v = v+2) {
        sum = sum+v;
    }
    return sum;
}

// Write a function that takes m and n as input and returns m^n
int power(int m, int n)
{
    int p = 1;
    for (int x = 1; x <= n; x++) {
        p = p*m;
    }

    return p;
}

// Write a function that takes n as input and
// return the closest integer to the squareroot of n (not bigger than)
int squareroot(int n)
{
    int z;
    for( z= 1 ; z*z <= n ; z++ );

    return z-1;
}


void main() {
    printf("Squareroot of %d is %d\n",36, squareroot(36));
}
