#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <string.h>

int main () {
  int tid, nthreads;
  #pragma omp parallel private(tid)
  {
    tid = omp_get_thread_num();
    printf("Hello World from thread %d\n", tid);
    #pragma omp barrier
    if( tid == 0 )
    {
      nthreads = omp_get_num_threads();
      printf("Total threads= %d\n",nthreads);
    }
  }
  return 0;
}


char[] bruteForceAlgo(char[] hash) {

        char[] a ={"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

        for (int n5=0; n5<37; n5++) {
            for (int n4=0; n4<37; n4++) {
                for (int n3=0; n3<37; n3++) {
                    for (int n2=0; n2<37; n2++) {
                        for (int n1=0; n1<37; n1++) {
                            for (int n0=0; n0<37; n0++) {
                                char[] possPass = a[n5]+a[n4]+a[n3]+a[n2]+ a[n1]+a[n0];

                                if (possPass == hash) {
                                    return possPass;
                                }
                            }
                        }
                    }
                }
            }
        }
        return "Failed";
    }


    // gcc hello.c –o hello –fopenmp
















///
