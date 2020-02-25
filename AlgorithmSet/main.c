#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "algorithm.h"

#define random(x) (rand() % x)

void (*sort)(int *, unsigned int);

void caltime(void (*sort)(int *, unsigned int), int *array, unsigned int size)
{
  long start = clock();
  sort(array, size);
  long end = clock();
  printf("\n排序耗时:==%4ld==\n", (end - start));
}

void printArray(int *array, unsigned int size)
{
  for (size_t i = 0; i < size; i++)
  {
    printf("%4d", array[i]);
  }
  printf("\n");
}

void printMenu()
{
  printf("--------------------------请输入算法对应编码------------------------\n");
  printf("-----插入排序(A)--希尔排序(B)--堆排序(C)--归并排序(D)--快速排序(E)-----\n");
}

int main()
{
  printMenu();
  char option;
  scanf("%c", &option);
  switch (option)
  {
  case 'A':
    printf("你选择了“插入排序”\n");
    break;
  case 'B':
    printf("你选择了“希尔排序”\n");
    break;
  case 'C':
    printf("你选择了“堆排序”\n");
    break;
  case 'D':
    printf("你选择了“归并排序”\n");
    break;
  case 'E':
    printf("你选择了“快速排序”\n");
    break;
  }

  printf("请输入数组大小:\n");

  unsigned int size;
  scanf("%d", &size);

  int array[size];
  for (size_t i = 0; i < size; i++)
  {
    array[i] = random(200);
  }
  printArray(array, size);
  switch (option)
  {
  case 'A':
    printf("插入排序 进行中...\n");
    caltime(&insertSort, array, size);
    break;
  case 'B':
    printf("希尔排序 进行中...\n");
    caltime(&shellSort, array, size);
    break;
  case 'C':
    printf("堆排序 进行中...\n");
    break;
  case 'D':
    printf("归并排序 进行中...\n");
    caltime(&mergeSort, array, size);
    break;
  case 'E':
    printf("快速排序 进行中...\n");
    caltime(&quickSort, array, size);
    break;
  }
  printArray(array, size);
  printf("\n");
  return 0;
}