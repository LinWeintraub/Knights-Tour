/* ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ *
 ~ Author        Lin Weintraub                                   ~
 * Version       1.0.0                                           *
 ~ Date          04/12/22                                        ~
 * Description   Knight_Tour                                     *
 * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ */
 
#include <stdio.h>
#include <assert.h>

#include "knight_tour.h"

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define CYAN "\033[1;36m"
#define WHITE "\033[0m"

#define TEST(name, actual, expected) \
    printf("%s: %s\n" , name, actual == expected ? GREEN"PASS"WHITE : RED"FAIL"WHITE)
#define TESTNOT(name, actual, expected) \
    printf("%s: %s\n" , name, actual != expected ? GREEN"PASS"WHITE : RED"FAIL"WHITE)

void TestKnightTourSteps(void);

int main(void)
{
  TestKnightTourSteps();

	return 0;
}

void TestKnightTourSteps(void)
{
  /* Test the knight's tour starting from (0, 0) */
  point_t start = {0, 0};
  point_t knight_path[BOARD_SIZE];
  int i = 0;
  KnightTour(start, knight_path, 0);

  /* Print the steps of the knight's tour */
  printf("Step 0: (%d, %d)\n", start.x, start.y);
  for (i = 0; i < BOARD_SIZE; i++) 
  {
    printf("Step %d: (%d, %d)\n", i + 1, knight_path[i].x, knight_path[i].y);
  }
}
