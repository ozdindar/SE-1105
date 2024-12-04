#include <stdio.h>


// Write a function that takes 2-dimensional 20x20 integer array
// returns the sum of all elements.
int sumOf2DArray(int arr[][20], int rowCount)
{
    int sum = 0;
    for (int row = 0; row < rowCount; ++row) {
        for (int col = 0; col < 20; ++col) {
            sum +=  arr[row][col];
        }
    }

    return sum;

}








// Write a function that takes 2-dimensional 20x20 integer array
// returns the sum of all elements on the diagonal.
int sumOf2DArrayDiagonal(int arr[][20], int rowCount)
{
    int sum = 0;

    for (int a=0 ; a < 20; ++a) {
        sum +=  arr[a][a];
    }

    return sum;

}







void main_old() {
    int arr[][5]= { {1,2,3,4,5},
                    {6,7,8,9,0} };

    printf("%d", arr[1][2]);


}
