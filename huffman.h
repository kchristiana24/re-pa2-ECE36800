#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode {
  int weight;
  char letter;
  struct treeNode *left;
  struct treeNode *right;
} treeNode;

unsigned char * createBinary(long int tBytes, char * byteArray); 
treeNode * preOrder(unsigned char * binary, long int tBytes);

