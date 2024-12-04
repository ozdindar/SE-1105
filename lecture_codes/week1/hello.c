#include "stdio.h"


int digitSum(int n)
{
    int sum =0;

    for ( int tmp =n; tmp>0; tmp/=10)
    {
        int d = tmp%10;
        if (d>0 && n%d==0)
            sum += d;
    }
    return sum;
}

int abs(int i) {
    if (i<0)
        i = -i;
    return i;
}

int maxDiff(int arr[], int size)
{
    int max =0;
    for (int i =0; i<size-1;i++)
    {
        int delta= abs(arr[i]-arr[i+1]);
        if (delta>max)
            max = delta;
    }
    return max;
}

void main()
{
    int arr[] = {1,4,2,7,30,0,6,-2,3,4};
    printf("%d\n", maxDiff(arr,10));
}