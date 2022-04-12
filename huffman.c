#include "huffman.h"
#include <stdio.h>
#include<stdlib.h>

// from bit array to binary array
unsigned char * createBinary(long int tBytes, char * byteArray)
{
  unsigned char * bitArray = malloc((sizeof(char)) * tBytes * 8);
  int m = 0;

  // build the array of bits
  for(int i = 0; i < tBytes; i++)
  {
    //printf("%c\n", byteArray[i]);   
    for(int j = 0; j < 8; j++)
    {
      bitArray[m] = (byteArray[i] >> j) & 1 ? 1 : 0;
      //printf("%d\n", bitArray[m]);
      m++;
    }
  }
  
  return bitArray;
}

// create preorder traversal key thingy
treeNode *preOrder(unsigned char * binary, long int i)
{
  if (i == 0)
  {
    return NULL;
  }
   
  treeNode *root = malloc(sizeof(*root));
 
  // traverse backwards to build the tree in preorder
  if(binary[i] == 0)
  {
    root->left = preOrder(binary, i-1);
    root->right = preOrder(binary, i-1);
  }
  else // 1 
  {  // value
    unsigned char bin[8];
    int m = 0;
    for(int j = i; j > i-8; j--)
    {
      bin[m] = binary[j];
    }
    root->letter = *bin;
    i = i - 8; // move iterator
  }    
  
  return root;
}


