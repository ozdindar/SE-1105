#include <stdio.h>
#include <time.h>


// Define a data type that represens the faces of coin

enum CoinFace { Head, Tail};

// Define a data type that represents the days of the week

enum Day { Monday , Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday};




// Write a function that takes a day as parameter and returns the day
// which comes n days after the given day
enum Day daysAfter( enum Day d, int n)
{
    int r = (d+n) %7;

    return r;
}





void main_old() {
    int arr[5];

    digitsOf(107,arr);

    printArray(arr,3);

    int arr2[] = { 5,7,1};

    int n = fromDigits(arr2,3);

    int m = 5711;

    if (hasDuplicateDigits(m))
        printf("Duplicates\n");
    else printf("No Duplicates\n");

    srand(time(0));
    for (int i = 0; i < 10; ++i) {
        printf("%d\n",randomNumber(4));
    }
    printf("n:%d\n",n);

}
