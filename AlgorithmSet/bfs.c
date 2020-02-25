#include <stdio.h>
#include <stdlib.h>

typedef struct VertexNode
{
  char data;
  int isVisited;
} vertex;

int vertexCount = 10;
vertex *vertexSet[10];
int nodeIndex = 0;
int edge[10][10];

int queue[10];
int tailIndex = -1;

void addVertex(char value)
{
  if (nodeIndex < 10)
  {
    vertex *node = (vertex *)malloc(sizeof(vertex));
    node->data = value;
    node->isVisited = 0;
    vertexSet[nodeIndex++] = node;
  }
}

void addEdge(int i, int j)
{
  edge[i][j] = 1;
  edge[j][i] = 1;
}

void enqueue(int data)
{

  if (tailIndex > 9)
  {
    return;
  }
  queue[tailIndex++] = data;
}

int dequeue()
{
  if (tailIndex < 0)
  {
    return -1;
  }

  int data = queue[0];
  for (int i = 1; i <= tailIndex; i++)
  {
    queue[i - 1] = queue[i];
  }
  tailIndex--;
  return data;
}

void findAdjacentAndEnqueue(int index)
{

  for (int i = 0; i < 10; i++)
  {
    if (edge[index][i] == 1 && vertexSet[i]->isVisited == 0)
    {
      vertexSet[i]->isVisited = 1;
      enqueue(i);
    }
  }
}

void printVertex()
{
  for (int i = 0; i < 10; i++)
  {
    printf("%c->%d  ", vertexSet[i]->data, vertexSet[i]->isVisited);
  }
  printf("\n");
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

void bfs(int start)
{

  vertexSet[start]->isVisited = 1;
  int temp = start;
  findAdjacentAndEnqueue(start);
  while (tailIndex >= 0)
  {
    findAdjacentAndEnqueue(dequeue());
  }
}

int main()
{
  int charset[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

  for (int i = 0; i < 10; i++)
  {
    addVertex(charset[i]);
  }

  printVertex();
  addEdge(0, 9);
  addEdge(0, 1);
  addEdge(1, 2);
  addEdge(1, 5);
  addEdge(2, 4);
  addEdge(2, 3);
  addEdge(2, 6);
  addEdge(3, 7);
  addEdge(3, 8);
  addEdge(4, 5);
  addEdge(4, 7);
  addEdge(6, 8);
  addEdge(6, 9);
  addEdge(7, 8);
  printEdge();
  bfs(0);
  printVertex();

  return 0;
}