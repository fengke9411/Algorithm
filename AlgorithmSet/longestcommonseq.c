#include <stdio.h>

int xsize = 10;
char X[10] = {'A', 'A', 'B', 'D', 'C', 'E', 'B', 'F', 'A', 'A'};
int ysize = 6;
char Y[6] = {'C', 'B', 'D', 'C', 'E', 'A'};
int Z[10][6];

void print(int z[][6])
{

  for (int i = 0; i < 10; i++)
  {

    for (int j = 0; j < 6; j++)
    {
      printf("%2d  ", z[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

void lcs(char *XS, char *YS, int xsize, int ysize)
{
  for (int i = 0; i < xsize; i++)
  {
    Z[i][0] = 0;
    if (XS[i] == YS[0])
    {
      Z[i][0] = 1;
    }
  }
  for (int j = 0; j < xsize; j++)
  {
    Z[0][j] = 0;
    if (XS[0] == YS[j])
    {
      Z[0][j] = 1;
    }
  }
  print(Z);
  int maxlength = 0;
  int x = 0;
  int y = 0;
  for (int i = 1; i < xsize; i++)
  {
    for (int j = 1; j < ysize; j++)
    {
      if (XS[i] == YS[j])
      {
        Z[i][j] = Z[i - 1][j - 1] + 1;
      }
      else
      {
        Z[i][j] = 0;
      }

      if (Z[i][j] > maxlength)
      {
        maxlength = Z[i][j];
        x = i;
        y = j;
      }
    }
  }
  print(Z);

  printf("longest common sequence: %d x:%d y:%d \n", maxlength,x,y);

  for (int i = x - maxlength+1; i <= x; i++)
  {
    printf(" %c ", XS[i]);
  }
  printf("\n");
}

int main()
{
  lcs(X, Y, 10, 6);
  return 0;
}