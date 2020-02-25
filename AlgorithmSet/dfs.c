
#include <stdio.h>
#include <stdlib.h>

typedef struct VertexNode
{
  char data;
  int isVisited;
} vertex;

int vertexCount = 10;
struct VertexNode vertexSet[10];
int nodeIndex = 0;
int edge[10][10];

int stack[10];
int stackTop = -1;

void addVertex(char value)
{
  if (nodeIndex < 10)
  {
    struct VertexNode *node = (struct VertexNode *)malloc(sizeof(struct VertexNode));
    node->data = value;
    node->isVisited = 0;
    vertexSet[nodeIndex++] = *node;
  }
}

void addEdge(int i, int j)
{
  edge[i][j] = 1;
  edge[j][i] = 1;
}

int findAdjacentNode(int index)
{
  for (int i = 0; i < 10; i++)
  {
    vertex node = vertexSet[i];
    printf(" node %c %d  ",node.data,node.isVisited);
    if (edge[index][i] == 1 && node.isVisited == 0)
    {
      return i;
    }
  }
  printf("\n");
  return -1;
}

void addStack(int index)
{
  if (stackTop > 9)
  {
    return;
  }

  stack[++stackTop] = index;
}

int popStack()
{
  if (stackTop < 0)
  {
    return -1;
  }
  return stack[stackTop--];
}
int getStackTop()
{
  return stack[stackTop];
}

void printVertex()
{
  for (int i = 0; i < 10; i++)
  {
    printf("%c->%d  ", vertexSet[i].data, vertexSet[i].isVisited);
  }
  printf("\n");
}


void traversal(int start)
{
  vertex current = vertexSet[start];
  current.isVisited = 1;
  vertexSet[start] = current;

  addStack(start);
  printVertex();
  int temp = start;
  while (stackTop>=0)
  {
    int nextIndex = findAdjacentNode(getStackTop());
    if (nextIndex != -1)
    {
      vertex current = vertexSet[nextIndex];
      printf(" %d  %c \n",nextIndex,current.data);
      current.isVisited = 1;
      vertexSet[nextIndex] = current;
      addStack(nextIndex);
    }
    else
    {
      popStack();
    }
  }

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
  traversal(0);
  printVertex();

  return 0;
}