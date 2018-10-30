#include <stdio.h>
#include <stdlib.h>

int in_array(int * needle, int *arr, int size) {
  int i;

  for (i = 0; i < size; i++) {
    if (*arr == *needle && needle != arr) {
      return 1;
    }
    arr++;
  }
  return 0;
}

void randomNonRepeatingArray(int * randArray, int size) {
  for(int i=0; i<size; i++) {
      randArray[i] = size+1;
  }

  for(int i=0; i<size; i++) {
      randArray[i] = (rand() % 9) + 1;
      while (in_array(&randArray[i], &randArray[0], size) == 1) {
        randArray[i] = (rand() % 9) + 1;
      }
  }
  printf("Random Array!\n");
  for(int i=0; i<size; i++) {
    printf("[%d] -  %d\n", i, randArray[i]);
  }
}


void randomArrayWithBlanks(int * randArray, int sizeOfArray, int filledSpots) {
  int randomVal = 0;
  int randomPosition[9] = {0,0,0,0,0,0,0,0,0};

  printf("Size : %d\n", sizeOfArray);
  printf("Filled : %d\n", filledSpots);

  for(int i=0; i<sizeOfArray; i++) {
      randArray[i] = sizeOfArray;
  }

  for(int i=0; i< sizeOfArray; i++) {
      randArray[i] = (rand() % 9) + 1;
      while (in_array(&randArray[i], &randArray[0], sizeOfArray) == 1) {
        randArray[i] = (rand() % 9) + 1;
      }
  }

  for(int i=0; i < (sizeOfArray - filledSpots); i++) {
      randomPosition[i] = (rand() % 9);
      while (in_array(&randomPosition[i], &randomPosition[0], sizeOfArray) == 1) {
        randomPosition[i] = (rand() % 9);
      }
  }

  for(int i=0; i < (sizeOfArray - filledSpots); i++) {
    randArray[randomPosition[i]] = 10;
  }

  printf("Random Array!\n");
  for(int i=0; i<sizeOfArray; i++) {
    printf("[%d] -  %d\n", (i), randArray[i]);
  }
}

void fillBlanks(int * randArray, int sizeOfArray) {
  for(int i= 0; i< sizeOfArray; i++) {
    if (randArray[i] == 10) {
      while ((in_array(&randArray[i], &randArray[0], sizeOfArray) == 1) || (randArray[i] == 10)) {
        randArray[i] = ((rand() % 9) + 1);
      }
    }
  }


  printf("\n");

  for(int i=0; i<sizeOfArray; i++) {
    printf("[%d] -  %d\n", (i), randArray[i]);
  }
}


int main()
{
    /////////////////////////////////////////////
    time_t t;

    srand((unsigned) time(&t));

    int randomArray[9];

    // randomNonRepeatingArray(&randomArray[0], 10);
    randomArrayWithBlanks(&randomArray[0], 9, 3);

    printf("\n");

    fillBlanks(&randomArray[0], 9);

    for(int i=0; i<9; i++) {
        // randVals[i] = (rand() % 9) + 1;
        // printf("%d ", randomArray[i]);
        // arrVal[(rand() % 9) + 1] = (rand() % 9) + 1;
        // printf("%d",(rand() % 9) + 1);
    }
    printf("\n");


    ////////////////////////////////////////////////////



   return 0;
}
