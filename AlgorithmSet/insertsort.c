#include <stdio.h>
#include <time.h>
#include "insertsort.h"

void insertSort(int *array,unsigned int size){
  long start = clock();
  for (size_t i = 1; i < size; i++)
  {
    for(int j=0;j<i;j++){
      if(array[i]<array[j]){
        int temp = array[j];
        array[j] = array[i];
        array[i] = temp;
      }
    }
  }
  long end = clock();
  printf("排序耗时%4ld\n",end-start);
}

int array[] = {1,4,7,2,2,1,5,6,4,3,8,5,1,9,0};
// int main(){
//   insertSort(array,15);
//   return 0;
// }