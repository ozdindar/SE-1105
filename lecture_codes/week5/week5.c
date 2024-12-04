#include <stdio.h>

int f2(int x, int y ) {
    int a;
    printf("f2 is called\n");
    return x+y;
}

void f(int x, int y)
{
    int a;
    a = f2(1,3);
    printf("f is called\n");
    a = f2(3,5);
}


void swap(int x ,int y)
{
    int z = x;
    x = y;
    y = z;
}

int increment(int a)
{
    return (++a);
}

void main_swap() {
    int x = 3;
    int y = 7;
    int z = x;
    x = y;
    y = z;

    printf("x: %d  y:%d\n",x,y);

    swap(x,y);

    printf("x: %d  y:%d\n",x,y);

    int a = 4;
    printf("a:%d\n", a);
    a = increment(a);
    printf("a:%d\n", a);

}



void main_double()
{
    double d = 3.5;

    int x = 3;

    d = x;

    d = 2.99;

    x = d;

    double  d1 = d +x;

    printf("%f\n",(double)x);
}

// Write a function that returns the average of two double numbers
double avg(double r2, double d2)
{
    double  a = (r2 + d2)/2;
    return a;
}




void main_arr_intro()
{
    int b[10];

    b[1]= 3;

    printf("%d \n", b[0]);
    printf("%d \n", b[1]);
    printf("%d \n", b[2]);

    for (int f = 0; f < 10; ++f) {
        printf("%d\n",b[f]);
    }

    int arr[5];
    arr[0]= 1;
    arr[1]= 2;
    arr[2]= 3;
    arr[3]= 4;
    arr[4]= 5;


    int arr2[] = { 1,2,3,4,5,6,7,8,9};

}

// Write a function that returns the average of elements in an array
double averageOf( int arr[], int len)
{
    int sum =0;

    for (int f = 0; f < len; ++f) {
        sum = sum+ arr[f];
    }

    return (double )sum/len;
}

// Write a function that returns the maximum element of an array
int maxOf(int arr[], int size)
{
    int max = arr[0];
    for (int i = 1; i < size ; ++i) {
        if (max<arr[i])
            max = arr[i];
    }

    return max;
}

// Write a function that returns the index of the maximum element of an array
int maxIndexOf(int arr[], int size)
{
    int maxIndex = 0;
    int i=1;
    for (; i < size ; ++i) {
        if ( arr[maxIndex]<arr[i])
            maxIndex = i;
    }

    return maxIndex;
}

void main()
{
    int a[] = {1,5,9,0,1,3,8,12,-3, 2};


    int max = maxOf(a,10);
    printf("Maximum:%d\n",max);
}