#include <stdio.h>
#include <stdlib.h>

int SIZE = 20;

typedef struct Entity
{
  int data;
  int key;
} Entry;

Entry *hashTable[20];

int hash(int key)
{
  return key % SIZE;
}

void insert(int key, int data)
{
  int hashcode = hash(key);
  while (hashTable[hashcode] != NULL)
  {
    int key1 = hashTable[hashcode]->key;
    if (key1 == key)
    {
      hashTable[hashcode]->data = data;
      return;
    }
    hashcode++;
    hashcode = hashcode % SIZE;
  }
  Entry *this = (Entry *)malloc(sizeof(Entry));
  this->data = data;
  this->key = key;
  hashTable[hashcode] = this;
}

Entry *search(int key)
{
  int hashcode = hash(key);

  while (hashTable[hashcode] != NULL)
  {
    Entry *temp = hashTable[hashcode];
    if (temp->key == key)
    {
      return temp;
    }
    hashcode++;
    hashcode %= SIZE;
  }
  return NULL;
}

void delete (int key)
{
  int hashcode = hash(key);
  while (hashTable[hashcode] != NULL)
  {

    Entry *temp = hashTable[hashcode];
    if (temp->key == key)
    {
      free(temp);
      hashTable[hashcode] = NULL;
    }else
    {
      hashcode++;
      hashcode %=SIZE;
    }
    
  }
}

void print()
{

  for (int i = 0; i < SIZE; i++)
  {
    Entry *ety = hashTable[i];
    if (ety != NULL)
    {
      printf("-%d key:%d data:%d; ", i, ety->key, ety->data);
    }
    else
    {
      printf("-%d NULL; ", i);
    }
  }
  printf("\n ");
}

int main()
{

  int a[10] = {9, 10, 20, 12, 15, 11, 33, 21, 17, 8};
  int b[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  for (int i = 0; i < 10; i++)
  {
    insert(a[i], b[i]);
  }
  delete(20);
  insert(20,1);
  print();
  return 0;
}