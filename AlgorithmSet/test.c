
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int array[] = {9, 1, 4, 3, 7, 5, 2, 8, 7, 1};

void printArray(int *array, unsigned int size)
{
  for (size_t i = 0; i < size; i++)
  {
    printf("%4d", array[i]);
  }
  printf("\n");
}

void Quick(int *array, unsigned int start, unsigned int end)
{
  if (start >= end)
  {
    return;
  }

  int startIndex = start;
  int endIndex = end;
  int pivot = array[start];

  while (startIndex < endIndex)
  {

    while (startIndex < endIndex && pivot < array[endIndex])
    {
      endIndex--;
    }

    while (startIndex < endIndex && array[startIndex] <= pivot)
    {
      startIndex++;
    }

    int temp = array[startIndex];
    array[startIndex] = array[endIndex];
    array[endIndex] = temp;
    // printf("start end %d %d\n", startIndex, endIndex);

    //printf("pivot %d %d\n", start, pivot);
    printArray(array, SIZE);
  }

  int temp0 = array[startIndex];
  printf("pivot start %d %d\n", pivot, temp0);

  array[startIndex] = pivot;
  array[start] = temp0;
  Quick(array, start, startIndex - 1);
  Quick(array, startIndex + 1, end);
}
void quickSort(int *array, unsigned int size)
{
  printf("11111");
  //sortQuick(array, 0, size - 1);
}

void shellSort(int *array, unsigned int size)
{
  int interval = size / 2;

  while (interval >= 1)
  {
    printf("interval %d\n", interval);

    for (int i = 0; i < interval; i++)
    {
      for (int j = i; j < size; j += interval)
      {
        for (int k = j + interval; k < size; k += interval)
        {
          if (array[j] > array[k])
          {
            int temp = array[j];
            array[j] = array[k];
            array[k] = temp;
          }
        }
      }
    }
    printArray(array, SIZE);

    interval = interval / 2;
  }
}

typedef struct Node
{
  struct Node *next;
  int data;
} Array;

void z(Array *node)
{
  Array *temp = node;
  while (temp->next != NULL)
  {
    printf("->%d", temp->data);
    temp = temp->next;
  }
  printf("->%d\n", temp->data);
}

Array *addNode(Array *node, int element)
{
  if (node == NULL)
  {
    Array *arr = (Array *)malloc(sizeof(Array));
    arr->data = element;
    return arr;
  }
  Array *temp = node;
  while (temp->next != NULL)
  {
    temp = temp->next;
  }
  temp->next = (Array *)malloc(sizeof(Array));
  temp->next->data = element;
  return node;
}


Array* traversal(Array *node){
  Array *temp = node;
  temp->next = NULL;
  Array *nextNode = node->next;
  while(nextNode->next != NULL){
    printf("->%d\n",nextNode->data);
    Array *tempNextNode = nextNode->next;
    nextNode->next = temp;
    temp = nextNode;
    printNode(nextNode);
    nextNode = tempNextNode;
  }
  nextNode->next = temp;
  return nextNode;
}

int main()
{

  printArray(array, SIZE);
  //quickSort(array,SIZE);
  //shellSort(array, 10);
  //printArray(array, SIZE);

  int i = 0;
  Array *node;
  node->data = 0;
  //printNode(node);

  while (i < 10)
  {
    addNode(node, array[i]);
   // printNode(node);
    i++;
  }
    printNode(node);

  Array *node0 = traversal(node);
  printNode(node0);
  return 0;
}
