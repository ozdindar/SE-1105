#include <stdio.h>
#include <stdbool.h>

int main_pointer_intro() {
    int a = 10;
    char c= 'k';

    a++;

    int *pa = &a;
    char *pc = &c;


    printf(" a: %d\n",a);
    printf(" pa: %p\n", pa);
    printf(" &a: %p\n", &a);
    printf(" c: %c\n", c);
    printf(" pc: %p\n", pc);
    printf(" &c: %p\n", &c);

    printf(" value at address pa: %d", *pa);


    int *pb;
    printf("%p\n",pb);


}

void main_dereferenceing()
{
    int x = 1027;

    int *px = &x;
    char *pcx = &x;

    printf("x:%d\n", *px);
    printf("x:%c\n", *pcx);
    printf("x:%d\n", *pcx);

    printf("px:%p\n", px);
    printf("pcx:%p\n", pcx);

    px = px+1;
    pcx= pcx+1;

    printf("px:%p\n", px);
    printf("pcx:%p\n", pcx);


}

void main_pointer_arithmetic()
{
    int a = 14;
    int *pa = &a;

    a+=2;
    int *pb = pa;

    printf("%d\n",*pa);
    printf("%d\n",*pb);

    *pb = *pb+1;
    *pa = 5;

    printf("%d\n",*pb);

    int b = 1047;
    char * pcb = &b;
    int *pb2 = &b;

    printf("%d\n", *pb2);
    printf("%d\n", *pcb);
    printf("%d\n", *(pcb+1));
    printf("%d\n", *(pcb+2));
    printf("%d\n", *(pcb+3));








}

void main_generic()
{
    int a = 4;
    void *p = &a;
    // WRONG *p = 3;
    // WRONG p = p+1;
}

void main_pointers_pointers()
{
    int a= 5;
    int *pa = &a;

    int* *ppa = &pa;
    int**     *pppa = &ppa;

    ***pppa = 4;

    printf("%p\n", pa);
    printf("%p\n", ppa);
    printf("%p\n", pppa);
    printf("(*pppa):%p\n", (*pppa));
    printf("&(*pppa):%p\n", &(*pppa));
    printf("*(&(*pppa)):%p\n", *(&(*pppa)));
}


void swap(int *pa, int *pb)
{
    int c = *pa;
    *pa = *pb;
    *pb = c;
}
void main_swap()
{
    int a = 4;
    int b = 7;

    printf("a:%d\n",a);
    printf("b:%d\n",b);

    swap(&a,&b);

    printf("a:%d\n",a);
    printf("b:%d\n",b);
}

int func(int arr[],int size)
{

}

void  main_arr()
{
    int arr[] = {1,2,3,4,5};

    int *p = arr;
    printf("%d\n",*p);
    printf("%d\n",*(p+1));
    printf("%d\n",*(p+2));

    p++;
    p[0] = 3;

    arr[2]= 4;

}

void printArray(int *arr, int len)
{

    for (int i = 0; i < len; ++i) {
        printf("%d\n",arr[i]);
    }
}

void main_arr2()
{
    int arr[] = { 1,2,3,4,5,6,7,8};
    int len = sizeof(arr)/ sizeof(int);
    printArray(arr,len);

    printf("%d", *(arr+2));
    printf("%d", arr[2]);

}

// Write strlen function with pointers
int strlen(char *str)
{
    int i=0;
    for (; *str != 0; str++, ++i);
    return i;

}

// Write a function that returns if a given string is palindrome
bool isPalindrome(char *str)
{
    int len = strlen(str);

    char * last =   &str[len-1]; //str+len-1;
 
    for (;  str<last; str++, last--) {
        if ( *str != *last)
            return false;
    }
    return true;
}



void main()
{
    char arr[] = "Hello";

    char* ptr = arr;

    printf("%c\n", *arr);
    printf("%c\n", *ptr);

}
