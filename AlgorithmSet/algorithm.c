#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "algorithm.h"

void insertSort(int *array, unsigned int size)
{
  for (size_t i = 1; i < size; i++)
  {
    for (int j = 0; j < i; j++)
    {
      if (array[i] < array[j])
      {
        int temp = array[j];
        array[j] = array[i];
        array[i] = temp;
      }
    }
  }
}

void selectSort(int *array, unsigned int size)
{
  for (int i = 0; i < size; i++)
  {
    for (int j = i; j < size; j++)
    {
      if (array[i] > array[j])
      {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
      }
    }
  }
}
void shellSort(int *array, unsigned int size)
{
  int interval = size / 2;

  while (interval >= 1)
  {
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
    interval = interval / 2;
  }
}

void merge(int *array, int start, int middle, int end)
{

  int indexLeft = start;
  int indexRight = middle + 1;
  int tempSize = end - start + 1;
  int tempArray[tempSize];
  int tempIndex = 0;
  while (indexLeft <= middle && indexRight <= end)
  {
    if (array[indexLeft] < array[indexRight])
    {
      tempArray[tempIndex] = array[indexLeft];
      indexLeft++;
    }
    else
    {
      tempArray[tempIndex] = array[indexRight];
      indexRight++;
    }
    tempIndex++;
  }

  while (indexLeft <= middle)
  {
    tempArray[tempIndex] = array[indexLeft];
    indexLeft++;
    tempIndex++;
  }
  while (indexRight <= end)
  {
    tempArray[tempIndex] = array[indexRight];
    indexRight++;
    tempIndex++;
  }
  for (int i = 0; i < tempSize; i++)
  {
    array[start] = tempArray[i];
    start++;
  }
}

void sortMerge(int *array, int start, int end)
{
  if (start < end)
  {
    int middle = (start + end) / 2;
    sortMerge(array, start, middle);
    sortMerge(array, middle + 1, end);
    merge(array, start, middle, end);
  }
}

void mergeSort(int *array, unsigned int size)
{
  int start = 0;
  int end = size - 1;
  sortMerge(array, start, end);
}

void sortQuick(int *array, unsigned int start, unsigned int end)
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
  }

  int temp0 = array[startIndex];
  array[startIndex] = pivot;
  array[start] = temp0;
  sortQuick(array, start, startIndex - 1);
  sortQuick(array, startIndex + 1, end);
}
void quickSort(int *array, unsigned int size)
{
  sortQuick(array, 0, size - 1);
}