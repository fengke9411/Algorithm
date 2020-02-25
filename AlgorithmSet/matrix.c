#include <stdio.h>

int X[5][4] = {{1, 2, 3, 4},
               {2, 1, 5, 3},
               {4, 9, 0, 8},
               {4, 5, 2, 1},
               {7, 6, 8, 9}};
int Y[4][6] = {{1, 2, 3, 4, 5, 6},
               {2, 1, 5, 3, 8, 3},
               {4, 9, 0, 8, 1, 6},
               {4, 5, 2, 1, 4, 3}};

int p = 5;
int q = 4;
int r = 6;

void printMatrix(int x, int y, int matrix[][y])
{

  for (int i = 0; i < x; i++)
  {
    for (int j = 0; j < y; j++)
    {
      printf("%4d", matrix[i][j]);
    }
    printf("\n");
  }
  printf("\n\n");
}

void matrix(int x[][q], int y[][r], int p, int q, int r)
{

  printMatrix(p, q, x);
  printMatrix(q, r, y);

  int Z[p][r];
  for (int i = 0; i < p; i++)
  {
    for (int j = 0; j < r; j++)
    {
      Z[i][j] = 0;
      for (int k = 0; k < q; k++)
      {
        printf("%d*%d  ", x[i][k], y[k][j]);
        Z[i][j] = Z[i][j] + x[i][k] * y[k][j];
      }
      printf(" %2d\t",Z[i][j]);
    }
    printf("\n");
  }

  printMatrix(p, r, Z);
}

int main()
{
  matrix(X, Y, p, q, r);
  return 0;
}