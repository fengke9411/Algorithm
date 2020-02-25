#include <stdio.h>

int W[5] = {5, 10, 6, 8, 2};
int P[5] = {10, 30, 5, 20, 50};

int COUNT = 5;
int SIZE = 20;
int cell[5][20];

void napsack(int array[][20])
{
  for (int i = 0; i < COUNT; i++)
  {
    for (int j = 0; j < SIZE; j++)
    {
      array[i][j] = 0;
      if (i == 0)
      {
        if (j < W[0])
        {
          array[i][j] = 0;
        }
        else
        {
          array[i][j] = P[0];
        }
      }
    }
  }

  for (int i = 1; i < COUNT; i++)
  {
    for (int j = 0; j < SIZE; j++)
    {
      if (j >= W[i])
      {
        if (array[i-1][j - W[i]] + P[i] > array[i-1][j])
        {
          array[i][j] = array[i-1][j - W[i]] + P[i];
        }
        else
        {
          array[i][j] =  array[i-1][j];
        }
      }
      else
      {
         array[i][j] = array[i - 1][j];
      }
    }
  }
}

void print(int array[][SIZE])
{
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < SIZE; j++)
    {
      printf("%4d ", array[i][j]);
    }
    printf("\n");
  }
}

int main()
{

  napsack(cell);
  print(cell);
  return 0;
}