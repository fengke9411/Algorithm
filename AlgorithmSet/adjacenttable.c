#include <stdio.h>
#include <stdlib.h>

typedef struct VertexEntry
{
  char node;
  struct VertexEntry *adjacentNode;
} Vertex;

Vertex *edge[10];
char nodename[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

void addNode(int index, char name)
{
  Vertex *v = (Vertex *)malloc(sizeof(Vertex));
  v->node = name;
  v->adjacentNode = NULL;
  edge[index] = v;
}

void addEdge(int i, int j)
{
  Vertex *head = edge[i];
  while (head->adjacentNode != NULL)
  {
    head = head->adjacentNode;
  }
  Vertex *v = (Vertex *)malloc(sizeof(Vertex));
  v->node = edge[j]->node;
  v->adjacentNode = NULL;
  head->adjacentNode = v;
}

void print()
{

  for (int i = 0; i < 10; i++)
  {
    Vertex *head = edge[i];
    printf("%d::", i);
    while (head->adjacentNode != NULL)
    {
      printf("%c -> ", head->node);
      head = head->adjacentNode;
    }
    printf("%c \n", head->node);
  }
}

int main()
{

  for (int i = 0; i < 10; i++)
  {
    addNode(i, nodename[i]);
  }

  print();
  addEdge(0, 1);
  addEdge(0, 2);
  addEdge(0, 5);

  addEdge(2, 5);
  addEdge(2, 3);
  addEdge(5, 3);

  addEdge(4, 8);
  addEdge(4, 9);
  //print();

  addEdge(8, 6);
  addEdge(8, 9);
  addEdge(6, 7);
  addEdge(7, 1);
  addEdge(6, 5);
  print();

  return 0;
}