#include "stdio.h"
#include "stdbool.h"
#include "utils.h"
#include "stdlib.h"


// Necessary Data types and constant definitions for Maze
#define  WALL "\xDB\xDB"   // Full-cursor character
#define  EMPTY "  "
#define  EXIT  "\xDA\xBF"  // Special box-like character
#define  ROBOT "* "





// Define a datatype to represent a cell of a maze MazeCell

enum MazeCell { Empty, Wall, Exit, Outside};
typedef enum MazeCell MazeCell;













// Define a datatype to represent a Maze
#define MAZESIZE 10
#define DIRECTIONCOUNT 4
typedef MazeCell Maze[MAZESIZE][MAZESIZE];











































// Define a data type to represent Direction
enum Direction { Up, Right, Down, Left};
typedef enum Direction Direction;




















// write a function that returns the opposite of  given Direction without if-s (oppositeOf)
Direction oppositeOf( Direction  d)
{
    return (d+2) % DIRECTIONCOUNT;
}
















// Define a data type to represent a Position in a maze
typedef int Position[2];
#define ROW 0
#define COL 1

















// Define a (arbitrary) global Maze variableas follows

  Maze maze =     {	{1,1,1,1,1,1,1,1,1,1},
					{1,0,1,1,0,0,0,0,0,1},
					{1,0,1,1,1,0,1,1,0,1},
					{1,0,1,1,1,1,1,1,0,1},
					{1,0,0,0,0,0,0,0,0,1},
					{1,0,1,1,1,1,0,1,1,1},
					{1,0,1,1,1,1,0,1,1,1},
					{1,0,0,0,0,0,0,1,1,1},
					{1,1,1,0,1,1,0,0,2,1},
					{1,1,1,1,1,1,1,1,1,1} };


















// Define an arbitrary global variable for the position of the robot
Position robot = { 1,1};



















// Write a function that prints a given maze (printMaze) with a given robot at a given position

void printMazeCell(Maze maze, int row, int col, Position robot) {
    MazeCell cell = maze[row][col];

    if (robot[ROW]== row && robot[COL]== col)
    {
        printf(ROBOT);
        return;
    }
    switch ( cell)
    {
        case Wall: printf(WALL);break;
        case Empty: printf(EMPTY);break;
        case Exit: printf(EXIT);break;
    }
}

void printRow(Maze maze, Position robot, int row) {
    for (int col = 0; col < MAZESIZE; ++col) {
        printMazeCell(maze,row,col,robot);
    }
    printf("\n");
}

void printMaze(Maze maze, Position robot)
{
    clearScreen();
    for (int row = 0; row < MAZESIZE; ++row)
    {
        printRow(maze,robot,row);
    }

}























































// Write a function that returns if a given  position is inside the maze or not (isInside)
bool isInside(Position p)
{
    return p[ROW] >= 0 && p[ROW]< MAZESIZE && p[COL] >= 0 && p[COL]< MAZESIZE;
}


















// Write a function that returns the cell at a given Position in a given Maze (getCell)
MazeCell getCell(Maze maze, Position p)
{
    if (isInside(p))
        return maze[p[ROW]][p[COL]];
    else return Outside;
}
















// Write a function that returns if a given  position is exit (isExit)
bool isExit(Maze maze, Position p)
{
    return getCell(maze,p)==Exit;
}

















































// Write a function that copies a position into another position(copyPosition)
void copyPosition(Position source, Position target)
{
    target[ROW]= source[ROW];
    target[COL]= source[COL];
}


















// Write a function that moves a given position towards a given direction (movePosition)
void movePositionPoor(Position p, Direction d)
{
    switch (d) {
        case Up: {
            p[ROW]--;break;
        }
        case Down: {
            p[ROW]++; break;
        }
        case Left: {
            p[COL]--;break;
        }
        case Right: {
            p[COL]++; break;
        }
    }
}























// Rewrite movePosition function without using if-s or switch
int deltaPositions[][2] = { /*UP*/    {-1, 0},
                            /*DOWN*/  { 1, 0},
                            /*LEFT*/  { 0,-1},
                            /*RIGHT*/ { 0, 1}  };

void movePosition(Position p, Direction d)
{
    p[ROW] += deltaPositions[d][ROW];
    p[COL] += deltaPositions[d][COL];
}

























// Write a function that returns the neighbor cell of the cell at a given position
// in a given Maze towards a given direction (neighborOf)
MazeCell neighborOf(Maze maze, Position p, Direction d)
{
    Position p2;
    copyPosition(p,p2);
    movePosition(p2,d);
    return getCell(maze,p2);
}





























// Write a function that returns if It is possible to move at a given Position
// towards a given direction in a given maze (canMove)
bool canMove(Maze maze, Position p, Direction d)
{
    MazeCell  neighbor = neighborOf(maze,p,d);
    return neighbor == Exit || neighbor == Empty;
}























// Write a function that moves a given position towards a given direction if it is
// possible in a given maze.
// Returns true if moved,false otherwise (tryMove)
bool tryMove(Maze maze, Position robot, Direction d)
{
    if (canMove(maze, robot,d))
    {
        movePosition(robot,d);
        return true;
    }
    return false;
}

































// Write a function that randomly moves a robot at a given position in a given maze
// The function should print the maze at each step and stop when the robot moves to exit
void moveRandomly(Maze maze, Position robot)
{
    while (!isExit(maze,robot))
    {
        waitForSomeTime();
        Direction d = randomBelow(DIRECTIONCOUNT);
        if (tryMove(maze,robot,d))
        {
            clearScreen();
            printMaze(maze,robot);
        }
    }
}


















// Write a function that randomly moves a robot at a given position in a given maze
// The function should print the maze at each step and stop when the robot moves to exit
// When the robot choose a random direction he should go in that direction until it hits
// the wall (moveRandomlyButDetermined)
void moveRandomlyDetermined(Maze maze, Position robot)
{
    while (!isExit(maze,robot))
    {

        Direction d = randomBelow(DIRECTIONCOUNT);
        while (tryMove(maze,robot,d))
        {
            waitForSomeTime();
            clearScreen();
            printMaze(maze,robot);
        }
    }
}

























// Write a function that moves the robot to one of the exits in a given maze
#define MEMORYSIZE 2*MAZESIZE+1
#define NONVISITED -1
#define START 1
typedef int Memory[MEMORYSIZE][MEMORYSIZE];


bool isInsideMemory(Position p) {
    return p[ROW]>=0 && p[ROW]<MEMORYSIZE && p[COL]>=0 && p[COL]<MEMORYSIZE ;
}

int getCellFromMemory(Memory memory, Position p)
{
    if (isInsideMemory(p))
        return memory[p[ROW]][p[COL]];
    else return -1;
}


int neighborOfMemory(Memory maze, Position p, Direction d)
{
    Position p2;
    copyPosition(p,p2);
    movePosition(p2,d);
    return getCellFromMemory(maze,p2);
}

void markMemory(Memory memory, Position p, int mark)
{
    memory[p[ROW]][p[COL]] = mark;
}

void clearMemory(Memory memory)
{
    for (int r = 0; r < MEMORYSIZE; ++r) {
        for (int c = 0; c < MEMORYSIZE; ++c) {
            memory[r][c]= NONVISITED;
        }
    }
}


bool discoverNewPlace(Maze maze, Position robot, Memory memory, Position finger) {
    int step = getCellFromMemory(memory,finger);

    for (int d = 0; d < DIRECTIONCOUNT; ++d) {
        if (neighborOfMemory(memory,finger,d)== NONVISITED && tryMove(maze,robot,d))
        {
            movePosition(finger,d);
            markMemory(memory,finger,step+1);
            return true;
        }
    }

    return false;
}

bool moveBack(Maze maze, Position robot, Memory memory, Position finger) {
    int step = getCellFromMemory(memory,finger);

    for (int d = 0; d < DIRECTIONCOUNT; ++d) {
        if (neighborOfMemory(memory,finger,d)== step-1)
        {
            movePosition(robot,d);
            movePosition(finger,d);
            return true;
        }
    }
    return false;
}

void printMemory(Memory memory) {

    printf("\n\n");
    for (int r = 0; r < MEMORYSIZE; ++r) {
        for (int c = 0; c < MEMORYSIZE; ++c) {
            if (memory[r][c]==NONVISITED)
                printf("  ");
            else printf("%d ",memory[r][c]);
        }
        printf("\n");
    }

}

void findExit(Maze maze, Position robot)
{
    Memory memory;
    clearMemory(memory);
    Position finger= {MAZESIZE,MAZESIZE};
    markMemory(memory,finger,START);

    while (!isExit(maze,robot))
    {
        if (discoverNewPlace(maze, robot,memory,finger))
        {
            printMaze(maze,robot);
            printMemory(memory);
            waitForSomeTime();
        }
        else if (moveBack(maze,robot,memory,finger))
        {
            printMaze(maze,robot);
        }
        else {
            printf("NO WAY!");
            printMemory(memory);
            waitForSomeTime();
        }
    }


}




void main()
{
    findExit(maze,robot);
}






