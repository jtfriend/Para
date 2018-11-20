// #include <stdio.h>
// #include <stdlib.h>
// #include <omp.h>
//
// int main () {
//   int tid, nthreads;
//   #pragma omp parallel private(tid)
//   {
//     tid = omp_get_thread_num();
//     printf("Hello World from thread %d\n", tid);
//     #pragma omp barrier
//     if( tid == 0 )
//     {
//       nthreads = omp_get_num_threads();
//       printf("Total threads= %d\n",nthreads);
//     }
//   }
//   return 0;
// }

// #include <stdio.h>
// #include <omp.h>
//
// void hello( ) {
//   /* get thread id */
//   int id = omp_get_thread_num( );
//   printf("Hello from thread %d!\n", id);
// }
//
// int main( ) {
// #pragma omp parallel num_threads(4)
//   hello( );
//   return 0;
// }


#include <stdio.h>
#include <omp.h>

int main( ) {
  int randomArray[10];
  int histoVals[10];

  for(int i=0; i< 10; i++) {
    histoVals[i] = 0;
  }

  FILE *grades;

  grades = fopen("grades.txt", "r");

  int save[100];
  int look;

  for (int i = 0; (fscanf(grades, "%u", &look) != EOF); i++)
  {
    save[i] = look;
  }

  fclose(grades);

  for(int i=0; i< 100; i++) {
    histoVals[((save[i]-1)/10)]++;
  }

  int num = 0;
  for(int i=0; i< 10; i++) {
    printf(":%d - %d :: ",num, num+10);
    for(int j=0; j< histoVals[i]; j++) {
      printf("* ");
    }
    num+=10;
    printf("\n");
  }

  return 0;
}















///
