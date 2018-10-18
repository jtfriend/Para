#include <stdio.h>
#include <stdlib.h>

int in_array(int * needle, int *arr, int size) {
  int i;
  for (i = 0; i < size; i++) {
    if (*arr == *needle && needle != arr) {
      printf("Found!\n");
      return 1;

    }
    // printf("address: %d value: %d\n",arr, *arr);
    arr++;
  }
  printf("Not Found!\n");
  return 0;
}

void randomNonRepeatingArray(int * randArray, int size) {
  for(int i=0; i<size; i++) {
      randArray[i] = 0;
  }

  for(int i=0; i<size; i++) {
      randArray[i] = rand() % 10;
      while (in_array(&randArray[i], &randArray[0], sizeof(randArray)) == 1) {
        randArray[i] = rand() % 10;
      }
  }
  printf("Random Array!\n");
  for(int i=0; i<size; i++) {
    printf("[%d] -  %d\n", i, randArray[i]);
  }
}



int main()
{

    printf("Hello, World!\n");


    /////////////////////////////////////////////
    time_t t;

    srand((unsigned) time(&t));

    int randomArray[10];

    randomNonRepeatingArray(&randomArray[0], 10);


    for(int i=0; i<10; i++) {
        // randVals[i] = rand() % 10;
        printf("%d ", randomArray[i]);
        // arrVal[rand() % 10] = rand() % 10;
    }
    printf("\n");


    ////////////////////////////////////////////////////



   return 0;
}
