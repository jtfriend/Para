#include <stdio.h>
#include <stdlib.h>
#include <time.h>


_Bool in_array(int * needle, int * arr, int size) {
  for (int i = 0; i< size; i++) {
    printf("Arg1 : %u, Arg2 : %u,\n", *needle, arr[i]);
    if (*needle == arr[i]) {
      return 0;
    }
  }
  return 1;
}


int main()
{

    srand(time(NULL));
    printf("Hello, World!\n");

    int arrVal[3];

    for(int i=0; i<3; i++) {
        arrVal[i] = rand() % 10;
        printf("Arg1 : %u, Arg2 : %u,\n", &arrVal[i], &arrVal);
        if (in_array(&arrVal[i], &arrVal, sizeof(arrVal))) {
          arrChosen[i] = arrVal[i];
              printf("Found!\n");
        }
    }

    for(int i=0; i<3; i++) {
        printf("%d ", arrVal[i]);
    }

    printf("\n");


   return 0;
}
