# Knights-Tour
The Knight's Tour is a chess puzzle in which the task is to find a sequence of moves for a knight on a chessboard such that the knight visits every square exactly once.
This repository contains the implementation of the Knight's Tour puzzle in C.

Function Description
The KnightTour function takes the following parameters:

* **starting_point:** A point_t type representing the starting position of the knight on the chessboard.
* **knight_path:** An array of point_t type representing the path taken by the knight on the chessboard. This array is used to store the knight's movements and will be updated as the knight makes its moves.
* **use_heuristic:** A flag indicating whether or not to use a heuristic function to guide the knight's movements. If set to 1, the heuristic function will be used; otherwise, the knight will be moved randomly.
The KnightTour function returns an integer indicating the success or failure of the knight's tour. A value of 0 indicates that the knight was unable to complete a tour of the board, while a value of 1 indicates that the knight was able to complete a tour.

# Directory Structure
The relevant files for the Knight's Tour are:

* **bit_array.c:** Source file containing the implementation of the Bit Array data structure used by the Knight's Tour.
* **bit_array.h:** Header file defining the interface and function prototypes for the Bit Array data structure.
* **knight_tour.c:** Source file containing the implementation of the Knight's Tour algorithm.
* **knight_tour.h:** Header file defining the interface and function prototypes for the Knight's Tour algorithm.
* **knight_tour_test.c:** Test file for unit testing the Knight's Tour algorithm.

# Usage
To use the Knight's Tour algorithm, follow these steps:

1. Include the knight_tour.h and bit_array.h header files in your C program.
2. Link the knight_tour.c and bit_array.c source files with your program.
3. Build and compile your program.

For example, to use the Knight's Tour algorithm:
```
#include <stdio.h>
#include "knight_tour.h"

int main() {
    point_t start = {0, 0};            // Starting position of the knight
    point_t knight_path[BOARD_SIZE];   // Array to store knight's movements
    int i;

    KnightTour(start, knight_path, 0); // Execute Knight's Tour algorithm

    /* Print the steps of the knight's tour */
    printf("Step 0: (%d, %d)\n", start.x, start.y);  // Print starting position

    for (i = 0; i < BOARD_SIZE; i++) {
        printf("Step %d: (%d, %d)\n", i + 1, knight_path[i].x, knight_path[i].y);  // Print each step
    }

    return 0;
}
```

# Contributing
Contributions to the Knight's Tour implementation are welcome. If you find any issues or want to improve the existing implementation, feel free to open a pull request.
