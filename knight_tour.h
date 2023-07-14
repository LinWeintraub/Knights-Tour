#ifndef __KNIGHT_TOUR__
#define __KNIGHT_TOUR__

#define BOARD_SIZE 64

typedef struct point
{
  int x;
  int y;
} point_t;

/* The KnightTour function takes in the following parameters:
  starting_point: A point_t type representing the starting position
  of the knight on the chess board.
  
  knight_path: An array of point_t type representing the path 
  taken by the knight on the chess board. 
  This array is used to store the knight's movements and will be 
  updated as the knight makes its moves.

  use_heuristic: A flag indicating whether or not to use 
  a heuristic function to guide the knight's movements. 
  If set to 1, the heuristic function will be used; 
  otherwise, the knight will be moved randomly.
  ---------------------------------------------------------------------
  The KnightTour function returns an integer indicating the success 
  or failure of the knight's tour. 
  A value of 0 indicates that the knight was unable to complete 
  a tour of the board, while a value of 1 indicates that the 
  knight was able to complete a tour. */

int KnightTour(point_t starting_point, 
               point_t knight_path[BOARD_SIZE], 
               int use_heuristic);

#endif /* __KNIGHT_TOUR__ */

