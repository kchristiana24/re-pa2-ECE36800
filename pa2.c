#include <stdio.h>
#include <stdlib.h>
#include "huffman.h"

int main(int argc, char * * argv)
{
  // argv[1] - name of the input file to be decoded
  // argv[2] - reconstruct tree and store in pre-order traversal here
  // argv[3] - decode and store the decoded version into output file here
  // argv[4] - frequencies of each ASCII character
  // argv[5] - topology of huffman tree using char based representation
  // argv[6] - number file

  // verify that all inputs are provided
  if (argc < 6)
  {
    //printf("\ntoo few inputs\n");
    return EXIT_FAILURE;
  }

  // read in from the input file
  FILE * inputFile = fopen(argv[1], "rb");
  if (inputFile == NULL)
  {
    fclose(inputFile);
    return EXIT_FAILURE;
  }

  long int info[3]; // header information
  fread(info,sizeof(long int),3,inputFile);

  // long confirmation
  //for(int i = 0; i < 3; i++)
  //{
  //  printf("num = %li\n", info[i]);
  //}
  
  char * byteArray = malloc(sizeof(char)*info[1]);

  for(int i = 0; i < info[1]; i++)
  {
    byteArray[i] = fgetc(inputFile);
  }
  
  unsigned char * bitArray = createBinary(info[1], byteArray);
   
  
  treeNode * pre = preOrder(bitArray, ( info[1] * 8) ); 
  
  free(pre);
 
  free(byteArray);
  free(bitArray);
  fclose(inputFile); 
  return EXIT_SUCCESS;
}
