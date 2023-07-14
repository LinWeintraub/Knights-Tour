/* ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ *
 ~ Author        Lin Weintraub                                   ~
 * Version       1.0.0                                           *
 ~ Date          04/12/22                                        ~
 * Description   Knight_Tour                                     *
 * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ */
 
#include <assert.h> /*assert*/
#include <math.h> /*sqrt*/
#include <time.h> /*time*/

#include "knight_tour.h"
#include "bit_array.h"

#define SUCCESS 0
#define FAILURE 1
#define TIME_OUT 2

#define VISITED_ALL 0xffffffffffffffff

#define KNIGHT_MOVES sqrt(BOARD_SIZE)
#define TIME_LIMIT 5 * 60

/*---------------------------Function Declarations----------------------------*/
static int KnightTourRecursive(point_t point, 
                              point_t knight_path[BOARD_SIZE],
                              bit_array_t visited, 
                              int use_heuristic, 
                              time_t time,
                              int *status);
static int IsMoveValid(point_t point, bit_array_t visited);
static size_t PointToIndex(point_t point);

/*----------------------------------------------------------------------------*/
const point_t knight_moves[8] = 
{
  {-2, -1},
  {-2, 1},
  {-1, -2},
  {-1, 2},
  {1, -2},
  {1, 2},
  {2, -1},
  {2, 1}
};
/*---------------------------------API-Function------------------------------*/
int KnightTour(point_t starting_point, 
              point_t knight_path[BOARD_SIZE],
              int use_heuristic) 
{
  bit_array_t visited = 0;
  int status = FAILURE;

  time_t curr_time = time(NULL);
  if (-1 == curr_time)
  {
      return FAILURE;
  }

  /* Perform the knight's tour and return the number of moves */
  KnightTourRecursive(starting_point,
                      knight_path, 
                      visited, 
                      use_heuristic, 
                      curr_time,
                      &status);

  return status;
}

/*--------------------------------Static-Functions----------------------------*/
/* Recursive helper function for KnightTour: performs a knight's tour
   starting from the given point, storing the visited points in
   knight_path and returning the number of moves made. If use_heuristic
   is nonzero, the function will use a heuristic to choose the next move
   in order to avoid dead ends. */
static int KnightTourRecursive(point_t point, 
                        point_t knight_path[BOARD_SIZE],
                        bit_array_t visited, 
                        int use_heuristic, 
                        time_t starting_time,
                        int *status) 
{
  point_t next_point = point;
  point_t next_next_point = {0};
  point_t best_next_point = {0};

  int num_moves = KNIGHT_MOVES;
  int min_moves = 0;
  
  int i = 0;
  int j = 0;

  time_t curr_time = time(NULL);
  if (-1 == curr_time)
  {
      *status = FAILURE;
      return FAILURE;
  }

  if (difftime(curr_time, starting_time) > TIME_LIMIT)
  {
    *status = FAILURE;
    return FAILURE;  
  }

  *knight_path = point;
  
  /* Mark the current point as visited */
  visited = SetOnBitArray(visited, PointToIndex(point));

  /* Check if we have visited all squares on the visited */
  if (visited == VISITED_ALL) 
  {
    *status = SUCCESS;
    return SUCCESS;
  }

  /* Try all possible knight moves from the current point */
  for (i = 0; i < KNIGHT_MOVES && SUCCESS != *status; ++i)
  {
    next_point.x = point.x + knight_moves[i].x;
    next_point.y = point.y + knight_moves[i].y;

    if (1 == use_heuristic)
    {
      min_moves = 0;
      
      if (IsMoveValid(next_point , visited))
      {
        /*Count the ways in the next move*/
        for (j = 0; j < KNIGHT_MOVES && SUCCESS != *status; ++j)
        {   
          next_next_point.x = next_point.x + knight_moves[j].x;
          next_next_point.y = next_point.y + knight_moves[j].y;

          if (IsMoveValid(next_next_point, visited))
          {
            ++min_moves;
          }
        }

        if (num_moves > min_moves)
        {
          best_next_point.x = next_point.x;
          best_next_point.y = next_point.y;
          num_moves = min_moves;
        }
      }
    }

    else
    {
      if(IsMoveValid(next_point , visited))
      {
        KnightTourRecursive(next_point, 
                            knight_path + 1, 
                            visited, 
                            use_heuristic, 
                            starting_time,
                            status);
      }
    }
  }

  if (1 == use_heuristic)
  {
    if (IsMoveValid(best_next_point , visited))
    {
      KnightTourRecursive(best_next_point, 
                          knight_path + 1, 
                          visited, 
                          use_heuristic, 
                          starting_time,
                          status);
    }
  }

  /*If none of the moves work, backtrack by marking the current point as unvisited*/
  if (SUCCESS != *status)
  {
    visited = SetOffBitArray(visited, PointToIndex(point));
  }
  
  return SUCCESS;
}
/*----------------------------------------------------------------------------*/
static int IsMoveValid(point_t point, bit_array_t visited)
{
  size_t visited_index = 0;

  visited_index = PointToIndex(point);

  /* Check if the new position is within the bounds of the chessvisited */
  if (point.x < 0 || point.x >= KNIGHT_MOVES ||
      point.y < 0 || point.y >= KNIGHT_MOVES ||
      GetValBitArray(visited, visited_index) == 1) 
  {
    return 0;
  }

  return 1;
}
/*----------------------------------------------------------------------------*/
static size_t PointToIndex(point_t point)
{
  return ((size_t)KNIGHT_MOVES * point.x + point.y);
}
