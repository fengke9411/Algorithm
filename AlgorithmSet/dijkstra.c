#include <stdio.h>
#include <stdlib.h>

char vertex[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
int edge[10][10];

typedef struct MinPath
{
  char vertex;
  int length;
} Path;

Path *vistedPaths[10];
Path *unvistedPaths[10];
int vistedSize = 0;

void addEdge(int i, int j, int dis)
{
  edge[i][j] = dis;
  edge[j][i] = dis;
}

void printEdge()
{
  for (int i = 0; i < 10; i++)
  {
    for (int j = 0; j < 10; j++)
    {
      printf("%d ", edge[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

void buildUnvisitedPath()
{
  for (int i = 0; i < 10; i++)
  {
    Path *path = (Path *)malloc(sizeof(Path));
    path->vertex = vertex[i];
    path->length = INT32_MAX;
    unvistedPaths[i] = path;
  }
}

void printPath()
{
  for (int i = 0; i < 10; i++)
  {
    Path *temp = vistedPaths[i];
    if (temp != NULL)
    {
      printf("%c  %d \n", temp->vertex, temp->length);
    }
  }
}

void printPath2()
{
  for (int i = 0; i < 10; i++)
  {
    Path *temp = unvistedPaths[i];
    if (temp != NULL)
    {
      printf("%c  %d \n", temp->vertex, temp->length);
    }
  }
}

void updateUnvisitedPath(int index, int dis)
{
  for (int i = 0; i < 10; i++)
  {
    Path *temp = unvistedPaths[i];
    if (temp != NULL)
    {
      if (edge[index][i] != 0)
      {
        printf("%c %d \n", temp->vertex, edge[index][i]);
        int distance;
        if (temp->length < dis + edge[index][i])
        {
          distance = temp->length;
        }
        else
        {
          distance = dis + edge[index][i];
        }

        temp->length = distance;
        printf("%c  ---  %d %d\n", temp->vertex, temp->length, distance);
      }
    }
  }
  printPath2();
}

void visitVertex(int index)
{
  if (vistedSize == 0)
  {
    Path *temp = unvistedPaths[index];
    temp->length = 0;
    vistedPaths[vistedSize] = temp;
    updateUnvisitedPath(index, 0);
  }
  else
  {
    vistedPaths[vistedSize] = unvistedPaths[index];
    updateUnvisitedPath(index, vistedPaths[vistedSize]->length);
  }
  unvistedPaths[index] = NULL;
  vistedSize++;
  printPath2();
}

int findMin()
{
  int min = INT32_MAX;
  int result;
  for (int i = 0; i < 10; i++)
  {
    Path *temp = unvistedPaths[i];
    if (temp != NULL)
    {
      if (temp->length < min)
      {
        min = temp->length;
        result = i;
      }
    }
  }
  printf("---------find min-------\n");
  printPath2();

  return result;
}

void findMSP(int start)
{
  visitVertex(start);

  while (vistedSize < 10)
  {
    int index = findMin();
    visitVertex(index);
    printPath();
  }
}

int main()
{

  addEdge(0, 1, 2);
  addEdge(0, 2, 3);
  addEdge(0, 5, 8);
  addEdge(2, 5, 1);
  addEdge(2, 3, 3);
  addEdge(5, 3, 4);
  addEdge(4, 8, 1);
  addEdge(4, 9, 2);
  addEdge(8, 6, 6);
  addEdge(8, 9, 9);
  addEdge(6, 7, 2);
  addEdge(7, 1, 4);
  addEdge(6, 5, 5);
  printEdge();
  buildUnvisitedPath();
  findMSP(0);
  printPath();

  return 0;
}