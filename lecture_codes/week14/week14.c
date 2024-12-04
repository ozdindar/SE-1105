#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

// Demo of not giving the area back
void main_not_freed() {
    for (int i = 0 ;true; ++i) {
        int *p1 = (int*)malloc(sizeof(int) );
        p1[0] = 4;
        printf("%d\n",*p1);


    }


}

void main_dynamic_arrrays()
{

    int x;
    scanf_s("%d",&x);

    int arr[5];
    for (int i = 1; i < 10; ++i) {
        int *p = (int*)malloc(i*sizeof(int));



        free(p);
    }

    int *p2 = (int*) malloc(sizeof(int) );

    *p2 = 4;


    int y= 5;

    p2 = &y;

}


// Write a function that takes an integer array which contains
// expected grade you will collect if you attend a final on a certain day
// denoted by the index of the element. The function will return
// maximum total grade assuming that you dont want to attend any two consecutive
// finals

int max(int a, int b)
{
    if (a>=b)
        return a;
    else return b;
}

int maxGrade(int exams[], int len)
{
    if (len ==0)
        return 0;
    if (len == 1)
        return exams[0];
    return max(maxGrade(exams,len-1), exams[len-1]+ maxGrade(exams,len-2));
}


#define DIRECTIONCOUNT 4

typedef enum {Up, Right,Down,Left} Direction;

typedef enum {CCW=-1, CW=1} TurnDirection;

Direction func( Direction initial, TurnDirection arr[], int len)
{
    int turnAmount=0;
    for (int i = 0; i < len; ++i) {
        turnAmount += DIRECTIONCOUNT+arr[i];
    }

    return (initial + turnAmount)%DIRECTIONCOUNT;
}


typedef int Map[10][10];

int circumferenceOfCell(Map map, int r, int c)
{
    int crc =0;

    if ( r==0 || map[r-1][c]==0) // Up
        crc++;
    if ( r==9 || map[r+1][c]==0) // Down
        crc++;
    if ( c==0 || map[r][c-1]==0) // Left
        crc++;
    if ( c==9 || map[r][c+1]==0) // Right
        crc++;

    return crc;
}

int circumference(Map map)
{
    int crc=0;
    for (int r = 0; r < 10; ++r) {
        for (int c = 0; c < 10; ++c) {
            if (map[r][c]==1)
                crc += circumferenceOfCell(map,r,c);
        }
    }
    return 0;
}

int rowSum(int arr[], int len)
{
    int sum =0;

    for (int i = 0; i < len; ++i) {
        sum += arr[i];
    }

    return sum;
}

int columnSum(int arr[][20], int c)
{
    int sum =0;

    for (int i = 0; i < 20; ++i) {
        sum += arr[i][c];
    }

    return sum;
}

int maxRow(int arr[][20])
{
    int max = rowSum(arr[0],20);
    int maxIndex =0;

    for (int i = 1; i < 20; ++i) {
        int sum = rowSum(arr[i],20);
        if (sum>max)
        {
            max = sum;
            maxIndex = i;
        }
    }
    return maxIndex;
}


void main()
{
    int exams[] = { 1,0,3,9,2,1,5,1,3,2,  1,0,3,9,2,1,5,1,3,2, 1,0,3,9,2,1,5,1,3,2, 1,0,3,9,2,1,5,1,3,2, 1,0,3,9,2,1,5,1,3,2, 1,0,3,9,2,1,5,1,3,2};

    printf("Max Grade: %d\n", maxGrade(exams,60));
}










