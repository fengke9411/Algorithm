#include <stdio.h>
#include <stdlib.h>

char vertex[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
int edge[10][10];
int points[10][10];

void printEdge()
{
  for (int i = 0; i < 10; i++)
  {
    for (int j = 0; j < 10; j++)
    {
      printf("%6d ", edge[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

void printPoints()
{
  for (int i = 0; i < 10; i++)
  {
    for (int j = 0; j < 10; j++)
    {
      printf("%2d ", points[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

void buildPoints()
{
  for (int i = 0; i < 10; i++)
  {
    for (int j = 0; j < 10; j++)
    {
      points[i][j] = -1;
    }
  }
  printPoints();
}

void buildEdge()
{
  for (int i = 0; i < 10; i++)
  {
    for (int j = 0; j < 10; j++)
    {
      if (i == j)
      {
        edge[i][j] = 0;
      }
      else
      {
        edge[i][j] = INT16_MAX;
      }
    }
  }
  printEdge();
}

void addEdge(int i, int j, int dis)
{
  edge[i][j] = dis;
}

void floyd()
{
  for (int i = 0; i < 10; i++)
  {
    for (int j = 0; j < 10; j++)
    {
      int dis0 = edge[i][j];
      int point = -1;
      for (int k = 0; k < 10; k++)
      {
        if (edge[i][k] + edge[k][j] < dis0)
        {
          dis0 = edge[i][k] + edge[k][j];
          point = k;
        }
      }
      edge[i][j] = dis0;
      points[i][j] = point;
    }
  }
  printEdge();
  printPoints();
}

int main()
{
  buildEdge();
  buildPoints();

  addEdge(0, 1, 3);
  addEdge(0, 5, 1);
  addEdge(1, 2, 1);
  addEdge(2, 3, 3);
  addEdge(2, 7, 2);
  addEdge(3, 5, 1);
  addEdge(3, 4, 2);
  addEdge(4, 6, 1);
  addEdge(4, 2, 1);

  addEdge(5, 6, 6);
  addEdge(5, 9, 5);
  addEdge(6, 9, 7);
  addEdge(7, 8, 1);
  addEdge(8, 9, 5);

  floyd();
  return 0;
}