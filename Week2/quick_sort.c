#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys\timeb.h>


int main()
{
    //set time checkers
    struct timeb start, end;
    double diff;
    int i = 0;
    ftime(&start);
    //////////////////////

    time_t t;

    srand((unsigned) time(&t));
    printf("Hello, World!\n");

    int arrVal[10];

    for(int i=0; i<10; i++) {
        arrVal[i] = rand() % 10;
    }

    for(int i=0; i<10; i++) {
        printf("%d ", arrVal[i]);
    }
    printf("\n");

    int temp = 0;

    for(int j=0; j< 9; j++) {
        for(int i=0; i< 9 - j; i++) {
            if ((arrVal[i] > arrVal[i+1])){
                temp = arrVal[i];
                arrVal[i] = arrVal[i+1];
                arrVal[i+1] = temp;
            }
        }
    }

    //looks at end element
    //compares element with first element
    //if end element is less, move to next element
    //else

    for(int i=0; i<10; i++) {
        printf("%d ", arrVal[i]);
    }
    printf("\n");


    ftime(&end);
    diff = ((end.time - start.time) + (end.millitm - start.millitm));

    printf("\nOperation took %f milliseconds\n", diff);


   return 0;
}
