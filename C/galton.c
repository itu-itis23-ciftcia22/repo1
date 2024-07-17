#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void print_board(int** board, int row_count)
{
  for(int i = 0; i < row_count;i++){
    for(int j = 0; j <= i; j++){
      printf("%5d ",*(*(board+i)+j));
    }
    printf("\n");
  }
}

int main()
{

  int** board = NULL; 
  int board_size = 0;
  printf("Enter the board size: ");
  scanf("%d",&board_size);

  board = (int**) malloc(board_size * sizeof(int*));

  //allocated memory the board
  for(int i=0; i<board_size; i++)
  {
    *(board+i) = (int*) malloc((i + 1) * sizeof(int));
  }

  //intialize the counters for pegs
  for(int i = 0; i < board_size; i++){
    for(int j = 0; j <= i; j++){
      *(*(board+i)+j) = 0;
    }
  }

  srand(time(0));

  for(int k = 0; k < 1000; k++) // for each simulation iteration
  {
    **board += 1;
    int j = 0;
    for(int i = 1; i < board_size; i++)
    {
      if(rand() % 2 == 1)
      {
        j++;
      }
      *(*(board+i)+j) += 1;
    }
  }

  print_board(board, board_size);

  for(int i = 0; i < board_size; i++){
    free(*(board+i));
  }
  free(board);
  return 0;
}