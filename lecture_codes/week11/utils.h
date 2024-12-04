//
// Created by dindar.oz on 12/11/2023.
//

#ifndef __UTILS__
#define __UTILS__

#include "time.h"
#include "stdlib.h"
#include "windows.h"



void randomize()
{
    srand(time(NULL));
}

int randomBelow(int n)
{
    return rand() % n;
}



void waitForSomeTime()
{
    Sleep(1000);
}


void clearScreen()
{
    system("CLS");
}













/*


void printMemory(BotMemory memory)
{
	for (int r = 0; r < MEMORYSIZE; ++r)
	{
		for (int c = 0; c < MEMORYSIZE; ++c)
		{
			if (memory[r][c] >= 0)
				printf("%2d ", memory[r][c]);
			else printf("   ");
		}
		printf("\n");
	}
	waitForSomeTime();
} */


#endif



