//
// Created by dindar.oz on 11/27/2023.
//


#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

void printArray(int arr[], int len)
{
    printf("[ ");
    for (int i = 0; i < len; ++i) {
        printf("%d ",arr[i]);
    }
    printf("]\n");
}

// Write a function that takes an integer (n) and a sufficiently big array
// as parameters. The function fills the array with the digits of n
void digitsOf(int n, int digits[])
{
    ;
    for ( int d = 0; n>0; d++)
    {
        digits[d]= n%10;
        n  = n/10;
    }
}










// Write a function that takes the digits of an integer as array
// and the digit count as parameter. It returns the integer

int power(int m,int n){

}

int fromDigits(int digits[], int digitCount)
{
    int num =0;
    for (int i = digitCount-1; i >= 0; --i) {
        num *=10;
        num  = num + digits[i];
    }
    return num;

}








// Write a function that takes an integer array and returns if it
// contains any duplicate elements
bool hasDuplicates(int arr[], int size)
{
    for (int f1 = 0; f1 < size - 1; ++f1) {
        for (int f2 = f1+1; f2 <size ; ++f2) {
            if (arr[f1] == arr[f2])
                return true;
        }
    }
    return false;
}
















// Write a function that takes an integer (n) as parameter and returns
// if it contains and duplicate digits

bool hasDuplicateDigits(int n)
{
    int arr[10];
    int dc = log10(n)+1;
    digitsOf(n,arr);

    return hasDuplicates(arr,dc);
}










// Write a function that takes two integer array of the same size
// and the size as parameter. It returns the number of elements taking place
// in both arrays and in the same position.
int plusComparison(int arr1[], int arr2[], int len)
{
    int plus=0;
    for (int f1 = 0; f1 < len; ++f1) {
        if (arr1[f1]== arr2[f1])
            plus++;
    }
    return plus;
}










// Write a function that takes two integer array of the same size
// and the size as parameter. It returns the number of elements taking place
// in both arrays but in the different positions.

int minusComparison(int arr1[], int arr2[], int len)
{
    int minus=0;

    for (int f1 = 0; f1 < len; ++f1) {
        for (int f2 = 0; f2 < len; ++f2) {
            if (arr1[f1]== arr2[f2] && f1 != f2)
                minus++;
        }
    }
    return minus;
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


// Write a function that takes an integer (digitcount) as parameter
// and returns a random positive integer that has digitcount digits.

int randomNumber(int digitCount)
{
    int min = pow(10,digitCount-1);
    int max = pow(10,digitCount)-1;

    return randomBetween(min,max);

}












// Write a function that takes an integer(digitcount as parameter
// and returns a random positive integer that has digitcount digits
// and no repeating digits.




