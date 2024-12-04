#include <stdio.h>
#include <stdbool.h>

/**
 * Write a function that takes a string
 * and prints it on the screen
 */
void printCharArray( char arr[])
{
    for (int i = 0; arr[i] != 0 ; ++i) {
        printf("%c",arr[i]);
    }
}


/**
 * Write a function that returns the length of a string
 */
 int strLength(char str[])
{
    int i = 0;
    for (;str[i]!=NULL  ; ++i) ;
    return i;
}

/**
 * Write a function that capitalizes a string
 */
void capitalize(char str[])
{
    int delta = 'a'-'A';
    for (int i = 0; str[i] != NULL; ++i) {
        if ( str[i]>='a' && str[i]<= 'z')
        {
            str[i] -= delta;
        }
    }
}

/**
 * Write a function that takes a string (str) and
 * two characters namely c1 and c2 as parameters.
 * The function must replace every occurrence of c1 in str with c2.
 */
void replaceAll(char str[] , char c1, char c2)
{
    for (int i = 0; str[i]==0; ++i) {
        if (str[i]== c1)
            str[i]= c2;
    }
}

// Write a function that returns if two strings are equal.
bool isEqual(char str1[], char str2[] )
{
    int i=0;
    for (; str1[i]!= 0; ++i) {
        if (str1[i]!= str2[i])
            return false;
    }
    return str2[i]==0;
}

// Write a function that returns if the given string (sentence)
//  is a pangram.
bool isPangram(char str[])
{
    int counts[26] ={0};

    for (int i = 0; str[i]!=0; ++i) {
        if ( str[i]>='a' && str[i]<= 'z' )
        {
            counts[ str[i]-'a']++;
        }
    }
    for (int i = 0; i < 26; ++i) {
        if(counts[i]==0)
            return false;
    }
    return true;
}


void main() {
    char c = '-';

    char arr[] = { 'H', 'e', 'l', 'l', 'o',0};

    char str[] = "Hello World!\n";

    printf("%s",str);
    capitalize(str);
    printf("%s",str);





}
